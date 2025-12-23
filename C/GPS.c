#include <stdio.h>

int main()
{
    struct GPS
    {
        float latitude; // Defining a member called latitude
        float longitude; // Defining a member called longitude
    }; 
    typedef struct GPS GPS;
 

    GPS location1 = {37.7749, -122.4194}; //Initialization latitude and longitudes of location1 (my own location)
    GPS location2 = {34.0522, -118.2437}; //Initialization latitude and longitudes of location2 (my visit location)
    printf("Difference between latitudes : %f\n", location2.latitude - location1.latitude);
    printf("Difference between longitudes : %f\n", location2.longitude - location1.longitude);
}