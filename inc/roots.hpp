#ifndef _ROOTS_HPP_
#define _ROOTS_HPP_

#include <vector>
#include <iostream>

std::vector<double> roots_linear(std::vector<double> coeffs, double min, double max);
std::vector<double> roots_quadratic(std::vector<double> coeffs, double min, double max);

#endif /* _ROOTS_HPP_ */