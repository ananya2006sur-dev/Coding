#include <iostream>
using namespace std;

int main()
{  
    int x;
    int y;
    try 
    { 
        cin >> x;
        cin >> y;
        if (y == 0)
        { 
            runtime_error ex = runtime_error("Division by zero not allowed");
            throw ex;
        } 
        cout << "The result of " << x << " divided by " << y << " is " << (float)x/y << endl;
    }

    catch (exception &ex)
    {
        cerr << ex.what() << endl;
    }

    return 0;
}

