#include <iostream>
#include <cmath>
#include <complex>
#include <numbers>
#include <vector>

// Include Agregate Header File - radiometry.h
#include "imgs/radiometry/radiometry.h"

using namespace std;

namespace radiometry {
// Member function to calculate radiance by dividing exidence by pi
const double Blackbody::Radiance(const double& wavelength) const {
  return Exitance(wavelength) / std::numbers::pi;
}

// Member function to find the peak wavelength by dividing the Wein's
// Displacement Constant by the absolute temp
const double Blackbody::PeakWavelength() const {
  const double kWeinsDisplacement = 2.897771955 * 1e-3;  // [m⋅K]
  return kWeinsDisplacement / AbsoluteTemp();
}

const double Blackbody::Exitance(const double& wavelength) const {
  // Define Planck's Constants, Speed of Light Constant, and Boltzmnnn Constant
  const double kPlancksConstant = 6.62607015 * 1e-34;  // kgm^2/s
  const double kSpeedOfLight = 2.99792458 * 1e8;       // meters /second
  const double kBoltzmannConstant = 1.380649 * 1e-23;  // joule per kelvin

  // Plancks Equation W/m^2*micron
  return ((2 * std::numbers::pi * kPlancksConstant * kSpeedOfLight *
           kSpeedOfLight) /
          (pow(wavelength, 5) *
           (exp((kPlancksConstant * kSpeedOfLight) /
                (wavelength * kBoltzmannConstant * AbsoluteTemp())) -
            1))) *
         1e-6;
}

vector<double> Blackbody::SpectralRadiantExitance(
    const vector<double>& wavelength_vector) const {
  vector<double> spectral_radiant_exitence = {};
  spectral_radiant_exitence.reserve(wavelength_vector.size());
  for (size_t i = 0; i < wavelength_vector.size(); i++) {
    spectral_radiant_exitence.push_back(Exitance(wavelength_vector[i]));
  }
  return spectral_radiant_exitence;
}

vector<double> Blackbody::SpectralRadiance(
    const vector<double>& wavelength_vector) const {
  vector<double> spectral_radiance = {};
  spectral_radiance.reserve(wavelength_vector.size());
  for (size_t i = 0; i < wavelength_vector.size(); i++) {
    spectral_radiance.push_back(Radiance(wavelength_vector[i]));
  }
  return spectral_radiance;
}
}  // namespace radiometry