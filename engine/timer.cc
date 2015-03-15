#include "timer.hh"

#include <functional>

namespace jesh {

Timer::Timer(double theTimeoutLength) :
    isRunning(true),
    timeToRun(theTimeoutLength),
    func([]{}) {
}

void Timer::start() {
    timeRunning = 0;
    isRunning = true;
}

void Timer::onDone(std::function<void()> theCallback) {
    func = theCallback;
}

void Timer::advance(double theSecondsPassed) {
    if (!isRunning) return;

    timeRunning += theSecondsPassed;
    if (timeRunning > timeToRun) {
        func();
        isRunning = false;
    }
}

}

