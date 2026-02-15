#include <iostream>
#include <algorithm>

int main(void) {
  int n;
  int xmin, xmax, ymin, ymax;
  int x, y;
  int result;

  std::cin >> n;
  std::cin >> xmin >> ymin;
  xmax = xmin;
  ymax = ymin;

  for (int i = 0; i < n-1; i++) {
    std::cin >> x >> y;

    xmin = std::min(x, xmin);
    xmax = std::max(x, xmax);
    ymin = std::min(y, ymin);
    ymax = std::max(y, ymax);
  }

  result = (xmax-xmin) * (ymax - ymin);

  std::cout << result;
  
  return 0;
}