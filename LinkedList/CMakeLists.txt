project(LinkedList)
cmake_minimum_required(VERSION 2.8)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall /wd\"4514; 4710; 4986; 4061; 4250;\" /EHsc /bigobj /WX /vd1")
    add_definitions(-DRECOGNITIONENGINE_EXPORTS)
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXPORT_HEADERS_DIRECTORY ${CMAKE_BINARY_DIR}/include)

set(PROBLEM_1_SRC_LIST "Problem1.cpp")

add_executable(${PROJECT_NAME}Problem1 ${PROBLEM_1_SRC_LIST})