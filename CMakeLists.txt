cmake_minimum_required(VERSION 3.12.0)

project(TEST)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-g")

aux_source_directory(${PROJECT_SOURCE_DIR} DIR_SRCS)

include_directories(
    #/usr/local/boost/include/
)
#link_directories(/usr/local/boost/lib/)

add_executable(test ${DIR_SRCS})

#target_link_libraries(test pthread boost_thread boost_system)
target_link_libraries(test pthread)