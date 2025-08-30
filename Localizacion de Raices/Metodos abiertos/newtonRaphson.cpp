#include <iostream>
#include <cmath>  // fabs()

using namespace std;

// Definir f(x)
double f(double x) {
    // Ejemplo: f(x) = x^2 - 2
    return x*x - 2;
}

// Definir f'(x) (opción tradicional)
double fprima(double x) {
    // Ejemplo: derivada de x^2 - 2 = 2x
    return 2*x;
}

// Alternativa: derivada numérica
double fprima_numerica(double x) {
    double h = 0.001;
    return (f(x + h) - f(x)) / h;
}

int main() {
    double x0, xi, error, tol;
    int iter = 0;
    const int MAX_ITER = 10000;

    cout << "Metodo de Newton-Raphson" << endl;
    cout << "Ingrese valor inicial X0: ";
    cin >> x0;
    cout << "Ingrese tolerancia: ";
    cin >> tol;

    do {
        iter++;

        double derivada = fprima(x0);  // Podés usar fprima_numerica(x0) si no tenés f'

        if (fabs(derivada) < 1e-4) {
            cout << "Error: Derivada muy pequena en x = " << x0 << endl;
            return 0;
        }

        xi = x0 - f(x0) / derivada;   // Formula de Newton-Raphson
        error = fabs(xi - x0);        // Error absoluto
        x0 = xi;                      // Actualizamos

    } while (error > tol && iter < MAX_ITER);

    cout << "\nResultado final:" << endl;
    cout << "Raiz aproximada = " << xi << endl;
    cout << "Iteraciones = " << iter << endl;
    cout << "Error = " << error << endl;
    cout << "f(x) en la raiz = " << f(xi) << endl;

    if (fabs(f(xi)) < tol)
        cout << "La solucion es valida (f(x) cerca de cero)" << endl;
    else
        cout << "Advertencia: f(x) no esta lo suficientemente cerca de cero" << endl;

    return 0;
}
