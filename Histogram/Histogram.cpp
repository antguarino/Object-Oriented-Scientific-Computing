/** Implementation file for computing an image histogram
 *
 *  \file ipcv/utils/Histogram.cpp
 *  \author Carl Salvaggio, Ph.D. (salvaggio@cis.rit.edu)
 *  \date 17 Mar 2018
 * 
 *  \author Anthony Guarino (ag4933@rit.edu)
 *  \date 25 April 2024
 */

#include "Histogram.h"

namespace ipcv {

void Histogram(const cv::Mat& src, cv::Mat& h) {
  h = cv::Mat_<int>::zeros(3, 256);

  for (int i = 0; i < 3; i++) {
    for (int row = 0; row < src.rows; row++) {
      for (int col = 0; col < src.cols; col++) {
          int value = src.at<cv::Vec3b>(row, col)[i];
          h.at<int>(i, value)++;
      }
    }
  }

}
}
