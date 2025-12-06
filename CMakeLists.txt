cmake_minimum_required(VERSION 3.10)
project(StudentuSistema)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -O2)
endif()
add_definitions(-DOPT_LEVEL=2)

set(COMMON_SOURCES
    Studentas.cpp
    Zmogus.cpp
    skaiciavimai.cpp
)

add_executable(programa
    main.cpp
    ivedimas.cpp
    failai.cpp
    isvedimas.cpp
    ${COMMON_SOURCES}
)

add_executable(test_studentas
    test_studentas.cpp
    ${COMMON_SOURCES}
)

enable_testing()
add_test(NAME StudentasUnitTestai COMMAND test_studentas)