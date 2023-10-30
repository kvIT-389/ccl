cmake_minimum_required(VERSION 3.9)

project(ccl LANGUAGES C)

set(SOURCE_LIST_LIB lib/src/list/list.c lib/src/list/listnode.c)
set(SOURCE_VECTOR_LIB lib/src/vector/vector.c)

include_directories(lib/include)

add_library(ccl STATIC ${SOURCE_LIST_LIB} ${SOURCE_VECTOR_LIB})

add_executable(listtest test/list/main.c)
add_executable(vectortest test/vector/main.c)

target_link_libraries(listtest ccl)
target_link_libraries(vectortest ccl)
