cmake_minimum_required( VERSION 3.10.2 )

project( global_variables
        VERSION 0.9
        DESCRIPTION "global variables lib"
        )

add_library(global_variables STATIC src/global_variables.cpp)


target_include_directories( global_variables
        PUBLIC include
)
        
target_link_libraries( global_variables
        PUBLIC PSE::piece
        PUBLIC PSE::piece_buffer
        PUBLIC PSE::box
        PUBLIC PSE::vision_system
)

add_library(PSE::global_variables ALIAS global_variables)