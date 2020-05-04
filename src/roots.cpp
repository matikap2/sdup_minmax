#include <iostream>
#include <vector>
#include <cmath>

#include "roots.hpp"

std::vector<double> roots_linear(std::vector<double> coeffs)
{
    std::vector<double> ret;

    ret.push_back(-coeffs[1]/coeffs[0]);
    std::cout << "Root: " << ret[0] << std::endl;

    return ret;
}

std::vector<double> roots_quadratic(std::vector<double> coeffs)
{
    std::vector<double> ret;
    double delta = pow(coeffs[1], 2) - 4 * coeffs[0] * coeffs[2];
    double sqrt_delta = sqrt(delta);

    if (delta > 0.0)
    {
        ret.push_back((-coeffs[1] - sqrt_delta) / (2 * coeffs[0]));
        ret.push_back((-coeffs[1] + sqrt_delta) / (2 * coeffs[0]));
    }
    else if (delta == 0.0)
    {
        ret.push_back((-coeffs[1]) / (2 * coeffs[0]));
    }

    std::cout << "Roots: ";
    for (auto i : ret)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return ret;
}