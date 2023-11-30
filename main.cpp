#include <iostream>
#include <algorithm>

int euclidGCD(int m, int n) {
    while (m != n) {
        if (m < n) {
            std::swap(m, n);
        }
        m = m - n;
    }
    return m;
}

int euclidGCDmod(int m, int n) {
    while (n != 0) {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int extendedEuclidGCD(int m, int n, int& x, int& y) {
    int x1 = 0, y1 = 1, x0 = 1, y0 = 0;
    while (n != 0) {
        int q = m / n;
        int r = m % n;
        m = n;
        n = r;
        int temp = x1;
        x1 = x0 - q * x1;
        x0 = temp;
        temp = y1;
        y1 = y0 - q * y1;
        y0 = temp;
    }
    x = x0;
    y = y0;
    return m;
}

int main() {
    int m, n;
    std::cout << "Enter the value of m: ";
    std::cin >> m;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    std::cout<<"----------------------------"<< std::endl;

    int gcd = euclidGCD(m, n);
    std::cout << "Euclidean GCD of " << m << " and " << n << " is: " << gcd << std::endl;
    std::cout<<"----------------------------"<< std::endl;

    int gcdAlt = euclidGCDmod(m, n);
    std::cout << "Modulo Euclidean GCD of " << m << " and " << n << " is: " << gcdAlt << std::endl;
    std::cout<<"----------------------------"<< std::endl;

    int x, y;
    int extendedGCD = extendedEuclidGCD(m, n, x, y);
    std::cout << "Extended Euclidean GCD of " << m << " and " << n << " is: " << extendedGCD << std::endl;
    std::cout << "Coefficients (x, y): " << x << ", " << y << std::endl;
    std::cout<<"----------------------------"<< std::endl;

    return 0;
}
