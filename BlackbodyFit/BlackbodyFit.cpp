#include <iostream>
#include <vector>
#include <algorithm>

// Include Aggregate Header File - radiometry.h
#include "imgs/radiometry/radiometry.h"

namespace radiometry {
    double BlackbodyFit(const std::vector<double>& wavelengths, const std::vector<double>& radiances, std::vector<double>& spectral_emissivity, const double& lower_limit, const double& upper_limit, const double& error) {
        
        // Reverse the order of vector if its not ascending
        std::vector<double> ascending_wavelengths, ascending_radiances;
        ascending_wavelengths.reserve(wavelengths.size());
        ascending_radiances.reserve(radiances.size());
        bool reversed;

        if (wavelengths[0] > wavelengths[wavelengths.size()-1]) {
            for (size_t i = 0; i < wavelengths.size(); i++) {
                ascending_wavelengths.push_back(wavelengths.at(wavelengths.size()-1-i));
                ascending_radiances.push_back(radiances.at(radiances.size()-1-i));
                reversed = true;
            }
        }

        else {
            ascending_wavelengths = wavelengths;
            ascending_radiances = radiances;
        }

        int lower_idx, upper_idx;
        for (size_t i = 0; ascending_wavelengths[i] < lower_limit; i++) {
                lower_idx = i;
        }

        for (size_t i = lower_idx; ascending_wavelengths[i] < upper_limit; i++) {
                upper_idx = i;  
        }

        double increment = 100;
        double estimated_temp = 6000;
        bool negative = false;
        radiometry::Blackbody bb(estimated_temp);
        std::vector<double> blackbody_radiance;

        while (error <= increment) {
            blackbody_radiance = bb.SpectralRadiance(ascending_wavelengths);
            for (int i = lower_idx; i <= upper_idx; i++) {
                if (blackbody_radiance[i] - ascending_radiances[i] < 0) {
                    negative = true;
                }
            }

            if (negative) {
                estimated_temp += increment;
                increment /= 10;
                bb.AbsoluteTemp(estimated_temp);
                
            }

            else {
                estimated_temp -= increment;
                bb.AbsoluteTemp(estimated_temp);
            }
            negative = false;
        }
        
        blackbody_radiance = bb.SpectralRadiance(ascending_wavelengths);
        spectral_emissivity.reserve(ascending_wavelengths.size());

        for (size_t i = 0; i < ascending_wavelengths.size(); i++) {
            spectral_emissivity.push_back(ascending_radiances[i]/blackbody_radiance[i]);

        }

        if (reversed) {
            std::reverse(spectral_emissivity.begin(), spectral_emissivity.end());
        }
        
        return estimated_temp;
    }
}