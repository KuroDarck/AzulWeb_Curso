/*
Crea una calculadora que pueda realizar las siguientes funciones; sumar, restar, dividir, sacar raíz
y elevar un numero a cualquier potencia. Utiliza una función para cada operación. El programa debe de
 tener un menú donde el usuario pueda elegir qué operación realizar, después se debe de mostrar el resultado
  y mostrar la opción de realizar otra operación o finalizar el programa.
*/

#include <iostream>
#include<iomanip>

using namespace std;

template <class TIPOD>
TIPOD Suma(TIPOD, TIPOD);

template <class TIPOD>
TIPOD Resta(TIPOD, TIPOD);

template <class TIPOD>
TIPOD Divicion(TIPOD, TIPOD);

template <class TIPOD>
TIPOD Raiz(TIPOD);

template <class TIPOD>
TIPOD Potencia(TIPOD, int);

float Resultado, Nmero, NmerO;

int main()
{

	cout.precision(3);

	int opc;

	do {
		system("cls");
		cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
		cout << "1. Suma" << endl;
		cout << "2. Resta" << endl;
		cout << "3. Divicion" << endl;
		cout << "4. Raiz" << endl;
		cout << "5. Potencia" << endl;
		cout << "6. Salir" << endl;
		cout << "     Opcion: ";
		cin >> opc;

		switch (opc) {
			case 1:
				do {
					system("cls");
					cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
					cout << "\n\t\tSUMA" << endl;
					cout << "Ingrese Dato: ";
					cin >> Nmero;
					cout << "Ingrese Dato: ";
					cin >> NmerO;
					Resultado = Suma(Nmero, NmerO);
					cout << "\nEl Resultafo es: " << Resultado << endl;
					cout << "\n1. Sumar Otros Datos" << endl;
					cout << "2. Salir" << endl;
					cout << "     Opcion: ";
					cin >> opc;
					cout << endl;

				} while (opc != 2);
				break;
			case 2:
				do {
					system("cls");
					cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
					cout << "\n\t\tRESTA" << endl;
					cout << "Ingrese Dato: ";
					cin >> Nmero;
					cout << "Ingrese Dato: ";
					cin >> NmerO;
					Resultado = Resta(Nmero, NmerO);
					cout << "\nEl Resultafo es: " << Resultado << endl;
					cout << "\n1. Restar Otros Datos" << endl;
					cout << "2. Salir" << endl;
					cout << "     Opcion: ";
					cin >> opc;
					cout << endl;
				} while (opc != 2);
				break;
			case 3:
				do {
					system("cls");
					cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
					cout << "\n\t\tDIVICION" << endl;
					cout << "Ingrese Dato: ";
					cin >> Nmero;
					cout << "Ingrese Dato: ";
					cin >> NmerO;
					Resultado = Divicion(Nmero, NmerO);
					cout << "\nEl Resultafo es: " << Resultado << endl;
					cout << "\n1. Duvidir Otros Datos" << endl;
					cout << "2. Salir" << endl;
					cout << "     Opcion: ";
					cin >> opc;
					cout << endl;
				} while (opc != 2);
				break;
			case 4:
				do {
					system("cls");
					cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
					cout << "\n\t\tRAIZ" << endl;
					cout << "Ingrese Dato: ";
					cin >> Nmero;

					Resultado =Raiz(Nmero);
					cout << "\nEl Resultafo es: " << fixed<<Resultado << endl;
					cout << "\n1. Sacar la Raiz de Otro Dato" << endl;
					cout << "2. Salir" << endl;
					cout << "     Opcion: ";
					cin >> opc;
					cout << endl;
				} while (opc != 2);
				break;
			case 5:
				do {
					system("cls");
					cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
					cout << "\n\t\tPOTENCIA" << endl;
					cout << "Ingrese Dato: ";
					cin >> Nmero;
					cout << "Ingrese La Potencia: ";
					cin >> NmerO;
					Resultado = Potencia(Nmero, NmerO);
					cout << "\nEl Resultafo es: " << Resultado << endl;
					cout << "\n1. Elevar Otro Dato" << endl;
					cout << "2. Salir" << endl;
					cout << "     Opcion: ";
					cin >> opc;
					cout << endl;
				} while (opc != 2);
				break;
		}

		system("pause");
	} while (opc != 6);
	return 0;
}


//Funcion de Suma
template <class TIPOD>
TIPOD Suma(TIPOD x, TIPOD y)
{
	return x + y;
}

//Funcion de Resta
template <class TIPOD>
TIPOD Resta(TIPOD x, TIPOD y)
{
	return x - y;
}


//Funcion Divicion
template <class TIPOD>
TIPOD Divicion(TIPOD x, TIPOD y)
{
	return x / y;
}

//Funcion de Potencia
template <class TIPOD>
TIPOD Potencia(TIPOD x, int y)
{
	TIPOD aux = 0;
	aux = x;
	for (int i = 1; i < y; i++) {
		x *= aux;
	}
	return x;
}


//Funcion de Raiz cuadrada
template <class TIPOD>
TIPOD Raiz(TIPOD x)
{
	TIPOD raiz=0,aux=0;
	TIPOD error = 0.00001;

	raiz= x;

	while ((raiz- x / raiz) > error) {
		raiz= (raiz + x / raiz) / 2;
	}

	return raiz;

}