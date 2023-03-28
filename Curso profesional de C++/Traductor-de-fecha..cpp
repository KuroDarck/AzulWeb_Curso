#include <iostream>
#include <conio.h>
using namespace std;
/*
Escriba un programa que lea tres valores enteros que represente el mes, el dia y el aÃ±o con cuatro dia gitos. 
El programa deberÃ¡ mostrar la fecha en uno de los formatos siguientes, dependiendo de la selecciÃ³n del usuario. 
Si el usuario introduce 1, se mostrara el mes con palabra (Enero), el dia como un entero (11) y el aÃ±o (1999). 
Si se introduce un 2, se mostrara el mes con una abreviatura de tres letras (Enero), el dia como un entero (11) y el aÃ±o (1999).
 Si se produce un 3, se mostrara el mes como un entero (01), el dia como un entero (11) y el aÃ±o (1999). Solo usar lo expuesto en temas vistos previamente.

*/

int main()
{
    int mes, dia, ano;
    
    //Lectura de Los valores a Traducir
    
    cout << "Ingrese la fecha a Traducir: (Mes-Dia-Anio)" << endl;
    cout << "Mes: ";
    cin >> mes;
    cout << "Dia: ";
    cin >> dia;
    cout << "Anio: ";
    cin >> ano;
    int opc;
    
//Menu de el  traductor de Fecha

    cout << "\t\t\t\"Elija la opcion de su preferencia\""<<endl;
    cout << "\"Elija La Opcion 1. para mostrar formato (Enero-01-201)\""<<endl;
    cout << "\"Elija La Opcion 2. para mostrar formato (Ene-01-201)\""<<endl;
    cout << "\"Elija La Opcion 3. para mostrar formato (01-01-201)\""<<endl;
    cout << "\t\t\t\"Opcion: \"";
    cin >> opc;
    cout<<endl;
    
    // Siclos de Decicion Para el Primer formato
    
    if (opc == 1)
    {
        switch (mes)
        {
        case 1:
            cout << "Enero-" << dia << "-" << ano << endl;
            break;
        case 2:
            cout << "Febrero-" << dia << "-" << ano << endl;
            break;
        case 3:
            cout << "Marzo-" << dia << "-" << ano << endl;
            break;
        case 4:
            cout << "Abril-" << dia << "-" << ano << endl;
            break;
        case 5:
            cout << "Mayo-" << dia << "-" << ano << endl;
            break;
        case 6:
            cout << "Junio-" << dia << "-" << ano << endl;
            break;
        case 7:
            cout << "Julio-" << dia << "-" << ano << endl;
            break;
        case 8:
            cout << "Agosto-" << dia << "-" << ano << endl;
            break;
        case 9:
            cout << "Septiembre-" << dia << "-" << ano << endl;
            break;
        case 10:
            cout << "Octubre-" << dia << "-" << ano << endl;
            break;
        case 11:
            cout << "Noviembre-" << dia << "-" << ano << endl;
            break;
        case 12:
            cout << "Diciembre-" << dia << "-" << ano << endl;
            break;
        default:
             cout << "Solo existen 12 meses y 31 dias maximo";
        }
    }
    
     // Siclos de Decicion Para el Segundo formato
    
    if (opc == 2)
    {
        switch (mes)
        {
        case 1:
            cout << "Ene-" << dia << "-" << ano << endl;
            break;
        case 2:
            cout << "Feb-" << dia << "-" << ano << endl;
            break;
        case 3:
            cout << "Mar-" << dia << "-" << ano << endl;
            break;
        case 4:
            cout << "Abr-" << dia << "-" << ano << endl;
            break;
        case 5:
            cout << "May-" << dia << "-" << ano << endl;
            break;
        case 6:
            cout << "Jun-" << dia << "-" << ano << endl;
            break;
        case 7:
            cout << "Jul-" << dia << "-" << ano << endl;
            break;
        case 8:
            cout << "Ago-" << dia << "-" << ano << endl;
            break;
        case 9:
            cout << "Sep-" << dia << "-" << ano << endl;
            break;
        case 10:
            cout << "Oct-" << dia << "-" << ano << endl;
            break;
        case 11:
            cout << "Nov-" << dia << "-" << ano << endl;
            break;
        case 12:
            cout << "Dic-" << dia << "-" << ano << endl;
            break;
        default:
             cout << "Solo existen 12 meses y 31 dias maximo";
        }
    }
    
     // Siclos de Decicion Para el Tercer formato
    
    if (opc == 3)
    {
        switch (mes)
        {
        case 1:
            cout << mes << "-" << dia << "-" << ano << endl;
            break;
        case 2:
            cout << mes << "-" << dia << "-" << ano << endl;
            break;
        case 3:
            cout << mes << "-" << dia << "-" << ano << endl;
            break;
        case 4:
            cout << mes << "-" << dia << "-" << ano << endl;
            break;
        case 5:
            cout << mes << "-" << dia << "-" << ano << endl;
            break;
        case 6:
            cout << mes << "-" << dia << "-" << ano << endl;
            break;
        case 7:
            cout << mes << "-" << dia << "-" << ano << endl;
            break;
        case 8:
            cout << mes << "-" << dia << "-" << ano << endl;
            break;
        case 9:
            cout << mes << "-" << dia << "-" << ano << endl;
            break;
        case 10:
            cout << mes << "-" << dia << "-" << ano << endl;
            break;
        case 11:
            cout << mes << "-" << dia << "-" << ano << endl;
            break;
        case 12:
            cout << mes << "-" << dia << "-" << ano << endl;
            break;
            default:
            cout << "Solo existen 12 meses y 31 dias maximo";
        }
    }
    return 0;
    getch();
}