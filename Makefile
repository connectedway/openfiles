
macos-smb: macos-smb-config macos-smb-build

macos-smb-config:
	cmake -Bbuild-macos-smb -DCMAKE_BUILD_TYPE=Debug -DOPENFILE_CONFIG=./configs/macos-smb

macos-smb-build:
	cmake --build build-macos-smb

macos-smb-test:
	cd build-macos-smb; OPEN_FILES_HOME=./configs/darwin_debug.xml ctest

macos-smb-clean:
	rm -rf build-macos-smb

macos-smbfs: macos-smbfs-config macos-smbfs-build

macos-smbfs-config:
	cmake -Bbuild-macos-smbfs -DCMAKE_BUILD_TYPE=Debug -DCMAKE_APPLE_SILICON_PROCESSOR=arm64 -DOPENFILE_CONFIG=./configs/macos-smbfs

macos-smbfs-build:
	cmake --build build-macos-smbfs

macos-smbfs-test:
	OPEN_FILES_HOME=./configs/darwin_debug.xml \
            ./build-macos-smbfs/of_smb_fs/test/test_fs_smb

macos-smbfs-clean:
	rm -rf build-macos-smbfs

macos-smbfs-install:
	cmake --install build-macos-smbfs
	cp configs/darwin_debug.xml /etc/openfiles.xml

macos-smbfs-uninstall:
	rm /etc/openfiles.xml
	@xargs rm < build-macos-smbfs/install_manifest.txt 2> /dev/null || true
	@rmdir /usr/local/bin/openfiles 2> /dev/null || true

macos-smbfs-init:
	git submodule init of_core_cheap of_core_binheap of_core Unity \
	of_core_fs_bookmarks of_core_fs_linux of_core_linux of_core_fs_pipe
	git submodule init of_smb of_smb_fs of_smb_client of_security \
	of_smb_browser of_netbios

macos-smbfs-update:
	git submodule update of_core_cheap of_core_binheap of_core Unity \
	of_core_fs_bookmarks of_core_fs_linux of_core_linux of_core_fs_pipe
	git submodule update of_smb of_smb_fs of_smb_client of_security \
	of_smb_browser of_netbios

androidsim-smb: androidsim-smb-config androidsim-smb-build

androidsim-smb-config:
	cmake -Bbuild-androidsim-smb -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=/Users/rschmitt/Library/Android/sdk/ndk/23.1.7779620/build/cmake/android.toolchain.cmake -DANDROID_ABI=x86_64 -DANDROID_PLATFORM=android-23 -DCMAKE_SYSTEM_VERSION=23 -DOPENFILE_CONFIG=./configs/android-smb

androidsim-smb-build:
	cmake --build build-androidsim-smb

androidsim-smb-clean:
	rm -rf build-androidsim-smb

linux-smb: linux-smb-config linux-smb-build

linux-smb-config:
	cmake -Bbuild-linux-smb -DCMAKE_BUILD_TYPE=Debug -DOPENFILE_CONFIG=./configs/linux-smb

linux-smb-build:
	cmake --build build-linux-smb

linux-smb-test:
	OPEN_FILES_HOME=./configs/linux_debug.xml \
            ./build-linux-smb/of_smb_fs/test/test_fs_smb

linux-smb-clean:
	rm -rf build-linux-smb

linux-smb-install:
	cmake --install build-linux-smb
	ldconfig /usr/local/lib
	cp configs/linux_debug.xml /etc/openfiles.xml

linux-smbfs: linux-smbfs-config linux-smbfs-build

linux-smbfs-config:
	cmake -Bbuild-linux-smbfs -DCMAKE_BUILD_TYPE=Debug -DOPENFILE_CONFIG=./configs/linux-smbfs -DMBEDTLS_ROOT_DIR=/usr/local

linux-smbfs-build:
	cmake --build build-linux-smbfs

linux-smbfs-install:
	cmake --install build-linux-smbfs
	ldconfig /usr/local/lib
	cp configs/linux_debug.xml /etc/openfiles.xml

linux-smbfs-uninstall:
	rm /etc/openfiles.xml
	@xargs rm < build-linux-smbfs/install_manifest.txt 2> /dev/null || true
	@rmdir /usr/local/bin/openfiles 2> /dev/null || true

linux-smbfs-test:
#	cd build-linux-smbfs; OPEN_FILES_HOME=./configs/linux_debug.xml ctest
	OPEN_FILES_HOME=./configs/linux_debug.xml \
            ./build-linux-smbfs/of_smb_fs/test/test_fs_smb

linux-smbfs-clean:
	rm -rf build-linux-smbfs

