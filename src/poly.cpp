#include <cmath>
#include "poly.hpp"
#include "roots.hpp"

Poly::Poly(std::vector<double>& _coeff, double _range_min, double _range_max)
{
    range_max = _range_max;
    range_min = _range_min;
    poly_degree = _coeff.size() - 1;

    for (auto i : _coeff)
    {
        coeff.push_back(i);
    }
}

void Poly::print(void)
{
    std::cout << "Coeffs: [ ";

    for (auto i : coeff)
    {
        std::cout << i << " ";
    }

    std::cout << "]" << std::endl;
    std::cout << "Range: (" << range_min << ";" << range_max << ")" << std::endl;
    std::cout << "Poly degree: " << poly_degree << std::endl;
}

Poly Poly::derive(void)
{
    std::vector<double> derived_coeff;

    for (int i = 0; i < poly_degree; i++)
    {
        derived_coeff.push_back(coeff[i] * (poly_degree - i));
    }

    Poly ret(derived_coeff, range_min, range_max);
    return ret;
}

double Poly::evaluate(double point)
{
    double value = 0.0;

    for (int i = 0; i < coeff.size(); i++)
    {
        if (i != 0 && coeff[i] >= 0.0)
        {
            std::cout << "+";
        }
        std::cout << coeff[i] << "x^" << poly_degree - i;
        value += coeff[i] * pow(point, poly_degree - i);
    }
    std::cout << " [x = " << point << "] = " << value << std::endl;

    return value;
}

std::vector<double> Poly::evaluate_vec(std::vector<double> points)
{
    std::vector<double> ret;
    double value = 0.0;

    for (auto point : points)
    {
        value = 0.0;
        for (int i = 0; i < coeff.size(); i++)
        {
            if (i != 0 && coeff[i] >= 0.0)
            {
                std::cout << "+";
            }
            std::cout << coeff[i] << "x^" << poly_degree - i;
            value += coeff[i] * pow(point, poly_degree - i);
        }
        std::cout << " [x = " << point << "] = " << value << std::endl;
        ret.push_back(value);
    }

    return ret;
}

std::vector<double> Poly::roots(void)
{
    switch(poly_degree)
    {
        case 0:
            return std::vector<double>();

        case 1:
            return roots_linear(coeff);

        case 2:
            return roots_quadratic(coeff);

        default:
            std::cout << "Evaluating other function roots than poly 0, 1st, 2nd degree is not available!" << std::endl;
            return std::vector<double>();
    }
}  

void Poly::set_coeff(const std::vector<double>& _coeff)
{
    coeff = _coeff;
    poly_degree = _coeff.size() - 1;
}  

std::vector<double> Poly::get_coeff(void)
{
    return coeff;
}  

void Poly::set_range_min(double _range_min)
{
    range_min = _range_min;
}  

double Poly::get_range_min(void)
{
    return range_min;
}  

void Poly::set_range_max(double _range_max)
{
    range_max = _range_max;
}  

double Poly::get_range_max(void)
{
    return range_max;
}  

int Poly::get_poly_degree(void)
{
    return poly_degree;
}  
