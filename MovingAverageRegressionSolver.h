#ifndef MOVINGAVERAGEREGRESSIONSOLVER_H_INCLUDED
#define MOVINGAVERAGEREGRESSIONSOLVER_H_INCLUDED

#include <vector>
#include <cmath>
#include "RegressionSolver.h"

class MovingAverageRegressionSolver : public RegressionSolver {
    public:
        MovingAverageRegressionSolver(float period);
        void setPeriod(float period);
        float getPeriod() const;
        std::vector<Point> Solve() override;
        double calculteRsquare(const std::vector<Point> &points);
        void name() const;

    private:
        float m_period;
};

#endif // MOVINGAVERAGEREGRESSIONSOLVER_H_INCLUDED
