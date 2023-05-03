#ifndef POWERSERIESREGRESSIONSOLVER_H_INCLUDED
#define POWERSERIESREGRESSIONSOLVER_H_INCLUDED

#include <cmath>
#include <vector>
#include <iostream>
#include "RegressionSolver.h"

class PowerSeriesRegressionSolver : public RegressionSolver {
    public:
        PowerSeriesRegressionSolver();
        std::vector<Point> Solve() override;
        double calculteRsquare(const std::vector<Point> &points);
        void name() const;
};

#endif // POWERSERIESREGRESSIONSOLVER_H_INCLUDED
