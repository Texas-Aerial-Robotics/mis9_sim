#include <fstream>
#include "wavefunctions.hpp"

int RES = 100;

int main() {
    std::ofstream file;
    file.open("output.csv");

    double thisAmplitude;
    double lastAmplitude = 1; // this value is the starting value for AMPLITUDE

    double thisPeriod;
    double lastPeriod = 1; // this value is the starting value for PERIOD

    double startingpoint = 0; // this value tells the CSV file where to pick up count for 't'

    for (int i = 0; i < 5; i++) {
        // update the values for PERIOD and AMPLITUDE
        thisAmplitude = next(.2, 2.8, .4, lastAmplitude);
        thisPeriod = next(1,5.2, .4, lastPeriod);

        // generate a new wave with @param PERIOD and AMPLITUDE
        std::vector< std::vector<double> > a = wave(thisAmplitude,thisPeriod, RES);

        // write wave to file
        for(int z = 0; z < a[1].size(); z++) {
            //std::cout << a[0][z]+startingpoint << "," << a[1][z] << "\n";
            file << a[0][z]+startingpoint << ", " << a[1][z] << "\n";
        }

        // update iterative variables
        lastAmplitude = thisAmplitude;
        lastPeriod = thisPeriod;
        startingpoint = startingpoint + thisPeriod;
    }
    file.close();
}