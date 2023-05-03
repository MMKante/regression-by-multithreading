#include "PolynomialRegressionSolver.h"

PolynomialRegressionSolver::PolynomialRegressionSolver(unsigned int degree) : m_degree(degree) {}

void PolynomialRegressionSolver::setDegree(unsigned int degree) {
    m_degree = degree;
}

void PolynomialRegressionSolver::name() const {
    std::cout << "Polynomiale" << std::endl;
}

std::vector<Point> PolynomialRegressionSolver::Solve() {
    const int n = m_points.size();
    std::vector<std::vector<double>> X(n, std::vector<double>(m_degree + 1));
    std::vector<double> Y(n);

    // Remplissage des matrices X et Y avec les points de données
    for (int i = 0; i < n; ++i) {
        const float x = m_points[i].x();
        Y[i] = m_points[i].y();
        for (unsigned int j = 0; j <= m_degree; ++j) {
            X[i][j] = pow(x, j);
        }
    }

    // Résolution de la régression polynomiale en utilisant la méthode du moindre carré
    std::vector<double> theta = SolveLeastSquares(X, Y);

    // Xmin et Xmax
    float Xmin = m_points[0].x(), Xmax = Xmin;
    for (unsigned int i = 0; i < m_points.size(); i++) {
        if (Xmin > m_points[i].x())
            Xmin = m_points[i].x();
        if (Xmax < m_points[i].x())
            Xmax = m_points[i].x();
    }

    std::vector<Point> result;
    for (float x = Xmin; x <= Xmax; x+=m_precision) {
        float y = 0.0f;
        for (unsigned int j = 0; j <= m_degree; ++j) {
            y += theta[j] * pow(x, j);
        }
        result.push_back(Point(x, y));
    }

    return result;
}

std::vector<double> PolynomialRegressionSolver::SolveLeastSquares(const std::vector<std::vector<double>> &X, const std::vector<double> &Y) const
{
    // On calcule la transposée de la matrice X
    std::vector<std::vector<double>> X_transposed(m_degree + 1, std::vector<double>(X.size()));
    for (unsigned int i = 0; i <= m_degree; ++i) {
        for (unsigned int j = 0; j < X.size(); ++j) {
            X_transposed[i][j] = X[j][i];
        }
    }

    // On calcule la produit de X transposé par X
    std::vector<std::vector<double>> X_transposed_X(m_degree + 1, std::vector<double>(m_degree + 1));
    for (unsigned int i = 0; i <= m_degree; ++i) {
        for (unsigned int j = 0; j <= m_degree; ++j) {
            X_transposed_X[i][j] = 0.0;
            for (unsigned int k = 0; k < X.size(); ++k) {
                X_transposed_X[i][j] += X_transposed[i][k] * X[k][j];
            }
        }
    }

    // On calcule la produit de X transposé par Y
    std::vector<double> X_transposed_Y(m_degree + 1);
    for (unsigned int i = 0; i <= m_degree; ++i) {
        X_transposed_Y[i] = 0.0;
        for (unsigned int j = 0; j < X.size(); ++j) {
            X_transposed_Y[i] += X_transposed[i][j] * Y[j];
        }
    }

    // On résout le système d'équations en utilisant la méthode de Gauss-Jordan
    for (unsigned int i = 0; i <= m_degree; ++i) {
        double pivot = X_transposed_X[i][i];
        for (unsigned int j = 0; j <= m_degree; ++j) {
            X_transposed_X[i][j] /= pivot;
        }
        X_transposed_Y[i] /= pivot;

        for (unsigned int j = 0; j <= m_degree; ++j) {
            if (j == i) continue;
            double ratio = X_transposed_X[j][i] / X_transposed_X[i][i];
            for (unsigned int k = 0; k <= m_degree; ++k) {
                X_transposed_X[j][k] -= ratio * X_transposed_X[i][k];
            }
            X_transposed_Y[j] -= ratio * X_transposed_Y[i];
        }
    }

    return X_transposed_Y;
}

double PolynomialRegressionSolver::calculteRsquare(const std::vector<Point> &points) {
    double a = 0;
    return a;
}
