#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
