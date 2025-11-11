cmake_minimum_required(VERSION 3.10)
project(StudentuRusiavimas)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    main.cpp
    ivedimas.cpp
    isvedimas.cpp
    skaiciavimai.cpp
    failai.cpp
)

add_executable(StudentuRusiavimas ${SOURCES})
