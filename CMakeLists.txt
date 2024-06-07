cmake_minimum_required(VERSION 3.0...3.17)
project(SDL2_Template)
set(CMAKE_CXX_STANDARD 17)


if (WIN32)
    set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)
    set(SDL2_PATH ${CMAKE_SOURCE_DIR}/SDL2)
endif ()


# Find SDL2
find_package(SDL2 REQUIRED)

# Uncomment this line if you want to change the output directory of the executable
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# Include directories for compiling
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
        ${SDL2_INCLUDE_DIR}
)

# Include all files in the src and include directories for running the project
file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# Copy over the SDL2.dll to the build directory
if (WIN32)
    file(GLOB DLL_FILES "${CMAKE_SOURCE_DIR}/SDL2/bin/*.dll")
    file(COPY ${DLL_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif ()

add_executable(${CMAKE_PROJECT_NAME} ${sources})


target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARY})

