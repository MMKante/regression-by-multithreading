#include "Config.h"

Config::Config() {
    std::ifstream file("configs/config.json");
    if (file.is_open()) {
        file >> m_config;
    } else {
        std::cerr << "Impossible d'ouvrir le fichier config.json." << std::endl;
    }
}

bool Config::isMultiThreaded() const {
    return m_config.value("multiThreaded", false);
}

std::vector<RegressionSolver*> Config::getSolvers() const {
    std::vector<RegressionSolver*> solvers;

    if (m_config["solvers"]["linear"].value("enabled", false))
        solvers.push_back(new LinearRegressionSolver());
    if (m_config["solvers"]["exponential"].value("enabled", false))
        solvers.push_back(new ExponentialRegressionSolver());
    if (m_config["solvers"]["logarithmic"].value("enabled", false))
        solvers.push_back(new LogarithmicRegressionSolver());
    if (m_config["solvers"]["polynomial"].value("enabled", false))
        solvers.push_back(new PolynomialRegressionSolver(m_config["solvers"]["polynomial"].value("degree", 2)));
    if (m_config["solvers"]["powerSeries"].value("enabled", false))
        solvers.push_back(new PowerSeriesRegressionSolver());
    if (m_config["solvers"]["movingAverage"].value("enabled", false))
        solvers.push_back(new MovingAverageRegressionSolver(m_config["solvers"]["polynomial"].value("period", 1)));

    return solvers;
}
