cmake_minimum_required(VERSION 3.5)

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

# qcamber executable
set(QCAMBER_SOURCES ${COMMON_SOURCES} main.cpp)
add_executable(qcamber ${QCAMBER_SOURCES})

# test executable
file(GLOB TEST_SOURCES tests/*.cpp)
set(TEST_APP_SOURCES ${COMMON_SOURCES} ${TEST_SOURCES})
add_executable(test ${TEST_APP_SOURCES})

if(WIN32)
    target_link_libraries(qcamber PRIVATE ws2_32)
    target_link_libraries(test PRIVATE ws2_32)
endif()
