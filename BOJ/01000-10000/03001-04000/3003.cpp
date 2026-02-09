#include <iostream>
#include <iterator>

int main(void) {
    int a[] = {1, 1, 2, 2, 2, 8};
    int n;
    
    for(int i = 0; i < std::size(a); i++) {
        std::cin >> n;
        std::cout << a[i] - n << ' ';
    }
        
    return 0;
}