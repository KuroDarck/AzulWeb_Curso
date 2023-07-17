
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
#include <iostream>
#include <cstdlib>
#include <iomanip>

const int MAX_STUDENTS = 30;
const int MIN_STUDENTS = 20;
const int MAX_GRADE = 10;
const int MIN_GRADE = 1;

void clearScreen();

int main() {
    int students[MAX_STUDENTS];
    int highestGrade = 0, lowestGrade = 11;
    int sum = 0, count = 0;
    char option;

    system("COLOR 04"); // only for Windows

    do {
        std::cout << std::setw(50) << "Classroom RHM\n";
        std::cout << "Enter the number of students: ";
        int studentCount;
        std::cin >> studentCount;

        while (studentCount < MIN_STUDENTS || studentCount > MAX_STUDENTS) {
            system("cls");
            std::cout << std::setw(50) << "Classroom RHM\n";
            std::cout << "The number of students must be between 20 and 30.\n";
            std::cout << "Enter the number of students: ";
            std::cin >> studentCount;
        }

        clearScreen();
        int iterator = 0;
        do {
            int studentGrade;
            std::cout << "Enter the grade of student [" << iterator + 1 << "]: ";
            std::cin >> studentGrade;

            if (studentGrade <= MAX_GRADE && studentGrade >= MIN_GRADE) {
                students[iterator] = studentGrade;
                sum += students[iterator];
                count++;
            } else {
                while (studentGrade > MAX_GRADE || studentGrade < MIN_GRADE) {
                    std::cout << "Enter the grade of student [" << iterator + 1 << "]: ";
                    std::cin >> studentGrade;
                    students[iterator] = studentGrade;
                    sum += students[iterator];
                    count++;
                }
            }

            iterator++;
        } while (iterator < studentCount);

        int average = sum / count;
        std::cout << "\n" << std::left << std::setw(20) << "CLASS AVERAGE: " << std::setw(2) << average << "\n";
        std::cout << "\nHIGHEST GRADE\n";
        for (int i = 0; i < studentCount; i++) {
            if (students[i] > highestGrade) {
                highestGrade = students[i];
            }
        }

        for (int i = 0; i < studentCount; i++) {
            if (students[i] == highestGrade) {
                std::cout << std::left << std::setw(20) << "Student #" << (i + 1) << " | Grade: " << highestGrade << "\n";
            }
        }

        std::cout << "\nLOWEST GRADE\n";
        for (int i = 0; i < studentCount; i++) {
            if (students[i] < lowestGrade) {
                lowestGrade = students[i];
            }
        }

        for (int i = 0; i < studentCount; i++) {
            if (students[i] == lowestGrade) {
                std::cout << std::left << std::setw(20) << "Student #" << (i + 1) << " | Grade: " << lowestGrade << "\n";
            }
        }

        std::cout << "\nGrades within 1 point of the average:\n";
        int range1 = average - 1;
        for (int i = 0; i < studentCount; i++) {
            if (students[i] == range1) {
                std::cout << std::left << std::setw(20) << "Student #" << (i + 1) << " | Grade: " << students[i] << "\n";
            }
        }

        std::cout << "\nGrades within 1 point of the average:\n";
        int range2 = average + 1;
        for (int i = 0; i < studentCount; i++) {
            if (students[i] == range2) {
                std::cout << std::left << std::setw(20) << "Student #" << (i + 1) << " | Grade: " << students[i] << "\n";
            }
        }

        int belowSixCount = 0;
        for (int i = 0; i < studentCount; i++) {
            if (students[i] <= 6) {
                belowSixCount++;
            }
        }

        int adjustedGrades[belowSixCount];
        int k = 0, i = 0;
        while (i < studentCount) {
            if (students[i] <= 6 && k < belowSixCount) {
                adjustedGrades[k] = students[i] + 1;
                k++;
            } else {
                i++;
            }
            i++;
        }

        std::cout << "\nGrades increased by 1 point for the work done:\n";
        for (int j = 0; j < belowSixCount; j++) {
            std::cout << std::left << std::setw(20) << "Previous Grade: " << (adjustedGrades[j] - 1) << " | Current Grade: " << adjustedGrades[j] << "\n";
        }

        std::cout << "\n\nDo you want to calculate the grades of other students? Enter 'C' to continue or 'S' to exit: ";
        std::cin >> option;
        system("cls");
    } while ((option != 'S' && option != 's') && (option == 'C' || option == 'c'));

    return 0;
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}
