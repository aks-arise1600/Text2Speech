cmake_minimum_required(VERSION 3.12)
message(STATUS "CMake version: ${CMAKE_VERSION}")

project(Text2Speech
  VERSION
    1.0
  DESCRIPTION
    "Text to speech "
  LANGUAGES
    CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets TextToSpeech)
if(Qt5_FOUND)
    message(STATUS "${PROJECT_NAME} Found Qt5 version: ${Qt5_VERSION}")
else()
    message(FATAL_ERROR "Qt5 not Found !!")
endif()


set(SRC_FILES
                main.cpp
                Text2Speech.cpp
                )
                
set(HEADER_FILES
                Text2Speech.h
                )
                
set(UI_FILES
                Text2Speech.ui
                )
                
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES} ${UI_FILES})

add_definitions(-DQT_NO_VERSION_TAGGING)

target_link_libraries(${PROJECT_NAME}
  Qt5::Widgets
  Qt5::Core
  Qt5::TextToSpeech
)

include_directories(.)
