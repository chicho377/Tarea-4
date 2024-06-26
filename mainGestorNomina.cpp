#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib> // para usar system("CLS")
using namespace std;

int main(int argc, char** argv) {
	
	// constante
    const int MAX_EMPLEADOS = 100;

    // arrays
    string cedulas[MAX_EMPLEADOS];
    string nombres[MAX_EMPLEADOS];
    int tipos[MAX_EMPLEADOS];
    double salariosPorHora[MAX_EMPLEADOS];
    double horasTrabajadas[MAX_EMPLEADOS];
    double salariosOrdinarios[MAX_EMPLEADOS];
    double aumentos[MAX_EMPLEADOS];
    double salariosBrutos[MAX_EMPLEADOS];
    double deduccionesCCSS[MAX_EMPLEADOS];
    double salariosNetos[MAX_EMPLEADOS];

	// variables
    int numEmpleados = 0;
    int opcion;
    int cantOperarios = 0, cantTecnicos = 0, cantProfesionales = 0;
    double acumuladoNetoOperarios = 0, acumuladoNetoTecnicos = 0, acumuladoNetoProfesionales = 0;

    do {
        system("CLS"); // limpiar pantalla
        
        cout << "Menu Principal:\n";
        cout << "1. Agregar empleado\n";
        cout << "2. Consultar empleado\n";
        cout << "3. Modificar empleado\n";
        cout << "4. Borrar empleado\n";
        cout << "5. Mostrar estadisticas finales\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        system("CLS"); // limpiar pantalla 

        switch (opcion) {
            case 1: {
                if (numEmpleados >= MAX_EMPLEADOS) {
                    cout << "Se ha alcanzado el número máximo de empleados.\n";
                    break;
                }

                cout << "Ingrese la cedula del empleado: ";
                cin >> cedulas[numEmpleados];

                cout << "Ingrese el nombre del empleado: ";
                cin.ignore(); // consumir el salto de linea pendiente 
                getline(cin, nombres[numEmpleados]);

                cout << "Ingrese el tipo de empleado (1-Operario, 2-Tecnico, 3-Profesional): ";
                cin >> tipos[numEmpleados];

                cout << "Ingrese el salario por hora: ";
                cin >> salariosPorHora[numEmpleados];

                cout << "Ingrese la cantidad de horas trabajadas: ";
                cin >> horasTrabajadas[numEmpleados];

                salariosOrdinarios[numEmpleados] = salariosPorHora[numEmpleados] * horasTrabajadas[numEmpleados];

                switch (tipos[numEmpleados]) {
                    case 1: // operario
                        aumentos[numEmpleados] = salariosOrdinarios[numEmpleados] * 0.15;
                        cantOperarios++;
                        break;
                    case 2: // tecnico
                        aumentos[numEmpleados] = salariosOrdinarios[numEmpleados] * 0.10;
                        cantTecnicos++;
                        break;
                    case 3: // profesional
                        aumentos[numEmpleados] = salariosOrdinarios[numEmpleados] * 0.05;
                        cantProfesionales++;
                        break;
                    default:
                        cout << "Tipo de empleado no valido.\n";
                        continue;
                }

                salariosBrutos[numEmpleados] = salariosOrdinarios[numEmpleados] + aumentos[numEmpleados];
                deduccionesCCSS[numEmpleados] = salariosBrutos[numEmpleados] * 0.0917;
                salariosNetos[numEmpleados] = salariosBrutos[numEmpleados] - deduccionesCCSS[numEmpleados];

                // actualiza los acumulados despues de calcular el salario neto
                if (tipos[numEmpleados] == 1) {
                    acumuladoNetoOperarios += salariosNetos[numEmpleados];
                } else if (tipos[numEmpleados] == 2) {
                    acumuladoNetoTecnicos += salariosNetos[numEmpleados];
                } else if (tipos[numEmpleados] == 3) {
                    acumuladoNetoProfesionales += salariosNetos[numEmpleados];
                }

                // mostrar los datos del empleado
                cout << "\nDatos del empleado:\n";
                cout << "--------------------------------------------------\n";
                cout << "Cedula: " << cedulas[numEmpleados] << "\n";
                cout << "Nombre: " << nombres[numEmpleados] << "\n";
                cout << "Tipo Empleado: " << tipos[numEmpleados] << "\n";
                cout << "Salario por Hora: " << salariosPorHora[numEmpleados] << "\n";
                cout << "Cantidad de Horas: " << horasTrabajadas[numEmpleados] << "\n";
                cout << "--------------------------------------------------\n";
                cout << "Salario Ordinario: " << salariosOrdinarios[numEmpleados] << "\n";
                cout << "Aumento: " << aumentos[numEmpleados] << "\n";
                cout << "Salario Bruto: " << salariosBrutos[numEmpleados] << "\n";
                cout << "Deduccion CCSS: " << deduccionesCCSS[numEmpleados] << "\n";
                cout << "Salario Neto: " << salariosNetos[numEmpleados] << "\n";
                cout << "--------------------------------------------------\n";

                numEmpleados++;
                break;
            }
            case 2: {
                string cedula;
                cout << "Ingrese la cedula del empleado a consultar: ";
                cin >> cedula;
                bool encontrado = false;
                for (int i = 0; i < numEmpleados; i++) {
                    if (cedulas[i] == cedula) {
                        cout << "\nDatos del empleado:\n";
                        cout << "--------------------------------------------------\n";
                        cout << "Cedula: " << cedulas[i] << "\n";
                        cout << "Nombre: " << nombres[i] << "\n";
                        cout << "Tipo Empleado: " << tipos[i] << "\n";
                        cout << "Salario por Hora: " << salariosPorHora[i] << "\n";
                        cout << "Cantidad de Horas: " << horasTrabajadas[i] << "\n";
                        cout << "--------------------------------------------------\n";
                        cout << "Salario Ordinario: " << salariosOrdinarios[i] << "\n";
                        cout << "Aumento: " << aumentos[i] << "\n";
                        cout << "Salario Bruto: " << salariosBrutos[i] << "\n";
                        cout << "Deduccion CCSS: " << deduccionesCCSS[i] << "\n";
                        cout << "Salario Neto: " << salariosNetos[i] << "\n";
                        cout << "--------------------------------------------------\n";
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Empleado no encontrado.\n";
                }
                break;
            }
            case 3: {
                string cedula;
                cout << "Ingrese la cedula del empleado a modificar: ";
                cin >> cedula;
                bool encontrado = false;
                for (int i = 0; i < numEmpleados; i++) {
                    if (cedulas[i] == cedula) {
                        encontrado = true;

                        cout << "Ingrese el nuevo nombre del empleado: ";
                        cin.ignore(); // consumir el salto de linea pendiente 
                        getline(cin, nombres[i]);

                        cout << "Ingrese el nuevo tipo de empleado (1-Operario, 2-Tecnico, 3-Profesional): ";
                        cin >> tipos[i];

                        cout << "Ingrese el nuevo salario por hora: ";
                        cin >> salariosPorHora[i];

                        cout << "Ingrese la nueva cantidad de horas trabajadas: ";
                        cin >> horasTrabajadas[i];

                        salariosOrdinarios[i] = salariosPorHora[i] * horasTrabajadas[i];

                        switch (tipos[i]) {
                            case 1: // operario
                                aumentos[i] = salariosOrdinarios[i] * 0.15;
                                break;
                            case 2: // tecnico
                                aumentos[i] = salariosOrdinarios[i] * 0.10;
                                break;
                            case 3: // profesional
                                aumentos[i] = salariosOrdinarios[i] * 0.05;
                                break;
                            default:
                                cout << "Tipo de empleado no valido.\n";
                                continue;
                        }

                        salariosBrutos[i] = salariosOrdinarios[i] + aumentos[i];
                        deduccionesCCSS[i] = salariosBrutos[i] * 0.0917;
                        salariosNetos[i] = salariosBrutos[i] - deduccionesCCSS[i];

                        // Actualizar acumulados
                        cantOperarios = cantTecnicos = cantProfesionales = 0;
                        acumuladoNetoOperarios = acumuladoNetoTecnicos = acumuladoNetoProfesionales = 0;
                        for (int j = 0; j < numEmpleados; j++) {
                            if (tipos[j] == 1) {
                                cantOperarios++;
                                acumuladoNetoOperarios += salariosNetos[j];
                            } else if (tipos[j] == 2) {
                                cantTecnicos++;
                                acumuladoNetoTecnicos += salariosNetos[j];
                            } else if (tipos[j] == 3) {
                                cantProfesionales++;
                                acumuladoNetoProfesionales += salariosNetos[j];
                            }
                        }

                        cout << "Empleado modificado correctamente.\n";
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Empleado no encontrado.\n";
                }
                break;
            }
            case 4: {
                string cedula;
                cout << "Ingrese la cedula del empleado a borrar: ";
                cin >> cedula;
                bool encontrado = false;
                for (int i = 0; i < numEmpleados; i++) {
                    if (cedulas[i] == cedula) {
                        encontrado = true;
                        
                        // Actualizar acumulados antes de borrar
                        if (tipos[i] == 1) {
                            cantOperarios--;
                            acumuladoNetoOperarios -= salariosNetos[i];
                        } else if (tipos[i] == 2) {
                            cantTecnicos--;
                            acumuladoNetoTecnicos -= salariosNetos[i];
                        } else if (tipos[i] == 3) {
                            cantProfesionales--;
                            acumuladoNetoProfesionales -= salariosNetos[i];
                        }

                        // Mover el último empleado a la posición actual
                        cedulas[i] = cedulas[numEmpleados - 1];
                        nombres[i] = nombres[numEmpleados - 1];
                        tipos[i] = tipos[numEmpleados - 1];
                        salariosPorHora[i] = salariosPorHora[numEmpleados - 1];
                        horasTrabajadas[i] = horasTrabajadas[numEmpleados - 1];
                        salariosOrdinarios[i] = salariosOrdinarios[numEmpleados - 1];
                        aumentos[i] = aumentos[numEmpleados - 1];
                        salariosBrutos[i] = salariosBrutos[numEmpleados - 1];
                        deduccionesCCSS[i] = deduccionesCCSS[numEmpleados - 1];
                        salariosNetos[i] = salariosNetos[numEmpleados - 1];
                        
                        numEmpleados--;
                        cout << "Empleado borrado correctamente.\n";
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Empleado no encontrado.\n";
                }
                break;
            }
            case 5: {
                cout << "\nEstadisticas finales:\n";
                cout << "--------------------------------------------------\n";
                cout << "Cantidad de Empleados Tipo Operarios: " << cantOperarios << "\n";
                if (cantOperarios > 0) {
                    cout << "Acumulado Salario Neto para Operarios: " << acumuladoNetoOperarios << "\n";
                    cout << "Promedio Salario Neto para Operarios: " << acumuladoNetoOperarios / cantOperarios << "\n";
                } else {
                    cout << "Acumulado Salario Neto para Operarios: N/A\n";
                    cout << "Promedio Salario Neto para Operarios: N/A\n";
                }

                cout << "--------------------------------------------------\n";
                cout << "Cantidad de Empleados Tipo Tecnico: " << cantTecnicos << "\n";
                if (cantTecnicos > 0) {
                    cout << "Acumulado Salario Neto para Tecnicos: " << acumuladoNetoTecnicos << "\n";
                    cout << "Promedio Salario Neto para Tecnicos: " << acumuladoNetoTecnicos / cantTecnicos << "\n";
                } else {
                    cout << "Acumulado Salario Neto para Tecnicos: N/A\n";
                    cout << "Promedio Salario Neto para Tecnicos: N/A\n";
                }

                cout << "--------------------------------------------------\n";
                cout << "Cantidad de Empleados Tipo Profesional: " << cantProfesionales << "\n";
                if (cantProfesionales > 0) {
                    cout << "Acumulado Salario Neto para Profesionales: " << acumuladoNetoProfesionales << "\n";
                    cout << "Promedio Salario Neto para Profesionales: " << acumuladoNetoProfesionales / cantProfesionales << "\n";
                } else {
                    cout << "Acumulado Salario Neto para Profesionales: N/A\n";
                    cout << "Promedio Salario Neto para Profesionales: N/A\n";
                }
                cout << "--------------------------------------------------\n";
                break;
            }
            case 6: {
                cout << "Saliendo del programa...\n";
                break;
            }
            default: {
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
            }
        }
        
        if (opcion != 6) {
            cout << "Presione cualquier tecla para continuar...";
            getch(); // Pausa antes de limpiar la pantalla y mostrar el menu nuevamente
        }
        
    } while (opcion != 6);

    return 0;
}

                                


