cmake_minimum_required( VERSION 3.10.2)

project( main_application
         VERSION 0.9
         DESCRIPTION "Construction Main" )

add_executable(application src/main.cpp)

target_link_libraries(application
    PRIVATE PSE::piece
    PRIVATE PSE::box
    PRIVATE PSE::store
    PRIVATE PSE::vision_system
    PRIVATE PSE::piece_buffer
    PRIVATE PSE::cobot
    PRIVATE PSE::global_variables
    PRIVATE pthread
)
