#ifndef EXPONENTIALREGRESSIONSOLVER_H_INCLUDED
#define EXPONENTIALREGRESSIONSOLVER_H_INCLUDED

#include <vector>
#include <cmath>
#include <iostream>
#include "RegressionSolver.h"
#include "Point.h"

class ExponentialRegressionSolver : public RegressionSolver {
    public:
        ExponentialRegressionSolver();
        std::vector<Point> Solve();
        double calculteRsquare(const std::vector<Point> &points);
        void name() const;
};


#endif // EXPONENTIALREGRESSIONSOLVER_H_INCLUDED
