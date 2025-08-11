#include <stdio.h>
#include <math.h>
#include <iostream>

double f(double x) {
    return -2 + 7*x - 5*x*x + 6*x*x*x;
}

int main() {
    double a = 0.0, b = 1.0, c, error;
    double tole = 1e-4;
    int i = 0;

    if (f(a) * f(b) < 0) {
        printf("El intervalo es válido\n");
    } else {
        printf("El intervalo no es válido\n");
        return 1;
    }

    do {
        c = (a + b) / 2.0;
        error = fabs(f(c));

        printf("Iteración %d: a = %.6lf, b = %.6lf, c = %.6lf, f(c) = %.6lf, error = %.6lf\n",
               i, a, b, c, f(c), error);

        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        i++;
    } while (error > tole);

    printf("\nLa raíz aproximada es: %.10lf\n", c);
    return 0;
}
