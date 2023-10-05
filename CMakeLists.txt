cmake_minimum_required(VERSION 3.25.0)
project(Particles)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

set(src
    src/main.cpp
    src/Tower.cpp
    src/Enemy.cpp
)

add_executable(${PROJECT_NAME} ${src})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system) 