
#include <fstream>
#include "wavefunctions.hpp"

int main() {

    std::ofstream file;
    file.open("test.csv");

    double thisRand;
    double lastRand = 1;

    for (int i = 0; i < 5; i++) {
        thisRand = next(0, 2.8, .25, lastRand);

        std::vector< std::vector<double> > a = wave (thisRand, 1, 100);
        
        lastRand = thisRand;

        for(int z = 0; z < a[1].size(); z++) {
            std::cout << a[0][z]+i << "," << a[1][z] << "\n";
            file << a[0][z]+i << ", " << a[1][z] << "\n";
        }

    }

    file.close();
}