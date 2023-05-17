/*
Crea un programa que ingrese los datos de 20 alumnos, nombre, apellido, nombre de materia 1, calificacion materia 1,
nombre de materia 2, calificacion materia 2, nombre de materia 3, calificación materia 3, nombre de materia 4,
calificación materia 4, nombre de materia 5, calificación materia 5. Y después calcular el promedio general de cada alumno,
 y promedio final del grupo de 20 alumnos.

Mostrar en pantalla.

Nombre con apellido del alumno.
Promedio general de alumno.
Materia con mayor calificacion.
Materia con menor calificacion.
Y al final el promedio general del grupo.

Una vez que se muestre en pantalla, darle la opción al usuario si todos los datos están correctos, y de no ser asi
se pueda modificar el dato erronneo y posteriormente mostrar de nuevo los datos en pantalla ya con los datos correctos.
*/
#include<iostream>
#include<string.h>
using namespace std;

const int MAX_ALUMNOS = 20;
const int MAX_MATERIAS = 5;

string NombreAlu[MAX_ALUMNOS];
string ApellidoAlu[MAX_ALUMNOS];

string Nombre,Apellido,Materia;

string NbreMateria[MAX_ALUMNOS][MAX_MATERIAS];
float Calificacion[MAX_ALUMNOS][MAX_MATERIAS];
float Calif,Prom=0,Suma=0;
float Promedio[MAX_ALUMNOS],ProGeneral=0;


int main()
{
	printf("%50s\n","Salon de Clases RHM");
	
	//LLenado de Dato de Los estudiantes 
	
	for(int i=0; i<MAX_ALUMNOS; i++) {
		cout<<"\nAlumno: N"<<i+1<<endl;
		cout<<"Nombre: ";
		getline(cin,Nombre);
		cout<<"Apellido: ";
		getline(cin,Apellido);
		NombreAlu[i]=Nombre;
		ApellidoAlu[i]=Apellido;
		
		// LLenado de las calificaciones
		for(int j=0; j<MAX_MATERIAS; j++) {
			cout<<"Materia N"<<j+1<<": ";
			getline(cin,Materia);
			cout<<"Calificacion: ";
			cin>>Calif;
			NbreMateria[i][j]=Materia;
			Calificacion[i][j]=Calif;
			cin.ignore();
		}
	}
	// Sacar el Promedio De los estudiantes
	for(int i=0; i<MAX_ALUMNOS; i++) {
		for(int j=0; j<MAX_MATERIAS; j++) {
			Suma+=Calificacion[i][j];
		}
		Prom=Suma/5;
		Promedio[i]=Prom;
		Suma=0;
	}
	
	//suma del promedio  de los estudiantes 
	
	for(int i=0; i<MAX_ALUMNOS; i++) {
		Suma+=Promedio[i];
	}
	ProGeneral=Suma/2;
	Suma=0;
	
	//Limpiesa de pantalla y imprecion de los datos ingresados
	
	system("cls");
	printf("%50s\n","Informacion de Los Estudiantes");
	
	for(int i=0; i<MAX_ALUMNOS; i++) {
		cout<<"\nNombre: "<<NombreAlu[i]<<" Apellido: "<<ApellidoAlu[i]<<endl;
		
		for(int j=0; j<MAX_MATERIAS; j++) {
			cout<<"Materia: "<<NbreMateria[i][j]<<" | "<<"Calificacion: "<<Calificacion[i][j]<<endl;
		}
		cout<<"Promedio: "<<Promedio[i]<<endl;
	}
	
	cout<<"\nPromedio General Del Grupo: "<<ProGeneral<<endl;
	cout<<endl;
	
	//Menu De consulta del estado de los datos
	
	printf("%50s\n","Todos los datos estan correctos");
	cout<<"1. Si"<<endl;
	cout<<"2. No"<<endl;
	cout<<"Opcion: ";
	
	int AlgoMal;
	cin>>AlgoMal;
	do {

        //Menu de edicion de los datos
		if(AlgoMal==2) {
		    
			system("cls");
			printf("%45s\n","Que Dato Esta Mal ");
			cout<<"1. Nombre"<<endl;
			cout<<"2. Apellido"<<endl;
			cout<<"3. Materia"<<endl;
			cout<<"4. Calificacion"<<endl;
			cout<<"Opcion: ";
			int CualDato;
			cin>>CualDato;
			
			int QMatCal;
			
			if(CualDato==3) {
				cout<<"Cual Materia(1,2,3,4 o 5): ";
				cin>>QMatCal;
			}
			if(CualDato==4) {
				cout<<"Cual Nota (1,2,3,4 o 5): ";
				cin>>QMatCal;
			}
			cout<<"De que Alumno (1,2,3,4,5 al 20): ";
			int QEstudiante;
			cin>>QEstudiante;
            
            cin.ignore();
			switch(CualDato) {
				case 1:
				    
					printf("%45s\n","Inicie Correccion");
					cout<<"Nombre: ";
					getline(cin,Nombre);
					NombreAlu[QEstudiante-1]=Nombre;
					
					break;
				case 2:
					printf("%45s\n","Inicie Correccion");
					cout<<"Apellido: ";
					getline(cin,Apellido);
					ApellidoAlu[QEstudiante-1]=Apellido;
                    
					break;
				case 3:
					fflush(stdin);
					printf("%45s\n","Inicie Correccion");
					cout<<"Materia: ";
					getline(cin,Materia);
					NbreMateria[QEstudiante-1][QMatCal-1]=Materia;
                    
					break;
				case 4:
					fflush(stdin);
					printf("%45s\n","Inicie Correccion");
					cout<<"Calificacion: ";
					cin>>Calif;
					Calificacion[QEstudiante-1][QMatCal-1]=Calif;
				
					break;


			}
		} else {
			cout<<"Todos Los Datos Correctos "<<endl;
			cout<<"Fin Del Programa"<<endl;
			exit(-1);
		}
		
		// sub menu de edicion 
		
		printf("%50s\n","Desea Editar Algun Otro Dato");
		cout<<"1. Si"<<endl;
		cout<<"2. No"<<endl;
		cout<<"Opcion: ";
		int opc;
		cin>>opc;
		cin.ignore();
	} while(opc==1);

   //Recalculacion de los promedio de los estudiante y el promedio general

	for(int i=0; i<20; i++) {
		for(int j=0; j<5; j++) {
			Suma+=Calificacion[i][j];
		}
		Prom=Suma/5;
		Promedio[i]=Prom;
		Suma=0;
	}
	for(int i=0; i<20; i++) {
		Suma+=Promedio[i];
	}
	ProGeneral=Suma/2;
	Suma=0;
	
	 //Reimprecion de los datos del los estudiantes
	
	system("cls");
	printf("%50s\n","Informacion Actualizada de Los Estudiantes");
	for(int i=0; i<20; i++) {
		cout<<"\nNombre: "<<NombreAlu[i]<<" Apellido: "<<ApellidoAlu[i]<<endl;
		for(int j=0; j<5; j++) {
			cout<<"Materia: "<<NbreMateria[i][j]<<" | "<<"Calificacion: "<<Calificacion[i][j]<<endl;
		}
		cout<<"Promedio: "<<Promedio[i]<<endl;
	}
	cout<<"\nPromedio General Del Grupo: "<<ProGeneral<<endl;
	return 0;
}