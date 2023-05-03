#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "libs/json.hpp"
#include "RegressionSolver.h"
#include "LinearRegressionSolver.h"
#include "ExponentialRegressionSolver.h"
#include "PolynomialRegressionSolver.h"
#include "PowerSeriesRegressionSolver.h"
#include "LogarithmicRegressionSolver.h"
#include "MovingAverageRegressionSolver.h"

using json = nlohmann::json;

class Config {
    public:
        Config();
        bool isMultiThreaded() const;
        std::vector<RegressionSolver*> getSolvers() const;

    private:
        json m_config;
};

#endif // CONFIG_H_INCLUDED
