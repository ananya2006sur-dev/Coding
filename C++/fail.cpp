#include <iostream>
#include <vector>
using namespace std;

int main()
{
    double input;
    double total = 0;
    double avg = 0;

    vector<double> v(0);

    cout << "Enter an integer or double value or enter a non-integer or non-double to stop: " << endl;

    while (true)
    {
        cin >> input;
        if(cin.good())
        {
            v.push_back(input);
            cout << "Enter an integer or double value or enter a non-integer or non-double to stop: " << endl;
        }
        else if (cin.fail())
        {
            break;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        total = total + v.at(i);
    }
    avg = total/v.size();

    cout << "Total: " << total << endl;
    cout << "Average: " << avg << endl;

    return 0;
}
