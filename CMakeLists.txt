cmake_minimum_required(VERSION 3.15)
project(pgenv LANGUAGES CXX VERSION 1.4.0 DESCRIPTION "PostgreSQL Binary Manager")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)

find_package(Boost COMPONENTS program_options system)

list(APPEND source_files
    src/main.cpp
    src/arguments_parser.cpp
    src/executor.cpp
)

add_executable(pgenv ${source_files})
target_link_libraries(pgenv PRIVATE Boost::program_options)
target_include_directories(pgenv PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS pgenv)
