#include <stdio.h>
#include <math.h>
#include <iostream>

double f(double x);

using namespace std;
int main(int argc, char const *argv[])
{
    double a, b, c, error;
    double fa, fb, fc;
    double tole = 1e-6;
    int i = 0;

    printf("Ingrese el inicio del intervalo: ");
    scanf("%lf", &a);
    printf("Ingrese el final del intervalo: ");
    scanf("%lf", &b);

    fa = f(a);
    fb = f(b);

    if (fa * fb < 0) {
        printf("El intervalo es válido\n");
    } else {
        printf("El intervalo no es válido\n");
        exit(0);
    }

    do {
        c = (a * fb - b * fa) / (fb - fa); // Fórmula de Regula Falsi
        fc = f(c);
        error = fabs(fc);

        printf("Iteración %d: a = %.10lf, b = %.10lf, c = %.10lf, f(c) = %.10lf, error = %.10lf\n",
               i, a, b, c, fc, error);

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
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
