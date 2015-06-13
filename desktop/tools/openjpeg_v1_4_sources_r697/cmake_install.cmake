# Install script for directory: C:/Users/Benni/Programmierung/Emmeth/desktop/tools/openjpeg_v1_4_sources_r697

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/OPENJPEG")
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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/openjpeg-1.4/OpenJPEGTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/openjpeg-1.4/OpenJPEGTargets.cmake"
         "C:/Users/Benni/Programmierung/Emmeth/desktop/tools/openjpeg_v1_4_sources_r697/CMakeFiles/Export/lib/openjpeg-1.4/OpenJPEGTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/openjpeg-1.4/OpenJPEGTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/openjpeg-1.4/OpenJPEGTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/openjpeg-1.4" TYPE FILE FILES "C:/Users/Benni/Programmierung/Emmeth/desktop/tools/openjpeg_v1_4_sources_r697/CMakeFiles/Export/lib/openjpeg-1.4/OpenJPEGTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/openjpeg-1.4" TYPE FILE FILES "C:/Users/Benni/Programmierung/Emmeth/desktop/tools/openjpeg_v1_4_sources_r697/CMakeFiles/Export/lib/openjpeg-1.4/OpenJPEGTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/openjpeg-1.4" TYPE FILE FILES "C:/Users/Benni/Programmierung/Emmeth/desktop/tools/openjpeg_v1_4_sources_r697/CMakeFiles/Export/lib/openjpeg-1.4/OpenJPEGTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/openjpeg-1.4" TYPE FILE FILES "C:/Users/Benni/Programmierung/Emmeth/desktop/tools/openjpeg_v1_4_sources_r697/CMakeFiles/Export/lib/openjpeg-1.4/OpenJPEGTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/openjpeg-1.4" TYPE FILE FILES "C:/Users/Benni/Programmierung/Emmeth/desktop/tools/openjpeg_v1_4_sources_r697/CMakeFiles/Export/lib/openjpeg-1.4/OpenJPEGTargets-release.cmake")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/openjpeg-1.4" TYPE FILE FILES "C:/Users/Benni/Programmierung/Emmeth/desktop/tools/openjpeg_v1_4_sources_r697/OpenJPEGConfig.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/openjpeg-1.4" TYPE FILE FILES
    "C:/Users/Benni/Programmierung/Emmeth/desktop/tools/openjpeg_v1_4_sources_r697/CHANGES"
    "C:/Users/Benni/Programmierung/Emmeth/desktop/tools/openjpeg_v1_4_sources_r697/LICENSE"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Benni/Programmierung/Emmeth/desktop/tools/openjpeg_v1_4_sources_r697/libopenjpeg/cmake_install.cmake")
  include("C:/Users/Benni/Programmierung/Emmeth/desktop/tools/openjpeg_v1_4_sources_r697/codec/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/Benni/Programmierung/Emmeth/desktop/tools/openjpeg_v1_4_sources_r697/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
