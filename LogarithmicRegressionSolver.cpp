#include "LogarithmicRegressionSolver.h"

LogarithmicRegressionSolver::LogarithmicRegressionSolver() {}

void LogarithmicRegressionSolver::name() const {
    std::cout << "Logarithmic" << std::endl;
}

std::vector<Point> LogarithmicRegressionSolver::Solve() {
    // Le nombre de points à traiter
    int n = m_points.size();

    // Initialisation des variables pour le calcul des coefficients de la régression logarithmique
    double sum_x = 0, sum_y = 0, sum_ln_x = 0, sum_ln_x_y = 0, sum_ln_x_squared = 0;

    // Boucle sur tous les points pour calculer les sommes
    for (const auto &point : m_points) {
        if (point.x() <= 0) {
            std::cerr << "Error: x (" << point.x() << ") must be positive" << std::endl;
            return {};
        }
        double ln_x = log(point.x());
        sum_x += point.x();
        sum_y += point.y();
        sum_ln_x += ln_x;
        sum_ln_x_y += ln_x * point.y();
        sum_ln_x_squared += ln_x * ln_x;
    }

    // Calcul des coefficients de la régression logarithmique en utilisant la méthode du moindre carré
    double b = (n * sum_ln_x_y - sum_ln_x * sum_y) / (n * sum_ln_x_squared - sum_ln_x * sum_ln_x);
    double a = (sum_y - b * sum_ln_x) / n;

    // Xmin et Xmax
    float Xmin = m_points[0].x(), Xmax = Xmin;
    for (unsigned int i = 0; i < m_points.size(); i++) {
        if (Xmin > m_points[i].x())
            Xmin = m_points[i].x();
        if (Xmax < m_points[i].x())
            Xmax = m_points[i].x();
    }
    // Calcul des coordonnées des points de la régression logarithmique pour tous les x
    std::vector<Point> regression_points;
    for (float x = Xmin; x <= Xmax; x+=m_precision) {
        float y = a + b * log(x);
        regression_points.emplace_back(Point(x, y));
    }

    return regression_points;
}

double LogarithmicRegressionSolver::calculteRsquare(const std::vector<Point> &points) {
    double a = 0;
    return a;
}
