#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> v(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    cout << v.at(0) << endl;
    cout << v.at(1) << endl;
    cout << v.at(2) << endl;
    v.insert(v.begin() + 1, 3);
    cout << v.at(0) << endl;
    cout << v.at(1) << endl;
    cout << v.at(2) << endl;
    return 0;
}

