# Install script for directory: /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Source/Lib/Common

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/Source/Lib/Common/Codec/cmake_install.cmake")
  include("/var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/Source/Lib/Common/C_DEFAULT/cmake_install.cmake")
  include("/var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/Source/Lib/Common/ASM_SSE2/cmake_install.cmake")
  include("/var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/Source/Lib/Common/ASM_SSSE3/cmake_install.cmake")
  include("/var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/Source/Lib/Common/ASM_SSE4_1/cmake_install.cmake")
  include("/var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/Source/Lib/Common/ASM_AVX2/cmake_install.cmake")
  include("/var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/Source/Lib/Common/ASM_AVX512/cmake_install.cmake")

endif()
