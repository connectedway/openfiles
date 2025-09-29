cmake_minimum_required(VERSION 3.20.0)
project(openfiles VERSION 5.3.0 DESCRIPTION "Multi-Platform Event-Driven Application Framework")

enable_testing()

set(CMAKE_VERBOSE_MAKEFILE TRUE)

if (NOT DEFINED OPENFILE_PLATFORM)
   set(OPENFILE_NAMING "build/naming.cfg")
   set(OPENFILE_PLATFORM "build/android_arm64-v8a-platform.cfg")
   set(OPENFILE_BEHAVIOR "build/android_arm64-v8a-behavior.cfg")
   set(OPENFILE_SIZING "build/sizing.cfg")
   set(OPENFILE_DEBUG "build/nodebug.cfg")
   set(OPENFILE_SMB "build/smbserver.cfg")
   set(OPENFILE_CIPHER "build/mbedtls.cfg")
   set(OPENFILE_JNI "build/jni.cfg")
endif()



include(${OPENFILE_NAMING})
include(${OPENFILE_PLATFORM})
include(${OPENFILE_BEHAVIOR})
include(${OPENFILE_SIZING})
include(${OPENFILE_DEBUG})
include(${OPENFILE_SMB})
include(${OPENFILE_CIPHER})
include(${OPENFILE_JNI})

