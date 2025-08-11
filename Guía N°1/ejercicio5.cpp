#include <stdio.h>
#include <math.h>

double gamma_value = 5.0 / 3.0;

double eficiencia(double x) {
    double lnx = log(x);
    double term1 = lnx - (1.0 - 1.0 / x);
    double term2 = lnx + (1.0 - 1.0 / x) / (gamma_value - 1.0);
    return term1 / term2 - 0.3;
}

int main() {
    double a = 1.5, b = 10.0, c, error;
    double tol = 1e-5;
    int i = 0;

    if (eficiencia(a) * eficiencia(b) > 0) {
        printf("Intervalo no válido. f(a) = %.6lf, f(b) = %.6lf\n", eficiencia(a), eficiencia(b));
        return 1;
    }

    do {
        c = (a + b) / 2.0;
        error = fabs(eficiencia(c));

        printf("Iteración %d: a = %.6lf, b = %.6lf, c = %.6lf, f(c) = %.6lf\n",
               i, a, b, c, eficiencia(c));

        if (eficiencia(a) * eficiencia(c) < 0)
            b = c;
        else
            a = c;

        i++;
    } while (error > tol);

    printf("\nRelación T2/T1 para eficiencia 30%%: x = %.10lf (en %d iteraciones)\n", c, i);
    return 0;
}
