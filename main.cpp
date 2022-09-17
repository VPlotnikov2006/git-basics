#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>

using namespace std;

const string WHITESPACE = " \n\r\t\f\v";

string ltrim(const string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string &s) {
    return rtrim(ltrim(s));
}

void get_data() {
    map<string, int> answers;
    ifstream q("inputfile");
    if(!q)
        return ;
    string question;
    int num = 0;
    string ans;
    while(getline(q, question)) num++;
    q.close();
    ifstream in("results.txt");
    if (!in) {
        cout << "No saved data";
        return;
    }
    int user = 1;
    cout << "User" << "\t\t| ";
    for (int i = 0; i < num; i++) cout << "Question " << i+1 << "\t\t| ";
    cout << "\n";
    while(getline(in,ans)) {
        ans = trim(ans);
        cout << user << "\t\t| ";
        cout << ans;
        for (int i = ans.size(); i < 22; i++)
            cout << " ";
        cout << "| ";
        for (int i = 1; i < num; i++){
            getline(in, ans);
            ans = trim(ans);
            cout << ans;
            for (int i = ans.size(); i < 22; i++)
                cout << " ";
            cout << "| ";
        }
        answers[ans]++;
        cout << "\n";
        user++;
    }
    int Max = -1;
    for (auto x: answers) {
        if (x.second > Max) {
            Max = x.second;
            ans = x.first;
        }
    }
    cout << "Users number: " << user-1 << "\n";
    cout << "Most popular answer: " << ans;
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
