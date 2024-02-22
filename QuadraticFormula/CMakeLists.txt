cmake_minimum_required(VERSION 3.1)
project(QuadraticFormula)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(quadratic_formula
    quadratic_formula.cpp
)

set_target_properties(quadratic_formula PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY “${CMAKE_BINARY_DIR}/bin”
)
