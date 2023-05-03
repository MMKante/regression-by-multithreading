#ifndef REGRESSIONSOLVER_H_INCLUDED
#define REGRESSIONSOLVER_H_INCLUDED

#include <vector>
#include "Point.h"

class RegressionSolver {
    public:
        RegressionSolver();
        void setPoints(const std::vector<Point> &points);
        void setPrecision(float precison);
        virtual std::vector<Point> Solve() = 0;
        virtual double calculteRsquare(const std::vector<Point> &points) = 0;
        virtual void name() const = 0;

    protected:
        std::vector<Point> m_points;
        float m_precision;
};

#endif // REGRESSIONSOLVER_H_INCLUDED
