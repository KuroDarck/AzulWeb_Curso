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
void clearScreen();
const int MAX_ALUMNOS = 30;
const int MIN_ALUMNOS = 20;
const int MAX_NOTA = 10;
const int MIN_NOTA = 1;


int main() {
	int Alumno[MAX_ALUMNOS];
	int mayor=0,menor=11;
	int Suma=0,tam=0;;
	char opc;

	system("COLOR 04");// solo en Windows

	do {
		printf("%50s\n","Salon de Clases RHM");
		cout<<"Ingrese Cantidad de Alumnos: ";
		int limiteAlumno;
		cin>>limiteAlumno;

		while(limiteAlumno<MIN_ALUMNOS || limiteAlumno>MAX_ALUMNOS) {
			system("cls");
			printf("%50s\n","Salon de Clases RHM");
			cout<<"La Cantidad De Alumno Deve Ser Mayor A 20 y Menor A 30"<<endl;
			cout<<"Ingrese Cantidad de Alumnos: ";
			cin>>limiteAlumno;
		}

		clearScreen();
		int iterador=0;
		do {
			int notaAlumno;
			cout<<"Ingrese la Nota del Alumno ["<<iterador+1<<"] :";
			cin>>notaAlumno;
			if((notaAlumno<=MAX_NOTA)&&(notaAlumno>=MIN_NOTA)) {
				Alumno[iterador]=notaAlumno;
				Suma+=Alumno[iterador];
			}
			while((notaAlumno>MAX_NOTA)||(notaAlumno<MIN_NOTA)) {

				cout<<"Ingrese la Nota del Alumno ["<<iterador+1<<"] :";
				cin>>notaAlumno;
				Alumno[iterador]=notaAlumno;
				Suma+=Alumno[iterador];

			}

			iterador++;
		} while(iterador<limiteAlumno);

		int Promedio;
		Promedio=Suma/limiteAlumno;
		printf("\n%1s%6d\n","PROMEDIO DEL SALON: ",Promedio);
		cout<<"\nNOTA MAS ALTA"<<endl;
		for(int i=0; i<limiteAlumno; i++) {
			if(Alumno[i]>mayor) {
				mayor=Alumno[i];
			}

		}
		for(int i=0; i<limiteAlumno; i++) {
			if(Alumno[i]==mayor) {
				printf("%1s%2d%7s%5d\n","Alumno #",(i+1)," | Nota:",mayor);
			}
		}
		cout<<"\nNOTA MAS VAJA"<<endl;
		for(int i=0; i<limiteAlumno; i++) {
			if(Alumno[i]<menor) {
				menor=Alumno[i];
			}
		}

		for(int i=0; i<limiteAlumno; i++) {
			if(Alumno[i]==menor) {
				printf("%1s%2d%7s%5d\n","Alumno #",(i+1)," | Nota:",menor);
			}
		}
		cout<<"\nNotas en un Rango Promedio -1:"<<endl;
		for(int i=0; i<limiteAlumno; i++) {
			int rango1=(Promedio-1);
			if(Alumno[i]==rango1) {
				printf("%1s%2d%7s%5d\n","Alumno #",(i+1)," | Nota:",Alumno[i]);
			}
		}
		cout<<"\nNotas en un Rango Promedio +1:"<<endl;
		for(int i=0; i<limiteAlumno; i++) {
			int rango2=(Promedio+1);
			if(Alumno[i]==rango2) {
				printf("%1s%2d%7s%5d\n","Alumno #",(i+1)," | Nota:",Alumno[i]);
			}
		}

		for(int i=0; i<limiteAlumno; i++) {
			if(Alumno[i]<=6) {
				tam++;
			}
		}
		int Alumno1[tam],k=0,i=0;;
		while(i<limiteAlumno) {
			if((Alumno[i]<=6) && (k<tam)) {
				Alumno1[k]=Alumno[i]+1;
				k++;
			} else {
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
}

void clearScreen() {
	cout << "\033[2J\033[1;1H";
}