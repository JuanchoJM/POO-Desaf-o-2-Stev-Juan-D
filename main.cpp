#include <iostream>
#include "redestaciones.h"
#include "funciones.h"
#include <fstream> 
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
        cout << "12. Verificar fugas" << endl; 
        cout << "0. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;  // Lee la opción del usuario
        cin.ignore();  // Limpiar el buffer de entrada después de `cin >>`

        switch (opcion) {
            case 1: {
                // Pedir al usuario que ingrese los datos para una nueva estación
                cout << "Ingrese el nombre de la estación: ";
                getline(cin, *pnombre);
                if (pnombre->empty()) {
                    cout << "Error: El nombre de la estación no puede estar vacío." << endl;
                    break;
                }

                cout << "Ingrese el código de identificación: ";
                cin >> *pcodident;

                // Validar que el código de identificación sea positivo
                if (*pcodident <= 0) {
                    cout << "Error: El código de identificación debe ser un número positivo." << endl;
                    cin.ignore(); // Limpiar el buffer
                    break;
                }
                cin.ignore();  // Para ignorar el carácter de nueva línea que queda en el buffer

                cout << "Ingrese el nombre del gerente: ";
                getline(cin, *pgerente);
                if (pgerente->empty()) {
                    cout << "Error: El nombre del gerente no puede estar vacío." << endl;
                    break;
                }

                // Seleccionar la región
                cout << "Seleccione la región:\n";
                cout << "0 - Norte\n";
                cout << "1 - Centro\n";
                cout << "2 - Sur\n";
                int opcionRegion;
                cin >> opcionRegion;

                // Validar la opción de región
                if (opcionRegion < 0 || opcionRegion > 2) {
                    cout << "Error: Opción de región no válida. Debe ser 0, 1 o 2." << endl;
                    cin.ignore(); // Limpiar el buffer
                    break;
                }

                // Asignar el nombre de la región basado en la opción seleccionada
                switch (opcionRegion) {
                    case 0:
                        *pregion = "norte";
                        break;
                    case 1:
                        *pregion = "centro";
                        break;
                    case 2:
                        *pregion = "sur";
                        break;
                }

                cout << "Ingrese las coordenadas de la estación: ";
                cin >> *pcoordenadas;

                // Validar que las coordenadas sean un número válido
                if (*pcoordenadas < 0) {
                    cout << "Error: Las coordenadas deben ser un número positivo." << endl;
                    cin.ignore(); // Limpiar el buffer
                    break;
                }

                // Verificar si la estación ya existe
                if (red.existeEstacion(*pcodident)) {
                    cout << "Error: Ya existe una estación con el código de identificación " << *pcodident << "." << endl;
                    break;
                }

                // Agregar la nueva estación a la red de estaciones utilizando los apuntadores
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

            case 5: {  // Agregar surtidor
                cout << "Ingrese el código de identificación de la estación: ";
                cin >> codident;

                Estacion* estacion = red.obtenerEstacion(codident);  // Obtener la estación
                if (estacion != nullptr) {
                    // Crear un nuevo surtidor
                    Surtidor nuevoSurtidor;

                    // Pedir el número del surtidor y el tipo de combustible
                    short int numeroSurtidor;
                    string tipoCombustible;

                    cout << "Ingrese el número del surtidor: ";
                    cin >> numeroSurtidor;
                    nuevoSurtidor.setIdentsurt(numeroSurtidor);  // Establecer el ID del surtidor

                    cout << "Ingrese el tipo de combustible: ";
                    cin.ignore();  // Limpiar el buffer de entrada
                    getline(cin, tipoCombustible);  // Leer tipo de combustible
                    nuevoSurtidor.setTipomaquina(tipoCombustible);  // Establecer el tipo de máquina

                    // Agregar el surtidor a la estación
                    estacion->agregar_eliminar_surtidor(true, nuevoSurtidor);  // true para agregar

                } else {
                    cout << "Estación no encontrada." << endl;
                }
                break;
            }

            
            
            case 6: {  // Eliminar surtidor
                cout << "Ingrese el código de identificación de la estación: ";
                cin >> codident;

                Estacion* estacion = red.obtenerEstacion(codident);
                if (estacion != nullptr) {
                    cout << "Surtidores disponibles:" << endl;

                    // Imprimir los surtidores con sus detalles
                    Surtidor* surtidores = estacion->getSurtidores();
                    for (short int i = 0; i < estacion->getNumMaquinas(); ++i) {
                        cout << i << ". Surtidor " << surtidores[i].getIdentsurt() 
                             << " - Tipo: " << surtidores[i].getTipomaquina() << endl;  // Imprime detalles del surtidor
                    }

                    int indiceEliminar;
                    cout << "Seleccione el número del surtidor a eliminar: ";
                    cin >> indiceEliminar;

                    // Ajustar el índice ya que el usuario selecciona un número basado en 1
                    estacion->agregar_eliminar_surtidor(false, Surtidor(), indiceEliminar);  // false para eliminar
                } else {
                    cout << "Estación no encontrada." << endl;
                }
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

            

            // Dentro de tu switch-case
            case 8: {
                // Lógica para consultar histórico de transacciones
                ifstream archivo("registrotrans.txt");  // Abre el archivo en modo lectura

                if (archivo.is_open()) {
                    string linea;
                    cout << "Histórico de transacciones:" << endl;
                    while (getline(archivo, linea)) {  // Lee el archivo línea por línea
                        cout << linea << endl;  // Imprime cada línea en la consola
                    }
                    archivo.close();  // Cierra el archivo
                } else {
                    cout << "No se pudo abrir el archivo de transacciones." << endl;
                }
                break;
            }


            case 9: {
                cout << "Ingrese el código de identificación de la estación: ";
                cin >> codident;

                Estacion* estacion = red.obtenerEstacion(codident);  // Obtener la estación
                if (estacion != nullptr) {

                    cout << "Total litros Regular vendidos: " << estacion->getTotalLitrosVendidos(0) << endl;
                    cout << "Total litros Premium vendidos: " << estacion->getTotalLitrosVendidos(1) << endl;
                    cout << "Total litros EcoExtra vendidos: " << estacion->getTotalLitrosVendidos(2) << endl;
                } else {
                    cout << "Estación no encontrada." << endl;
                }
                break;
            }


            case 10: {
                cout << "Simular venta" << endl;

                cout << "Ingrese el código de identificación de la estación: ";
                cin >> codident;

                Estacion* estacion = red.obtenerEstacion(codident);  // Obtener la estación
                if (estacion != nullptr) {
                    simularventa(red, *estacion);  // Llama a la función de simular venta con la red y la estación
                } else {
                    cout << "Estación no encontrada." << endl;
                }
                break;
            }



            case 11: {
                // Seleccionar estación y asignar tanques
                cout << "Ingrese el código de identificación de la estación para asignar los tanques: ";
                cin >> codident;
                cin.ignore();  // Limpiar buffer de entrada

                // Busca la estación y asigna los tanques
                Estacion* estacion = red.obtenerEstacion(codident);  // Método que busca la estación
                if (estacion != nullptr) {
                    estacion->asignarTanques();  // Llama al método asignarTanques
                } else {
                    cout << "Estación no encontrada." << endl;
                }
                break;
            }

            case 12: {  // Verificar fugas
                cout << "Ingrese el código de identificación de la estación: ";
                cin >> codident;

                Estacion* estacion = red.obtenerEstacion(codident);  // Obtener la estación
                if (estacion != nullptr) {
                    if (estacion->verificarFugas()) {
                        cout << "¡Advertencia! Se ha detectado una posible fuga." << endl;
                    } else {
                        cout << "No se han detectado fugas. El total de litros está dentro de los límites aceptables." << endl;
                    }
                } else {
                    cout << "Estación no encontrada." << endl;
                }
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
