/*Una empresa desea un pequeño sistema que les permita guardar los datos de 20 empleados; número de empleado y primer nombre.

Los números de empleados van del 1 al 20, pero no se ingresan de forma consecutiva, el usuario lo ingresa aleatoriamente, por ejemplo:
primero ingresa el número 5, después ingresa el número 2, etc.

Una vez que los datos estén guardados el usuario desea tener las siguientes funciones:

>> Buscar el nombre de un empleado por su número de empleado.

>> Buscar el número de empleado por su nombre.

>> Saber si un usuario no existe.

>> Saber si hay nombres similares entre sus empleados.

>> Mostrar empleados de forma ascendente por número de empleado.

>> Mostrar empleados de forma descendente por número de empleado.

Crea un programa en C++ que de solución a este problema. Solo utiliza lo aprendido en los módulos anteriores.*/
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

const int MAX_EMPLEADOS = 2;

void clearScreen();

void pausa();

int main() {
	int i = 0, opc, Pos = 0;
	char ban;
	int ID, empleadoID[MAX_EMPLEADOS];
	string empleadosNombre[MAX_EMPLEADOS];
	string Nombre;

	//Lectura de los datos de los empleado

	while (i <MAX_EMPLEADOS) {
		cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
		cout << "X\t\t\tEmpleado " << i + 1 <<"\t\t\tX"<<endl;
		cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
		cout << "\nID: ";
		cin>>ID;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Ingrese el ID nuevamente.\n";
			pausa();
			clearScreen();
			continue;
		}

		cin.ignore();
		cout << "Nombre: ";
		string nombre;
		getline(cin, nombre);
		empleadoID[i] = ID;
		empleadosNombre[i] = nombre;
		i++;
		pausa();
		clearScreen();
	}

	//Ordenamiento de Datos utilisando orden por insercion

	for (int i = 0; i < MAX_EMPLEADOS; i++) {
		int pos = i;
		int aux = empleadoID[i];
		string aux1 = empleadosNombre[i];
		while ((pos > 0) && (empleadoID[pos - 1]> aux)) {
			empleadoID[pos]= empleadoID[pos - 1];
			empleadosNombre[pos]= empleadosNombre[pos - 1];
			pos--;
		}
		empleadoID[pos] = aux;
		empleadosNombre[pos]= aux1;
	}

	//Menu Del Aplicativo
	do {
		cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
		cout << "1. Buscar Empleado Por ID\t\t\t\tX" << endl;
		cout << "2. Buscar ID De Empleado Por Nombre\t\t\tX" << endl;
		cout << "3. Saber si un usuario no existe\t\t\tX" << endl;
		cout << "4. Nombres similares de empleados\t\t\tX" << endl;
		cout << "5. Mostrar empleados de forma ascendente\t\tX" << endl;
		cout << "6. Mostrar empleados de forma descendente\t\tX" << endl;
		cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
		cout<<"\nOpcion: ";
		cin >> opc;
		cin.ignore();
		clearScreen();
		switch (opc) {
			case 1:
				ban = 'f';
				cout << "ingrese ID: ";
				cin>>ID;
				i = 0, Pos = 0;
				while ((i < MAX_EMPLEADOS)) {
					if (empleadoID[i]== ID) {
						ban = 'v';
						Pos = i;
					}
					i++;
				}
				if (ban == 'v') {
					cout << "\t\t\nEmpleado encontrado" << endl;
					cout << "\nNombre: " << empleadosNombre[Pos]<< endl;

				}
				if (ban == 'f') {
					cout << "\t\t\nEmpleado no Encontrado" << endl;

				}

				break;
			case 2:
				ban = 'f';
				cout << "Ingrese Nombre: ";
				getline(cin, Nombre);
				i = 0, Pos = 0;
				while ((i < MAX_EMPLEADOS)) {
					if (empleadosNombre[i]== Nombre) {
						ban = 'v';
						Pos = i;
					}
					i++;
				}
				if (ban == 'v') {
					cout << "\t\t\nEmpleado encontrado" << endl;
					cout << "\nID: " << empleadoID[Pos]<< endl;

				}
				if (ban == 'f') {
					cout << "\t\tEmpleado No Encontrado" << endl;

				}

				break;
			case 3:
				ban = 'f';
				cout << "\ningrese ID: ";
				cin>>ID;
				cin.ignore();
				cout << "ingrese Nombre: ";
				getline(cin, Nombre);
				i = 0, Pos = 0;
				while ((i < MAX_EMPLEADOS)) {
					if ((empleadoID[i]== ID) && (empleadosNombre[i] == Nombre)) {
						ban = 'v';
					}
					i++;
				}
				if (ban == 'v') {
					cout << "\n\t\t\nEl empleado Que Busca Existe" << endl;

				}
				if (ban == 'f') {
					cout << "\n\t\tEl empleado Que Busca No Existe\n" << endl;
				}
				break;
			case 4: {
				cout << "\t\t\nCantidad de Nombres Parecido" << endl;
				int Iguales = 0, Iguales1 = 0;
				string NAme, nAme;
				for(int i=0; i<MAX_EMPLEADOS; i++) {
					NAme = empleadosNombre[i];
					for(int j=(i+1); j<MAX_EMPLEADOS; j++) {
						nAme = empleadosNombre[j];
						if (NAme == nAme) {
							Iguales++;
							Iguales1++;
						}
					}
				}
				cout << "\nHay " << Iguales << " nombres iguales." << endl;
				cout << "Se contaron " << Iguales1 << " pares de nombres iguales." << endl;
				break;
			}

			case 5:
				for (int i = 0; i < MAX_EMPLEADOS; i++) {
					cout << "\nID: " << empleadoID[i] << endl;
					cout << "Nombre: " << empleadosNombre[i] << endl;

				}
				break;
			case 6:
				for (int i = MAX_EMPLEADOS-1; i >= 0; i--) {
					cout << "\nID: " << empleadoID[i]<< endl;
					cout << "Nombre: " << empleadosNombre[i] << endl;

				}
				break;
		}

		cout << "\n1. Volver al Menu" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> opc;
		clearScreen();
	} while (opc == 1);

	return 0;
	pausa;
}
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    std::cout << "Press any key to continue...";
    std::cin.get();
}
