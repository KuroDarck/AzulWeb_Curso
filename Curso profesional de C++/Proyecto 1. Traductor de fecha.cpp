/*
Escriba un programa que lea tres valores enteros que represente el mes, el dia y el aÃ±o con cuatro dia gitos.
El programa deberÃ¡ mostrar la fecha en uno de los formatos siguientes, dependiendo de la selecciÃ³n del usuario.
Si el usuario introduce 1, se mostrara el mes con palabra (Enero), el dia como un entero (11) y el aÃ±o (1999).
Si se introduce un 2, se mostrara el mes con una abreviatura de tres letras (Enero), el dia como un entero (11) y el aÃ±o (1999).
 Si se produce un 3, se mostrara el mes como un entero (01), el dia como un entero (11) y el aÃ±o (1999). Solo usar lo expuesto en temas vistos previamente.

*/
#include <iostream>
#include <string>

void clearScreen();
void pause();
void showDate(int month, int day, int year, int option);

int main() {
    int month, day, year;

    // Reading the values to translate
    std::cout << "Enter the date to translate (Month-Day-Year):" << std::endl;
    std::cout << "Month: ";
    std::cin >> month;
    std::cout << "Day: ";
    std::cin >> day;
    std::cout << "Year: ";
    std::cin >> year;

    // Menu for date translation options
    clearScreen();
    std::cout << "\t\t\t\"Choose your preferred option\"" << std::endl;
    std::cout << "\"Choose Option 1 to display format (January-01-201)\"" << std::endl;
    std::cout << "\"Choose Option 2 to display format (Jan-01-201)\"" << std::endl;
    std::cout << "\"Choose Option 3 to display format (01-01-201)\"" << std::endl;
    std::cout << "\t\t\t\"Option: \"";
    int option;
    std::cin >> option;
    clearScreen();
    showDate(month, day, year, option);

    pause();
    return 0;
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void pause() {
    std::cout << "Press any key to continue...";
    std::cin.get();
}

void showDate(int month, int day, int year, int option) {
    std::string monthName;

    if (month <= 12) {
        switch (option) {
            case 1: {
                switch (month) {
                    case 1:
                        monthName = "January";
                        break;
                    case 2:
                        monthName = "February";
                        break;
                    case 3:
                        monthName = "March";
                        break;
                    case 4:
                        monthName = "April";
                        break;
                    case 5:
                        monthName = "May";
                        break;
                    case 6:
                        monthName = "June";
                        break;
                    case 7:
                        monthName = "July";
                        break;
                    case 8:
                        monthName = "August";
                        break;
                    case 9:
                        monthName = "September";
                        break;
                    case 10:
                        monthName = "October";
                        break;
                    case 11:
                        monthName = "November";
                        break;
                    case 12:
                        monthName = "December";
                        break;
                }
                break;
            }
            case 2: {
                switch (month) {
                    case 1:
                        monthName = "Jan";
                        break;
                    case 2:
                        monthName = "Feb";
                        break;
                    case 3:
                        monthName = "Mar";
                        break;
                    case 4:
                        monthName = "Apr";
                        break;
                    case 5:
                        monthName = "May";
                        break;
                    case 6:
                        monthName = "Jun";
                        break;
                    case 7:
                        monthName = "Jul";
                        break;
                    case 8:
                        monthName = "Aug";
                        break;
                    case 9:
                        monthName = "Sep";
                        break;
                    case 10:
                        monthName = "Oct";
                        break;
                    case 11:
                        monthName = "Nov";
                        break;
                    case 12:
                        monthName = "Dec";
                        break;
                }
                break;
            }
            case 3: {
                monthName = std::to_string(month);
                break;
            }
        }
        std::cout << monthName << " - " << day << " - " << year << std::endl;
    } else {
        std::cout << "There are 12 months in a year, and each month can have a maximum of 31 days." << std::endl;
    }
}
