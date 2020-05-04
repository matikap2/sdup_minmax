#include <iostream>
#include <vector>
#include <string>
#include "poly.hpp"

int main()
{
    std::vector<double> p_coeff {4.0, 3.0, -2.0, 1};
    Poly p(p_coeff, -1.0, 0.5);

    std::cout << "SDUP MinMax behavioral!" << std::endl << std::endl;
    std::cout << "Input polynomial 3rd degree:" << std::endl;
    p.print();

    std::cout << "Derived input polynomial:" << std::endl;
    Poly p_derived = p.derive();
    p_derived.print();

    std::cout << "Calulating derived polynomial roots..." << std::endl;
    std::vector<double> q_roots = p_derived.roots();

    std::vector<double> points = q_roots;
    points.push_back(p_derived.get_range_max());
    points.push_back(p_derived.get_range_min());

    std::cout << "Evaluating values of original poly in roots and range ends..." << std::endl;
    std::vector<double> evaluated_extrema = p.evaluate_vec(points);

    std::cout << "Caluclated values in points: ";
    for (auto j : evaluated_extrema)
    {
        std::cout << j << " ";
    }
    std::cout << std::endl;

    std::cout << "Local minimum: " << *std::min_element(evaluated_extrema.begin(), evaluated_extrema.end()) << std::endl;
    std::cout << "Local maximum: " << *std::max_element(evaluated_extrema.begin(), evaluated_extrema.end()) << std::endl;
    
    return 0; 
}