//(**Last Updated**: February 3 2025)
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "blastwave.h"

bool isValidNumber(const std::string &str) {
    std::stringstream ss(str);
    double num;
    return (ss >> num) && (ss.eof());  // Check if the whole string was consumed
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./blastwave <gamma> <dx>\n";
        return 1;
    }

    std::string gammaStr = argv[1];
    std::string dxStr = argv[2];

    if (!isValidNumber(gammaStr) || !isValidNumber(dxStr)) {
        std::cerr << "Error: Gamma and dx must be valid numeric values.\n";
        return 1;
    }

    try {
        double gamma = std::stod(gammaStr);
        double dx = std::stod(dxStr);

        if (gamma <= 1 || dx <= 0) {
            throw std::invalid_argument("Invalid input values. Ensure gamma > 1 and dx > 0.");
        }

        BlastWaveSolver solver(gamma, dx);
        solver.solve();

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
