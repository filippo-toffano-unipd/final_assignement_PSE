cmake_minimum_required( VERSION 3.10.2 )

project( piece
        VERSION 0.9
        DESCRIPTION "piece lib class"
        )

add_library(piece STATIC src/piece.cpp)


target_include_directories(piece
        PUBLIC include
)

target_link_libraries( piece
        PUBLIC PSE::global_variables
)

add_library(PSE::piece ALIAS piece)
