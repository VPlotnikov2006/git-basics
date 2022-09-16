#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
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
    out << "\n";
	out.close();
	return 0;
}
