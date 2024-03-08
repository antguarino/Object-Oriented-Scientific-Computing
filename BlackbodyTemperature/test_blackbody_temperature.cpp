#include <iostream>

// Include Aggregate Header File - radiometry.h
#include "imgs/radiometry/radiometry.h"

using namespace std;

int main() {
    // Create variables for radiance, wavelength, and tolerance
    double radiance, wavelength, tolerance;
    
    cout << "Radiance [W/m^2/sr/micron]: ";
    cin >> radiance;
    cout << "Wavelength [micron]: ";
    cin >> wavelength;
    wavelength *= 1e-6;
    cout << "Acceptable tolerance: [K]: ";
    cin >> tolerance;
    cout << "Temperature = " << radiometry::BlackbodyTemperature(radiance, wavelength, tolerance) << " [K]" << endl;   
}