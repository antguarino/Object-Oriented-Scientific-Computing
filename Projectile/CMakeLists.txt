cmake_minimum_required(VERSION 3.1)
project(Projectile)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(Projectile
    Projectile.cpp
    test_projectile.cpp
    Projectile.h
    physics.h
)

set_target_properties(Projectile PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
