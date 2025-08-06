#include <stdio.h>
#include <math.h>
#include <iostream>

double f(double x);

using namespace std;
int main(int argc, char const *argv[])
{
    double a, b, c, error;
    double tole = 1e-6;
    int i = 0;
    printf("Ingrese el inicio del intervalo: ");
    scanf("%lf", &a);
    printf("Ingrese el final del intervalo: ");
    scanf("%lf", &b);

    if (f(a) * f(b) < 0) {
        printf("El intervalo es válido \n");
    } else {
        printf("El intervalo no es válido \n");
        exit(0);
    }
    do {
        c = (a + b) / 2.0;
        error = fabs(f(c)); // Error actual (valor absoluto de f(c))

        printf("Iteración %d: a = %.10lf, b = %.10lf, c = %.10lf, f(c) = %.10lf, error = %.10lf\n",
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
// Desarrollo de la función
double f(double x)
{
    // Ejemplo de función: f(x) = ln(x) + e^(sin(x)) - x
    return log(x) + exp(sin(x)) - x;
}
