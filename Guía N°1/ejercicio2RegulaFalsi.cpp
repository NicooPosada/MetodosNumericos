#include <stdio.h>
#include <math.h>
#include <vector>

double g(double a) {
    return pow(a, 10) - 1;
}

int main() {
    double a = 0.5, b = 1.5, c, fa, fb, fc, error;
    double tol = 1e-5;
    int i = 0;

    std::vector<double> errores_falsi;

    fa = g(a);
    fb = g(b);

    if (fa * fb > 0) {
        printf("Intervalo no válido\n");
        return 1;
    }

    do {
        c = (a * fb - b * fa) / (fb - fa);  // Fórmula de Regula Falsi
        fc = g(c);
        error = fabs(fc);
        errores_falsi.push_back(error);

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }

        i++;
    } while (error > tol);

    printf("Raíz encontrada (regula falsi): %.10lf en %d iteraciones\n", c, i);

    // Guardar errores para graficar
    FILE *fr = fopen("errores_falsi.txt", "w");
    for (int j = 0; j < errores_falsi.size(); j++) {
        fprintf(fr, "%d\t%.10e\n", j + 1, errores_falsi[j]);
    }
    fclose(fr);

    return 0;
}
