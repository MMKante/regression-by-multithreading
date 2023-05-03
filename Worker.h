#ifndef WORKER_H_INCLUDED
#define WORKER_H_INCLUDED

#include <chrono>
#include <iostream>
#include "RegressionSolver.h"

#include <ctime>

class Worker {
    public:
        Worker() {}
        void process(RegressionSolver* solver) {
            std::chrono::high_resolution_clock::time_point beginning;
            std::chrono::high_resolution_clock::time_point ending;
            beginning = std::chrono::high_resolution_clock::now();

            solver->Solve();

            ending = std::chrono::high_resolution_clock::now();
            solver->name();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(ending - beginning).count();
            std::cout << "Time : " << duration << " microsecondes" << std::endl;
        }
};


#endif // WORKER_H_INCLUDED
