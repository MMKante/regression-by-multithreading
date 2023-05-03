#include "RegressionSolver.h"
#include <iostream>

RegressionSolver::RegressionSolver() {}

void RegressionSolver::setPoints(const std::vector<Point> &points) {
    m_points = points;
}

void RegressionSolver::setPrecision(float precision) {
    m_precision = precision;
}

void RegressionSolver::name() const {
    std::cout << "Empty" << std::endl;
}
