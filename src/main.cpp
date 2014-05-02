#include <iostream>
#include "ThreadPool.h"
using namespace std;

class DemoJob: public Job{
public:
    DemoJob(){
        this->mCurrentJob = ++DemoJob::counter;
        std::cout << "Job #" << this->mCurrentJob << " created\n" << std::endl;
    }

    ~DemoJob(){
        std::cout << "Job #" << this->mCurrentJob << " destroyed" << std::endl;
    }

    void run(){
        for(unsigned int i = 0; i < 100000000; i++){
            int a = 1+1;
            int b = 3+4;
            a = b*2;
        }
        std::cout << "Job #" << this->mCurrentJob << " ended" << std::endl;
    }
private:
    static int counter;
    int mCurrentJob;
};

int DemoJob::counter = 0;
const unsigned int JOB_COUNT = 50;

int main(){
    ThreadPool tp;
    tp.init();

    for(unsigned int i = 0; i < JOB_COUNT; i++)
        tp.getJobStack()->addJob(new DemoJob());

    return 0;
}

