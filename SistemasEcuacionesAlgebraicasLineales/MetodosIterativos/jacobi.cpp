#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Verificar si una matriz es diagonalmente dominante
bool esDiagonalmenteDominante(const vector<vector<double>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        double suma = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) suma += fabs(A[i][j]);
        }
        if (fabs(A[i][i]) < suma) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Metodo de Jacobi\n";
    cout << "Ingrese el tamano de la matriz (n): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);
    vector<double> Xv(n, 0.0), Xn(n, 0.0);

    // Ingreso de la matriz A
    cout << "Ingrese los elementos de la matriz A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Ingreso del vector b
    cout << "Ingrese los elementos del vector b (" << n << "):\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Verificar diagonalmente dominante
    if (!esDiagonalmenteDominante(A)) {
        cout << "Advertencia: La matriz NO es diagonalmente dominante." << endl;
        cout << "El metodo puede no converger." << endl;
    }

    // Parámetros del método
    double tol;
    cout << "Ingrese la tolerancia: ";
    cin >> tol;

    double errorViejo = 1000.0;
    double error = 0.0;
    int iter = 0;
    const int MAX_ITER = 10000;

    do {
        iter++;
        // Calcular nueva aproximacion
        for (int i = 0; i < n; i++) {
            double suma = 0;
            for (int j = 0; j < n; j++) {
                if (j != i) suma += A[i][j] * Xv[j];
            }
            Xn[i] = (b[i] - suma) / A[i][i];
        }

        // Calcular error
        error = 0;
        for (int i = 0; i < n; i++) {
            error += pow(Xn[i] - Xv[i], 2);
        }
        error = sqrt(error);

        if (error > errorViejo) {
            cout << "El metodo no converge (el error aumento)." << endl;
            return 0;
        }

        errorViejo = error;

        // Actualizar Xv
        for (int i = 0; i < n; i++) {
            Xv[i] = Xn[i];
        }

    } while (error > tol && iter < MAX_ITER);

    // Mostrar resultados
    cout << "\nSolucion aproximada:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << Xn[i] << endl;
    }
    cout << "Error final = " << error << endl;
    cout << "Iteraciones = " << iter << endl;

    return 0;
}
