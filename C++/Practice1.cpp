#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

int main()
{
    vector<string> nums(0);
    string read; 
    
    try 
    {
        ifstream file;
        file.open("numbers.txt");
        if (!file)
        {
            throw runtime_error("File failed to open");
        }
        while (getline(file, read))
        {
            stringstream ss(read);
            while (getline(ss, read, ','))
            {
                nums.push_back(read);
            }
        }
        file.close();
        for (int i = 0; i < 3; i++)
        {
            int total = 0;
            for (int j = 0; j < 10; j += 3)
            {
                total += stoi(nums.at(i + j));
            }
            cout << "Total: " << total << endl;
        }
    }

    catch (exception& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}

