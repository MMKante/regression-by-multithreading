#include "LinearRegressionSolver.h"
#include <cmath>

LinearRegressionSolver::LinearRegressionSolver() {}

void LinearRegressionSolver::name() const {
    std::cout << "Linear" << std::endl;
}

void LinearRegressionSolver::initParams() {
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;
    int n = m_points.size();

    for (int i = 0; i < n; i++) {
        sum_x += m_points[i].x();
        sum_y += m_points[i].y();
        sum_xy += m_points[i].x() * m_points[i].y();
        sum_xx += m_points[i].x() * m_points[i].x();
    }

    m_a = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    m_b = (sum_y - m_a * sum_x) / n;
}

std::vector<Point> LinearRegressionSolver::Solve() {
    initParams();

    float x_min = m_points[0].x(), x_max = m_points[0].x();
    int n = m_points.size();

    for (int i = 1; i < n; i++) {
        if (m_points[i].x() < x_min) {
            x_min = m_points[i].x();
        }
        if (m_points[i].x() > x_max) {
            x_max = m_points[i].x();
        }
    }

    std::vector<Point> points;
    points.push_back(Point(x_min, m_a * x_min + m_b));
    points.push_back(Point(x_max, m_a * x_max + m_b));

    return points;
}

double LinearRegressionSolver::calculteRsquare(const std::vector<Point> &points) {
    double sum_x = 0, sum_y = 0, avg_x = 0, avg_y = 0, cov_xy = 0, var_x = 0, var_y = 0;
    const unsigned int n = m_points.size();

    for (unsigned int i = 0; i < n; i++) {
        sum_x += m_points[i].x();
        sum_y += m_points[i].y();
    }
    avg_x = sum_x / n;
    avg_y = sum_y / n;

    for (unsigned int i = 0; i < n; i++) {
        cov_xy += ((m_points[i].x() - avg_x) * (m_points[i].y() - avg_y));
        var_x += pow((m_points[i].x() - avg_x), 2);
        var_y += pow((m_points[i].y() - avg_y), 2);
    }
    cov_xy /= n;
    var_x /= n;
    var_y /= n;

    return ( cov_xy / sqrt(var_x * var_y));
}
