// Найдите число членов последовательности x_n=(2n−1/4n+5), лежащих вне интервала (1/2−1/1000,1/2+1/1000).
// 873:0.4989991421

#include <iostream>
#include <iomanip>

int main() {
    double x = 0.0;
    for (int n = 1; n < 1000; ++n) {
        x = (double)(2*n-1)/(4*n+5);
        if (x < 0.499 || x > 0.501)
            std::cout << n << ":"
                  << std::setprecision(10) << x << "\n";
    }
    return 0;
}