cmake_minimum_required(VERSION 3.1)
project(Blackbody)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(matplotplusplus)

add_executable(test_blackbody
    Blackbody.cpp
    test_blackbody.cpp
    Blackbody.h
    radiometry.h
)

target_link_libraries(test_blackbody PUBLIC matplot)

set_target_properties(test_blackbody PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
