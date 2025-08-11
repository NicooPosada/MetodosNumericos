#include <stdio.h>
#include <math.h>

double g = 9.81;
double c = 14.0;
double t = 7.0;

double f(double m) {
    return (g * m / c) * (1 - exp(-c * t / m)) - 35.0;
}

int main() {
    double a = 30.0, b = 90.0, m, fa, fb, fm, error;
    double tol = 1e-5;
    int i = 0;

    fa = f(a);
    fb = f(b);

    if (fa * fb > 0) {
        printf("Intervalo no válido\n");
        return 1;
    }

    do {
        m = (a * fb - b * fa) / (fb - fa);
        fm = f(m);
        error = fabs(fm);

        printf("Iteración %d: a = %.6lf, b = %.6lf, m = %.6lf, f(m) = %.6lf\n",
               i, a, b, m, fm);

        if (fa * fm < 0) {
            b = m;
            fb = fm;
        } else {
            a = m;
            fa = fm;
        }

        i++;
    } while (error > tol);

    printf("\nMasa encontrada por regula falsi: %.10lf kg en %d iteraciones\n", m, i);
    return 0;
}
