cmake_minimum_required(VERSION 3.16)
project(Visualization-of-sorting-algorithms LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Visualization WIN32 src/Launch.cpp)

add_subdirectory(lib)

set(LIBS 

    button
    infoWindow
    inputField 
    menu
    showAlgorithm
    sortingAlgo
    tickBox)

target_link_libraries(button PRIVATE sfml-graphics)
target_link_libraries(infoWindow PRIVATE sfml-graphics)
target_link_libraries(inputField PRIVATE sfml-graphics)
target_link_libraries(menu PRIVATE sfml-graphics)
target_link_libraries(showAlgorithm PRIVATE sfml-graphics)
target_link_libraries(sortingAlgo PRIVATE sfml-graphics)
target_link_libraries(tickBox PRIVATE sfml-graphics)

target_link_libraries(Visualization PRIVATE ${LIBS})
target_link_libraries(Visualization PRIVATE sfml-graphics)
target_include_directories(Visualization PRIVATE ./include)

target_compile_definitions(Visualization PRIVATE RESOURCES="${CMAKE_CURRENT_SOURCE_DIR}/res/")
target_compile_definitions(tickBox PRIVATE RESOURCES="${CMAKE_CURRENT_SOURCE_DIR}/res/")
target_compile_definitions(infoWindow PRIVATE RESOURCES="${CMAKE_CURRENT_SOURCE_DIR}/res/")
target_compile_definitions(menu PRIVATE RESOURCES="${CMAKE_CURRENT_SOURCE_DIR}/res/")