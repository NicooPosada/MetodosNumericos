#include <stdio.h>
#include <math.h>
#include <iostream>

double f(double x);

using namespace std;
int main(int argc, char const *argv[])
{
    double a, b, c, error;
    double tole = exp(1e-6); // Tolerance for the method
    int i = 0;
    printf("Ingrrese el inicio del intervalo");
    scanf("%lf", &a);
    printf("Ingrese el final del intervalo");
    scanf("%lf", &b);
    if (f(a) * f(b) < 0) {
        printf("El intervalo es valido\n");
    }else {
        printf("El intervalo no es valido\n");
        exit (0)
    }
    do {

    }while(error > tole);
    
    return 0;
}
//Desarroollo de la funcion


double f(double x)
{
    // Example function: f(x) = x^2 - 4
    return log(x)+ exp(sin(x)) - x;
}
