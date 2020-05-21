cmake_minimum_required(VERSION 3.12)
project(met_aromatic)

# user defined macro definitions
set(CXX_CHAIN "A")
set(CXX_CUTOFF_DISTANCE 6.0)
set(CXX_CUTOFF_ANGLE 109.5)
set(DEBUG_PHE 0)
set(DEBUG_TYR 0)
set(DEBUG_TRP 0)
set(DEBUG_MET 1)

set(CMAKE_CXX_STANDARD 17)
set(CURL_LIBRARY "-lcurl") 

find_package(CURL REQUIRED) 
include_directories(${CURL_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include/)

message(STATUS "Source directory: " ${PROJECT_SOURCE_DIR})
message(STATUS "Chain: " ${CXX_CHAIN})
message(STATUS "Cutoff angle: " ${CXX_CUTOFF_ANGLE})
message(STATUS "Cutoff distance: " ${CXX_CUTOFF_DISTANCE})
message(STATUS "Debug phenylalanine: " ${DEBUG_PHE})
message(STATUS "Debug tyroosine: " ${DEBUG_TYR})
message(STATUS "Debug tryptophan: " ${DEBUG_TRP})
message(STATUS "Debug methionine: " ${DEBUG_MET})

add_compile_definitions(CXX_CUTOFF_DISTANCE=${CXX_CUTOFF_DISTANCE})
add_compile_definitions(CXX_CUTOFF_ANGLE=${CXX_CUTOFF_ANGLE})
add_compile_definitions(DEBUG_PHE=${DEBUG_PHE})
add_compile_definitions(DEBUG_TYR=${DEBUG_TYR})
add_compile_definitions(DEBUG_TRP=${DEBUG_TRP})
add_compile_definitions(DEBUG_MET=${DEBUG_MET})

add_executable(met_aromatic met_aromatic.cpp)

target_link_libraries(met_aromatic ${CURL_LIBRARIES})
