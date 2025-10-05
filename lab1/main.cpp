#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Привіт,", "це", "моя", "перша", "програма", "на", "C++", "в", "VS Code!"};
    int count = 0;

    for (const string& word : msg)
    {
        cout << word << " ";
        count++;
    }
    cout << endl;
    cout << "Кількість слів: " << count << endl;
}
