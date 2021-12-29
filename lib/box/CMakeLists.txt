cmake_minimum_required( VERSION 3.10.2 )

project( Box
        VERSION 0.9
        DESCRIPTION "box lib class"
        )

add_library(box STATIC src/box.cpp)

target_link_libraries( box
        PUBLIC PSE::piece
)

target_include_directories(box
        PUBLIC include
)


add_library(PSE::box ALIAS box)
