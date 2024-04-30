/** Implementation file for computing the PDF from a histogram
 *
 *  \file ipcv/utils/HistogramToPdf.cpp
 *  \author Carl Salvaggio, Ph.D. (salvaggio@cis.rit.edu)
 *  \date 17 Mar 2018
 * 
 *  \author Anthony Guarino (ag4933@rit.edu)
 *  \date 25 April 2024
 */

#include "HistogramToPdf.h"

namespace ipcv {

void HistogramToPdf(const cv::Mat& h, cv::Mat& pdf) {
  pdf.create(h.size(), CV_64F);

  cv::normalize(h, pdf, 0.009, 0, cv::NORM_INF, CV_64F);
}
}
