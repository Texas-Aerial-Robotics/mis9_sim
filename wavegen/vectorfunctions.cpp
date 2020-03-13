#include <vector>
#include <iostream>
#include "vectorfunctions.hpp"

// function 'printVect' prints a given vector to the terminal

void printVect (std::vector<double> in) {
    for (double i : in) {
        std::cout << i << "\n";
    }
    std::cout << "\n";
}

// function 'linspace' mirrors the matlab linspace function

std::vector<double> linspace (double start, double space, double end) {
    std::vector<double> x((end-start)/space+1,0);
    for(int i = 0; i <= x.size(); i++) {
        x[i] = i*space;
    }
    return x;
}