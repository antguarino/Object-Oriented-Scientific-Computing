#include <iostream>
#include <vector>

// Include Header File - Sorting.h
#include "imgs/numerical/sorting/Sorting.h"

using namespace std;

int main() {
  // Create vector
  vector<double> vector = {11, 4, 1, 8, 3, 3, 7, 0, 9, 5};

  // Print out Original Vector horizontally.
  std::cout << "Original vector ..." << std::endl;
  for (size_t i = 0; i < vector.size(); i++) {
    cout << vector[i] << endl;
  }

  sorting::Bubble bubble_sort;
  std::vector<double> sorted_vector = {};
  // Call the Bubble Sorter and set it to ascending.
  sorted_vector = bubble_sort.BubbleSort(vector, true);
  // Print out sorted values.
  cout << "Sorted vector (ascending) ..." << endl;
  for (size_t i = 0; i < sorted_vector.size(); i++) {
    cout << sorted_vector[i] << endl;
  }

  // Call the Bubble Sorter and set it to descending.
  sorted_vector = bubble_sort.BubbleSort(vector, false);
  // Print out sorted values.
  cout << "Sorted vector (descending) ..." << endl;
  for (size_t i = 0; i < sorted_vector.size(); i++) {
    cout << sorted_vector[i] << endl;
  }
}