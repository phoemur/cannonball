#include "timer.h"

#include <SDL.h>
#include <string>

namespace Timer {

static uint32_t _prev_ticks = 0;
static uint32_t _frames = 0;

void capFrameRate(unsigned fps)
{
    auto ticks_per_frame = 1000.0 / fps;

    ++_frames;
    auto frame_ticks = elapsedTicks();

    if (frame_ticks < ticks_per_frame) {
        SDL_Delay(ticks_per_frame - frame_ticks);
    }

    _prev_ticks = SDL_GetTicks();
}

double getFPS_asDouble()
{
    return _frames / ( SDL_GetTicks() / 1000.0 );
}

std::string getFPS_asStr()
{
    return std::to_string(getFPS_asInt());
}

std::uint32_t elapsedTicks()
{
    return SDL_GetTicks() - _prev_ticks;
}

std::uint32_t frameCount()
{
    return _frames;
}

std::uint32_t getFPS_asInt()
{
    return static_cast<std::uint32_t>(getFPS_asDouble());
}


}
