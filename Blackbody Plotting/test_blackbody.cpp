#include <iostream>
#include <cmath>
#include <complex>
#include <numbers>
#include <vector>
#include "matplot/matplot.h"

// Include Aggregate Header File - Radiometry.h
#include "radiometry.h"

using namespace std;

int main() {
  double wavelength = 0.000008;
  radiometry::Blackbody bb(
      200);  // Create Blackbody with an absolute temperature of 200 K
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
  wavelength = 0.00001;  // Change the wavelength variable
  bb.AbsoluteTemp(300);  // Call the setter function to change the absolute
                         // temperature to 300 K
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

  cout << endl;

  // Vector of Wavelengths in Meters
  vector<double> wavelength_vector = {
      8E-6,    8.5E-6, 9E-6,    9.5E-6, 1E-5,    1.05E-5, 1.1E-5,
      1.15E-5, 1.2E-5, 1.25E-5, 1.3E-5, 1.35E-5, 1.4E-5};

  // Vector of Wavelengths in Microns
  vector<double> wavelength_vector_microns = {
      8, 8.5, 9, 9.5, 10, 10.5, 11, 11.5, 12, 12.5, 13, 13.5, 14};

  cout << "Wavelength [micron], Exitance [W/m^2/micron]" << endl;
  for (int i = 0; i < wavelength_vector.size(); i++) {
    cout << wavelength_vector[i] * 1000000 << ", "
         << bb.SpectralRadiantExitance(wavelength_vector)[i] << endl;
  }
  cout << endl;
  cout << "Wavelength [micron], Radiance [W/m^2/sr/micron]" << endl;
  for (int i = 0; i < wavelength_vector.size(); i++) {
    cout << wavelength_vector[i] * 1000000 << ", "
         << bb.SpectralRadiance(wavelength_vector)[i] << endl;
  }

  matplot::plot(wavelength_vector_microns,
                bb.SpectralRadiantExitance(wavelength_vector))
      ->color("b")
      .line_width(2);
  matplot::xlabel("Wavelength [microns]");
  matplot::ylabel("Spectral Radiant Exitance [W/m^2/micron]");
  matplot::show();
  matplot::save("SpectralRadiantExitance.eps");

  matplot::plot(wavelength_vector_microns,
                bb.SpectralRadiance(wavelength_vector))
      ->color("b")
      .line_width(2);
  matplot::xlabel("Wavelength [microns]");
  matplot::ylabel("Spectral Radiance [W/m^2/sr/micron]");
  matplot::show();
  matplot::save("SpectralRadiance.eps");
}