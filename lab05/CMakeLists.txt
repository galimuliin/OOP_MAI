cmake_minimum_required( VERSION 3.10 )

project( oop_exercise_05 LANGUAGES CXX )

add_executable( ${CMAKE_PROJECT_NAME} "src/main.cpp" "src/figure.hpp" "src/vector.hpp" )

set_target_properties(  ${CMAKE_PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
