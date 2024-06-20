#include <iostream>
#include <stdio.h>
#include <conio.h>
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
    
    do{
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

        cout << "\n¿Desea ingresar otro empleado? (1-Si, 0-No): ";
        cin >> opcion;

        numEmpleados++;
	}while(opcion != 0);
    
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
    
    getch(); // Pausa antes de finalizar el programa
    
	return 0;
}
