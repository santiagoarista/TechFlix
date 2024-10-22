#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Videos {
protected:
  string id, name, genre, comment, genree;
  int duration;
  float rating;

public:
  virtual void display_info() {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Genre: " << genre << endl;
    cout << "Length: " << duration << " minutes" << endl;
    cout << "Rating: " << rating << endl;
    cout << "Comments: " << comment << endl;
    cout << "-------------------------" << endl;
  }

  void set_data(string i, string n, string g, int l, float r, string c) {
    id = i;
    name = n;
    genre = g;
    duration = l;
    rating = r;
    comment = c;
  }
};

class Movies : public Videos {
public:

  void searchMovie(Movies m[], int size) {
    string movieSearch;
    cout << "Enter the name of the movie you are looking for: ";
    cin.ignore();
    getline(cin, movieSearch);

    bool found = false;
    for (int i = 0; i < size; i++) {
      if (m[i].name == movieSearch) {
        cout << "Movie found:\n";
        cout << "ID: " << m[i].id << endl;
        cout << "Name: " << m[i].name << endl;
        cout << "Genre: " << m[i].genre << endl;
        cout << "Length: " << m[i].duration << " minutes" << endl;
        cout << "Rating: " << m[i].rating << endl;
        cout << "Comment: " << m[i].comment << endl;
        found = true;
        break;
      }
    }

    if (!found) {
      cout << "Movie not found.\n";
    }
  }

  void searchMoviesByGenre(Movies m[], int size, string Genre) {
    bool found = false;
    cout << "\nMovies in genre " << Genre << ":\n";
    for (int i = 0; i < size; i++) {
      if (m[i].genre == Genre) {
        m[i].display_info();
        found = true;
      }
    }
    if (!found) {
      cout << "No movies found in genre " << Genre << ".\n";
    }
  }

  void rateMovie(Movies m[], int size) {
    string movieRate;
    float userRate;
    float timesrate = 1;
    cout << "Enter the name of the movie you want to rate: ";
    cin.ignore();
    getline(cin, movieRate);
    for (int i = 0; i < size; i++) {
      if (m[i].name == movieRate) {
        float sum = m[i].rating;
        cout << "Enter the rate you want to give to the movie (between 0 and 5): ";
        cin >> userRate;
        if (userRate > 5 || userRate < 0) {
          cout << "Invalid rate, please enter a number between 0 and 5" << endl;
        } else {
          cout << "The movie " << m[i].name << " has been rated with " << userRate << " stars." << endl;
          timesrate++;
          sum += userRate;
          m[i].rating = sum / timesrate;
        }
        break;
      }
    }
  }
void saveMoviesToFile(Movies m[], int size) {
    ofstream movieFile("movies.csv");
    if (movieFile.is_open()) {
      for (int i = 0; i < size; i++) {
        movieFile << m[i].id << "," << m[i].name << "," << m[i].genre << ","
                  << m[i].duration << "," << m[i].rating << "," << m[i].comment << endl;
      }
      movieFile.close();
      cout << "Movie ratings saved to movies.csv successfully." << endl;
    } else {
      cout << "Error: Could not open movies.csv for writing." << endl;
    }
  }
};

