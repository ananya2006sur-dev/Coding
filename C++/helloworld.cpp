#include <iostream> 
#include <iomanip> 
#include <string> // Add this line to include the string header
using namespace std;
int main(void) 
{
   int x;
    cout << "Enter a number: ";
    cin >> x; 
   if (x % 2 == 0)
   {
        cout << "x is even" << endl;
   }
   else
   {
        cout << "x is odd" << endl;
   }
   return 0;
}





