#include "Program.h"

Program::Program() {
    m_config = new Config();
    PointLoader* loader = new PointLoader("dataset/points.csv");
    m_points = loader->LoadData();
    delete loader;
}

std::vector<RegressionSolver*> Program::getSolvers() {
    std::vector<RegressionSolver*> solvers = m_config->getSolvers();
    for (const auto& solver: solvers) {
        solver->setPoints(m_points);
        solver->setPrecision(10);
    }
    return solvers;
}

void Program::run() {
    Worker worker;
    std::vector<RegressionSolver*> solvers = getSolvers();

    if (m_config->isMultiThreaded()) {
        for (const auto& solver: solvers) {
            m_threads.push_back(new std::thread(threadFunction, std::ref(worker), solver));
        }
        for (const auto& th: m_threads) {
            th->join();
        }
    } else {
        std::chrono::high_resolution_clock::time_point beginning;
        std::chrono::high_resolution_clock::time_point ending;
        for (const auto& solver: solvers) {
            beginning = std::chrono::high_resolution_clock::now();
            solver->Solve();
            ending = std::chrono::high_resolution_clock::now();
            solver->name();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(ending - beginning).count();
            std::cout << "Time : " << duration << " microsecondes" << std::endl;
        }
    }
}

void Program::threadFunction(Worker& worker, RegressionSolver* solver) {
    worker.process(solver);
}
