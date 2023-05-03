#ifndef LOGARITHMICREGRESSIONSOLVER_H_INCLUDED
#define LOGARITHMICREGRESSIONSOLVER_H_INCLUDED

#include <vector>
#include <cmath>
#include <iostream>
#include "RegressionSolver.h"

class LogarithmicRegressionSolver : public RegressionSolver {
    public:
        LogarithmicRegressionSolver();
        std::vector<Point> Solve() override;
        double calculteRsquare(const std::vector<Point> &points);
        void name() const;
};


#endif // LOGARITHMICREGRESSIONSOLVER_H_INCLUDED
