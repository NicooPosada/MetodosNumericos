#include <stdio.h>
#include <math.h>

double g = 9.81;
double c = 14.0;
double t = 7.0;

double f(double m) {
    return (g * m / c) * (1 - exp(-c * t / m)) - 35.0;
}

int main() {
    double a = 30.0, b = 90.0, c, error;
    double tol = 1e-5;
    int i = 0;

    if (f(a) * f(b) > 0) {
        printf("Intervalo no válido\n");
        return 1;
    }

    do {
        c = (a + b) / 2.0;
        error = fabs(f(c));

        printf("Iteración %d: a = %.6lf, b = %.6lf, c = %.6lf, f(c) = %.6lf\n",
               i, a, b, c, f(c));

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        i++;
    } while (error > tol);

    printf("\nMasa encontrada por bisección: %.10lf kg en %d iteraciones\n", c, i);
    return 0;
}
