#include <chrono>
#include <random>
#include <fstream>
#include "vectorfunctions.hpp"

double next(double FMIN, double FMAX, double MAX_STEP, double last);

std::vector< std::vector<double> > wave (double A, double T, int RES);