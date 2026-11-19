#include <iostream>
#include <iomanip> // Para usar setprecision
#include <cstdlib> // Para usar system()
#include <limits>  // Para limpiar el buffer de entrada

using namespace std;

// PROCEDIMIENTO PARA LIMPIAR PANTALLA
void limpiarPantalla() {
    // Detecta el sistema operativo automáticamente
    #ifdef _WIN32
        system("cls");   // Comando para Windows
    #else
        system("clear"); // Comando para Linux / macOS
    #endif
}

double convertirAFahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32.0;
}

double convertirAKelvin(double c) {
    return c + 273.15;
}

double convertirARankine(double c) {
    double f = convertirAFahrenheit(c);
    return f + 459.67;
}

void mostrarMenu() {
    cout << "========================================" << endl;
    cout << "   MENU DE CONVERSION DE TEMPERATURA" << endl;
    cout << "========================================" << endl;
    cout << "1. Convertir a Fahrenheit (oF)" << endl;
    cout << "2. Convertir a Kelvin (oK)" << endl;
    cout << "3. Convertir a Rankine (oR)" << endl;
    cout << "4. Salir del programa" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Seleccione una opcion (1-4): ";
}

// FUNCIÓN PRINCIPAL
int main() {
    int opcion;
    double celsius, resultado;

    cout << fixed << setprecision(2);

    do {
        // 1. Limpiar pantalla al inicio de cada ciclo
        limpiarPantalla();

        // 2. Mostrar el menú
        mostrarMenu();
        cin >> opcion;

        // 3. Si la opción es de conversión (1, 2 o 3), solicitamos el dato
        if (opcion >= 1 && opcion <= 3) {
            cout << "\nIngrese la temperatura en grados Celsius (oC): ";
            cin >> celsius;
        }

        // 4. Evaluamos la opción y realizamos el cálculo
        switch (opcion) {
            case 1:
                resultado = convertirAFahrenheit(celsius);
                cout << "\n--> Resultado: " << celsius << " oC = " << resultado << " oF" << endl;
                break;

            case 2:
                resultado = convertirAKelvin(celsius);
                cout << "\n--> Resultado: " << celsius << " oC = " << resultado << " oK" << endl;
                break;

            case 3:
                resultado = convertirARankine(celsius);
                cout << "\n--> Resultado: " << celsius << " oC = " << resultado << " oR" << endl;
                break;

            case 4:
                cout << "\nSaliendo del programa... ¡Hasta luego!" << endl;
                break;

            default:
                cout << "\nERROR: Opcion invalida. Por favor, intente de nuevo." << endl;
                break;
        }

        // 5. PAUSA: Solo si no va a salir del programa
        if (opcion != 4) {
            cout << "\nPresione Enter para continuar...";
            
            // Limpiamos el buffer por si quedaron saltos de línea del 'cin' anterior
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            
            // Esperamos a que el usuario presione Enter
            cin.get(); 
        }

    } while (opcion != 4); 

    return 0;
}