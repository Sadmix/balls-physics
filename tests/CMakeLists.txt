find_package(Gtest REQUIRED)


set(BINARY Test)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows ${PROJECT_NAME}_lib gtest)