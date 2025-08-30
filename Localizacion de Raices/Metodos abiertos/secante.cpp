#include <iostream>
#include <cmath> // fabs()

using namespace std;

// Definir f(x)
double f(double x) {
    // Ejemplo: f(x) = x^2 - 2
    return x*x - 2;
}

int main() {
    double x0, x1, x2, error, tol;
    int iter = 0;
    const int MAX_ITER = 10000;

    cout << "Metodo de la Secante" << endl;
    cout << "Ingrese valor inicial X0: ";
    cin >> x0;
    cout << "Ingrese valor inicial X1: ";
    cin >> x1;
    cout << "Ingrese la tolerancia: ";
    cin >> tol;

    do {
        iter++;

        double fx0 = f(x0);
        double fx1 = f(x1);

        if (fabs(fx1 - fx0) < 1e-10) {
            cout << "Error: Division por cero en el metodo de la secante." << endl;
            return 0;
        }

        // Formula de la secante
        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);

        error = fabs(x2 - x1);

        // Actualizamos valores
        x0 = x1;
        x1 = x2;

    } while (error > tol && iter < MAX_ITER);

    cout << "\nResultado final:" << endl;
    cout << "Raiz aproximada = " << x2 << endl;
    cout << "Iteraciones = " << iter << endl;
    cout << "Error = " << error << endl;
    cout << "f(x) en la raiz = " << f(x2) << endl;

    if (fabs(f(x2)) < tol)
        cout << "La solucion es valida (f(x) cerca de cero)" << endl;
    else
        cout << "Advertencia: f(x) no esta lo suficientemente cerca de cero" << endl;

    return 0;
}