linux-smbfs-init:
	git submodule init of_core_cheap of_core_binheap of_core Unity \
	of_core_fs_bookmarks of_core_fs_linux of_core_linux of_core_fs_pipe
	git submodule init of_smb of_smb_fs of_smb_client of_security \
	of_smb_browser of_netbios

linux-smbfs-update:
	git submodule update of_core_cheap of_core_binheap of_core Unity \
	of_core_fs_bookmarks of_core_fs_linux of_core_linux of_core_fs_pipe
	git submodule update of_smb of_smb_fs of_smb_client of_security \
	of_smb_browser of_netbios

yocto-smbfs: yocto-smbfs-config yocto-smbfs-build

yocto-smbfs-config:
	cmake -Bbuild-yocto-smbfs -DCMAKE_BUILD_TYPE=Debug -DOPENFILE_CONFIG=./configs/yocto-smbfs -DMBEDTLS_ROOT_DIR=/usr/local

yocto-smbfs-build:
	cmake --build build-yocto-smbfs

yocto-smbfs-install:
	cmake --install build-yocto-smbfs

yocto-smbfs-test:
	OPEN_FILES_HOME=./configs/linux_debug.xml \
            ./build-yocto-smbfs/of_smb_fs/test/test_fs_smb

yocto-smbfs-clean:
	rm -rf build-yocto-smbfs

linux-smbloop: linux-smbloop-config linux-smbloop-build

linux-smbloop-config:
	cmake -Bbuild-linux-smbloop -DCMAKE_BUILD_TYPE=Debug -DOPENFILE_CONFIG=./configs/linux-smbloop -DMBEDTLS_ROOT_DIR=/usr/local

linux-smbloop-build:
	cmake --build build-linux-smbloop

linux-smbloop-install:
	cmake --install build-linux-smbloop
	ldconfig /usr/local/lib
	cp configs/linux_loop.xml /etc/openfiles.xml

linux-smbloop-uninstall:
	rm /etc/openfiles.xml
	@xargs rm < build-linux-smbloop/install_manifest.txt 2> /dev/null || true
	@rmdir /usr/local/bin/openfiles 2> /dev/null || true

linux-smbloop-test:
#	cd build-linux-smbfs; OPEN_FILES_HOME=./configs/linux_debug.xml ctest
	OPEN_FILES_HOME=./configs/linux_loop.xml \
            ./build-linux-smbloop/of_smb_fs/test/test_fs_smb

linux-smbloop-clean:
	rm -rf build-linux-smbloop

linux-smbloop-init:
	git submodule init of_core_cheap of_core_binheap of_core Unity \
	of_core_fs_bookmarks of_core_fs_linux of_core_linux of_core_fs_pipe
	git submodule init of_smb of_smb_fs of_smb_client of_security \
	of_smb_browser of_smb_server of_netbios

linux-smbloop-update:
	git submodule update of_core_cheap of_core_binheap of_core Unity \
	of_core_fs_bookmarks of_core_fs_linux of_core_linux of_core_fs_pipe
	git submodule update of_smb of_smb_fs of_smb_client of_security \
	of_smb_browser of_smb_server of_netbios


linux: linux-config linux-build

linux-config:
	cmake -Bbuild-linux -DCMAKE_BUILD_TYPE=Debug -DOPENFILE_CONFIG=./configs/linux

linux-build:
	cmake --build build-linux

linux-install:
	cmake --install build-linux
	ldconfig /usr/local/lib

linux-uninstall:
	@xargs rm < build-linux/install_manifest.txt 2> /dev/null || true
	@rmdir /usr/local/bin/openfiles 2> /dev/null || true

linux-init:
	git submodule init of_core_cheap of_core_binheap of_core Unity \
	of_core_fs_bookmarks of_core_fs_linux of_core_linux of_core_fs_pipe

linux-update:
	git submodule update of_core_cheap of_core_binheap of_core Unity \
	of_core_fs_bookmarks of_core_fs_linux of_core_linux of_core_fs_pipe

linux-test:
	cd build-linux; OPEN_FILES_HOME=./configs/linux_debug.xml ctest

linux-clean:
	rm -rf build-linux

linux-perf: linux-perf-config linux-perf-build

linux-perf-config:
	cmake -Bbuild-linux-perf -DCMAKE_BUILD_TYPE=Debug -DOPENFILE_CONFIG=./configs/linux-perf

linux-perf-build:
	cmake --build build-linux-perf

linux-perf-test:
	OPEN_FILES_HOME=./configs/linux_debug.xml \
            ./build-linux-perf/of_core/test/test_fs_linux

linux-perf-clean:
	rm -rf build-linux-perf


