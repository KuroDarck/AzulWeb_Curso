/*
Realice un programa en C++ para mostrar las tablas de multiplicar. El programa debe de mostrar un mensaje
 con las tablas del 1 al 10, el usuario debe de elegir cual tabla desea que se imprima en pantalla, el
 usuario tambien puede elegir hasta que numeroero se va a mostrar la tabla, por ejemplo la tabla del 5
 hasta el numero 20. Al final de mostrar la tabla el usuario puede elegir si desea regresar al menu o
 finalizar el programa. Se utiliza If, While o Do While y For.
*/
#include <iostream>

void clearScreen(); // Function to clear the screen

int main() {
    int Table, Limit, Multi;
    char option;
    system("COLOR 04"); // Changes the font color to red (Windows only)

    do {
        std::cout << "\t\t\t\tMultiplication Tables:\n";
        std::cout << "\nChoose which table to display: 1-2-3-4-5-6-7-8-9-10\n";

        do {
            std::cout << "Table of: ";
            std::cin >> Table;
        } while (Table == 0 || Table > 10);

        std::cout << "Up to which number do you want to multiply: ";
        std::cin >> Limit;
        std::cout << std::endl;

        clearScreen();

        std::cout << "\t\t\t\tTable of " << Table << std::endl;

        for (int i = 1; i <= Limit; i++) { // Multiply and print the table up to the limit
            Multi = Table * i;
            std::cout << "|" << Table << "*" << i << "=" << Multi << "|" << std::endl;
        }

        std::cout << "\nTo multiply again, enter: |C|\n";
        std::cout << "To exit, enter: |S|\n";
        std::cout << "Option: ";
        std::cin >> option;
        clearScreen();

    } while ((option == 'C' || option == 'c') && (option != 'S' || option != 's')); // User options to continue or exit

    return 0;
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}
