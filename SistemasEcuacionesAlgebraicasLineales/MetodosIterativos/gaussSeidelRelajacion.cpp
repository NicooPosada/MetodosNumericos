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
    cout << "Metodo de Gauss-Seidel con Relajacion (SOR)\n";
    cout << "Ingrese el tamano del sistema (n): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n), X(n, 0.0);

    cout << "Ingrese los elementos de la matriz A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Ingrese el vector b (" << n << " elementos):\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    if (!esDiagonalmenteDominante(A)) {
        cout << "⚠️ La matriz no es diagonalmente dominante. El metodo puede no converger.\n";
    }

    double tolerancia, w;
    cout << "Ingrese la tolerancia: ";
    cin >> tolerancia;
    cout << "Ingrese el coeficiente de relajacion w [0,2]: ";
    cin >> w;

    double errorViejo = 1e9, error = 0.0;
    const int MAX_ITER = 10000;
    int iter = 0;

    do {
        iter++;
        vector<double> Xv = X; // guardar valores viejos
        for (int i = 0; i < n; i++) {
            double suma = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) suma += A[i][j] * X[j]; // usar los valores más recientes disponibles
            }
            double xi_gs = (b[i] - suma) / A[i][i]; // Gauss-Seidel estándar
            X[i] = w * xi_gs + (1 - w) * X[i];      // aplicar relajación
        }

        // Calcular error (norma euclídea)
        error = 0.0;
        for (int i = 0; i < n; i++)
            error += pow(X[i] - Xv[i], 2);
        error = sqrt(error);

        if (error > errorViejo) {
            cout << "❌ El metodo no converge (error aumento).\n";
            return 0;
        }
        errorViejo = error;

    } while (error > tolerancia && iter < MAX_ITER);

    // Mostrar resultados
    cout << "\n✅ Solucion encontrada en " << iter << " iteraciones:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << X[i] << endl;
    cout << "Error final = " << error << endl;

    return 0;
}
