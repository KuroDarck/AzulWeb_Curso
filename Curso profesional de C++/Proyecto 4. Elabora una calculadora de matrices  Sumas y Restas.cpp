
/*Elabora una calculadora de matrices | Sumas y Restas.
*/
#include <iostream>

void clearScreen();

int Matrix1[10][10], Matrix2[10][10], ResultMatrix[10][10];
int rows1, columns1, rows2, columns2;

int main() {
	char option;
	do {
		std::cout << "Enter the number of rows for the first matrix: ";
		std::cin >> rows1;
		std::cout << "Enter the number of columns for the first matrix: ";
		std::cin >> columns1;
		std::cout << std::endl;
		clearScreen();
		std::cout << "Enter the number of rows for the second matrix: ";
		std::cin >> rows2;
		std::cout << "Enter the number of columns for the second matrix: ";
		std::cin >> columns2;
		clearScreen();
		std::cout << "\nEnter data for the first matrix:" << std::endl;
		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < columns1; j++) {
				std::cout << "Enter data [" << i << "][" << j << "]: ";
				std::cin >> Matrix1[i][j];
			}
		}
		clearScreen();
		std::cout << "\nEnter data for the second matrix:" << std::endl;
		for (int i = 0; i < rows2; i++) {
			for (int j = 0; j < columns2; j++) {
				std::cout << "Enter data [" << i << "][" << j << "]: ";
				std::cin >> Matrix2[i][j];
			}
		}
		clearScreen();
		int operationResult;
		std::cout << "1. Addition" << std::endl;
		std::cout << "2. Subtraction" << std::endl;
		std::cout << "Select an option: ";
		std::cin >> operationResult;
		clearScreen();
		if (operationResult == 1) {
			if ((rows1 == rows2) && (columns1 == columns2)) {
				for (int i = 0; i < rows2; i++) {
					for (int j = 0; j < columns2; j++) {
						ResultMatrix[i][j] = Matrix1[i][j] + Matrix2[i][j];
					}
				}
				std::cout << "The result of the addition is:" << std::endl;
				for (int i = 0; i < rows2; i++) {
					std::cout << "[ ";
					for (int j = 0; j < columns2; j++) {
						std::cout << ResultMatrix[i][j] << " ";
					}
					std::cout << "]" << std::endl;
				}
			}
			else {
				std::cout << "The matrices must have the same number of rows and columns to perform addition." << std::endl;
			}
		}
		else if (operationResult == 2) {
			if ((rows1 == rows2) && (columns1 == columns2)) {
				for (int i = 0; i < rows2; i++) {
					for (int j = 0; j < columns2; j++) {
						ResultMatrix[i][j] = Matrix1[i][j] - Matrix2[i][j];
					}
				}
				std::cout << "The result of the subtraction is:" << std::endl;
				for (int i = 0; i < rows2; i++) {
					std::cout << "[ ";
					for (int j = 0; j < columns2; j++) {
						std::cout << ResultMatrix[i][j] << " ";
					}
					std::cout << "]" << std::endl;
				}
			}
			else {
				std::cout << "The matrices must have the same number of rows and columns to perform subtraction." << std::endl;
			}
		}
		std::cout << "S. Exit" << std::endl;
		std::cout << "C. Continue" << std::endl;
		std::cout << "Select an option: ";
		std::cin >> option;
		clearScreen();
	} while ((option != 'S' && option != 's') && (option == 'C' || option == 'c'));
}

void clearScreen() {
	std::cout << "\033[2J\033[1;1H";
}