class Series : public Videos {
public:
void searchSeries(Series s[], int size) {
  string seriesSearch;
  cout << "Enter the name of the series you are looking for: ";
  cin.ignore();
  getline(cin, seriesSearch);

  bool found = false;
  for (int i = 0; i < size; i++) {
    if (s[i].name == seriesSearch) {
      cout << "Series found:\n";
      cout << "ID: " << s[i].id << endl;
      cout << "Name: " << s[i].name << endl;
      cout << "Rating: " << s[i].rating << endl;
      cout << "Genre: " << s[i].genre << endl;
      cout << "Comment: " << s[i].comment << endl;
      found = true;
      break;
    }
  }

  if (!found) {
    cout << "Series not found.\n";
  }
}
void searchSeriesByGenre(Series s[], int size, string Genre) {
  bool found = false;
  cout << "\nMovies in genre " << Genre << ":\n";
  for (int i = 0; i < size; i++) {
    if (s[i].genre == Genre) {
      s[i].display_info();
      found = true;
    }
  }
  if (!found) {
    cout << "No movies found in genre " << Genre << ".\n";
  }
}

void rateSeries(Series s[], int size) {
  string movieRate;
  float userRate;
  float timesrate = 1;
  cout << "Enter the name of the series you want to rate: ";
  cin.ignore();
  getline(cin, movieRate);
  for (int i = 0; i < size; i++) {
    if (s[i].name == movieRate) {
      float sum = s[i].rating;
      cout << "Enter the rate you want to give to the series (between 0 and 5): ";
      cin >> userRate;
      if (userRate > 5 || userRate < 0) {
        cout << "Invalid rate, please enter a number between 0 and 5" << endl;
      } else {
        cout << "The series " << s[i].name << " has been rated with " << userRate << " stars." << endl;
        timesrate++;
        sum += userRate;
        s[i].rating = sum / timesrate;
      }
      break;
    }
  }
}

virtual void display_info() {
  cout << "ID: " << id << endl;
  cout << "Name: " << name << endl;
  cout << "Genre: " << genre << endl;
  cout << "Length: " << duration << " minutes" << endl;
  cout << "Rating: " << rating << endl;
  cout << "Comments: " << comment << endl;
  cout << "-------------------------" << endl;
}

void saveSeriesToFile(Series s[], int size) {
    ofstream movieFile("series.csv");
    if (movieFile.is_open()) {
      for (int i = 0; i < size; i++) {
        movieFile << s[i].id << "," << s[i].name << "," << s[i].genre << ","
                  << s[i].duration << "," << s[i].rating << "," << s[i].comment << endl;
      }
      movieFile.close();
      cout << "Series ratings saved to series.csv successfully." << endl;
    } else {
      cout << "Error: Could not open series.csv for writing." << endl;
    }
  }

};

int main() {
  string genre;
    ifstream movies("movies.csv"), series("series.csv");
    Movies m[30];
    Series s[30];
    Videos* videoPointer = s;
    string line, word, row[6];
    int j = 0;
    

    while (getline(movies, line)) {
        stringstream ss(line);
        int i = 0;
        while (getline(ss, word, ',')) {
            row[i++] = word;
        }
        m[j].set_data(row[0], row[1], row[2], stoi(row[3]), stof(row[4]), row[5]);
        j++;
    }

    j = 0;
    while (getline(series, line)) {
        stringstream ss(line);
        int i = 0;
        while (getline(ss, word, ',')) {
            row[i++] = word;
        }
        s[j].set_data(row[0], row[1], row[2], stoi(row[3]), stof(row[4]), row[5]);
        j++;
    }

    cout << "Welcome to TrashFlix. Select an option from the menu below.\n";
    int option;
    while (true) {
        cout << "1. Display all videos (movies and series)\n2. Display all movies\n3. Display all movies by genre\n4. Search movie by name\n5. Evaluate movie between 0-5\n6. Save the changes in the moviefile\n7. Display all series\n8. Display series by genre\n9. Search Series by name\n10. Evaluate series betweeen 0-5\n11. Save changes in the series file\n12. Exit\nEnter your choice: ";
        cin >> option;
      if (option < 1 || option > 12) {
        cout << "Invalid option, please enter a number between 1 to 12\n";
        continue;
      }
        switch(option) {
            case 1:
              cout << "\nMovies\n";
              for (int i = 0; i < 30; i++) {
                m[i].display_info();
              }
              cout << "\nSeries\n";
              for (int i = 0; i < 30; i++) {
                videoPointer->display_info();
                videoPointer++; 
              }
                break;
            case 2:
              cout << "\nMovies\n";
              for (int i = 0; i < 30; i++) {
                m[i].display_info();
              }
                break;
            case 3:
              cout << "Enter the genre you want to search for: ";
              cin >> genre;
              for(int i = 0; i < j; i++){
                m[0].searchMoviesByGenre(m, j, genre);
              }
              break;
            case 4:
              m[0].searchMovie(m, 30);
              break;
            case 5:
              m[0].rateMovie(m, 30);
              break;
            case 6:
              m[0].saveMoviesToFile(m, 30);
              break;
            case 7:
              cout << "\nSeries\n";
              for (int i = 0; i < 30; i++) {
                s[i].display_info();
              }
              break;
            case 8:
              cout << "Enter the genre you want to search for: ";
              cin >> genre;
              for(int i = 0; i < j; i++){
                s[0].searchSeriesByGenre(s, 30, genre);
              }
              break;
            case 9:
              s[0].searchSeries(s, 30);
              break;
            case 10:
              s[0].rateSeries(s, 30);
              break;
            case 11:
              s[0].saveSeriesToFile(s, 30);
              break;
            case 12:
                cout << "Goodbye\n";
                return 0;
        }
    }
}
