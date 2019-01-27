cmake_minimum_required(VERSION 3.9)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(cannonball DESCRIPTION "Cannonball shooter game" LANGUAGES C CXX VERSION 0.1.0)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include"
                     ${SDL2_INCLUDE_DIR}
                     ${SDL2_IMAGE_INCLUDE_DIR}
                     ${SDL2_TTF_INCLUDE_DIR}
                     ${SDL2_MIXER_INCLUDE_DIRS}
)

set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/exception.cpp
    src/texture.cpp
    src/font.cpp
    src/timer.cpp
    src/gamestate.cpp
    src/intro.cpp
    src/music.cpp
    src/cannon.cpp
    src/house.cpp
    src/bullet.cpp
    src/particle.cpp
    src/baselevel.cpp
    src/level1.cpp
    src/level2.cpp
    src/level3.cpp
    src/level4.cpp
    src/level5.cpp
    src/endgame.cpp
    src/background.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
        -pipe -march=native
        $<$<CONFIG:Debug>:-O0 -Wall -Wextra -Weffc++>>
    $<$<CXX_COMPILER_ID:MSVC>:
        $<$<CONFIG:Debug>:/Od /Wall /Zi>>
)

target_link_libraries(${PROJECT_NAME}
                      ${SDL2_LIBRARY}
                      ${SDL2_IMAGE_LIBRARIES}
                      ${SDL2_TTF_LIBRARIES}
                      ${SDL2_MIXER_LIBRARIES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/cannonball_assets/
    DESTINATION ${CMAKE_INSTALL_BINDIR}/cannonball_assets/
)
