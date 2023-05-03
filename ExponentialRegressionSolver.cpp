#include "ExponentialRegressionSolver.h"

ExponentialRegressionSolver::ExponentialRegressionSolver() {}

void ExponentialRegressionSolver::name() const {
    std::cout << "Exponential" << std::endl;
}

std::vector<Point> ExponentialRegressionSolver::Solve() {
    std::vector<Point> result;
    const unsigned int n = m_points.size();
    std::vector<float> x(n), y(n);
    for (unsigned int i = 0; i < n; i++) {
        if (m_points[i].y() <= 0) {
            std::cerr << "Error: y must be positive" << std::endl;
            return {};
        }
        x[i] = m_points[i].x();
        y[i] = log(m_points[i].y());
    }

    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;
    for (unsigned int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
    }

    float a = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    float b = (sum_y - a * sum_x) / n;

    // Xmin et Xmax
    float Xmin = m_points[0].x(), Xmax = Xmin;
    for (unsigned int i = 0; i < m_points.size(); i++) {
        if (Xmin > m_points[i].x())
            Xmin = m_points[i].x();
        if (Xmax < m_points[i].x())
            Xmax = m_points[i].x();
    }

    for (float x = Xmin; x < Xmax; x+=m_precision) {
        float x_ = x;
        float y_ = exp(a * x_ + b);
        result.push_back(Point(x_, y_));
    }

    return result;
}

double ExponentialRegressionSolver::calculteRsquare(const std::vector<Point> &points) {
    return 0.0;
}
