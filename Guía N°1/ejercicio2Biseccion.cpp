#include <stdio.h>
#include <math.h>
#include <vector>

double g(double a) {
    return pow(a, 10) - 1;
}

int main() {
    double a = 0.5, b = 1.5, c, error;
    double tol = 1e-5;
    int i = 0;

    std::vector<double> errores_biseccion;

    if (g(a) * g(b) > 0) {
        printf("Intervalo no válido\n");
        return 1;
    }

    do {
        c = (a + b) / 2.0;
        error = fabs(g(c));
        errores_biseccion.push_back(error);

        if (g(a) * g(c) < 0) {
            b = c;
        } else {
            a = c;
        }

        i++;
    } while (error > tol);

    printf("Raíz encontrada (bisección): %.10lf en %d iteraciones\n", c, i);

    // Guardar errores para graficar
    FILE *fb = fopen("errores_biseccion.txt", "w");
    for (int j = 0; j < errores_biseccion.size(); j++) {
        fprintf(fb, "%d\t%.10e\n", j + 1, errores_biseccion[j]);
    }
    fclose(fb);

    return 0;
}
