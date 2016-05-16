#ifndef CLOCK_H_
#define CLOCK_H_

class Clock {
public:
    Clock();
    long long get_tick();
    void tick_up();
private:
    long long ticks;
};

#endif // CLOCK_H_
