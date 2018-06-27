cmake_minimum_required(VERSION 3.9)

project(cannonball DESCRIPTION "Cannonball shooter game" LANGUAGES C CXX VERSION 0.1.0)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
include_directories(include/ ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS})

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

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES} ${SDL2MIXER_LIBRARIES})
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
