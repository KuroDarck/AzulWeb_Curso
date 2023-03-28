#include<iostream>
#include<conio.h>
using namespace std;
/*Crea un programa en C++ para guardar las notas de N alumnos, N tiene que ser mayor o igual que 20 o menor o igual que 30,
 esto se debe de verificar en el programa, y en caso de que el numero de alumnos este fuera del rango se debe de mostrar la
 opción de ingresar de nuevo el numero de alumnos.

Una vez que tengamos los notas guardadas dentro de un arreglo, hay que sumar todas las calificaciones, mostrar el promedio del
 salón, mostrar el alumno con nota mas alta, mostrar alumnos con nota promedio (rango de promedio – 1 a promedio + 1)
 y el alumno con menor nota.

A los alumnos que tiene una nota menor o igual a 6 se les encargo un trabajo, este trabajo suma un punto mas a su nota.
 Se debe de utilizar el arreglo con las notas originales para generar otro arreglo con las notas modificadas de estos alumnos.
 Imprimir las dos notas en columnas diferentes.

Al final se debe de mostrar la opción para volver a calcular mas notas de alumnos, o finalizar el programa*/

int main()
{
	int Alumno[30];
	int N=0,mayor=0,menor=11;
	int Suma=0,tam=0;;
	char opc;
	int Promedio;
	system("COLOR 04");

	do {
		printf("%50s\n","Salon de Clases RHM");
		cout<<"Ingrese Cantidad de Alumnos: ";
		cin>>N;
		while(N<20 || N>30) {
			system("cls");
			printf("%50s\n","Salon de Clases RHM");
			cout<<"La Cantidad De Alumno Deve Ser Mayor A 20 y Menor A 30"<<endl;
			cout<<"Ingrese Cantidad de Alumnos: ";
			cin>>N;
		}
		for(int i=0; i<N; i++) {
			cout<<"Ingrese la Nota del Alumno ["<<i+1<<"] :";
			cin>>Alumno[i];
			Suma+=Alumno[i];
		}
		Promedio=Suma/N;
		printf("\n%1s%6d\n","PROMEDIO DEL SALON: ",Promedio);
		cout<<"\nNOTA MAS ALTA"<<endl;
		for(int i=0; i<N; i++) {
			if(Alumno[i]>mayor) {
				mayor=Alumno[i];
			}

		}
		for(int i=0; i<N; i++) {
			if(Alumno[i]==mayor) {
				printf("%1s%2d%7s%5d\n","Alumno #",(i+1)," | Nota:",mayor);
			}
		}
		cout<<"\nNOTA MAS VAJA"<<endl;
		for(int i=0; i<N; i++) {
			if(Alumno[i]<menor) {
				menor=Alumno[i];
			}
		}
		for(int i=0; i<N; i++) {
			if(Alumno[i]==menor) {
				printf("%1s%2d%7s%5d\n","Alumno #",(i+1)," | Nota:",menor);
			}
		}
		cout<<"\nNotas en un Rango Promedio -1:"<<endl;
		for(int i=0; i<N; i++) {
			int rango1=(Promedio-1);
			if(Alumno[i]==rango1) {
				printf("%1s%2d%7s%5d\n","Alumno #",(i+1)," | Nota:",Alumno[i]);
			}
		}
		cout<<"\nNotas en un Rango Promedio +1:"<<endl;
		for(int i=0; i<N; i++) {
			int rango2=(Promedio+1);
			if(Alumno[i]==rango2) {
				printf("%1s%2d%7s%5d\n","Alumno #",(i+1)," | Nota:",Alumno[i]);
			}
		}

		for(int i=0; i<N; i++) {
			if(Alumno[i]<=6) {
				tam++;
			}
		}
		int Alumno1[tam],l=0,i=0;;
		while(i<N) {	
			if(Alumno[i]<=6&&l<tam){
			Alumno1[l]=Alumno[i]+1;	
			l++;
			}
			else{
				i++;
			}	
		i++;
		}
	
		
	

		cout<<"\nNota mas UN punto por el trabajo Realizado"<<endl;
		for(int j=0; j<tam; j++) {

			printf("%1s%3d%7s%5d\n","Nota Anterior:",(Alumno1[j]-1)," | Nota Actual:",Alumno1[j]);
		}
		cout<<"\n\nDesea Volver a Calcular Nota De Atros Alumnos arque 'C'"<<endl;
		cout<<"Desea Salir 'S': "<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		system("cls");
	} while((opc!='S'||opc!='s')&&(opc=='C'||opc=='c'));

	return 0;
	getch();
}
