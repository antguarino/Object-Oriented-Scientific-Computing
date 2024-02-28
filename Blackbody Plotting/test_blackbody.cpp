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

  // Set up variables to create wavelength vector for loops
  int upper_limit = 14;
  int lower_limit = 8;
  double range = upper_limit - lower_limit;
  int amount_of_values = 12;
  double delta_x = range / amount_of_values;

  // Vector of Wavelengths in Meters
  vector<double> wavelength_vector = {};
  wavelength_vector.reserve(amount_of_values);
  for (int i = 0; i <= amount_of_values; i++) {
    wavelength_vector.push_back((lower_limit + i * delta_x) / 1000000);
  };

  // Vector of Wavelengths in Microns
  vector<double> wavelength_vector_microns = {};
  wavelength_vector_microns.reserve(amount_of_values);
  for (int i = 0; i <= amount_of_values; i++) {
    wavelength_vector_microns.push_back((lower_limit + i * delta_x));
  };

  cout << "Wavelength [micron], Exitance [W/m^2/micron]" << endl;
     auto Exitances = bb.SpectralRadiantExitance(wavelength_vector);
  for (int i = 0; i < wavelength_vector.size(); i++) {
    cout << wavelength_vector[i] * 1000000 << ", "
         << Exitances[i] << endl;
  }
  cout << endl;
  cout << "Wavelength [micron], Radiance [W/m^2/sr/micron]" << endl;
  auto Radiances = bb.SpectralRadiance(wavelength_vector);
  for (int i = 0; i < wavelength_vector.size(); i++) {
    cout << wavelength_vector[i] * 1000000 << ", "
         << Radiances[i] << endl;
  }

  matplot::plot(wavelength_vector_microns,
                Exitances)
      ->color("b")
      .line_width(2);
  matplot::xlabel("Wavelength [microns]");
  matplot::ylabel("Spectral Radiant Exitance [W/m^2/micron]");
  matplot::show();
  matplot::save("SpectralRadiantExitance.eps");

  matplot::plot(wavelength_vector_microns,
                Radiances)
      ->color("b")
      .line_width(2);
  matplot::xlabel("Wavelength [microns]");
  matplot::ylabel("Spectral Radiance [W/m^2/sr/micron]");
  matplot::show();
  matplot::save("SpectralRadiance.eps");
}