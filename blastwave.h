//(**Last Updated**: February 3 2025)
#ifndef BLASTWAVE_H
#define BLASTWAVE_H

#include <array>

class BlastWaveSolver {
public:
    BlastWaveSolver(double gamma, double dx);
    void solve();

private:
    double gamma; // Polytropic index
    double dx;    // Step size for numerical integration
    std::array<double, 3> initial_values;

    void rungeKutta4(double &xi, std::array<double, 3> &y, double dx, double gamma);
    void deri(double xi, double gamma, const std::array<double, 3> &y, std::array<double, 3> &dydx) const;
};

#endif // BLASTWAVE_H
