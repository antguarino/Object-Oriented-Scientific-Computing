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
 *    This will allow you to create a blackbody object with an associated
 * absolute temperature. You can get and set absolute temperature with the
 * AbsoluteTemp() function There are also member functions to calculate
 * Exidence, Spectral Radiance, and Peak Wavelength
 *
 * \warning
 *      I dont know what I am doing so use this code at your own risk
 *
 */
#include <cmath>
#include <numbers>
#include <vector>

// Namespace for Radiometry
namespace radiometry {

class Blackbody {
 public:
  // Empty Blackbody Constructor
  Blackbody() { absolute_temp_ = 0; }

  // Blackbody Constructor takes in Absolute Temperature
  Blackbody(const double& absolute_temp) { absolute_temp_ = absolute_temp; }

  // Temperature Getter
  double AbsoluteTemp() const { return absolute_temp_; };

  // Temperature Setter
  void AbsoluteTemp(const double& absolute_temp) {
    absolute_temp_ = absolute_temp;
  };

  // Member function to calculate radiance by dividing exidence by pi
  const double Radiance(const double& wavelength) const;

  // Member function to find the peak wavelength by dividing the Wein's
  // Displacement Constant by the absolute temp
  const double PeakWavelength() const;

  // Member function to find
  const double Exitance(const double& wavelength) const;

  // Member function to create a vector of Exitance for a given vector of
  // wavelengths
  const std::vector<double> SpectralRadiantExitance(
      std::vector<double> wavelength_vector) const;

  // Member function to create a vector of Radiance for a given vector of
  // wavelengths
  const std::vector<double> SpectralRadiance(
      std::vector<double> wavelength_vector) const;

 private:
  // Defining Private Variable Absolute Temperature
  double absolute_temp_;  // [K]
};
}  // namespace radiometry
