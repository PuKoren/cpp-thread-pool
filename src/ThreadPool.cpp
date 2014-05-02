#include "ThreadPool.h"

ThreadPool::ThreadPool(){
    this->mStack = new JobStack();
}

ThreadPool::~ThreadPool(){
    for(unsigned int i = 0; i < this->mPthreads.size(); i++){
        this->mThreads.at(i)->release();
        this->mPthreads.at(i).join();
    }
    delete this->mStack;
}

JobStack* ThreadPool::getJobStack(){
    return this->mStack;
}

bool ThreadPool::init(){
    for(int i = 0; i < THREADS_COUNT; i++){
        CThread* t = new CThread(this->mStack);
        this->mThreads.push_back(t);
        this->mPthreads.push_back(std::thread(&CThread::work, t));
    }
    return true;
}
