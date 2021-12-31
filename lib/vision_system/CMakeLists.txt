cmake_minimum_required( VERSION 3.10.2 )

project( Vision_System
        VERSION 0.9
        DESCRIPTION "vision system lib class"
        )

add_library(vision_system STATIC src/vision_system.cpp)


target_include_directories( vision_system
        PUBLIC include
)
        
target_link_libraries( vision_system
        PUBLIC PSE::piece
        PUBLIC PSE::piece_buffer
        PUBLIC PSE::global_variables
)

add_library(PSE::vision_system ALIAS vision_system)