cmake_minimum_required(VERSION 3.9)
project(primer)

set(CMAKE_CXX_STANDARD 11)

add_executable(primer main.cpp mail.h mail.cpp blob.h blob.cpp strVec.h strVec.cpp textquery/textquery.h textquery/textquery.cpp textquery/query.h textquery/query_base.h textquery/wordquery.h textquery/notquery.h textquery/notquery.cpp textquery/binaryquery.h textquery/andquery.h textquery/orquery.h textquery/andqueyr.cpp textquery/orquery.cpp algorithm/seq_list/seqlist.h algorithm/seq_list/seqlist.cpp algorithm/tree/tree.h algorithm/tree/tree.cpp algorithm/tree/avl/avltree.h algorithm/tree/avl/avltree.cpp algorithm/tree/binqueue/binqueue.h algorithm/heap/leftheap/leftheap.h algorithm/heap/leftheap/leftheap.cpp algorithm/tree/redblack/redblacktree.h algorithm/tree/redblack/redblacktree.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexec-charset=gbk -finput-charset=utf-8")
