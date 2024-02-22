/** Interface file for the function to calculate Plancks Constant
 *
 * \file Blackbody.h
 *
 * \author Anthony Guarino, (ag4933@rit.edu)
 * \date 01 February 2024
 *
 * \copyright Copyright © 2024, Rochester Institute of Technology
 *
 * \version 1.0.0
 *
 * \details
 *    This will allow you to create a blackbody object with an associated absolute temperature.
 *    You can get and set absolute temperature with the AbsoluteTemp() function
 *    There are also member functions to calculate Exidence, Spectral Radiance, and Peak Wavelength
 *
 * \warning
 *      I dont know what I am doing so use this code at your own risk
 *
 */
#include <cmath>
#include <numbers>

// Namespace for Radiometry
namespace radiometry {

class Blackbody {
 public:
  // Blackbody Constructor takes in Absolute Temperature
  Blackbody(const double& absolute_temp) { absolute_temp_ = absolute_temp; }

  // Temp Getter
  double AbsoluteTemp() { return absolute_temp_; };

  // Temp Setter
  void AbsoluteTemp(const double& absolute_temp) {
    absolute_temp_ = absolute_temp;
  };

  //Member function to calculate radiance by dividing exidence by pi
  double Radiance(double wavelength) {
    return Exitance(wavelength) / std::numbers::pi;
  }

  //Member function to find the peak wavelength by dividing the Wein's Displacement Constant by the absolute temp
  double PeakWavelength() {
    double kWeinsDisplacement = 2.897771955 * 1e-3;
    return kWeinsDisplacement / absolute_temp_;
  }

  double Exitance(double wavelength) {
    // Define Planck's Constants, Speed of Light Constant, and Boltzmnnn Constant
    double kPlancksConstant = 6.62607015 * 1e-34;
    double kSpeedOfLight = 2.99792458 * 1e8;
    double kBoltzmannConstant = 1.380649 * 1e-23;

    // Plancks Equation W/m^2*micron
    return ((2 * std::numbers::pi * kPlancksConstant * kSpeedOfLight *
             kSpeedOfLight) /
            (pow(wavelength, 5) *
             (exp((kPlancksConstant * kSpeedOfLight) /
                  (wavelength * kBoltzmannConstant * absolute_temp_)) -
              1))) *
           1e-6;
  };

 private:
  // Defining Private Variable Absolute Temperature
  double absolute_temp_;  // [K]
};
}
