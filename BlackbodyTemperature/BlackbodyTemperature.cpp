#include <iostream>
#include <cmath>
#include <complex>
#include <numbers>

// Include Aggregate Header File - radiometry.h
#include "imgs/radiometry/radiometry.h"

using namespace std;

namespace radiometry {
  // Blackbody Temperature Function
  double BlackbodyTemperature(const double& radiance, const double& wavelength, const double& tolerance) {

      // Create Variables
      double min_temp = 0, max_temp = 6000;
      double middle_temp = (min_temp + max_temp) / 2;
      double range = max_temp - min_temp;

      // Blackbody Object Constructor
      radiometry::Blackbody bb(middle_temp);

      // While loop that runs as long as the range is larger than the allowed tolerance
      while (range > tolerance) {
        if (radiance < bb.Radiance(wavelength)) {
          max_temp = middle_temp;
        }

        else if (radiance > bb.Radiance(wavelength)) {
          min_temp = middle_temp;
        }
        
        // Update variables with new values
        middle_temp = (min_temp + max_temp) / 2;
        range = max_temp - min_temp;
        bb.AbsoluteTemp(middle_temp);
      }
      return middle_temp;
    }
}