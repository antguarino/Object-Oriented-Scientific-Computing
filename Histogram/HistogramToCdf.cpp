/** Implementation file for computing a CDF from a histogram
 *
 *  \file ipcv/utils/HistogramToCdf.cpp
 *  \author Carl Salvaggio, Ph.D. (salvaggio@cis.rit.edu)
 *  \date 17 Mar 2018
 * 
 *  \author Anthony Guarino (ag4933@rit.edu)
 *  \date 25 April 2024
 */

#include "HistogramToCdf.h"

#include "imgs/ipcv/utils/HistogramToPdf.h"

#include <opencv2/opencv.hpp>

namespace ipcv {

void HistogramToCdf(const cv::Mat& h, cv::Mat& cdf) {
  cv::Mat pdf;
  ipcv::HistogramToPdf(h, pdf);

  cdf.create(h.size(), CV_64F);

  for (int c = 0; c < 3; ++c) {
        double total = cv::sum(h.row(c))[0];
        double cumulative = 0;

        for (int i = 0; i < 256; ++i) {
            double count = static_cast<double>(h.at<int>(c, i));
            double pdf = count / total;

            cumulative += pdf;
            cdf.at<double>(c, i) = cumulative;
        }

}
}
}

