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
    while(in >> name >> surname >> film)
        cout << name << " " << surname << " " << film << "\n";
    in.close();
}

int main() {
	string name, surname, film;
	cin >> name >> surname >> film;
	ofstream out("results.txt", ios_base::app);
	if (!out)
        return 1;
	out << name << " " << surname << " " << film << "\n";
	out.close();
	return 0;
}
