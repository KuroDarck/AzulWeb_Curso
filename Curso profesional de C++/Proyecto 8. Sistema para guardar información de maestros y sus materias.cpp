/*En Azul Web se desea hacer un programa en C++ que guarde la información de los maestros que ofrecen cursos dentro de
 su plataforma, el programa debe de realizar lo siguiente:

1.- Permitir guardar datos completos del maestro. Maestro; nombre, edad, país, especialidad. Especialidad; Programación, base de datos y servidores.

2.- También se desea ordenar los cursos que se están brindando. Curso; maestro, especialidad, y fecha. Fecha: día, mes y año.

(Todos los dato se deben de guardar al momento de programar, no hay que pedírselo al usuario).

3.- Al momento de correr el programa se debe de mostrar en pantalla el siguiente menú:

>> Buscar cursos pro maestro.

>> Buscar cursos por especialidad.

>> Buscar cursos mayores a un año brindado por el usuario.

>> Buscar cursos menores a un año brindado por el usuario.

>> Permitir al usuario modificar cualquiera de los datos mostrados anteriormente utilizando una contraseña.
 (La contraseña la definimos al momento de programar).

>> Permitir salir del programa. (El programa no se debe de cerrar hasta que el usuario así lo desee).

Nota: Solo se puede utilizar lo aprendido en los módulos anteriores.
*/

#include <iostream>

using namespace std;

struct Fecha { // estructura para la fecha
	int Dia;
	int Mes;
	int Anio;
};
struct Maestro {// estructura para la Maestro
	string nombre;
	int edad;
	string pais;
	string Especialidad;
};
struct {// estructura para Nombre del curso, Profesor y fecha
	string NombreCurso;
	Maestro maestro;
	Fecha fecha;
} curso[4];


