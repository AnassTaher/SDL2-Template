cmake_minimum_required(VERSION 3.0)
project(SDL2_Template)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)
set(SDL2_PATH ${CMAKE_SOURCE_DIR}/SDL2)


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
file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/*.cpp" # Remove this line if you don't have any .cpp files in the root dir
)

# Copy over the SDL2.dll to the build directory
file(GLOB DLL_FILES "${CMAKE_SOURCE_DIR}/SDL2/bin/*.dll")
file(COPY ${DLL_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${all_SRCS})


target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARY})

