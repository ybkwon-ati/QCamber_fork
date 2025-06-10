cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_definitions(-DUNICODE -D_UNICODE)

# Collect common source files
file(GLOB_RECURSE COMMON_SOURCES
    archiveloader.cpp
    context.cpp
    settings.cpp
    symbolpool.cpp
    parser/*.cpp
    parser/odbpp/*.cpp
    symbol/*.cpp
    graphicsview/*.cpp
    gui/*.cpp
)
set(COMMON_SOURCES ${COMMON_SOURCES} resources.qrc)

# qcamber executable
set(QCAMBER_SOURCES ${COMMON_SOURCES} main.cpp)
add_executable(qcamber ${QCAMBER_SOURCES})
target_link_libraries(qcamber PRIVATE Qt5::Widgets)

# test executable
file(GLOB TEST_SOURCES tests/*.cpp)
set(TEST_APP_SOURCES ${COMMON_SOURCES} ${TEST_SOURCES})
add_executable(test ${TEST_APP_SOURCES})
target_link_libraries(test PRIVATE Qt5::Widgets)

if(WIN32)
    target_link_libraries(qcamber PRIVATE ws2_32)
    target_link_libraries(test PRIVATE ws2_32)
endif()
