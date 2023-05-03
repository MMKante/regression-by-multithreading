#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED

#include <thread>
#include <vector>
#include "Worker.h"
#include "PointLoader.h"
#include "Config.h"

class Program {
    public:
        Program();
        void run();

    private:
        std::vector<RegressionSolver*> getSolvers();
        static void threadFunction(Worker& worker, RegressionSolver* solver);
        std::vector<Point> m_points;
        std::vector<std::thread*> m_threads;
        Config* m_config;
};

#endif // PROGRAM_H_INCLUDED
