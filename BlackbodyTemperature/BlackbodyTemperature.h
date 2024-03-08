/** Interface file for the function to calculate Plancks Constant
 *
 * \file BlackbodyTemperature.h
 *
 * \author Anthony Guarino, (ag4933@rit.edu)
 * \date 01 March 2024
 *
 * \copyright Copyright © 2024, Rochester Institute of Technology
 *
 * \version 1.0.0
 *
 * \details
 *    This creates a single function that will compute the temperature of a blackbody, given a radiance, wavelength, and tolerance
 *
 * \warning
 *      I dont know what I am doing so use this code at your own risk
 *
 */
#include <cmath>
#include <numbers>

// Namespace for Radiometry
namespace radiometry {
  // Blackbody Temperature Function
  double BlackbodyTemperature(const double& radiance, const double& wavelength, const double& tolerance);
}
