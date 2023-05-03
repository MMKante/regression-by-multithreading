#include "PowerSeriesRegressionSolver.h"

PowerSeriesRegressionSolver::PowerSeriesRegressionSolver() {}

void PowerSeriesRegressionSolver::name() const {
    std::cout << "Power Series" << std::endl;
}

std::vector<Point> PowerSeriesRegressionSolver::Solve() {
    std::vector<Point> result;
    int n = m_points.size();
    float sum_x = 0;
    float sum_y = 0;
    float sum_xy = 0;
    float sum_x_squared = 0;
    float sum_y_squared = 0;
    float sum_x_power_y = 0;

    for (int i = 0; i < n; i++) {
        if (m_points[i].x() <= 0 || m_points[i].y() <= 0) {
            std::cerr << "Invalid data, x and y must be positive." << std::endl;
            return result;
        }
        sum_x += log(m_points[i].x());
        sum_y += log(m_points[i].y());
        sum_xy += log(m_points[i].x()) * log(m_points[i].y());
        sum_x_squared += log(m_points[i].x()) * log(m_points[i].x());
        sum_y_squared += log(m_points[i].y()) * log(m_points[i].y());
        sum_x_power_y += pow(log(m_points[i].x()), 2) * log(m_points[i].y());
    }

    float b = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);
    float a = exp((sum_y - b * sum_x) / n);

    // Xmin et Xmax
    float Xmin = m_points[0].x(), Xmax = Xmin;
    for (unsigned int i = 0; i < m_points.size(); i++) {
        if (Xmin > m_points[i].x())
            Xmin = m_points[i].x();
        if (Xmax < m_points[i].x())
            Xmax = m_points[i].x();
    }

    for (float x = Xmin; x <= Xmax; x+=m_precision) {
        float y = a * pow(x, b);

        result.push_back(Point(x, y));
    }

    return result;
}

double PowerSeriesRegressionSolver::calculteRsquare(const std::vector<Point> &points) {
    double a = 0;
    return a;
}
