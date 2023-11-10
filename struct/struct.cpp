#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
using namespace std;

struct VideoStore
{
    string movieName;
    string director;
    string genre;
    int rating;
    double price;
};

const int sizeOfStore = 5;
VideoStore store[sizeOfStore];

void showStore(int sizeOfStore);
void show(int num);

void addInfo(string movieName, string director, string genre, char rating, double price,int i)
{
    store[i] = {movieName,director,genre,rating,price};
}

string Lower(string str1)
{
    string str2 = str1;
    for (int i = 0; i < str1.length(); i++)
    {
        str2[i] = tolower(str1[i]);
    }
    return str2;
}

void searchMovieName(string name)
{
    for (int i = 1; i <= sizeOfStore; i++)
    {
        if (Lower(store[i].movieName) == Lower(name))
        {
            cout << endl << "Movie was found." << endl << "Information about Movie: " << endl;
            show(i);
        }
    }
}

void searchMovieDirector(string director)
{
    for (int i = 1; i <= sizeOfStore; i++)
    {
        if (Lower(store[i].director) == Lower(director))
        {
            cout << endl << "Movie was found." << endl << "Information about Movie: " << endl;
            show(i);
        }
    }
}

void searchMovieGenre(string genre)
{
    for (int i = 1; i <= sizeOfStore; i++)
    {
        if (Lower(store[i].genre) == Lower(genre))
        {
            cout << endl << "Movie was found." << endl << "Information about Movie: " << endl;
            show(i);
        }
    }
}

void popularMovieInGenre(string genre)
{
    int maxRating = 0;
    string popularMovie;
    for (int i = 1; i <= sizeOfStore; i++)
    {
        if (Lower(store[i].genre) == Lower(genre) && store[i].rating > maxRating)
        {
            maxRating = store[i].rating;
            popularMovie = store[i].movieName;
        }
    }
    cout << endl << endl << "Most Popular Movie in genre = " << popularMovie << endl;
    cout << "Max Rating = " << maxRating << endl << endl << endl;
}

void show(int num)
{
    cout << "Movie: " << store[num].movieName << endl;
    cout << "Director: " << store[num].director << endl;
    cout << "Genre: " << store[num].genre << endl;
    cout << "Rating: " << store[num].rating << endl;
    cout << "Price: " << store[num].price << endl;
    cout << "------------------------" << endl;
}

void showStore()
{
    for (int i = 1; i <= sizeOfStore; i++)
    {
        cout << "Movie: " << store[i].movieName << endl;
        cout << "Director: " << store[i].director << endl;
        cout << "Genre: " << store[i].genre << endl;
        cout << "Rating: " << store[i].rating << endl;
        cout << "Price: " << store[i].price << endl;
        cout << "------------------------" << endl;
    }
}

int main()
{
    int count = 1;
    addInfo("How to Train Your Dragon", "Dean DeBlois", "Adventure", 10, 1500, count);
    addInfo("Wrong Turn", "Rob Schmidt", "Horror", 7, 499, ++count);
    addInfo("Saw", "James Wan", "Horror", 9, 399, ++count);
    addInfo("Scooby Doo, Where Are You!", "Joseph Barbera", "Adventure", 7, 999, ++count);
    addInfo("Into the Abyss","Matías Rispau", "Fantastic", 4, 233, ++count);
 
    cout << "Enter 1,if you want to find movie by the name." << endl;
    cout << "Enter 2,if you want to find movie by the director." << endl;
    cout << "Enter 3,if you want to find movie by the genre." << endl;
    cout << "Enter 0,if you dont want to find anything." << endl;

    int n;
    cin >> n;

    string name;
    string director;
    string genre;
    char* buffer = (char*)malloc(128);
    switch (n)
    {
    case 1:
        cout << "Enter name of movie: ";
        cin.getline(buffer, 128, '\n');
        cin.getline(buffer, 128, '\n');
        name = string(buffer);
        free(buffer);
        searchMovieName(name);
        break;
    case 2:
        cout << "Enter director of movie: ";
        cin.getline(buffer, 128, '\n');
        cin.getline(buffer, 128, '\n');
        director = string(buffer);
        free(buffer);

        searchMovieDirector(director);
        break;
    case 3:
        cout << "Enter genre of movie: ";
        cin >> genre;
        searchMovieGenre(genre);
        break;
    case 0:
        break;
    default:
        cout << "Uncorrect choice." << endl;
        break;

    }

    popularMovieInGenre(genre);
    cout << "Information about movie in VideoStore: " << endl;
    showStore();
}


