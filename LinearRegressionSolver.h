#ifndef LINEARREGRESSIONSOLVER_H_INCLUDED
#define LINEARREGRESSIONSOLVER_H_INCLUDED

#include <vector>
#include <math.h>
#include <iostream>
#include "RegressionSolver.h"
#include "Point.h"

class LinearRegressionSolver : public RegressionSolver {
    public:
        LinearRegressionSolver();
        std::vector<Point> Solve();
        void initParams();
        double calculteRsquare(const std::vector<Point> &points);
        void name() const;

    private:
        float m_a;
        float m_b;
};

#endif // LINEARREGRESSIONSOLVER_H_INCLUDED
