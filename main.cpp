/*VladimirP*/
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

void get_data(size_t width = 200, size_t height = 100) {
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
    string output = "";

    output += string("User") + string("            | ");
    for (int i = 0; i < num; i++) {output += string("Question ") + char(i+1+'0') + string("\t\t| ");   }
    if (output.size() >= width)  {
        output = output.substr(0, width - 3) + string("...");
    }
    cout << output << "\n";
    while(getline(in,ans)) {
        if (user >= height)
            break;
        ans = trim(ans);
        output = "";
        output+= char(user + '0') + string("             ");
        if (user < 100)
            output += string(" ");
        if (user < 10)
            output += string(" ");
        output += string("| ");
        output += ans;
        for (int i = ans.size(); i < 22; i++)
            output += string(" ");
        output += string("| ");
        for (int i = 1; i < num; i++){
            getline(in, ans);
            ans = trim(ans);
            output += ans;
            for (int j = ans.size(); j < 22; j++)
                output+=string(" ");
            output+= string("| ");
        }
        if (output.size() >= width) {
            output = output.substr(0, width-3) + string("...");
        }
        answers[ans]++;
        cout << output <<"\n";
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
    if (user-1 != 0)
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
