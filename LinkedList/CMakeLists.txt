project(LinkedList)
cmake_minimum_required(VERSION 2.8)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall /EHsc /WX")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Wall /EHsc /WX")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXPORT_HEADERS_DIRECTORY ${CMAKE_BINARY_DIR}/include)

set(PROBLEM_1_SRC_LIST "Problem1.c")
set(PROBLEM_2_SRC_LIST "Problem2.c")

add_executable(${PROJECT_NAME}Problem1 ${PROBLEM_1_SRC_LIST})
add_executable(${PROJECT_NAME}Problem2 ${PROBLEM_2_SRC_LIST})
