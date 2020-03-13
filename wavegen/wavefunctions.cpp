#include <chrono>
#include <random>
#include <fstream>
#include "vectorfunctions.hpp"

// Setup random number generator and create normal distribution for use by 'next' function

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator (seed);
std::normal_distribution<double> stdNorm (0.0, 1.0);

/*
Function 'next' calculates the next value in a random-walk series. This function calculates the next value
by adding or subtracting a portion of the functions range from its previous value. This portion is
calculated from a normal distribution which is multiplied by a scaling constant. This constant defines
the maximum percentage of the functions range which the output is allowed to move in each step.
The motion of the function is bounded.

@param:
FMIN, the minimum value which the function is allowed to return
FMAX, the maximum value which the function is allowed to return
MAX_STEP, the maximum percentage of the range FMAX-FMIN which the next term is allowed to differ from
    the previous term
last, the previous value in the series

@return:
the next value in the series
*/


double next(double FMIN, double FMAX, double MAX_STEP, double last) {
    double SIZE = FMAX - FMIN;
    double thisRand = stdNorm(generator);
    double thisMove = (MAX_STEP*SIZE)*(thisRand/3);

    if (last + thisMove > FMAX) {
        //std::cout << "max triggered\n";
        return last - thisMove;
    }
    else if (last + thisMove < FMIN) {
        //std::cout << "min triggered\n";
        return last - thisMove;
    }
    else {
        //std::cout << "else triggered\n";
        return last + thisMove;
    }
}

/*
The 'wave' function returns a 2xN vector which consists of a single sine wave with the given parameters

@param:
A, the amplitude
T, the period
RES, the resolution of the wave

@return:
A 2xN vector which consists of a single sine wave
*/

std::vector< std::vector<double> > wave (double A, double T, int RES) {
    std::vector<double> t = linspace(0, 1/double(RES), T);
    std::vector<double> y (t.size(),0);
    for (int i = 0; i < t.size(); i++) {
        y[i] = A * sin( (2*M_PI*t[i])/T );
    }
    return {t,y};
}