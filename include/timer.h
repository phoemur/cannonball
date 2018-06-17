#ifndef TIMER_H
#define TIMER_H

#include <string>
#include <cstdint>

namespace Timer {

void capFrameRate(unsigned fps);
inline double getFPS_asDouble();
inline std::uint32_t getFPS_asInt();
inline std::string getFPS_asStr();
std::uint32_t elapsedTicks();
std::uint32_t frameCount();

}

#endif // TIMER_H
