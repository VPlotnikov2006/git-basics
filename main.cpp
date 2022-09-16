#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void get_data() {
    ifstream in("results.txt");
    if (!in) {
        cout << "No saved data";
        return;
    }
    string name, surname, film;
    while(getline(in, name)) {
        getline(in, surname);
        getline(in, film);
        cout << name << " " << surname << " " << film << "\n";
    }
    in.close();
}

int main() {
    string s;
    cout << "Type 'poll' if you want to take a poll or 'data' to get data\n";
    cin >> s;
    if (s == "poll"){
        string name, surname, film;
        cin >> name >> surname >> film;
        ofstream out("results.txt", ios_base::app);
        if (!out)
            return 1;
        out << name << "\n" << surname << "\n" << film << "\n";
        out.close();
    }
    if (s == "data")
        get_data();
	return 0;
}
