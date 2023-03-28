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

int main()
{
	int i = 0, opc, Pos = 0;
	char ban;
	int ID, IdEmpleado[20];
	string empleados[20];
	string Nombre;

	//Lectura de los datos de los empleado

	do {
		system("cls");
		cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
		cout << "X\t\t\tEmpleado " << i + 1 <<"\t\t\tX"<<endl;
		cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
		cout << "\nID: ";
		cin>>ID;
		cin.ignore();
		cout << "Nombre: ";
		getline(cin, Nombre);

		IdEmpleado[i]= ID;
		empleados[i]= Nombre;
		i++;

		system("pause");
	} while (i < 20);

	//Ordenamiento de Datos utilisando orden por insercion

	for (int i = 0; i < 20; i++) {
		int pos = i;
		int aux = IdEmpleado[i];
		string aux1 = empleados[i];
		while ((pos > 0) && (IdEmpleado[pos - 1]> aux)) {
			IdEmpleado[pos]= IdEmpleado[pos - 1];
			empleados[pos]= empleados[pos - 1];
			pos--;
		}
		IdEmpleado[pos] = aux;
		empleados[pos]= aux1;
	}

	//Menu Del Aplicativo
	do {
		system("cls");
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
		switch (opc) {
			case 1:
				ban = 'f';
				cout << "ingrese ID: ";
				cin>>ID;
				i = 0, Pos = 0;
				while ((i < 20)) {
					if (IdEmpleado[i]== ID) {
						ban = 'v';
						Pos = i;
					}
					i++;
				}
				if (ban == 'v') {
					cout << "\t\t\nEmpleado encontrado" << endl;
					cout << "\nNombre: " << empleados[Pos]<< endl;
				
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
				while ((i < 20)) {
					if (empleados[i]== Nombre) {
						ban = 'v';
						Pos = i;
					}
					i++;
				}
				if (ban == 'v') {
					cout << "\t\t\nEmpleado encontrado" << endl;
					cout << "\nID: " << IdEmpleado[Pos]<< endl;
				
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
				while ((i < 20)) {
					if ((IdEmpleado[i]== ID) && (empleados[i] == Nombre)) {
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
					for(int i=0; i<20; i++) {
						NAme = empleados[i];
						for(int j=(i+1); j<20; j++) {
							nAme = empleados[j];
							if (NAme == nAme) {
								Iguales++;
								Iguales1 +=2;
							}
						}
					}
					cout << "\nExisten " << Iguales << " Parecido, en los Nombre de " << Iguales1 << " Empleados." << endl;
				
					break;
				}
			case 5:
				for (int i = 0; i < 20; i++) {
					cout << "\nID: " << IdEmpleado[i] << endl;
					cout << "Nombre: " << empleados[i] << endl;
					
				}
				break;
			case 6:
				for (int i = 19; i >= 0; i--) {
					cout << "\nID: " << IdEmpleado[i]<< endl;
					cout << "Nombre: " << empleados[i] << endl;
					
				}
				break;
		}

		cout << "\n1. Volver al Menu" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> opc;
	} while (opc == 1);

	return 0;
	getch();
}