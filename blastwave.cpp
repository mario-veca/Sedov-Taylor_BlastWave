//(**Last Updated**: February 3 2025)
#include "blastwave.h"
#include <iostream>
#include <vector>

BlastWaveSolver::BlastWaveSolver(double gamma, double dx) : gamma(gamma), dx(dx) {
    // Initial conditions: H(1) = 1, P(1) = 1, V(1) = 1
    initial_values = {1.0, 1.0, 1.0};
}

void BlastWaveSolver::solve() {
    std::array<double, 3> y = initial_values;
    double xi = 1.0; // Start integration at xi = 1

    while (xi >= dx) { // Stop when xi reaches 0
        double T_xi = y[2] / y[0];  // Compute temperature T = P / H
        					//		H				P				V
        std::cout << xi << "\t" << y[0] << "\t" << y[1] << "\t" << y[2] << "\t" << T_xi << "\n";

        rungeKutta4(xi, y, dx, gamma); // Move backwards in xi, starting from 1 ang going towards 0
        xi -= dx;
    }
}

void BlastWaveSolver::rungeKutta4(double &xi, std::array<double, 3> &y, const double dx, const double gamma) {
    std::array<double, 3> k1{}, k2{}, k3{}, k4{}, y_temp{};

    deri(xi, gamma, y, k1);
    for (int i = 0; i < 3; i++) y_temp[i] = y[i] - 0.5 * dx * k1[i];


    deri(xi - 0.5 * dx, gamma, y_temp, k2);
    for (int i = 0; i < 3; i++) y_temp[i] = y[i] - 0.5 * dx * k2[i];


    deri(xi - 0.5 * dx, gamma, y_temp, k3);
    for (int i = 0; i < 3; i++) y_temp[i] = y[i] - dx * k3[i];

    deri(xi - dx, gamma, y_temp, k4);
    for (int i = 0; i < 3; i++) y[i] += (-dx / 6.0) * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);


}

/**
 * Computes the derivatives by inversion of 
 * equations (17), (18), (19) from the document.
 */
void BlastWaveSolver::deri(double xi, double gamma, const std::array<double, 3> &y, std::array<double, 3> &dydx) const { 
    double H = y[0], P = y[1], V = y[2];

    // Various terms from equations (17), (18), (19)
    double a = -xi + 2.0 * V / (gamma + 1);
    double b = 2.0 * H / (gamma + 1);
    double c = -4.0 * H * V / (xi * (gamma + 1));
    double d = -2.0 * xi + 4.0 * V / (gamma + 1);
    double e = 2.0 * (gamma - 1) / ((gamma + 1) * H);
    double f = 3.0 * V;
    double g = -(gamma / H) * (-xi + 2.0 * V / (gamma + 1));
    double h = (-xi + 2.0 * V / (gamma + 1)) / P;
    double i = 3.0;

    double denom = e * g * b + d * h * a;

    // Compute derivatives
    dydx[0] = (d * h * c - b * f * h + b * i * e) / denom;
    dydx[1] = (a * d * i + g * b * f - g * c * d) / denom;
    dydx[2] = (a * f * h - a * i * e + e * g * c) / denom;
    
}

