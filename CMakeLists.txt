cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled main.cpp postac.cpp postac.h plansza.cpp plansza.h GameManager.cpp GameManager.h Intro.cpp Intro.h Score.cpp Score.h bitwa.cpp bitwa.h obiekt.cpp obiekt.h bot.cpp bot.h)
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(untitled ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()