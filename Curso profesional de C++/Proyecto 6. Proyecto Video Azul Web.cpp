/*
Azul Web acaba de sacar una nueva plataforma de video, donde se van a publicar películas. Las películas tiene los siguientes atributos; Nombre de la película y Fecha de lanzamiento.

Crea un programa en C++ que haga lo siguiente:

1.- Permitir guardar 20 registros en una matriz; Nombre de película y año de lanzamiento.

2.- Un menú que nos va a dar tres opciones:

>> a) Mostrar películas desde las más viejas a las más nuevas.

>> b) Mostrar películas desde las más nuevas a las más viejas.

>> c) Mostrar películas de un año en concreto.

3.- Opción de regresar al menú o salir del programa.

Utiliza solo lo aprendido en los módulos anteriores.
*/

#include <iostream>
#include <string>
#include <limits>

const int MAX_MOVIES = 20;

struct Movie {
    std::string title;
    std::string releaseYear;
};

// Function to clear Screen
void clearScreen() {
	std::cout << "\033[2J\033[1;1H";
}

// Function to input movie data
void inputMovieData(Movie movies[]) {
    std::cout << "\t************************ RHM Video Store ************************" << std::endl;
    for (int i = 0; i < MAX_MOVIES; i++) {
        std::cout << "\t***** Movie Title: ";
        std::getline(std::cin, movies[i].title);

        // Validate if the title is empty
        if (movies[i].title.empty()) {
            std::cout << "\t***** Invalid movie title. Please try again. *****" << std::endl;
            i--; // Decrement i to re-enter the title
            continue;
        }

        std::cout << "\t***** Release Year: ";
        std::getline(std::cin, movies[i].releaseYear);

        // Validate if the release year is empty
        if (movies[i].releaseYear.empty()) {
            std::cout << "\t***** Invalid release year. Please try again. *****" << std::endl;
            i--; // Decrement i to re-enter the release year
        }
    }
}

// Function to sort movies by release year in ascending order
void sortMoviesByReleaseYearAscending(Movie movies[]) {
    for (int i = 0; i < MAX_MOVIES - 1; i++) {
        for (int j = 0; j < MAX_MOVIES - i - 1; j++) {
            if (movies[j].releaseYear > movies[j + 1].releaseYear) {
                std::swap(movies[j], movies[j + 1]);
            }
        }
    }
}

// Function to display movies from oldest to newest
void displayMoviesAscending(const Movie movies[]) {
    std::cout << "\n\t***** Showing movies from oldest to newest *****" << std::endl;
    std::cout << "\n\t***** Title \t\t" << "|" << "\t\tYear *****" << std::endl;
    for (int i = 0; i < MAX_MOVIES; i++) {
        std::cout << "\t***** " << movies[i].title << "\t\t" << "|" << "\t\t" << movies[i].releaseYear << " *****" << std::endl;
    }
}

// Function to display movies from newest to oldest
void displayMoviesDescending(const Movie movies[]) {
    std::cout << "\n\t***** Showing movies from newest to oldest *****" << std::endl;
    std::cout << "\n\t***** Title \t\t" << "|" << "\t\tYear *****" << std::endl;
    for (int i = MAX_MOVIES - 1; i >= 0; i--) {
        std::cout << "\t***** " << movies[i].title << "\t\t" << "|" << "\t\t" << movies[i].releaseYear << " *****" << std::endl;
    }
}

// Function to display movies from a specific year
void displayMoviesByYear(const Movie movies[]) {
    std::string year;
    std::cout << "\n\t***** Showing movies from a specific year *****" << std::endl;
    std::cout << "\n\t***** Which Year: ";
    std::getline(std::cin, year);

    // Validate if the year is empty
    if (year.empty()) {
        std::cout << "\t***** Invalid year. Please try again. *****" << std::endl;
        return;
    }

    bool found = false;
    std::cout << "\n\t***** Title \t\t" << "|" << "\t\tYear *****" << std::endl;
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].releaseYear == year) {
            std::cout << "\t***** " << movies[i].title << "\t\t" << "|" << "\t\t" << movies[i].releaseYear << " *****" << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "\t***** No movies found for the specified year. *****" << std::endl;
    }
}

// Function to display the main menu
void displayMainMenu() {
    std::cout << "\t************************ RHM Video Store ************************" << std::endl;
    std::cout << "\t*************************** Main Menu ***************************" << std::endl;
    std::cout << std::endl;
    std::cout << "\t***** 1. Show movies from oldest to newest *****" << std::endl;
    std::cout << "\t***** 2. Show movies from newest to oldest *****" << std::endl;
    std::cout << "\t***** 3. Show movies from a specific year *****" << std::endl;
    std::cout << "\t\tOption: ";
}

// Function to display the sub menu
void displaySubMenu() {
    std::cout << "\n\t*************************** Sub Menu ***************************" << std::endl;
    std::cout << "\t***** 1. Return to Main Menu" << std::endl;
    std::cout << "\t***** 2. Exit" << std::endl;
    std::cout << "\t***** Option: ";
}

// Function to get the menu option
int getMenuOption() {
    int option;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return option;
}

int main() {
    Movie movies[MAX_MOVIES];
    inputMovieData(movies);

    // Sorting the movies by release year in ascending order
    sortMoviesByReleaseYearAscending(movies);

    int option;
    do {
        clearScreen();
        displayMainMenu();
        option = getMenuOption();

        switch (option) {
            case 1:
                displayMoviesAscending(movies);
                break;
            case 2:
                displayMoviesDescending(movies);
                break;
            case 3:
                displayMoviesByYear(movies);
                break;
            default:
                std::cout << "\t***** Invalid option. Please try again. *****" << std::endl;
                break;
        }

        displaySubMenu();
        option = getMenuOption();

    } while (option == 1);

    return 0;
}

