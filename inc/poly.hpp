#ifndef _POLY_HPP_
#define _POLY_HPP_

#include <iostream>
#include <vector>

class Poly
{
    std::vector<double> coeff;
    int poly_degree;
    double range_min;
    double range_max;

    public:
        Poly(std::vector<double>& _coeff, double _range_min, double _range_max);
        Poly derive(void);
        double evaluate(double point);
        std::vector<double> evaluate_vec(std::vector<double> points);
        void print(void);
        std::vector<double> roots(void);

        void set_coeff(const std::vector<double>& _coeff);
        std::vector<double> get_coeff(void);
        void set_range_min(double _range_min);
        double get_range_min(void);
        void set_range_max(double _range_max);
        double get_range_max(void);
        int get_poly_degree(void);

};



#endif /* _POLY_HPP_ */