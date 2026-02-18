// 웰컴 키트

#include <iostream>
#include <vector>

int main(void) {
  int total, tmp, input;
  int T, P;
  int bundle_T = 0;
  int bundle_P = 0;
  int ea_P = 0;
  std::vector<int> a;

  std::cin >> total;

  for (int i = 0; i < 6; i++) {
    std::cin >> input;
    a.push_back(input);
  }

  std::cin >> T >> P;

  for (int i = 0; i < a.size(); i++) {
    bundle_T = bundle_T + (a[i] - 1 + T) / T;
  }

  bundle_P = total / P;
  ea_P = total % P;

  std::cout << bundle_T << '\n' << bundle_P << ' ' << ea_P;

  return 0;
}