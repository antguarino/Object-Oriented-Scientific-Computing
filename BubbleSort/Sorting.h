/** Interface file for the function to calculate Plancks Constant
 *
 * \file Sorting.h
 *
 * \author Anthony Guarino, (ag4933@rit.edu)
 * \date 07 March 2024
 *
 * \copyright Copyright © 2024, Rochester Institute of Technology
 *
 * \version 1.0.0
 *
 * \details
 *    This will allow you to sort a vector using a bubble sort algorithm.
 *    You will be able to input a vector and specify if you want it to be
 * ascending or descending.
 *
 *    Template Functions:
 *    BubbleSort(vector, bool);
 *    BubbleSort(vector);
 *
 *
 * \warning
 *      I dont know what I am doing so use this code at your own risk
 *
 */
#include <vector>

// Namespace for sorting
namespace sorting {

class Bubble {
 public:
  // If Bubble Sort function template is not declared as ascending or
  // descending, it will automatically be ascending.
  /*
  template <typename T>
  T BubbleSort(const T& vector) {
    return BubbleSort(vector, true);
  }
*/

  // Bubble Sort function template that takes in a vector and boolean that
  // decides if it is ascending or descending.

  template <typename T>
  std::vector<T> BubbleSort(const std::vector<T>& vector,
                            const bool& ascending) {
    std::vector<T> sorted_vector = vector;
    int length = sorted_vector.size();
    bool swap = true;
    T compare;

    // Only runs if swaps are being made. If none are made, it will end.
    for (int passes = 1; passes < length; passes++) {
      swap = false;
      for (int i = 1; i <= length - passes; i++) {
        // If ascending, it checks if the number is less than the previous and
        // switches.
        if (sorted_vector[i - 1] > sorted_vector[i] && ascending) {
          // Creates a temporary variable to hold on to the number while
          // swapping.
          compare = sorted_vector[i - 1];
          sorted_vector[i - 1] = sorted_vector[i];
          sorted_vector[i] = compare;
          // A switch happened so swap is set back to true so it can keep
          // sorting.
          swap = true;
        }

        // If descending, it checks if the number is greater than the previous
        // and switches.
        else if (sorted_vector[i - 1] < sorted_vector[i] && !ascending) {
          // Creates a temporary variable to hold on to the number while
          // swapping.
          compare = sorted_vector[i - 1];
          sorted_vector[i - 1] = sorted_vector[i];
          sorted_vector[i] = compare;
          // A switch happened so swap is set back to true so it can keep
          // sorting.
          swap = true;
        }
      }

      if (swap == false) {
        return sorted_vector;
      }
    }

    // return the new sorted vector.
    return sorted_vector;
  }
};
}