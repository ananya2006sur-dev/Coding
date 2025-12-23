#include <iostream>
using namespace std;

double max(double d[])
{
    double max = d[0];
    for (int i = 1; i < sizeof(d)/sizeof(max); i++)
    {
        if (d[i] > max)
        {
            max = d[i];
        }
        else
        {
            continue;
        }
    }
    return max;
}

double min(double d[])
{
    double min = d[0];
    for (int i = 1; i < sizeof(d)/sizeof(min); i++)
    {
        if (d[i] < min)
        {
            min = d[i];
        }
        else
        {
            continue;
        }
    }
    return min;
}

int main()
{
    double d[10];
    for (int i = 0; i < sizeof(d)/sizeof(d[0]); i++)
    {
        cout << "Enter the " << i << " th double";
        cin >> d[i];
        cout << endl;
    }
    cout << "Maximum number: " << max(d) << endl;
    cout << "Minimum number: " << min(d) << endl;
    return 0; 
}