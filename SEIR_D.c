#include <stdio.h>
#include <math.h>
#include "SEIR_D.h"

int main()
{
    int t_0 = 0, T = 90, h = 1;
    int delta_T = T - t_0;
    int n = (delta_T / h) + 1;
    double S[n], E[n], I[n], R[n], D[n], N[n], t[n];
    t[0] = t_0;
    D[0] = 0;
    R[0] = R_0;
    I[0] = 0;
    E[0] = E_0;
    S[0] = 2798170 - E[0] - R[0];

    N[0] = S[0] + E[0] + I[0] + R[0] + D[0];
    printf("N[0] = %.2lf S[0] = %.2lf E[0] = %.2lf I[0] = %.2lf R[0] = %.2lf D[0] = %.2lf\n", N[0], S[0], E[0], I[0], R[0], D[0]);
    for(int i = 1; i < n; i++){
        t[i] = t_0 + i * h;
        D[i] = D[i - 1] + D_function(I[i - 1]);
        I[i] = I[i - 1] + I_with_h(E[i - 1], I[i - 1], h);
        R[i] = R[i - 1] + R_with_h(E[i - 1], I[i - 1], R[i - 1], h);
        E[i] = E[i - 1] + E_with_h(S[i - 1], E[i - 1], I[i - 1], N[i - 1], h);
        S[i] = S[i - 1] + S_with_h(S[i - 1], E[i - 1], I[i - 1], R[i - 1], N[i - 1], h);
        N[i] = D[i] + I[i] + R[i] + E[i] + S[i];
        printf("N[%d] = %.2lf\t S[%d] = %.2lf\t E[%d] = %.2lf\t I[%d] = %.2lf\t R[%d] = %.2lf\t D[%d] = %.2lf\n", i, N[i], i, S[i], i, E[i], i, I[i], i, R[i], i, D[i]);
    }
  
    FILE* file_D = fopen("Data/D.txt", "w");
    FILE* file_I = fopen("Data/I.txt", "w");
    FILE* file_R = fopen("Data/R.txt", "w");
    FILE* file_E = fopen("Data/E.txt", "w");
    FILE* file_S = fopen("Data/S.txt", "w");
    FILE* file_N = fopen("Data/N.txt", "w");
    for(int i = 0; i < n; i++) {  
        fprintf(file_D, "%.0lf %.2lf\n", t[i], D[i]);
        fprintf(file_I, "%.0lf %.2lf\n", t[i], I[i]);
        fprintf(file_R, "%.0lf %.2lf\n", t[i], R[i]);
        fprintf(file_E, "%.0lf %.2lf\n", t[i], E[i]);
        fprintf(file_S, "%.0lf %.2lf\n", t[i], S[i]);
        fprintf(file_N, "%.0lf %.2lf\n", t[i], N[i]);
    }
    fclose(file_D);
    fclose(file_I);
    fclose(file_R);
    fclose(file_E);
    fclose(file_S);
    fclose(file_N);

    return 0;
}

double D_function(double I){
    double answer = mu * I;
    return answer;
}

double I_function(double E, double I){
    double answer = (k * E) - (beta * I) - (mu * I);
    return answer;
}

double R_function(double E, double I, double R){
    double answer = (beta * I) + (ro * E) - (g * R);
    return answer;
}

double E_function(double S, double E, double I, double N){
   double answer = (1 * S) * ((alpha_I * I) / N + (alpha_E * E) / N) - (k + ro) * E;
   return answer;
}

double S_function(double S, double E, double I, double R, double N){
    double answer = (-1 * S) * ((alpha_I * I) / N + (alpha_E * E) / N) + g * R;
    return answer;
}

double I_with_h(double E, double I, double h){
    double answer = h * I_function(E, I + h / 2 * I_function(E, I));
    return answer;
}

double R_with_h(double E, double I, double R, double h){
    double answer = h * R_function(E, I, R + h / 2 * R_function(E, I, R));
    return answer;
}

double E_with_h(double S, double E, double I, double N, double h){
    double answer = h * E_function(S, (E + h) / (2 * E_function(S, E, I, N)), I, N);
    return answer;
}

double S_with_h(double S, double E, double I, double R, double N, double h){
    double answer = h * S_function((S + h) / (2 * S_function(S, E, I, R, N)), E, I, R, N);
    return answer;
}
