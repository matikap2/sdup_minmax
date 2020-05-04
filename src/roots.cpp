#include <iostream>
#include <vector>
#include <cmath>

#include "roots.hpp"

std::vector<double> roots_linear(std::vector<double> coeffs, double min, double max)
{
    std::vector<double> ret;
    double root = -coeffs[1]/coeffs[0];

    if (root >= min && root <= max)
    {
        ret.push_back(root);
    }
    
    std::cout << "Roots: ";
    for (auto i : ret)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return ret;
}

std::vector<double> roots_quadratic(std::vector<double> coeffs, double min, double max)
{
    std::vector<double> ret;
    double delta = pow(coeffs[1], 2) - 4 * coeffs[0] * coeffs[2];
    double sqrt_delta = sqrt(delta);
    double root;

    if (delta > 0.0)
    {
        root = (-coeffs[1] - sqrt_delta) / (2 * coeffs[0]);
        if (root >= min && root <= max)
        {
            ret.push_back(root);
        }
        
        root= (-coeffs[1] + sqrt_delta) / (2 * coeffs[0]);
        if (root >= min && root <= max)
        {
            ret.push_back(root);
        }
    }
    else if (delta == 0.0)
    {
        root = (-coeffs[1]) / (2 * coeffs[0]);
        if (root >= min && root <= max)
        {
            ret.push_back(root);
        }
    }

    std::cout << "Roots: ";
    for (auto i : ret)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return ret;
}