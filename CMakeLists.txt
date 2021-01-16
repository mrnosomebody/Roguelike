cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME roguelike)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 17)
set(SOURCES main.cpp GameTile.cpp GameTile.h GameWorld.cpp GameWorld.h Character.cpp Character.h otrisovka.cpp otrisovka.h Types.h)
add_executable(${PROJECT_NAME} ${SOURCES} )
include_directories(C:\\Users\\mrnos\\CLionProjects\\roguelike\\imgs)
set(SFML_ROOT C:/Libraries/SFML)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(C:\\Libraries\\SFML\\include\\)
    target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio ${SFML_DEPENDENCIES})
endif ()