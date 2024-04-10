#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <matplot/matplot.h>

//./bin/blackbody_fit /home/ag4933/src/cpp/rit/data/spectra/tes/200005260950.sac

// Include Aggregate Header File - radiometry.h
#include "imgs/radiometry/radiometry.h"

#include "imgs/numerical/sorting/Sorting.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
    }
    std::string header;
    std::vector<double> wavelengths;
    std::vector<double> radiances;

    std::string filename = argv[1];
    std::ifstream f(filename);
    std::getline(f, header);

    std::string line;
    while (getline(f, line)) {
        std::stringstream ss(line);

        std::string str; // Throwaway string
        std::getline(ss, str, ','); // Single quotes are a trait
        double x = stod(str); // Converts string to double

        std::getline(ss, str); // Go to end of line
        double y = stod(str); // Converts string to double

        wavelengths.push_back(x);
        radiances.push_back(y);
    }

    std::vector<double> spectral_emissivity;
    cout << "Derived temperature = " << radiometry::BlackbodyFit(wavelengths, radiances, spectral_emissivity, 7, 15, 0.001) << " [K]" << endl;

    // Plot the graphs [Only works on RealVNC]
    matplot::plot(wavelengths, spectral_emissivity) -> color("b").line_width(2);
    matplot::xlabel("Wavelength [microns]");
    matplot::ylabel("Emissivity");
    matplot::xlim({7, 15});
    matplot::ylim({0, 1.2});
    matplot::show();
}