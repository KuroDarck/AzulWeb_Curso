/*
Azul Web acaba de sacar una nueva plataforma de video, donde se van a publicar películas. Las películas tiene los siguientes atributos; Nombre de la película y Fecha de lanzamiento.

Crea un programa en C++ que haga lo siguiente:

1.- Permitir guardar 20 registros en una matriz; Nombre de película y año de lanzamiento.

2.- Un menú que nos va a dar tres opciones:

>> a) Mostrar películas desde las más viejas a las más nuevas.

>> b) Mostrar películas desde las más nuevas a las más viejas.

>> c) Mostrar películas de un año en concreto.

3.- Opción de regresar al menú o salir del programa.

Utiliza solo lo aprendido en los módulos anteriores.
*/

#include <iostream>
#include <string.h>

using namespace std;

string Peliculas[20][2];
string Nombre, anio;
int opc,Clun=0;

int main()
{
	//Ingreso de Los Datos de Nombre y Año De Las Peliculas

	system("cls");
	cout << "\t************************ Tienda De Videos RHM ************************" << endl;
	for(int i=0; i<20; i++) {

		cout<<"\t***** Nombre de La Pelicula: ";
		getline(cin,Nombre);
		cout<<"\t***** Anio de La Pelicula: ";
		getline(cin,anio);
		Peliculas[i][Clun]=Nombre;
		Peliculas[i][Clun+1]=anio;
	}

//Orddenando Por Insercion 
for (int i = 0; i < 4; i++) {
					int	pos = i;
					string aux0 = Peliculas[i][Clun];
					string aux = Peliculas[i][Clun+1];
					while ((pos > 0 ) && (Peliculas[pos - 1][Clun+1] > aux)) {
						Peliculas[pos][Clun] = Peliculas[pos - 1][Clun];
						Peliculas[pos][Clun+1] = Peliculas[pos - 1][Clun+1];
						pos--;
					};
					Peliculas[pos][Clun]=aux0;
					Peliculas[pos][Clun+1] = aux;
					
				};

// inicio del menu de Salida en pantalla
	do {
		system("cls");
		cout << "\t************************ Tienda De Videos RHM ************************" << endl;
		cout << "\t*************************** Menu Principal ***************************" << endl;
		cout<<endl;
		cout << "\t***** 1. Mostrar peliculas desde las mas viejas a las mas nuevas *****" << endl;
		cout << "\t***** 2. Mostrar peliculas desde las mas nuevas a las mas viejas *****" << endl;
		cout<<"\t***** 3. Mostrar peliculas de un anio en concreto *****"<<endl;
		cout<<"\t\tOpcion: ";
		cin>>opc;


		switch (opc) {
			case 1:
				cout<<"\n\t***** Mostrando peliculas desde las mas viejas a las mas nuevas *****"<<endl;
				cout<<"\n\t***** Nombre \t\t"<<"|"<<"\t\tAnio *****"<<endl;
				for(int i=0;i<20;i++){
					cout<<"\t***** "<<Peliculas[i][Clun]<<"\t\t"<<"|"<<"\t\t"<<Peliculas[i][Clun+1]<<" *****"<<endl;
				}
				break;
				
				case 2: 
				cout<<"\n\t***** Mostrando peliculas desde las mas nuevas a las mas viejas *****"<<endl;
				cout<<"\n\t***** Nombre \t\t"<<"|"<<"\t\tAnio *****"<<endl;
				for(int i=19;i>=0;i--){
					cout<<"\t***** "<<Peliculas[i][Clun]<<"\t\t"<<"|"<<"\t\t"<<Peliculas[i][Clun+1]<<" *****"<<endl;
				}
				
				break;
			case 3:
				cin.ignore();
				int fecha;
				cout<<"\n\t***** Mostrando peliculas de un anio en concreto *****"<<endl;
				cout<<"\n\t***** DE Que Anio es La Pelicula: ";
				getline(cin,anio);
				for(int i=0;i<20;i++){
					if(Peliculas[i][Clun+1]==anio){
					fecha=i;	
					}
				}
				cout<<"\n\t***** Nombre \t\t"<<"|"<<"\t\tAnio *****"<<endl;
				cout<<"\t***** "<<Peliculas[fecha][Clun]<<"\t\t"<<"|"<<"\t\t"<<Peliculas[fecha][Clun+1]<<" *****"<<endl;
				break;

		}
		//Menu de decicion salida o continuar
		cout << "\n\t*************************** Sub Menu ***************************" << endl;
		cout << "\t***** 1. Regresar al Menu" << endl;
		cout << "\t***** 2. Salir" << endl;
		cout << "\t***** Opcion: ";
		cin >> opc;

	} while (opc==1);
}