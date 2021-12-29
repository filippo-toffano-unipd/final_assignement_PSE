cmake_minimum_required( VERSION 3.10.2)

project( main_application
         VERSION 0.9
         DESCRIPTION "Construction Main" )

add_executable(application src/main.cpp)

target_link_libraries(application
    PUBLIC PSE::piece
    PUBLIC PSE::box
    PUBLIC PSE::store
    PUBLIC PSE::vision_system
)
