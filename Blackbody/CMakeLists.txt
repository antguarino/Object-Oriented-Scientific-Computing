cmake_minimum_required(VERSION 3.1)
project(Blackbody)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(blackbody_radiance
    blackbody_radiance.cpp
)

set_target_properties(blackbody_radiance PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
