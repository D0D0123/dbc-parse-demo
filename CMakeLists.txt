cmake_minimum_required(VERSION 3.8)
project(dbc_parse_demo)


add_executable(dbc_parse_demo dbc_parse_demo.cpp)

find_library(LIB_DBCPPP libdbcppp.so PATHS /usr/local/lib)
target_link_libraries(dbc_parse_demo ${LIB_DBCPPP})