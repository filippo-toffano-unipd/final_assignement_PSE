cmake_minimum_required( VERSION 3.10.2 )

project( Box
        VERSION 0.9
        DESCRIPTION "store lib class"
        )

add_library(store STATIC src/store.cpp)


target_include_directories(store
        PUBLIC include
)
        
target_link_libraries( store
        PUBLIC PSE::piece
        PUBLIC PSE::box
        PUBLIC PSE::global_variables
)

add_library(PSE::store ALIAS store)