
/*Elabora una calculadora de matrices | Sumas y Restas.
*/
#include <iostream>
#include <conio.h>

using namespace std;

int Matriz1[10][10], Matriz2[10][10],MatrizResultado[10][10];
int fla1, Clun1, fla2, Clun2;
int main()
{
	char opc;
	do {
	    system("cls");
	cout << "Ingrese Cantidad De Filas de la primera matriz: ";
	cin >> fla1;
	cout << "Ingrese Cantidad De Columna de la primera matriz: ";
	cin >> Clun1;
	cout << endl;
	cout << "Ingrese Cantidad De Filas de la segunda matriz: ";
	cin >> fla2;
	cout << "Ingrese Cantidad De Columna de la segunda matriz: ";
	cin >> Clun2;
	cout << "\nIngrese Dato de La Primera matriz" << endl;
	for (int i = 0; i < fla1; i++) {
		for (int j = 0; j < Clun1; j++) {
			cout << "Ingrese Dato [" << i << "][" << j << "] :";
			cin >> Matriz1[i][j];
		}
	}
	cout << "\nIngrese Dato de La Segunda matriz" << endl;
	for (int i = 0; i < fla2; i++) {
		for (int j = 0; j < Clun2; j++) {
			cout << "Ingrese Dato [" << i << "][" << j << "] :";
			cin >> Matriz2[i][j];
		}
	}
		int SmRes;
		cout << "1. Sumar: " << endl;
		cout << "2. Restar: " << endl;
		cout << "Seleccione: ";
		cin >> SmRes;

		if (SmRes == 1) {
			if ((fla1 == fla2)&&(Clun1 == Clun2)) {
				for (int i = 0; i < fla2; i++) {
					for (int j = 0; j < Clun2; j++) {
						MatrizResultado[i][j]=Matriz1[i][j]+Matriz2[i][j];
					}
				}
				cout<<"El Resultado De La Suma es:"<<endl;
				for (int i = 0; i < fla2; i++) {
					cout << "[ ";
					for (int j = 0; j < Clun2; j++) {
						cout<<MatrizResultado[i][j]<<" ";
					}
					cout << "]" << endl;
				}

			} else {
				cout << "Deven tener La misma cantidad de Filas y Columnas Para Sumar" << endl;
			}
		}
		if(SmRes==2) {
			if ((fla1 == fla2)&&(Clun1 == Clun2)) {
				for (int i = 0; i < fla2; i++) {
					for (int j = 0; j < Clun2; j++) {
						MatrizResultado[i][j]=Matriz1[i][j]-Matriz2[i][j];
					}
				}
				cout<<"El Resultado de laResta es:"<<endl;
				for (int i = 0; i < fla2; i++) {
					cout << "[ ";
					for (int j = 0; j < Clun2; j++) {
						cout<<	MatrizResultado[i][j]<<" ";
					}
					cout << "]" << endl;
				}
			} else {
				cout << "Deven tener La misma cantidad de Filas y Columnas Para Restar" << endl;
			}
		}
		cout<<" S. Salir: "<<endl;
		cout<<" C. Vover Al Principio: "<<endl;
		cout<<" Seleccionar: ";
		cin>>opc;
	} while ((opc != 'S' && opc != 's') && (opc == 'C' && opc == 'c'));
}
