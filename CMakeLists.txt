project(globalmodel)
cmake_minimum_required(VERSION 2.8.0)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake-modules")

find_package(NetCDF REQUIRED)

include_directories(${NETCDF_INCLUDES})

add_executable(globalmodel globalmodel.c)
target_link_libraries(globalmodel ${NETCDF_LIBRARIES})
