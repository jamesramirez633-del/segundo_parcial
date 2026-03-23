#include <iostream>
using namespace std;


void registrar(string nombres[], float notas[], int& cantidad) {
    cout << "Ingrese la cantidad de estudiantes (max 20): ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante #" << i + 1 << endl;
        cout << "Nombre: ";
        cin >> nombres[i];
        cout << "Nota (0-100): ";
        cin >> notas[i];
    }
}

float calcularPromedio(float notas[], int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += notas[i];
    }
    return suma / cantidad;
}

float notaMayor(float notas[], int cantidad) {
    float mayor = notas[0];
    for (int i = 1; i < cantidad; i++) {
        if (notas[i] > mayor) {
            mayor = notas[i];
        }
    }
    return mayor;
}


float notaMenor(float notas[], int cantidad) {
    float menor = notas[0];
    for (int i = 1; i < cantidad; i++) {
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }
    return menor;
}


void mostrarAprobados(string nombres[], float notas[], int cantidad) {
    cout << "\nEstudiantes aprobados (>=70):\n";
    for (int i = 0; i < cantidad; i++) {
        if (notas[i] >= 70) {
            cout << nombres[i] << " - " << notas[i] << endl;
        }
    }
}

int main() {
    string nombres[20];
    float notas[20];
    int cantidad = 0;
    int opcion;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Registrar estudiantes\n";
        cout << "2. Mostrar promedio\n";
        cout << "3. Mostrar nota mas alta\n";
        cout << "4. Mostrar nota mas baja\n";
        cout << "5. Mostrar aprobados\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            registrar(nombres, notas, cantidad);
            break;
        case 2:
            if (cantidad > 0)
                cout << "Promedio: " << calcularPromedio(notas, cantidad) << endl;
            else
                cout << "Primero registre estudiantes.\n";
            break;
        case 3:
            if (cantidad > 0)
                cout << "Nota mas alta: " << notaMayor(notas, cantidad) << endl;
            else
                cout << "Primero registre estudiantes.\n";
            break;
        case 4:
            if (cantidad > 0)
                cout << "Nota mas baja: " << notaMenor(notas, cantidad) << endl;
            else
                cout << "Primero registre estudiantes.\n";
            break;
        case 5:
            if (cantidad > 0)
                mostrarAprobados(nombres, notas, cantidad);
            else
                cout << "Primero registre estudiantes.\n";
            break;
        case 6:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);

    return 0;
}