int main() {
	
	int opc;
	string Password="PagePorSufrir";
	
	//Guardado de los datos en el array de Estructura curso
	curso[0].maestro.nombre = "Alejandro Taboada";
	curso[0].maestro.edad = 22;
	curso[0].maestro.pais = "Peru";
	curso[0].maestro.Especialidad = "Programacion";
	curso[0].NombreCurso = "C++ Profecional";
	curso[0].fecha.Dia = 12;
	curso[0].fecha.Mes = 07;
	curso[0].fecha.Anio = 2019;

	curso[1].maestro.nombre = "Rodrigo Alvarez";
	curso[1].maestro.edad = 45;
	curso[1].maestro.pais = "Guatemala";
	curso[1].maestro.Especialidad = "Base De Datos";
	curso[1].NombreCurso = "MySQL Principiante a Avansado";
	curso[1].fecha.Dia = 25;
	curso[1].fecha.Mes = 3;
	curso[1].fecha.Anio = 2020;

	curso[2].maestro.nombre = "Noel Urbina";
	curso[2].maestro.edad = 30;
	curso[2].maestro.pais = "Mexico";
	curso[2].maestro.Especialidad = "Servidores";
	curso[2].NombreCurso = "Linux Services";
	curso[2].fecha.Dia = 23;
	curso[2].fecha.Mes = 11;
	curso[2].fecha.Anio = 2021;

	curso[3].maestro.nombre = "Maxi Reyes";
	curso[3].maestro.edad = 25;
	curso[3].maestro.pais = "Panama";
	curso[3].maestro.Especialidad = "Base De Datos";
	curso[3].NombreCurso = "MySQL Server";
	curso[3].fecha.Dia = 6;
	curso[3].fecha.Mes = 1;
	curso[3].fecha.Anio = 2022;
	//fin del guardado de datos

	do {
		system("cls");
		cout << "*****************************************************************" << endl;

		cout << "*\t\t\tMENU RHM\t\t\t\t*"<<endl;
		cout << "*****************************************************************" << endl;

		cout << "1. Buscar cursos por maestro: "<<endl;

		cout << "2. Buscar cursos por especialidad: "<<endl;

		cout << "3. Buscar cursos mayores a un anio brindado por el usuario: "<<endl;

		cout << "4. Buscar cursos menores a un anio brindado por el usuario: "<<endl;

		cout << "5. Modificar Datos"<<endl;

		cout << "6. Salir"<<endl;
		cout<<"Seleccion: ";
		cin>>opc;
		cout << "*****************************************************************" << endl;
		switch(opc) {
			case 1: {


				string buscar;
				int count=0;
				cout<<"Cursos Por Mestro"<<endl;
				cout<<"Ingrese Nombre Del Maestro: ";
				cin.ignore();
				getline(cin,buscar);
				cout << "*****************************************************************" << endl;
				for(int i=0; i<4; i++) {

					if(curso[i].maestro.nombre==buscar) {
						cout<<"Curso: "<<curso[i].NombreCurso<<endl;
						cout<<"Mestro: "<<curso[i].maestro.nombre<<endl;
						cout<<"Especialidad: "<<curso[i].maestro.Especialidad<<endl;
						cout<<"Edad: "<<curso[i].maestro.edad<<endl;
						cout<<"Nacionalidad: "<<curso[i].maestro.pais<<endl;
						cout<<"Fecha: "<<curso[i].fecha.Dia<<"/"<<curso[i].fecha.Mes<<"/"<<curso[i].fecha.Anio<<endl;
						cout<<endl;
						count++;
					}
				}
				if(count==0) {
					cout<<"Error El Maestro no existe."<<endl;
				}
				system("pause");
				break;
			}

			case 2: {


				string buscar;
				int count=0;
				cout<<"Cursos Por Especialidad"<<endl;
				cout<<"Ingrese Especialidad: ";
				cin.ignore();
				getline(cin,buscar);
				cout << "*****************************************************************" << endl;
				for(int i=0; i<4; i++) {

					if(curso[i].maestro.Especialidad==buscar) {
						cout<<"Curso: "<<curso[i].NombreCurso<<endl;
						cout<<"Mestro: "<<curso[i].maestro.nombre<<endl;
						cout<<"Especialidad: "<<curso[i].maestro.Especialidad<<endl;
						cout<<"Edad: "<<curso[i].maestro.edad<<endl;
						cout<<"Nacionalidad: "<<curso[i].maestro.pais<<endl;
						cout<<"Fecha: "<<curso[i].fecha.Dia<<"/"<<curso[i].fecha.Mes<<"/"<<curso[i].fecha.Anio<<endl;
						cout<<endl;
						count++;
					}
				}
				if(count==0) {
					cout<<"Error La Especialidad no existe."<<endl;
				}
				system("pause");
				break;
			}
			case 3: {

				Fecha fecha1;
				cout<<"Cursos Mayores a un Anio Brindado Por El Usuario"<<endl;
				cout<<"Ingrese Fecha Actual (mm/yyyy): "<<endl;
				cout<<"Mes: ";
				cin>>fecha1.Mes;
				cout<<"Anio: ";
				cin>>fecha1.Anio;
				for(int i=0; i<4; i++) {
					if((fecha1.Anio>curso[i].fecha.Anio)&&(fecha1.Mes>=curso[i].fecha.Mes)) {

						cout<<"Curso: "<<curso[i].NombreCurso<<endl;
						cout<<"Mestro: "<<curso[i].maestro.nombre<<endl;
						cout<<"Especialidad: "<<curso[i].maestro.Especialidad<<endl;
						cout<<"Edad: "<<curso[i].maestro.edad<<endl;
						cout<<"Nacionalidad: "<<curso[i].maestro.pais<<endl;
						cout<<"Fecha: "<<curso[i].fecha.Dia<<"/"<<curso[i].fecha.Mes<<"/"<<curso[i].fecha.Anio<<endl;
						cout<<endl;
					}
				}
				system("pause");
				break;
			}
			case 4: {
				Fecha fecha1;
				cout<<"Cursos Menores a un Anio Brindado Por El Usuario"<<endl;
				cout<<"Ingrese Fecha Actual (mm/yyyy): "<<endl;
				cout<<"Mes: ";
				cin>>fecha1.Mes;
				cout<<"Anio: ";
				cin>>fecha1.Anio;
				for(int i=0; i<4; i++) {
					if((fecha1.Anio-1<=curso[i].fecha.Anio)||(fecha1.Mes<curso[i].fecha.Mes)) {

						cout<<"Curso: "<<curso[i].NombreCurso<<endl;
						cout<<"Mestro: "<<curso[i].maestro.nombre<<endl;
						cout<<"Especialidad: "<<curso[i].maestro.Especialidad<<endl;
						cout<<"Edad: "<<curso[i].maestro.edad<<endl;
						cout<<"Nacionalidad: "<<curso[i].maestro.pais<<endl;
						cout<<"Fecha: "<<curso[i].fecha.Dia<<"/"<<curso[i].fecha.Mes<<"/"<<curso[i].fecha.Anio<<endl;
						cout<<endl;
					}
				}
				system("pause");
				break;
			}
			break;
			case 5: {
				string Clave;
				int intento=0;
				cout <<"Modificar Datos"<<endl;
				while(intento<3) {
					system("cls");
					cout<<"Ingrese clave: ";
					cin.ignore();
					getline(cin,Clave);
					if(Clave==Password) {
						cout<<"Contracenia Correcta"<<endl;
						break;
					} else {
						cout<<"Contracenia Incorrecta Intentelo de Nuevo"<<endl;
						cout<<endl;
					}
					intento++;
					cout<<"Intentos "<<intento<<" Restantes "<<3-intento<<endl;;
					cout<<endl;
					system("pause");
					if(intento==3) {
						cout<<endl;
						cout<<"contenido de edicion Bloqueado"<<endl;
						exit(-1);
					}
				}
				int opc;
				cout<<"1. Editar Nombre"<<endl;
				cout<<"2. Editar Edad"<<endl;
				cout<<"3. Editar Pais"<<endl;
				cout<<"4. Editar Especialidad"<<endl;
				cout<<"5. Editar Nombre del Curso"<<endl;
				cout<<"6. Editar Fecha"<<endl;
				cout<<"Seleccion: ";
				cin>>opc;
				switch(opc) {
					case 1: {
						string Nmbre;
						int Opc;
						cout<<"\tMaestro a Editar Nombre?"<<endl;
						cout<<"1. "<<curso[0].maestro.nombre<<"\n2. "<<curso[1].maestro.nombre<<" \n3. "<<curso[2].maestro.nombre
						    <<" \n4. "<<curso[3].maestro.nombre<<""<<endl;
						cout<<"Seleccione: ";
						cin>>Opc;
						cout<<"Ingrese Nuevo Nombre: ";
						cin.ignore();
						getline(cin,Nmbre);
						curso[Opc-1].maestro.nombre=Nmbre;
						cout<<"Nuevo Nombre: "<<curso[Opc-1].maestro.nombre<<endl;
						system("pause");
						break;
					}

					case 2: {
						int Opc,Nedad;
						cout<<"\tMaestro a Editar Edad?"<<endl;
						cout<<"1. "<<curso[0].maestro.nombre<<"\n2. "<<curso[1].maestro.nombre<<" \n3. "<<curso[2].maestro.nombre
						    <<" \n4. "<<curso[3].maestro.nombre<<""<<endl;
						cout<<"Seleccione: ";
						cin>>Opc;
						cout<<"Ingrese Nueva Edad: ";
						cin>>Nedad;
						curso[Opc-1].maestro.edad=Nedad;
						cout<<"Nueva Edad: "<<curso[Opc-1].maestro.edad<<endl;
						system("pause");
						break;
					}

					case 3: {
						int Opc;
						string pAis;
						cout<<"\tMaestro a Editar Pais?"<<endl;
						cout<<"1. "<<curso[0].maestro.nombre<<"\n2. "<<curso[1].maestro.nombre<<" \n3. "<<curso[2].maestro.nombre
						    <<" \n4. "<<curso[3].maestro.nombre<<""<<endl;
						cout<<"Seleccione: ";
						cin>>Opc;
						cout<<"Ingrese Nueva Pais: ";
						cin.ignore();
						getline(cin,pAis);
						curso[Opc-1].maestro.pais=pAis;
						cout<<"Nueva Nacionalidad: "<<curso[Opc-1].maestro.pais<<endl;
						system("pause");
						break;
					}

					case 4: {
						int Opc;
						string Espe;
						cout<<"\tMaestro a Editar Especialidad?"<<endl;
						cout<<"1. "<<curso[0].maestro.nombre<<"\n2. "<<curso[1].maestro.nombre<<" \n3. "<<curso[2].maestro.nombre
						    <<" \n4. "<<curso[3].maestro.nombre<<""<<endl;
						cout<<"Seleccione: ";
						cin>>Opc;
						cout<<"Ingrese Nueva Especialidad: ";
						cin.ignore();
						getline(cin,Espe);
						curso[Opc-1].maestro.Especialidad=Espe;
						cout<<"Nueva Especialidad: "<<curso[Opc-1].maestro.Especialidad<<endl;
						system("pause");
						break;
					}

					case 5: {
						int Opc;
						string Ncurso;
						cout<<"\tMaestro a Editar Nombre Del Curso?"<<endl;
						cout<<"1. "<<curso[0].maestro.nombre<<"\n2. "<<curso[1].maestro.nombre<<" \n3. "<<curso[2].maestro.nombre
						    <<" \n4. "<<curso[3].maestro.nombre<<""<<endl;
						cout<<"Seleccione: ";
						cin>>Opc;
						cout<<"Ingrese Nuevo Nombre del Curso: ";
						cin.ignore();
						getline(cin,Ncurso);
						curso[Opc-1].NombreCurso=Ncurso;
						cout<<"Nuevo Nombre del Curso: "<<curso[Opc-1].NombreCurso<<endl;
						system("pause");
						break;
					}

					case 6: {
						int Opc;
						Fecha f1;
						cout<<"\tMaestro a Editar Fecha del Curso?"<<endl;
						cout<<"1. "<<curso[0].maestro.nombre<<"\n2. "<<curso[1].maestro.nombre<<" \n3. "<<curso[2].maestro.nombre
						    <<" \n4. "<<curso[3].maestro.nombre<<""<<endl;
						cout<<"Seleccione: ";
						cin>>Opc;
						cout<<"Ingrese Nueva Fecha (dd,mm,yyyy): "<<endl;
						cout<<"Dia: ";
						cin>>f1.Dia;
						cout<<"Mes: ";
						cin>>f1.Mes;
						cout<<"Anio: ";
						cin>>f1.Anio;
						curso[Opc-1].fecha.Dia=f1.Dia;
						curso[Opc-1].fecha.Mes=f1.Mes;
						curso[Opc-1].fecha.Anio=f1.Anio;
						cout<<"Nueva Fecha del Curso: "<<curso[Opc-1].fecha.Dia<<"/"<<curso[Opc-1].fecha.Mes
						    <<"/"<<curso[Opc-1].fecha.Anio<<endl;
						system("pause");
						break;
					}
					default: {

						cout<<"Syntax Error"<<endl;

						break;
					}

				}
				break;
			}
			case 6:
				cout<<"Graciass Por Su Visita"<<endl;
				exit(-1);
				break;
			default:
				cout<<"Error Volviendo al menu Principal"<<endl;
				break;
		}
	} while (opc !=6);

	return 0;
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