if(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
  option(OFC_64BIT_POINTER "Compiler supports 64 bit pointers" ON)
else()
  option(OFC_64BIT_POINTER "Compiler supports 64 bit pointers" OFF)
endif()  
if(DEFINED OFC_64BIT_POINTER AND NOT DEFINED OFC_64BIT_INTEGER)
    message(FATAL_ERROR "Must support 64 bit integers if 64 bit pointers defined")
endif()

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")

configure_file(include/ofc/config.h.in ofc/config.h @ONLY)
include_directories(${openfiles_BINARY_DIR})

#
# Tell cmake where openssl and mbedtls are for Android and Darwin.
# Linux is much more cooperative
#
if(ANDROID)
  # Check if environment variable is set, otherwise use local path
  if(DEFINED ENV{OPENSSL_NDK_PATH})
    set(OPENSSL_NDK $ENV{OPENSSL_NDK_PATH}/${CMAKE_ANDROID_ARCH_ABI})
  else()
    set(OPENSSL_NDK /home/vnc/git/openssl/install-ndk/${CMAKE_ANDROID_ARCH_ABI})
  endif()
  set(OPENSSL_ROOT_DIR ${OPENSSL_NDK})
  set(OPENSSL_INCLUDE_DIR ${OPENSSL_NDK}/include)
  set(OPENSSL_CRYPTO_LIBRARY ${OPENSSL_NDK}/lib/libcrypto.so)
  set(OPENSSL_SSL_LIBRARY ${OPENSSL_NDK}/lib/libssl.so)

  if(DEFINED ENV{MBEDTLS_NDK_PATH})
    set(MBEDTLS_NDK $ENV{MBEDTLS_NDK_PATH}/${CMAKE_ANDROID_ARCH_ABI})
  else()
    set(MBEDTLS_NDK /home/vnc/git/mbedtls/install-ndk/${CMAKE_ANDROID_ARCH_ABI})
  endif()
  set(MBEDTLS_ROOT_DIR ${MBEDTLS_NDK})
  set(MBEDTLS_INCLUDE_DIR ${MBEDTLS_NDK}/include)
  set(MBEDTLS_CRYPTO_LIBRARY ${MBEDTLS_NDK}/lib/libmbedcrypto.a)
  set(MBEDTLS_SSL_LIBRARY ${MBEDTLS_NDK}/lib/libmbedtls.a)
  set(MBEDTLS_X509_LIBRARY ${MBEDTLS_NDK}/lib/libmbedx509.a)

endif()
if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  set(OPENSSL_ROOT_DIR "/opt/homebrew/Cellar/openssl@3/3.2.1")
  set(OPENSSL_INCLUDE_DIR ${OPENSSL_ROOT_DIR}/include)
  set(OPENSSL_CRYPTO_LIBRARY ${OPENSSL_ROOT_DIR}/lib/libcrypto.3.dylib)
  set(OPENSSL_SSL_LIBRARY ${OPENSSL_ROOT_DIR}/lib/libssl.3.dylib)

  set(MBEDTLS_ROOT_DIR "/opt/homebrew/Cellar/mbedtls/3.2.1")
  set(MBEDTLS_INCLUDE_DIR ${MBEDTLS_ROOT_DIR}/include)
  # Dynamic MbedTLS library does not work on MacOS.  Just link in static
  set(MBEDTLS_CRYPTO_LIBRARY ${MBEDTLS_ROOT_DIR}/lib/libmbedcrypto.a)
  set(MBEDTLS_SSL_LIBRARY ${MBEDTLS_ROOT_DIR}/lib/libmbedtls.a)
  set(MBEDTLS_X509_LIBRARY ${MBEDTLS_ROOT_DIR}/lib/libmbedx509.a)
endif()
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(MBEDTLS_ROOT_DIR "/usr/local")
  set(MBEDTLS_INCLUDE_DIR ${MBEDTLS_ROOT_DIR}/include)
  set(MBEDTLS_CRYPTO_LIBRARY ${MBEDTLS_ROOT_DIR}/lib64/libmbedcrypto.so)
  set(MBEDTLS_SSL_LIBRARY ${MBEDTLS_ROOT_DIR}/lib64/libmbedtls.so)
  set(MBEDTLS_X509_LIBRARY ${MBEDTLS_ROOT_DIR}/lib64/libmbedx509.so)
endif()

#
# Get the Library Variables all set up
#
if(OF_OPENSSL)
  find_package(OpenSSL)
  if (OPENSSL_FOUND)
     list(APPEND crypto_library_list ${OPENSSL_CRYPTO_LIBRARY} ${OPENSSL_SSL_LIBRARY})
  endif()
endif()

if(OF_MBEDTLS)
  list(APPEND crypto_library_list ${MBEDTLS_SSL_LIBRARY} ${MBEDTLS_X509_LIBRARY} ${MBEDTLS_CRYPTO_LIBRARY})
endif()

if(OF_GNUTLS)
  find_package(GnuTLS)
  if (GNUTLS_FOUND)
    list(APPEND ssl_library_list GnuTLS::GnuTLS)
  endif()
endif()

if(ANDROID AND OFC_KERBEROS)
set(KRB5_NDK /Users/rschmitt/git/krb5.of/install-ndk/${CMAKE_ANDROID_ARCH_ABI})
set(KRB5_INCLUDE_PATH ${KRB5_NDK}/include)
set(KRB5_LIBRARY_PATH ${KRB5_NDK}/lib)
set(KRB5_LIBS ${KRB5_LIBRARY_PATH}/libgssapi_krb5.a ${KRB5_LIBRARY_PATH}/libkrb5support.a ${KRB5_LIBRARY_PATH}/libcom_err.a ${KRB5_LIBRARY_PATH}/libkrb5.a ${KRB5_LIBRARY_PATH}/libk5crypto.a)
endif()

add_subdirectory(of_core)
include_directories(${of_core_SOURCE_DIR}/include)

add_subdirectory(of_core_binheap)
add_subdirectory(of_core_cheap)

if(OF_RESOLVER_FS)
  add_subdirectory(of_resolver_fs)
endif()

if (CMAKE_SYSTEM_NAME STREQUAL "Android")
    add_subdirectory(of_core_android)
    add_subdirectory(of_core_fs_android)
endif ()
if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    add_subdirectory(of_core_darwin)
    add_subdirectory(of_core_fs_darwin)
endif ()
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_subdirectory(of_core_linux)
    add_subdirectory(of_core_fs_linux)
endif ()
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_subdirectory(of_core_windows)
    add_subdirectory(of_core_fs_windows)
endif ()
add_subdirectory(of_core_fs_bookmarks)

if(OFC_INCLUDE_JNI)
  message("Adding JNI")
  add_subdirectory(of_core_jni)
endif()

if(OFC_FS_PIPE)
  add_subdirectory(of_core_fs_pipe)
endif()

if(OF_NETBIOS)
  message("Adding NetBIOS")
  add_subdirectory(of_netbios)
endif()

if(OF_SMB)
  message("Adding SMB")
  add_subdirectory(of_smb)
  add_subdirectory(of_security)
  if(OF_SMB_SERVER)
    message("Adding SMB Server")
    add_subdirectory(of_smb_server)
  endif()
  if(OF_SMB_CLIENT)
    message("Adding SMB Client")
    add_subdirectory(of_smb_client)
    add_subdirectory(of_smb_fs)
    add_subdirectory(of_smb_browser)
  endif()
  if(OPENFILES_SMB_JNI)
    message("Adding SMB JNI")
    add_subdirectory(of_smb_jni)
  endif()
endif()

find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_PROJECT_NAME "Open Files")
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_LATEX YES)
    set(DOXYGEN_GENERATE_PDF YES)
    set(DOXYGEN_USE_PDFLATEX YES)
    set(DOXYGEN_PDF_HYPERLINKS YES)
    set(DOXYGEN_PROJECT_LOGO ${CMAKE_CURRENT_SOURCE_DIR}/documentation/connected.png)
    set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_EXTRACT_PRIVATE NO)
    set(DOXYGEN_FULL_SIDEBAR YES)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
    set(DOXYGEN_HTML_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/documentation/headerFile)
    set(DOXYGEN_INTERNAL_DOCS NO)
    list(APPEND DOXYGEN_HTML_EXTRA_FILES ${CMAKE_CURRENT_SOURCE_DIR}/documentation/connected.ico)
    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.openfiles)
    set(DOXYGEN_EXAMPLE_PATH ${of_core_SOURCE_DIR}/test)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/documentation)
    set(DOXYGEN_EXCLUDE_PATTERNS
	*/file_call.h
	*/net_internal.h
	*/fs.h
	*/fstypes.h
	*/impl/*
	*.c
	README.md
	)

if (OFC_INCLUDE_JNI)
   set(JNI_FILES
       of_core_jni/java
       of_core_jni/documentation/openfiles_jni.h
       )
    list(APPEND DOXYGEN_EXAMPLE_PATH ${of_core_jni_SOURCE_DIR}/test)
endif()

    list(APPEND DOXYGEN_EXAMPLE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/smbcp)
    list(APPEND DOXYGEN_EXAMPLE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/configs)
    doxygen_add_docs(
        openfiles
	${CMAKE_CURRENT_SOURCE_DIR}/documentation/openfiles.h
	${CMAKE_CURRENT_SOURCE_DIR}/documentation/config.h
	${of_core_SOURCE_DIR}/include/ofc/types.h
	${of_core_SOURCE_DIR}/include/ofc/framework.h
	${of_smb_SOURCE_DIR}/include/of_smb/framework.h
	${of_core_SOURCE_DIR}/include/ofc/path.h
	${of_core_SOURCE_DIR}/include/ofc/file.h
	${of_core_SOURCE_DIR}/include/ofc/heap.h
	${of_core_SOURCE_DIR}/include/ofc/handle.h
	${of_core_SOURCE_DIR}/include/ofc/waitset.h
	${of_core_SOURCE_DIR}/include/ofc/queue.h
	${of_core_SOURCE_DIR}/include/ofc/time.h
	${JNI_FILES}
	)
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        add_custom_target(
            doc ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM
            )
    endif()
endif()

