#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool outOfOrder(vector<int> arr, int i) {
  int x = arr[i];

  if (i == 0) {
    return x > arr[i+1];
  }
  if (i == arr.size() - 1) {
    return x < arr[i-1];
  }
  return x > arr[i+1] || x < arr[i-1];
}

pair<int, int> subarraySort(vector<int> arr) {
  int smallest = INT_MAX;
  int largest = INT_MIN;

  for (int i = 0; i < arr.size(); i++) {
    if (outOfOrder(arr, i)) {
      smallest = min(arr[i], smallest);
      largest = max(arr[i], largest);
    }
  }

  int left = 0;
  while (smallest > arr[left]) {
    left++;
  }
  int right = arr.size() - 1;
  while (largest < arr[right]) {
    right--;
  }
  return {left, right};
}

int main(void) {
  vector<int> arr = {1,2,3,4,5,8,6,7,9,10,11};
  auto p = subarraySort(arr);
  cout << p.first << " and " << p.second << endl;

  return 0;
}
