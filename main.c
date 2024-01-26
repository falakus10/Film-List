#include <stdio.h>
#include <string.h>

typedef enum filmGenre {
    drama = 1, horror, thriller
} Genre;

typedef struct cinemaFilm {
    char filmName[100];
    int productionYear;
    float imdbRating;
    Genre filmGenre;
} Film;

void printFilmGenre(Genre filmGenre);
void printFilms(Film films[], int arraySize);

int main() {
    Film films[3] = {{"Titanic", 1997, 7.9, drama},
                     {"Saw", 2004, 7.6, horror},
                     {"Rebecca", 1940, 8.1, thriller}};

    printf("Size of Genre: %d\n", sizeof(Genre));
    printf("Size of Film: %d\n", sizeof(Film));
    printf("Size of film variable: %d\n", sizeof(films) / sizeof(Film));

    printFilms(films, sizeof(films) / sizeof(Film));

    return 0;
}

void printFilmGenre(Genre filmGenre) {
    switch (filmGenre) {
        case drama:
            printf("DRAMA");
            break;
        case horror:
            printf("HORROR");
            break;
        case thriller:
            printf("THRILLER");
            break;
        default:
            printf("ERROR!");
            break;
    }
}

void printFilms(Film films[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        printf("Film Name: %s\n", films[i].filmName);
        printf("Production Year: %d\n", films[i].productionYear);
        printf("IMDB Rating: %f\n", films[i].imdbRating);
        printf("Film Genre: ");
        printFilmGenre(films[i].filmGenre);
        printf("\n-----------\n");
    }
}