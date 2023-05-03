#ifndef POLYNOMIALREGRESSIONSOLVER_H_INCLUDED
#define POLYNOMIALREGRESSIONSOLVER_H_INCLUDED

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include "RegressionSolver.h"
#include "Point.h"

class PolynomialRegressionSolver : public RegressionSolver {
    public:
        PolynomialRegressionSolver(unsigned int degree);
        std::vector<Point> Solve() override;
        void setDegree(unsigned int degree);
        std::vector<double> SolveLeastSquares(const std::vector<std::vector<double>> &X, const std::vector<double> &Y) const;
        double calculteRsquare(const std::vector<Point> &points);
        void name() const;

    private:
        unsigned int m_degree = 0;
};


#endif // POLYNOMIALREGRESSIONSOLVER_H_INCLUDED
