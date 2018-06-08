#include <iostream>
#include <vector>

int getMax(std::vector<int> vec) {
  int max;
  for (int i=0; i<vec.size(); i++) {
    if (vec[i] > max) {
      max = vec[i];
    }
  }
  return max;
}

std::vector<int> radixSort(std::vector<int> vec, int base) {
  std::vector<int> buckets[base];
  int digit;

  for (int placeValue = base; placeValue < getMax(vec); placeValue *= base) {

    // Sort into buckets by digit
    for (int i=0; i<vec.size(); i++) {
      digit = (vec[i] / placeValue) % base;
      buckets[digit].push_back(vec[i]);
    }
    vec.clear();

    // Recombine buckets.
    // In the next run of the while loop, the items will be sorted by the
    // place_value bit, then by the place_value/base bit, etc. 
    for (int i=0; i<base; i++) {
      for (int j=0; j<buckets[i].size(); j++) {
        vec.push_back(buckets[i][j]);
      }

      // Clear the buckets before restarting the main loop
      buckets[i].clear();
    }
  }

  return vec;
}

int main () {
  std::vector<int> vec, sorted_vec;
  int num;  

  do {
    std::cin >> num;
    vec.push_back(num);
  } while (num);
 
  sorted_vec = radixSort(vec, 2);
  for (int i=0; i<sorted_vec.size(); i++) {
    std::cout << sorted_vec[i] << ' ';
  }
  
  std::cout << std::endl;
  return 0;
}

