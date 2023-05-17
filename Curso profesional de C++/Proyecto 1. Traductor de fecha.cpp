#include <iostream>
#include <string>
using namespace std;
/*
Escriba un programa que lea tres valores enteros que represente el mes, el dia y el aÃ±o con cuatro dia gitos.
El programa deberÃ¡ mostrar la fecha en uno de los formatos siguientes, dependiendo de la selecciÃ³n del usuario.
Si el usuario introduce 1, se mostrara el mes con palabra (Enero), el dia como un entero (11) y el aÃ±o (1999).
Si se introduce un 2, se mostrara el mes con una abreviatura de tres letras (Enero), el dia como un entero (11) y el aÃ±o (1999).
 Si se produce un 3, se mostrara el mes como un entero (01), el dia como un entero (11) y el aÃ±o (1999). Solo usar lo expuesto en temas vistos previamente.

*/

void clearScreen();//Schroll
void pausa();//Pause
void mostrarFecha(int a,int b, int c,int opcion);//Formato de fehca

int main() {
	int mes, dia, ano;

	//Lectura de Los valores a Traducir
	cout << "Ingrese la fecha a Traducir: (Mes-Dia-Anio)" << endl;
	cout << "Mes: ";
	cin >> mes;
	cout << "Dia: ";
	cin >> dia;
	cout << "Anio: ";
	cin >> ano;

	//Menu de el  traductor de Fecha
	clearScreen();
	cout << "\t\t\t\"Elija la opcion de su preferencia\""<<endl;
	cout << "\"Elija La Opcion 1. para mostrar formato (Enero-01-201)\""<<endl;
	cout << "\"Elija La Opcion 2. para mostrar formato (Ene-01-201)\""<<endl;
	cout << "\"Elija La Opcion 3. para mostrar formato (01-01-201)\""<<endl;
	cout << "\t\t\t\"Opcion: \"";
	int opc;
	cin >> opc;
	clearScreen();
	mostrarFecha(mes,dia,ano,opc);



	pausa();
	return 0;
}

void clearScreen() {//duncion de desplazamiento de los contenidos
	cout << "\033[2J\033[1;1H";
}

void pausa() {//funcion de pausa
	cout << "Presione cualquier tecla para continuar...";
	cin.get();
}

void mostrarFecha(int a,int b, int c,int opcion) {// funcion traductora de fecha
	string mesName;

	if(a<=12) {// If que Comprueba que el mes esta en el rango permitido del 1 - 12

		switch (opcion) {

			case 1: {  // Caso Para Colocar Nombre Completo del mes
				switch (a) {
					case 1:
						mesName = "Enero";
						break;
					case 2:
						mesName = "Febrero";
						break;
					case 3:
						mesName = "Marzo";
						break;
					case 4:
						mesName = "Abril";
						break;
					case 5:
						mesName = "Mayo";
						break;
					case 6:
						mesName = "Junio";
						break;
					case 7:
						mesName = "Julio";
						break;
					case 8:
						mesName = "Agosto";
						break;
					case 9:
						mesName = "Septiembre";
						break;
					case 10:
						mesName = "Octubre";
						break;
					case 11:
						mesName = "Noviembre";
						break;
					case 12:
						mesName = "Diciembre";
						break;
				}
				break;
			}

			case 2: { //Caso Para Colocar Acronimo del mes
				switch (a) {
					case 1:
						mesName = "Ene";
						break;
					case 2:
						mesName = "Feb";
						break;
					case 3:
						mesName = "Mar";
						break;
					case 4:
						mesName = "Abr";
						break;
					case 5:
						mesName = "May";
						break;
					case 6:
						mesName = "Jun";
						break;
					case 7:
						mesName = "Jul";
						break;
					case 8:
						mesName = "Ago";
						break;
					case 9:
						mesName = "Sep";
						break;
					case 10:
						mesName = "Oct";
						break;
					case 11:
						mesName = "Nov";
						break;
					case 12:
						mesName = "Dic";
						break;

				}
				break;
			}

			case 3: { // Caso Para Colocar Numero del mes
				mesName =to_string(a);
				break;
			}

		}

		cout<<mesName<<" - " << b << " - " << c << endl;
	} else {// mensaje de error en caso de que supere el rango permitido del 1 - 12
		cout << "Existe un total de 12 meses en un anio y cada mes puede tener hasta 31 dias como maximo."<<endl;

	}

}
