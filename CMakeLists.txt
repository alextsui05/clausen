cmake_minimum_required( VERSION 2.8 )

add_library( clausen SHARED
    Clausen.cpp
)
add_executable( eval_clausen main.cpp )
target_link_libraries( eval_clausen clausen )

install( TARGETS
    clausen
    eval_clausen
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static
)

install( FILES
    Clausen.h
    DESTINATION include
)

