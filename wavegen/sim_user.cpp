#include <fstream>
#include "wavefunctions.hpp"

int RES = 100;

int main() {
    std::ofstream file;
    file.open("output.csv");

    std::cout << "Input a maximum amplitude: ";
    double MAX_AMPLITUDE;
    std::cin >> MAX_AMPLITUDE;

    std::cout << "Input a minimum amplitude: ";
    double MIN_AMPLITUDE;
    std::cin >> MIN_AMPLITUDE;
    
    std::cout << "Input a maximum period: ";
    double MAX_PERIOD;
    std::cin >> MAX_PERIOD;
    
    std::cout << "Input a minimum period: ";
    double MIN_PERIOD;
    std::cin >> MIN_PERIOD;

    std::cout << "Input an amplitude for the first wave: ";
    double thisAmplitude;
    double lastAmplitude;
    std::cin >> lastAmplitude;

    std::cout << "Input a period for the first wave: ";
    double thisPeriod;
    double lastPeriod;
    std::cin >> lastPeriod;

    std::cout << "What maximum percentage variation should we allow? ";
    double MAX_VAR;
    std::cin >> MAX_VAR;

    std::cout << "How many waves do you want? ";
    double NUM_WAVES;
    std::cin >> NUM_WAVES;

    double startingpoint = 0; // this value tells the CSV file where to pick up count for 't'

    for (int i = 0; i < NUM_WAVES; i++) {
        // update the values for PERIOD and AMPLITUDE
        thisAmplitude = next(MIN_AMPLITUDE, MAX_AMPLITUDE, MAX_VAR, lastAmplitude);
        thisPeriod = next(MIN_PERIOD,MAX_PERIOD, MAX_VAR, lastPeriod);

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
    std::cout << NUM_WAVES << " waves successfully generated. Output [x,y] can be found in output.csv.\n";
}