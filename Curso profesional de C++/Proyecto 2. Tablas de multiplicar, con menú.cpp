#include<iostream>
using namespace std;
/*
Realice un programa en C++ para mostrar las tablas de multiplicar. El programa debe de mostrar un mensaje
 con las tablas del 1 al 10, el usuario debe de elegir cual tabla desea que se imprima en pantalla, el
 usuario tambien puede elegir hasta que numeroero se va a mostrar la tabla, por ejemplo la tabla del 5
 hasta el numero 20. Al final de mostrar la tabla el usuario puede elegir si desea regresar al menu o
 finalizar el programa. Se utiliza If, While o Do While y For.
*/

void clearScreen();//Schroll

int main() {
	int Tabla,Limite,Multi;
	char opc;
	system("COLOR 04");// solo en Windowas Cambia a rojo la fuentee
	do {
		cout<<"\t\t\t\t:Las Tablas de Multiplicar:"<<endl;
		cout<<"\nElija que tabla desea mostrar ";
		cout<<"\t| 1-2-3-4-5-6-7-8-9-10|"<<endl;


		do { // comprueba entrada de usuario
			cout<<"Tabla del: ";
			cin>>Tabla;
		} while(Tabla==0 || Tabla>10);
		
		cout<<"Hasta Donde desea Multiplicar: ";
		cin>>Limite;
		cout<<endl;
		
		clearScreen();

		cout<<"\t\t\t\t:La Tablas del: "<<Tabla<<endl;
		for(int i=1; i<=Limite; i++) { // multiplica e imprime la tabla hasta su limite
			Multi=Tabla*i;
			cout<<"|"<<Tabla<<"*"<<i<<"="<<Multi<<"|"<<endl;
		}
		
		cout<<"\nDesea Volver a MultiplicarMarque: |C|"<<endl;
		cout<<"Desea Salir Marque: |S|"<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		clearScreen();
		
	} while((opc=='C'|| opc=='c')&(opc!='S'||opc!='s'));// opciones para el usuario salir o multiplicar de nuevo

	return 0;
}

void clearScreen() {
	cout << "\033[2J\033[1;1H";
}