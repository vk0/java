// Для каждого данного ε найдите соответствующие номера N, что при всех n⩾N верно неравенство ∣∣∣(2n−1/n+2)−2∣∣∣<ε. В ответе приведите числа, разделенные пробелами, ε=10^−1, ε=10^−3 и ε=10^−6.
// 49 4999 4999999

#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double x = 0.0;
    size_t a[3] = {};
    double e1 = pow(10, -1),
           e2 = pow(10, -3),
           e3 = pow(10, -6);
    //std::cout << e1 << " " << e2 << " " << e3 << "\n";
    for (size_t n = 1; n < 5000000; ++n) {
        x = ((2.0 * n - 1.0) / (n + 2.0) - 2.0) * (-1.0);
        //std::cout << std::setprecision(4) << x << ";";
        if (x < e1 && a[0] == 0)
            a[0] = n;
        if (x < e2 && a[1] == 0)
            a[1] = n;
        if (x < e3 && a[2] == 0)
            a[2] = n;
    }
    //std::cout << std::endl;
    std::cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    return 0;
}