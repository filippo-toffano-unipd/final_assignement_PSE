cmake_minimum_required( VERSION 3.10.2 )

project( cobot
        VERSION 0.9
        DESCRIPTION "cobot system lib class"
        )

add_library(cobot STATIC src/cobot.cpp)


target_include_directories( cobot
        PUBLIC include
)
        
target_link_libraries( cobot
        PUBLIC PSE::piece
        PUBLIC PSE::piece_buffer
        PUBLIC PSE::vision_system
        PUBLIC PSE::box
        PUBLIC PSE::global_variables
)

add_library(PSE::cobot ALIAS cobot)