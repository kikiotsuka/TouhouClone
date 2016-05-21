#include "clock.h"

Clock::Clock() {
    ticks = 0LL;
}

long long Clock::get_tick() {
    return ticks;
}

void Clock::tick_up() {
    ticks++;
}
