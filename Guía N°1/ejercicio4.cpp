#include <stdio.h>
#include <math.h>

int main() {
    double a, b, delta;
    int n;

    printf("Ingrese el valor de a (inicio del intervalo): ");
    if (scanf("%lf", &a) != 1) {
        printf("Entrada inválida para a.\n");
        return 1;
    }

    printf("Ingrese el valor de b (fin del intervalo): ");
    if (scanf("%lf", &b) != 1) {
        printf("Entrada inválida para b.\n");
        return 1;
    }

    printf("Ingrese la tolerancia delta: ");
    if (scanf("%lf", &delta) != 1) {
        printf("Entrada inválida para delta.\n");
        return 1;
    }

    if (delta <= 0 || b <= a) {
        printf("Entrada no válida. Verifique que b > a y delta > 0.\n");
        return 1;
    }

    double n_real = log2((b - a) / delta);
    n = (int)ceil(n_real);

    printf("\nNúmero mínimo de bisecciones necesarias: %d\n", n);

    return 0;
}
