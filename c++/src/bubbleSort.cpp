#include <iostream>

void swap(int &a, int &b);

template<typename T, size_t N>
constexpr size_t array_size(T (&)[N]) noexcept {
  return N;
}

void bubbleSort(int *arr, int n) {
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      if(arr[j] > arr[j + 1]) {
        // Swap arr[j] and arr[j + 1]
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  // int n = sizeof(arr) / sizeof(arr[0]);
  int n = array_size(arr);
  bubbleSort(arr, n);

  // Print sorted array
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl;

  return 0;
}


