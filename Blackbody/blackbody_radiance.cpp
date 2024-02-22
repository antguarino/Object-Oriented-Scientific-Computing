#include <iostream>
#include <cmath>
#include <complex>
#include <numbers>

// Include Aggregate Header File - Radiometry.h
#include "radiometry.h"

using namespace std;

int main() {
  double wavelength = 0.000008;
  radiometry::Blackbody bb(200);  // Create Blackbody with an absolute temperature of 200 K
  cout << "Temperature = " << bb.AbsoluteTemp() << " [K]"
       << endl;  // Print The Absolute Temperature for bb
  cout << "Wavelength = " << wavelength * 1000000 << " [micron]"
       << endl;  // Print The Wavelength for bb
  cout << "Exitance = " << bb.Exitance(wavelength) << " [W/m^2/micron]"
       << endl;  // Print The Exitance for bb
  cout << "Radiance = " << bb.Radiance(wavelength) << " [W/m^2/sr/micron]"
       << endl;  // Print The Radiance for bb
  cout << "Peak Wavelength = " << bb.PeakWavelength() * 1000000 << " [micron]"
       << endl;  // Print The Peak Wavelength for bb

  cout << endl;
  wavelength = 0.00001; //Change the wavelength variable
  bb.AbsoluteTemp(300); //Call the setter function to change the absolute temperature to 300 K
  cout << "Temperature = " << bb.AbsoluteTemp() << " [K]"
       << endl;  // Print The Absolute Temperature for bb2
  cout << "Wavelength = " << wavelength * 1000000 << " [micron]"
       << endl;  // Print The Wavelength for bb2
  cout << "Exitance = " << bb.Exitance(wavelength) << " [W/m^2/micron]"
       << endl;  // Print The Exitance for bb2
  cout << "Radiance = " << bb.Radiance(wavelength) << " [W/m^2/sr/micron]"
       << endl;  // Print The Radiance for bb2
  cout << "Peak Wavelength = " << bb.PeakWavelength() * 1000000 << " [micron]"
       << endl;  // Print The Peak Wavelength for bb2
}