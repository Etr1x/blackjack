cmake_minimum_required(VERSION 2.9.0)

project(blackjack)

set(SOURCE_FILES "main.c")
add_executable(blackjack ${SOURCE_FILES})
add_subdirectory(lib)
target_link_libraries(blackjack lib)