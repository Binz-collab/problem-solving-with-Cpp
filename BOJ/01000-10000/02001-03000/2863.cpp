#include <iostream>
#include <iterator>
#include <algorithm>

int main(void) {
    double a, b, c, d, tmp;
    double s[4];
    double t[4];
    int idx = -1;
    
    std::cin >> a >> b >> c >> d;
    
    for (int i = 0; i < 4; i++) {
        s[i] = a / c + b / d;
        tmp = a;
        a = c;
        c = d;
        d = b;
        b = tmp;
    }
    
    for (int i = 0; i < 4; i++) {
      t[i] = s[i];
    }

    std::sort(t, t+4);

    for (int i = 0; i < 4; i++) {
      // std::cout << t[i];
      if (s[i] == t[3]) {
        idx = i;
      }
    }

    std::cout << idx;
    
    return 0;
}