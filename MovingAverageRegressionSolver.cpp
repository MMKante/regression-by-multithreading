#include "MovingAverageRegressionSolver.h"
#include <iostream>

MovingAverageRegressionSolver::MovingAverageRegressionSolver(float period) : m_period(period) {}

void MovingAverageRegressionSolver::setPeriod(float period) {
    m_period = period;
}

float MovingAverageRegressionSolver::getPeriod() const {
    return m_period;
}

void MovingAverageRegressionSolver::name() const {
    std::cout << "Moving Average" << std::endl;
}

std::vector<Point> MovingAverageRegressionSolver::Solve() {
    std::vector<Point> solution;
    const unsigned int n = m_points.size();
    // Xmin et Xmax
    float Xmin = m_points[0].x(), Xmax = Xmin;
    for (unsigned int i = 0; i < n; i++) {
        if (Xmin > m_points[i].x())
            Xmin = m_points[i].x();
        if (Xmax < m_points[i].x())
            Xmax = m_points[i].x();
    }
    Xmin = std::floor(Xmin);
    Xmax = std::ceil(Xmax);

    for (float x = Xmin; x <= Xmax; x+=m_precision) {
        float a = x - m_period;
        float b = x + m_period;
        float sumY = 0.f;
        unsigned int count = 0;

        for (unsigned int i = 0; i < m_points.size(); i++) {
            if (a < m_points[i].x() && b > m_points[i].x()) {
                sumY += m_points[i].y();
                count++;
            }
        }
        if (count > 0) {
            float y = sumY / count;
            solution.push_back(Point(x, y));
        }
    }

    return solution;
}

double MovingAverageRegressionSolver::calculteRsquare(const std::vector<Point> &points) {
    double a = 0;
    return a;
}
