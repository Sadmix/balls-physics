set(BINARY ${PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib ${SOURCES})

target_link_libraries(${BINARY}_run ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows -mconsole)
target_link_libraries(${BINARY}_lib ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows)