cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS_INIT} -Wall -fPIC")
add_subdirectory(stl_parser)

find_package(Eigen3 REQUIRED)
ADD_DEFINITIONS(-DEIGEN_NO_DEBUG)
include_directories(${EIGEN3_INCLUDE_DIR})

add_library(raytest STATIC raytest.cpp)
target_link_libraries(raytest stl_parser)

add_executable(main main.cpp)
target_link_libraries(main raytest)

set(LIBRARY_NAME raytestpy)
add_subdirectory(pybind11)
pybind11_add_module(raytestpy wrapper.cpp)
target_link_libraries(raytestpy PRIVATE raytest)

set(CMD_SITE_PKG "import site; import sys;sys.stdout.write(site.getusersitepackages())")

execute_process(
    COMMAND ${PYTHON_EXECUTABLE} -c "${CMD_SITE_PKG}"
    OUTPUT_VARIABLE PYTHON_SITE_PACKAGES_INSTALL_DIR
    )
install(TARGETS raytestpy DESTINATION ${PYTHON_SITE_PACKAGES_INSTALL_DIR})
message("destination site-packages:" ${PYTHON_SITE_PACKAGES_INSTALL_DIR})
