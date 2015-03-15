#ifndef JESH_TIMER_H_
#define JESH_TIMER_H_

#include <functional>

namespace jesh {

class Timer {
    public:
        Timer(double);
        void start();
        void onDone(std::function<void()>);
        void advance(double);

    private:
        double timeRunning;
        double timeToRun;
        bool isRunning;
        std::function<void()> func;
};

}

#endif // JESH_TIMER_H_



