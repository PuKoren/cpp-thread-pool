#pragma once
#include <vector>
#include <thread>
#include "CThread.h"
#include "JobStack.h"

const unsigned int THREADS_COUNT = 4;

class ThreadPool{
public:
    ThreadPool();
    ~ThreadPool();
    bool init();
    JobStack* getJobStack();
private:
    std::vector<CThread*> mThreads;
    std::vector<std::thread> mPthreads;
    JobStack* mStack;
};
