cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME "acetest")
message("PROJECT_NAME: ${PROJECT_NAME}")
project(${PROJECT_NAME} VERSION 1.0.0)
aux_source_directory(. DIR_SRCS)
add_library(${PROJECT_NAME} SHARED ${DIR_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

#project(acetest VERSION 1.0.0)
#add_library(acetest acetest.cpp)
#
#target_include_directories(acetest
#          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
#          )
#
#install(TARGETS acetest DESTINATION lib)
#install(FILES include/acetest.h DESTINATION include)

# ============================== install script ==============================
set(HEADERS ${CMAKE_SOURCE_DIR}/include/acetest.h)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADERS}")

# Install the target and create export-set
install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include)

# Generate the version file for the config file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY SameMajorVersion)

# Exporting Targets from the Build Tree
install(EXPORT ${PROJECT_NAME}Targets
        DESTINATION "lib/cmake/${PROJECT_NAME}")

# Create config file
configure_package_config_file(
        ${CMAKE_SOURCE_DIR}/Config.cmake.in ${PROJECT_NAME}Config.cmake
        INSTALL_DESTINATION "lib/cmake/${PROJECT_NAME}")

# Install config files
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION "lib/cmake/${PROJECT_NAME}")
