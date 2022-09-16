#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
    string action;
    cout << "Type 'poll' if you want to take a poll or 'data' to get data\n";
    getline(cin, action);
    if (action == "poll"){
        vector<string> answers;
        ifstream questions("inputfile");
        if(!questions)
            return 2;
        string question;
        while (getline(questions, question)) {
            cout << question << "\n";
            string ans;
            getline(cin, ans);
            answers.push_back(ans);
        }
        ofstream out("results.txt", ios_base::app);
        if (!out)
            return 1;
        for (auto x: answers)
            out << x << "\n";
        out.close();
    }
    if (action == "data")
        get_data();
	return 0;
}
