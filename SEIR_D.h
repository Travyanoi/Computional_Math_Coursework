#ifndef SIER_D_H
#define SIER_D_H

const double alpha_I = 0.999, alpha_E = 0.999, k = 0.042, ro = 0.952, beta = 0.999,
    mu = 0.0188, c_isol = 0, E_0 = 99, R_0 = 24, g = 0;

double D_function(double I);
double I_function(double E, double I);
double R_function(double E, double I, double R);
double E_function(double S, double E, double I, double N);
double S_function(double S, double E, double I, double R, double N);

double I_with_h(double E, double I, double h);
double R_with_h(double E, double I, double R, double h);
double E_with_h(double S, double E, double I, double N, double h);
double S_with_h(double S, double E, double I, double R, double N, double h);

#endif
