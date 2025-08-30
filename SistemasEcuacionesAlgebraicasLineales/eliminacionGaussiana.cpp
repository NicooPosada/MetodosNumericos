#include <iostream>
#include <cmath>   // fabs()
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Metodo de Eliminacion Gaussiana con Pivoteo Parcial\n";
    cout << "Ingrese el tamano de la matriz (n): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n), x(n);

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

    // Eliminacion Gaussiana
    for (int i = 0; i < n - 1; i++) {
        // --- Pivoteo parcial ---
        int p = i;
        if (fabs(A[i][i]) < 1e-2) {
            for (int l = i + 1; l < n; l++) {
                if (fabs(A[l][i]) > fabs(A[p][i])) {
                    p = l;
                }
            }
            if (p != i) {
                // Intercambio de filas en A
                for (int m = i; m < n; m++) {
                    double aux = A[p][m];
                    A[p][m] = A[i][m];
                    A[i][m] = aux;
                }
                // Intercambio en b
                double aux = b[p];
                b[p] = b[i];
                b[i] = aux;
            }
        }

        // --- Eliminacion hacia adelante ---
        for (int j = i + 1; j < n; j++) {
            double factor = -A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] = A[i][k] * factor + A[j][k];
            }
            b[j] = b[i] * factor + b[j];
        }
    }

    // Imprimir matriz triangular superior
    cout << "\nMatriz triangular superior (A):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << "\t";
        }
        cout << "| " << b[i] << endl;
    }

    // Chequear determinante
    double det = 1;
    for (int i = 0; i < n; i++) {
        det *= A[i][i];
    }
    if (fabs(det) < 1e-12) {
        cout << "La matriz tiene determinante cero. No se puede resolver." << endl;
        return 0;
    }

    // Sustitucion hacia atras
    x[n - 1] = b[n - 1] / A[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        double suma = b[i];
        for (int j = i + 1; j < n; j++) {
            suma -= A[i][j] * x[j];
        }
        x[i] = suma / A[i][i];
    }

    // Mostrar resultados
    cout << "\nSolucion del sistema:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
