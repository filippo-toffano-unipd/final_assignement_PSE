cmake_minimum_required( VERSION 3.10.2 )

project( piece_buffer
        VERSION 0.9
        DESCRIPTION "piece buffer lib class"
        )

add_library(piece_buffer STATIC src/piece_buffer.cpp)


target_include_directories( piece_buffer
        PUBLIC include
)
        
target_link_libraries( piece_buffer
        PUBLIC PSE::piece
        PUBLIC PSE::global_variables
)

add_library(PSE::piece_buffer ALIAS piece_buffer)