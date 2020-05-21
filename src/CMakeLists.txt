cmake_minimum_required(VERSION 3.12)
project(met_aromatic)

# user defined macro definitions
set(CXX_CHAIN "A")
set(CXX_CUTOFF_DISTANCE 6.0)
set(CXX_CUTOFF_ANGLE 109.5)

set(CMAKE_CXX_STANDARD 17)
set(CURL_LIBRARY "-lcurl") 

find_package(CURL REQUIRED) 
include_directories(${CURL_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include/)

message(STATUS "Source directory: " ${PROJECT_SOURCE_DIR})
message(STATUS "Chain: " ${CXX_CHAIN})
message(STATUS "Cutoff angle: " ${CXX_CUTOFF_ANGLE})
message(STATUS "Cutoff distance: " ${CXX_CUTOFF_DISTANCE})

add_compile_definitions(CXX_CHAIN=${CXX_CHAIN})
add_compile_definitions(CXX_CUTOFF_DISTANCE=${CXX_CUTOFF_DISTANCE})
add_compile_definitions(CXX_CUTOFF_ANGLE=${CXX_CUTOFF_ANGLE})

add_executable(met_aromatic met_aromatic.cpp)

target_link_libraries(met_aromatic ${CURL_LIBRARIES})
