cmake_minimum_required(VERSION 3.9)
project(primer)

set(CMAKE_CXX_STANDARD 11)

add_executable(primer main.cpp mail.h mail.cpp blob.h blob.cpp strVec.h strVec.cpp textquery.h textquery.cpp query.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexec-charset=gbk -finput-charset=utf-8")
