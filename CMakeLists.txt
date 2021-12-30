cmake_minimum_required( VERSION 3.10.2 )

project( final_assignment
        VERSION 0.9
        DESCRIPTION "final_assignment"
        )


if (MSVC)
        # warning level 4 and all warnings as errors
        add_compile_options(/W4 /WX)
else()
        # lots of warnings and all warnings as errors
        #add_compile_options(-Wall -g -Wextra -pedantic)
        add_compile_options(-Wall -Wextra -pedantic)
endif()

add_subdirectory(app)
add_subdirectory(lib/piece)
add_subdirectory(lib/box)
add_subdirectory(lib/store)
add_subdirectory(lib/vision_system)
add_subdirectory(lib/piece_buffer)
