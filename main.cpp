#include <iostream>
#include "redestaciones.h"

using namespace std;

int main() {
    RedEstaciones red(0);
    string nombre;
    short int codident;
    string gerente;
    string region;
    short int coordenadas;
    string *pnombre = &nombre;
    short int *pcodident = &codident;
    string *pgerente = &gerente;
    string *pregion = &region;
    short int *pcoordenadas = &coordenadas;
    int opcion;  // Variable para almacenar la opción seleccionada
    do {
        // Muestra el menú de opciones
        cout << "Menú de opciones:" << endl;
        cout << "1. Agregar estación" << endl;
        cout << "2. Eliminar estación" << endl;
        cout << "3. Calcular ventas" << endl;
        cout << "4. Fijar precios" << endl;
        cout << "5. Agregar surtidor" << endl;
        cout << "6. Eliminar surtidor" << endl;
        cout << "7. Activar/Desactivar surtidor" << endl;
        cout << "8. Consultar histórico de transacciones" << endl;
        cout << "9. Reportar cantidad de litros vendidos" << endl;
        cout << "10. Simular venta" << endl;
        cout << "11. Asignar tanque" << endl;
        cout << "0. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;  // Lee la opción del usuario
        cin.ignore();  // Limpiar el buffer de entrada después de `cin >>`

        switch (opcion) {
            case 1: {
                // Pedir al usuario que ingrese los datos para una nueva estación
                cout << "Ingrese el nombre de la estación: ";
                getline(cin, nombre);  // Aquí usamos `getline` correctamente

                cout << "Ingrese el código de identificación: ";
                cin >> codident;
                cin.ignore();  // Para ignorar el carácter de nueva línea que queda en el buffer

                cout << "Ingrese el nombre del gerente: ";
                getline(cin, gerente);

                cout << "Ingrese la región: ";
                getline(cin, region);

                cout << "Ingrese las coordenadas de la estación: ";
                cin >> coordenadas;

                // Agregar la nueva estación a la red de estaciones
                red.agregarEstacion(*pnombre, *pcodident, *pgerente, *pregion, *pcoordenadas);

                // Mostrar las estaciones
                red.mostrarEstaciones();
                break;
            }

            case 2:                
                cout << "Ingrese el código de identificación de la estación a eliminar: ";
                cin >> codident;
                cin.ignore();  // Limpiar el buffer de entrada

                // Lógica para eliminar una estación
                cout << "Eliminando estación..." << endl;
                red.eliminarEstacion(*pcodident);  // Pasar el valor leído
                break;

            case 3:
                // Lógica para calcular ventas
                cout << "Calculando ventas..." << endl;
                // Aquí puedes implementar la lógica necesaria
                break;

            case 4: {
                red.mostrarPrecios();
                break;
            }

            case 5: {break;} // Por ejemplo, para agregar un surtidor
               



            case 6: {
                // Lógica para eliminar surtidor
                cout << "Funcionalidad para eliminar surtidor aún no implementada." << endl;
                break;
            }

            case 7: {
                // Lógica para activar/desactivar surtidor
                short int codident;
                    cout << "Ingrese el código de identificación de la estación: ";
                    cin >> codident;

                    Estacion* estacion = red.obtenerEstacion(codident);
                    if (estacion != nullptr) {
                        // Aquí puedes llamar a crearMaquinas() o hacer otras operaciones con la estación
                        estacion->crearMaquinas(); // O el método que necesites
                    } else {
                        cout << "Estación no encontrada." << endl;
                    }
                    break;
                
            }

            case 8: {
                // Lógica para consultar histórico de transacciones
                cout << "Funcionalidad para consultar histórico de transacciones aún no implementada." << endl;
                break;
            }

            case 9: {
                // Lógica para reportar cantidad de litros vendidos
                cout << "Funcionalidad para reportar cantidad de litros vendidos aún no implementada." << endl;
                break;
            }

            case 10: {
                // Lógica para simular venta
                cout << "Funcionalidad para simular venta aún no implementada." << endl;
                break;
            }

            case 11: {
                // Lógica para asignar tanque
                cout << "Funcionalidad para asignar tanque aún no implementada." << endl;
                break;
            }

            case 0:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción inválida. Intenta nuevamente." << endl;
                break;
        }
        cout << endl;  // Espacio entre opciones
    } while (opcion != 0);  // Continúa hasta que el usuario seleccione salir

    return 0;
}
