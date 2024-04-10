/** Interface file for the function to calculate Plancks Constant
 *
 * \file BlackbodyFit.h
 *
 * \author Anthony Guarino, (ag4933@rit.edu)
 * \date 03 April 2024
 *
 * \copyright Copyright © 2024, Rochester Institute of Technology
 *
 * \version 1.0.0
 *
 * \details
 *    This function, BlackbodyFit, finds a temperature that would be the closest match to a given blackbody
 *
 * \warning
 *      I dont know what I am doing so use this code at your own risk
 *
 */
#ifndef BLACKBODYFIT_H

// Namespace for Radiometry
namespace radiometry {
    double BlackbodyFit(const std::vector<double>& wavelengths, const std::vector<double>& radiances, std::vector<double>& spectral_emissivity, const double& upper_limit, const double& lower_limit, const double& error);
}

#endif
