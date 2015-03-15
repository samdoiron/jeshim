#include "timer.hh"

#include <functional>

namespace jesh {

Timer::Timer(double theTimeoutLength) :
    func([]{}) {
}

void Timer::reset() {
    timeRunning = 0;
}

void Timer::onDone(std::function<void()> theCallback) {
    func = theCallback;
}

void Timer::advance(double theSecondsPassed) {
    timeRunning += theSecondsPassed;
    if (timeRunning > timeToRun) {
        func();
    }
}

}

