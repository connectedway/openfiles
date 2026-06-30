/*!
\defgroup config Static Configuration Parameters

These parameters control the build of the Open Files stack.

Openfiles configuration is managed through a set of cmake 
include files.  In order to support flexible configurations, we
group include files as follows:

- platform configurations
- behavior configurations
- debug configurationss
- smb configurations
- cipher configurations
- jni configurations  
- identity configuration
- limit configurations

### Platform Configuration

A platform configuration file defines the compile type definitions
required to support the platform.

Openfiles comes preconfigured for the following platforms:

- android armv8: ./build/android_arm64-v8a-platform.cfg
- android armv7: ./build/android_armeabi-v7a-platform.cfg
- android x86_64: ./build/android_x86_64-platform.cfg
- android x86: ./build/android_x86-platform.cfg
- linux arm64 and x86_64: ./build/linux-platform.cfg
- macos arm64 and x86_64: ./build/macos-platform.cfg
- windows x86_64: ./build/win-platform.cfg

Openfiles is easily ported to other platforms.  Any of the above
configuration files can be used as a template for a new platform config.
Connected Way also has other config files for platforms not listed.

Configuration Item | Example | Description
-------------------|---------|------------
OFC_IMPL | linux | Platform Support Library
OFC_64BIT_INTEGER | ON/OFF | Compiler supports 64 bit integers
OFC_64BIT_POINTER | ON/OFF | Compiler supports 64 bit pointers
OFC_LONGINT_64 | ON/OFF | Compiler treats a long int as 64 bits
OFC_WCHAR | wchar_t | Platform type of a wide character
INCLUDE_PLATFORM_WCHAR | ON/OFF | Include a file with wchar definition
PLATFORM_WCHAR | wchar.h | Name of File to include
OFC_PROCESS_ID | pid_t | Platform type of a process id
INCLUDE_PLATFORM_PROCESS_ID | ON/OFF | Include a file with pid definition
PLATFORM_PROCESS_ID | sys/types.h | Name of File to include
OFC_FS_LINUX | ON/OFF | Platform File System Library
OFC_LOOPBACK | ON/OFF | Configure a loopback Address
OFC_MULTI_TCP | ON/OFF | Listen on Each TCP Interface
OFC_MULTI_UDP | ON/OFF | Listen on Each UDP Interface

### <a name="behavior"></a>Behavior Configuration

A behavior configuration file defines the Open Stack behavior for 
the various platforms.

Openfiles comes preconfigured for the following behaviors.

- android armv8: ./build/android_arm64-v8a-behavior.cfg
- android armv7: ./build/android_armeabi-v7a-behavior.cfg
- android x86_64: ./build/android_x86_64-behavior.cfg
- android x86: ./build/android_x86-behavior.cfg
- linux arm64 and x86_64: ./build/linux-behavior.cfg
- macos arm64 and x86_64: ./build/macos-behavior.cfg
- windows x86_64: ./build/win-behavior.cfg

The default behavior for each platform is specified in the above
configuration files.  These can be modified or used as a template
for other behaviors.

Configuration Item | Example | Description
-------------------|---------|------------
OFC_NETMON | ON/OFF | Include Network Monitoring in build (ON/OFF)
OFC_PERSIST | ON/OFF | Build in persistent configuration support (ON/OF)
OFC_PERF_STATS | ON/OFF | Build in performance statistics (ON/OFF)
OFC_UNICODE_API | ON/OFF | File APIs use unicode (ON/OFF)
OFC_PRESELECT_PASS | ON/OFF | Scheduling Optimization (ON/OFF)
INIT_ON_LOAD | ON/OFF | Initialize libraries on load (ON/OFF)
OFC_LOAD_CORE | __attribute__((constructor(102))) | Macro to specify auto load constructor 
OFC_UNLOAD_CORE | __attribute__((destructor(102))) | Macro to specify auto unload destructor
OFC_LOAD_SMB | __attribute__((constructor(105))) | Macro to specify auto load constructor for SMB
OFC_UNLOAD_SMB | __attribute__((destructor(105))) | Macro to specify auto unload destructor for SMB
OFC_DISCOVER_IPV4 | ON/OFF | Support IPv4 Network Addresses
OFC_DISCOVER_IPV6 | ON/OFF | Support IPv6 Network Addresses

### Debug Configuration

Configurations that govern debug options within Open Files

Openfiles comes preconfigured for the following debug configurations.

- ./build/debug.cfg: Debug Configuration
- ./build/nodebug.cfg: Release Configuration

The default behavior for debug and release configurations is defined
in the above configuration files.  These can be modified or used as a
template for other debug behaviors.

Configuration Item | Example | Description
-------------------|---------|------------
OFC_HANDLE_DEBUG | ON/OFF | Build in debug checks for handles
OFC_MESSAGE_DEBUG | ON/OFF | Build in debug checks for messages
OFC_APP_DEBUG | ON/OFF | Build in debug checks for apps
OFC_HEAP_DEBUG | ON/OFF | Build in debug checks for heap
OFC_STACK_TRACE | ON/OFF | Store call stack traces in debug output
OFC_TRACE_LEN | 1 | Size of trace buffer (must be at least 1)
OFC_LOG_DEFAULT | 3 | Default Log Level
OFC_LOG_CONSOLE | 0 | Log to Console, 1=yes, 0=no
OFC_HEAP_IMPL | cheap | Heap implementation to use, binheap/cheap

\note
binheap is a custom implementation of a binary heap with additional debug
capabilities.  cheap is a wrapper for the libc malloc/free library.

### Identity Configuration

Configurations that set the default platform identity.  These
can be overwritten by the persistent runtime configuration file or
though an API.

The identity configuration is defined in:

- ./build/naming.cfg

Configuration Item | Example | Description
-------------------|---------|------------
OFC_SHARE_VARIANT | main | Variant name of build. 
OFC_DEFAULT_NAME | localhost | Default system name
OFC_DEFAULT_SCOPE | | Default NetBIOS scope
OFC_DEFAULT_DESCR | Open Files | Default System Description
OFC_DEFAULT_DOMAIN | WORKGROUP | Default System Domain

### Sizing Configuration

Configurations that manage sizing of the Open Files stack.  The default
sizing configuration has been qualified as optimal.  You may find a need
to tweak these depending on your specific workloads

The sizing configuration is defined in:

- ./build/sizing.cfg

Configuration Item | Example | Description
-------------------|---------|------------
OFC_MAX_HANDLE16 | 100 | Max 16-bit handles (eg. 100)
OFC_MAX_MAPS | 20 | Max file system maps (eg. 20)
OFC_MAX_SCHED_WAIT | 4000 | Maximum scheduler sleep (eg. 4000)
OFC_MAX_IO | 65536 | Maximum IO Buffer Size for Streaming (eg. 65536)
OFC_CALL_STACK_SIZE | 32768 | Maximum Buffer To Map for I/O (eg. 32768)

### JNI Configuration

If building with a Java Native Interface for the OpenFiles SMB stack,
there are configuration items required to build in the JNI layer.

The jni configuration is defined in one of the following two configuration
files:

- ./build/jni.cfg: Build with JNI
- ./build/nojni.cfg: Build without JNI

Configuration Item | Example | Description
-------------------|---------|------------
OFC_INCLUDE_JNI | ON/OFF | Build a base JNI library
OPENFILES_SMB_JNI | ON/OFF | Build a SMB JNI library

The list of includes are:

### SMB Enablement

If building in the SMB support into OpenFiles, there is the enablement
of SMB, and then a separate SMB Configuration.

For enablement, there are three preconfigured files:

- ./build/nosmb.cfg: Do not build in SMB
- ./build/smbclient.cfg: Build in the SMB client
- ./build/smbserver.cfg: Build in the SMB server.  This also includes the SMB
client

Configuration Item | Example | Description
-------------------|---------|------------
OF_NETBIOS | ON/OFF | Include Netbios
OFC_DEFAULT_NETBIOS_MODE | OFC_CONFIG_BMODE | Default NetBIOS Mode
OFC_FS_PIPE | ON/OFF| Add Open File Pipe File System
OFC_FS_BOOKMARKS | ON/OFF | Add Bookmarks (alias) for client
OF_RESOLVER_FS | ON/OFF | Add Open Files Android Resolver File System
OF_SMB | ON/OFF | Include SMB build
OF_SMB_CLIENT | ON/OFF | Include SMB client
OF_SMB_SERVER | ON/OFF | Include SMB server
OFC_FS_SMB | ON/OFF | Include a SMB Client File System
OFC_KERBEROS | ON/OFF | Include Kerberos Package

The values for `OFC_DEFAULT_NETBIOS_MODE` are one of:
- OFC_CONFIG_BMODE: Broadcast Mode
- OFC_CONFIG_PMODE: Wins Mode
- OFC_CONFIG_HMODE: Wins First, then Broadcast
- OFC_CONFIG_MMODE: Broadcast First, then Wins

`OFC_FS_PIPE` brings in a pipe file system used by Lan Manager applications.
The lan manager applications supported by OpenFiles are 

- srvsvc: Server Services
- wkssvc: Workstation Services

### SMB Behavior

The SMB Behavior is defined in:

- ./of_smb/configs/default.cfg

There are many configuration parameters for the SMB stack.  For the most
part, these are tuning parameters and never need to be changed.  If chaning
one of these, discuss with Connected Way support.

Configuration Item | Example | Description
-------------------|---------|------------
SMB_CREDITS_DEFAULT | 32 | Default Credit Request
SMB_CREDITS_REQUEST | 20 | Client Credits to Maintain
SMB_CREDITS_ALLOCATED | 512 | Max Credits that Server Allocates
SMB_LOCAL_PORT | 4445 | Default Local SMB Port
SMB_REMOTE_PORT | 445 | Default Remote SMB Port
SMB_MAX_VOLUME | 32 | Maximum Volume Name Size
SMB_MAX_BUFFER | 524288 | Maximum SMB Buffer Size
SMB_MAX_XACTION_SIZE | 65536 | Maximum SMB Transaction Size
SMB_MAX_REMOTES | 20 | Maximum Remotes (i.e servers) Maintained in API
SMB_WAIT_TIMEOUT | 2000 | Maximum MS to Wait For SMB Negotiate Response
SMB_IDLE_TIMEOUT | 10000 | Time to allow a session to be idle
SMB_SERVER_OVERLAPPED_IOS | 5 | Number of Overlapped IOS that server supports
SMB_MAX_EVENTS | 5 | Max failed login to allow before closing connection
SMB_TIME_PERIOD | 30000 | Time period for max failed logins to occur within
DFS_SUPPORT_GET_DFS_REFERRAL_EX v3 | ON/OFF | Servers support the GET_DFS_REFERREL_EX
DFS_SUPPORT_SYSVOL | ON/OFF | DFS Stack supports SYSVOL requests
DFS_MAX_REFERRAL_VERSION | 4 | Max Referal Version to Support
DFS_BOOTSTRAP_DC_TIMEOUT | 86400 | Refresh Interval for Bootstrap DC
DFS_MAX_TTL | 86400 | Max TTL for a Referral Entry
OFC_TEST_FS_SMB_PATH | | Default Path to store test files for fs smb.
OFC_NTLMV2_TARGET_TIMESTAMP | ON/OFF | Populate target timestamp in NTLM (ON/OFF)

\note
SMB_MAX_REMOTES is for storing persistent remotes.  There is no limit to
the number of remotes that a client can connect to.

\note
OFC_TEST_FS_SMB_PATH can be overridden in runtime configuration

\note
OFC_NTLMV2_TARGET_TIMESTAMP is non standard and allows client/server time 
synchronization during NTLM authentication

### Cipher Configuration

When buiding in SMBv3 support, a Cipher needs to be configured.

Available ciphers:

- ./build/gnutls.cfg: Use GnuTLS
- ./build/openssl.cfg: Use OpenSSL
- ./build/mbedtls.cfg: Use MbedTLS

The values in these files select and delect various ciphers

Configuration Item | Example | Description
-------------------|---------|------------
OF_OPENSSL | ON/OFF | Build with openssl
OF_GNUTLS | ON/OFF | Build with gnutls
OF_MBEDTLS | ON/OFF | Build with mbedtls

\note
Only one of OF_OPENSSL, OF_GNUTLS, OF_MBEDTLS should be enabled.

\defgroup runtime Runtime Configuration Parameters

Runtime configuration of the openfiles stack is managed by an XML file.
On Linux platforms, the default xml file is located at the 
`OPEN_FILES_HOME` environment variable.  If that variable is not defined,
the file will be located at `/etc/openfiles.xml`.

To configure a platform, you can modify the default configuration file
for your build (located within `<source>/configs`), or you can
start with the \ref template.xml and configure as necessary.

Lastly, you can bring up the stack without
any configuration file, and statically configure the stack using the
management APIs, and then call \ref ofc_framework_save with a path to
the file you wish to save.

- of_core: Configuration for core OpenFiles components
  + logging: Logging configuration
    - console: Should logs go to console (yes/no)
    - level: Logging level (0-3)
  + devicename: Name of the device (string)
  + uuid: UUID for the device (UUID in UUID format)
  + description: Description of the device (string)
  + ip: Network Configuration
    - autoip: Deprecated (yes/no)
    - interfaces
      + config: Whether Interfaces are configured from underlying platform (auto/manual)
      + interface: One or more interfaces if config is manual
        - ipaddress: IP Address (ipv4 or ipv6 address string)
        - bcast: Broadcast Address (ipv4 only)
        - mask: Netmask (ipv4 only)
        - mode: NetBios Mode (BMODE, PMODE, MMODE, HMODE)
        - winslist (0 or more)
          + wins: ip address of WINS server (ipv4 or ipv6 address)
        - master: Local Master Browser (ipv4 or ipv6 address)
    - dnslist (0 or more)
      + dns: ip address of DNS server (ipv4 or ipv6 address)
  + drives
    - map (0 or more)
      + drive: Bookmark String (string)
      + description: Description of Bookmark (string)
      + thumbnail: Whether thumbnails should be displayed (yes/no)
      + path: Path to directory
  + smb
    - fqdn: Fully Qualified Domain Name (string)
    - bootstrap_dcs (0 or more)
      + dc: ip of DC (ipv4 or ipv6 address)
    - serveruser: Server Username (string)
    - serverwake: Server should remain awake (yes/no)
    - serverpass: Server Password (string)
    - remotes: A discovered server (0 or more)
      + remote: a remote server
        - name: Name of remote (string)
        - ip: IP address of remote
        - port: Port for server
    - exports: Exported Share (0 or more)
      + export: an export
        - share: The share name (string)
        - comment: Comment for share (string)
        - nativefs: File System String (string)
        - path: Local path for share (string)
        - exporttype: Type of export (DISK, PRINTER, PIPE, COMM, DEVICE)
        - encrypted: Is share encrypted (yes, no)
    - max_events: Max events before critical event (number)
    - time_period: Time period for events (number of ms)
    - max_version: Max SMB Version supported (202, 302, 311)
    - ciphers: 1 or more
      + cipher: (aes128-ccm, aes128-gcm)
    - servers: SMB Server - 0 or more
      + port: Port that server listens on
      + encrypt: Encrypt all traffic (yes/no)

*/




