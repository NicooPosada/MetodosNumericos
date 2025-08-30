#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Verificar si la matriz es diagonalmente dominante
bool esDiagonalmenteDominante(const vector<vector<double>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        double suma = 0.0;
        for (int j = 0; j < n; j++) {
            if (i != j) suma += fabs(A[i][j]);
        }
        if (fabs(A[i][i]) < suma) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Ingrese el tamano del sistema (n): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);
    vector<double> X(n, 0.0); // inicializamos X en ceros
    vector<double> Xv(n, 0.0);

    cout << "Ingrese la matriz A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Ingrese el vector b (" << n << " elementos):\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    if (!esDiagonalmenteDominante(A)) {
        cout << "La matriz no es diagonalmente dominante. El metodo podria no converger.\n";
    }

    double tolerancia;
    cout << "Ingrese la tolerancia: ";
    cin >> tolerancia;

    double errorViejo = 1e9;
    double error = 0.0;
    int iter = 0;

    do {
        iter++;
        for (int i = 0; i < n; i++) {
            double suma = 0.0;

            // Usar valores nuevos para j < i
            for (int j = 0; j < i; j++) {
                suma += A[i][j] * X[j];
            }
            // Usar valores viejos para j > i
            for (int j = i + 1; j < n; j++) {
                suma += A[i][j] * Xv[j];
            }

            X[i] = (b[i] - suma) / A[i][i];
        }

        // Calculo del error
        error = 0.0;
        for (int i = 0; i < n; i++) {
            error += pow(X[i] - Xv[i], 2);
        }
        error = sqrt(error);

        if (error > errorViejo) {
            cout << "El metodo no converge.\n";
            return 0;
        }
        errorViejo = error;

        // Actualizamos Xv
        Xv = X;

    } while (error > tolerancia);

    cout << "\nSolucion encontrada en " << iter << " iteraciones:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << X[i] << endl;
    }
    cout << "Error = " << error << endl;

    return 0;
}