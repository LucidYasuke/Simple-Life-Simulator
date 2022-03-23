cmake_minimum_required(VERSION 3.2)
project(SLS)

set(CMAKE_CXX_STANDARD 11)
set(SFML_INCLUDE_DIR "/usr/local/Cellar/sfml/2.5.1_1/include")
set(SFML_LIBRARY_DIR "/usr/local/Cellar/sfml/2.5.1_1/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(SLS main.cpp Engine.cpp Food.cpp Entity.cpp Shelter.cpp)
target_link_libraries (SLS sfml-graphics sfml-window sfml-system)