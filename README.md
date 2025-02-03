# Sedov-Taylor Blast Wave Simulation
(**Last Updated**: February 3, 2025)

---

This repository contains a numerical study of the Sedov-Taylor blast wave problem, conducted during my undergraduate studies. 
The project involves solving the governing differential equations in a polytropic gas using a fourth-order Runge-Kutta integration
method. The analysis focuses on the evolution of self-similar profiles for density, pressure, velocity, and temperature, with an 
investigation into the impact of the stiffness parameter γ on the shockwave structure.

---

## Contents

- **Source Code**:
  - `main.cpp` - Contains the main function to execute the simulation.
  - `blastwave.h` - Header file declaring functions and constants used in the simulation.
  - `blastwave.cpp` - Implementation of the functions declared in `blastwave.h`.

- **Documentation**:
  - `Blast_wave_Sedov_Taylor.pdf` - A comprehensive report detailing the problem formulation, numerical methods employed, analysis
     of results, and observations on numerical integration errors.
    

---

## Overview

The Sedov-Taylor blast wave problem models the behavior of state variables within the post-shock region of a violent explosion in a
non-viscous polytropic fluid. The study aims to:

1. Formulate the problem using fluid dynamics equations.
2. Numerically integrate the resulting system of differential equations.
3. Analyze the solution profiles as a function of the stiffness parameter γ.
4. Discuss observations related to numerical integration errors.

---

## Numerical Method

A fourth-order Runge-Kutta integration method is utilized to solve the system of first-order nonlinear differential equations. This
approach balances accuracy and computational efficiency, ensuring reliable simulation results.

---

## Results

The simulation provides insights into:

- The distribution of density, pressure, and velocity within the shock region.
- The influence of the stiffness parameter γ on the shockwave structure.
- The behavior of the temperature profile and its implications on the physical properties of the explosion.

For detailed results and discussions, please refer to the included PDF report.

---

## Compilation and Execution

To compile and run the simulation, follow these steps:

1. Ensure you have a C++ compiler installed (e.g., `g++`).
2. Open a terminal and navigate to the project directory.
3. Compile the source files using:
   ```bash
   g++ main.cpp blastwave.cpp -o blastwave_simulation
4. Run the compiled executable:
   ```bash
   ./blastwave_simulation

The program will output the simulation results, which can be further analyzed or visualized as needed.

---

## Note 

This project was undertaken during my undergraduate studies, reflecting my early exploration into 
numerical simulations and fluid dynamics. This repository represents a version of that work 
translated in English with no deeper text modification, and a polished program to make it more 
in line with good coding practices.






   
