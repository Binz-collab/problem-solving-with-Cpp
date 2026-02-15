#include <iostream>
#include <vector>

int main(void) {
  int size;
  int n;
  int x, y, z;

  std::cin >> size;
  std::vector<int> a(size);

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> x >> y >> z;
    for (int j = x-1; j < y; j++) {
      a[j] = z;
    }
  }

  for (int i = 0; i < size; i++) {
    std::cout << a[i] << ' ';
  }
  
  return 0;
}