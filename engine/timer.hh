#ifndef JESH_TIMER_H_
#define JESH_TIMER_H_

#include <functional>

namespace jesh {

class Timer {
    public:
        Timer(double);
        void reset();
        void onDone(std::function<void()>);
        void advance(double);

    private:
        double timeRunning;
        double timeToRun;
        std::function<void()> func;
};

}

#endif // JESH_TIMER_H_



