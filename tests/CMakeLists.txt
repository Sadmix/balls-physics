find_package(Gtest REQUIRED)


set(BINARY ${PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows ${PROJECT_NAME}_lib gtest)