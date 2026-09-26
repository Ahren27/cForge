cmake_minimum_required(VERSION 3.20)

project(cforge
    VERSION 0.1.0
    DESCRIPTION "C Standard Library Reimplementation"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

enable_testing()