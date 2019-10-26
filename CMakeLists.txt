cmake_minimum_required(VERSION 3.5)

project(Examples_08)

SET(CMAKE_CXX_COMPILER /usr/local/Cellar/gcc/HEAD-f2787da/bin/c++-HEAD)



add_executable(custom_unique custom_unique.cpp)
set_target_properties(custom_unique PROPERTIES
       CXX_STANDARD 14
       CXX_STANDARD_REQUIRED ON
       )

add_executable(custom_unique_2 custom_unique_2.cpp)
set_target_properties(custom_unique_2 PROPERTIES
              CXX_STANDARD 14
              CXX_STANDARD_REQUIRED ON
       )

add_executable(unique_ptr unique_ptr.cpp)
set_target_properties(unique_ptr PROPERTIES
       CXX_STANDARD 14
       CXX_STANDARD_REQUIRED ON
       )

add_executable(unique_copy unique_copy.cpp)
set_target_properties(unique_copy PROPERTIES
       CXX_STANDARD 14
       CXX_STANDARD_REQUIRED ON
       )

add_executable(custom_shared custom_shared.cpp)
set_target_properties(custom_shared PROPERTIES
       CXX_STANDARD 14
       CXX_STANDARD_REQUIRED ON
       )

add_executable(shared_ptr shared_ptr.cpp)
set_target_properties(shared_ptr PROPERTIES
       CXX_STANDARD 14
       CXX_STANDARD_REQUIRED ON
       )

add_executable(enable_shared_from_this enable_shared_from_this.cpp)
set_target_properties(enable_shared_from_this PROPERTIES
       CXX_STANDARD 14
       CXX_STANDARD_REQUIRED ON
       )

add_executable(dead_lock dead_lock.cpp)
set_target_properties(dead_lock PROPERTIES
       CXX_STANDARD 14
       CXX_STANDARD_REQUIRED ON
       )

add_executable(weak_ptr_deadlock weak_ptr_deadlock.cpp)
set_target_properties(weak_ptr_deadlock PROPERTIES
       CXX_STANDARD 14
       CXX_STANDARD_REQUIRED ON
       )

add_executable(weak_ptr weak_ptr.cpp)
set_target_properties(weak_ptr PROPERTIES
       CXX_STANDARD 14
       CXX_STANDARD_REQUIRED ON
       )

add_executable(shared_exception shared_exception.cpp)
set_target_properties(shared_exception PROPERTIES
       CXX_STANDARD 14
       CXX_STANDARD_REQUIRED ON
       )

add_executable(dynamic_pointer_cast dynamic_pointer_cast.cpp)
set_target_properties(dynamic_pointer_cast PROPERTIES
       CXX_STANDARD 14
       CXX_STANDARD_REQUIRED ON
       )