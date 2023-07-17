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
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

const int MAX_STUDENTS = 20;
const int MAX_SUBJECTS = 5;

struct Student {
    std::string name;
    std::string surname;
    std::string subjects[MAX_SUBJECTS];
    float grades[MAX_SUBJECTS];
    float average;
};

void clearScreen();
void enterStudentData(Student& student);
void enterGrades(Student& student);
void calculateStudentAverage(Student& student);
void calculateClassAverage(const Student students[], float& classAverage);
void displayStudentInformation(const Student students[], float classAverage);
void correctStudentData(Student students[]);

int main()
{
    std::cout << std::setw(50) << "Classroom RHM\n";

    Student students[MAX_STUDENTS];
    float classAverage = 0.0f;

    // Enter student data
    for (int i = 0; i < MAX_STUDENTS; i++) {
        std::cout << "\nStudent: N" << i + 1 << std::endl;
        enterStudentData(students[i]);
        enterGrades(students[i]);
        calculateStudentAverage(students[i]);
    }

    calculateClassAverage(students, classAverage);

    clearScreen();
    std::cout << std::setw(50) << "Student Information\n";
    displayStudentInformation(students, classAverage);

    std::cout << "\nClass Average: " << classAverage << std::endl;
    std::cout << std::endl;

    std::cout << std::setw(50) << "All data is correct\n";
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    std::cout << "Option: ";

    int somethingWrong;
    std::cin >> somethingWrong;

    if (somethingWrong == 2) {
        correctStudentData(students);
    } else {
        std::cout << "All Data Correct\n";
        std::cout << "End of Program\n";
        return 0;
    }

    clearScreen();
    std::cout << std::setw(50) << "Updated Student Information\n";
    displayStudentInformation(students, classAverage);

    std::cout << "\nClass Average: " << classAverage << std::endl;
    return 0;
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void enterStudentData(Student& student) {
    std::string name, surname;

    std::cout << "Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    student.name = name;

    std::cout << "Surname: ";
    std::getline(std::cin, surname);
    student.surname = surname;
}

void enterGrades(Student& student) {
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        std::string subject;
        float grade;

        std::cout << "Subject " << i + 1 << ": ";
        std::getline(std::cin, subject);
        student.subjects[i] = subject;

        while (true) {
            std::cout << "Grade: ";
            std::cin >> grade;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter a valid grade.\n";
            } else if (grade < 0 || grade > 100) {
                std::cout << "The grade should be between 0 and 100.\n";
            } else {
                student.grades[i] = grade;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
    }
}

void calculateStudentAverage(Student& student) {
    float sum = 0.0f;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        sum += student.grades[i];
    }
    student.average = sum / MAX_SUBJECTS;
}

void calculateClassAverage(const Student students[], float& classAverage) {
    float sum = 0.0f;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        sum += students[i].average;
    }
    classAverage = sum / MAX_STUDENTS;
}

void displayStudentInformation(const Student students[], float classAverage) {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        std::cout << "\nName: " << students[i].name << " Surname: " << students[i].surname << std::endl;

        for (int j = 0; j < MAX_SUBJECTS; j++) {
            std::cout << "Subject: " << students[i].subjects[j] << " | " << "Grade: " << students[i].grades[j] << std::endl;
        }

        std::cout << "Average: " << students[i].average << std::endl;
    }
}

void correctStudentData(Student students[]) {
    while (true) {
        clearScreen();
        std::cout << std::setw(45) << "Which Data is Incorrect\n";
        std::cout << "1. Name" << std::endl;
        std::cout << "2. Surname" << std::endl;
        std::cout << "3. Subject" << std::endl;
        std::cout << "4. Grade" << std::endl;
        std::cout << "Option: ";

        int whichData;
        std::cin >> whichData;

        if (whichData < 1 || whichData > 4) {
            std::cout << "Enter a valid option.\n";
            continue;
        }

        int studentNumber;
        std::cout << "Which Student (1 to " << MAX_STUDENTS << "): ";
        std::cin >> studentNumber;

        if (studentNumber < 1 || studentNumber > MAX_STUDENTS) {
            std::cout << "Enter a valid student number.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (whichData) {
            case 1: {
                std::cout << std::setw(45) << "Initiate Correction\n";
                std::string name;
                std::cout << "Name: ";
                std::getline(std::cin, name);
                students[studentNumber - 1].name = name;
                break;
            }
            case 2: {
                std::cout << std::setw(45) << "Initiate Correction\n";
                std::string surname;
                std::cout << "Surname: ";
                std::getline(std::cin, surname);
                students[studentNumber - 1].surname = surname;
                break;
            }
            case 3: {
                int subjectNumber;
                std::cout << "Which Subject (1 to " << MAX_SUBJECTS << "): ";
                std::cin >> subjectNumber;
                if (subjectNumber < 1 || subjectNumber > MAX_SUBJECTS) {
                    std::cout << "Enter a valid subject number.\n";
                    continue;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << std::setw(45) << "Initiate Correction\n";
                std::string subject;
                std::cout << "Subject: ";
                std::getline(std::cin, subject);
                students[studentNumber - 1].subjects[subjectNumber - 1] = subject;
                break;
            }
            case 4: {
                int subjectNumber;
                std::cout << "Which Grade (1 to " << MAX_SUBJECTS << "): ";
                std::cin >> subjectNumber;
                if (subjectNumber < 1 || subjectNumber > MAX_SUBJECTS) {
                    std::cout << "Enter a valid grade number.\n";
                    continue;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                while (true) {
                    std::cout << std::setw(45) << "Initiate Correction\n";
                    float grade;
                    std::cout << "Grade: ";
                    std::cin >> grade;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Enter a valid grade.\n";
                    } else if (grade < 0 || grade > 100) {
                        std::cout << "The grade should be between 0 and 100.\n";
                    } else {
                        students[studentNumber - 1].grades[subjectNumber - 1] = grade;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }
                }
                break;
            }
        }

        std::cout << std::setw(50) << "Do you want to correct any other data\n";
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;
        std::cout << "Option: ";

        int option;
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (option != 1) {
            break;
        }
    }
}