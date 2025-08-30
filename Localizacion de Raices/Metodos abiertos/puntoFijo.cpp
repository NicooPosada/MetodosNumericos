#include <iostream>
#include <cmath>   // Para fabs()

using namespace std;

// Definir g(x) a mano
double g(double x) {
    // Ejemplo: g(x) = cos(x)
    return cos(x);
}

// Aproximación numérica de la derivada de g(x)
double gp(double x) {
    double h = 0.001;
    return (g(x + h) - g(x)) / h;
}

int main() {
    double x0, x1, error, tol;
    int iter = 0;

    cout << "Metodo de Punto Fijo" << endl;
    cout << "Ingrese valor inicial X0: ";
    cin >> x0;
    cout << "Ingrese la tolerancia: ";
    cin >> tol;

    do {
        iter++;

        // Verificamos condición de convergencia
        if (fabs(gp(x0)) > 1) {
            cout << "El metodo no converge en este punto inicial." << endl;
            return 0;
        }

        x1 = g(x0);                     // Siguiente aproximación
        error = fabs(x1 - x0);          // Error absoluto
        x0 = x1;                        // Actualizamos x0 para la próxima iteración

    } while (error > tol);

    cout << "\nResultado final:" << endl;
    cout << "Raiz aproximada = " << x1 << endl;
    cout << "Error = " << error << endl;
    cout << "Iteraciones = " << iter << endl;

    return 0;
}
