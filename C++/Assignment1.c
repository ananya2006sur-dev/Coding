#include <stdio.h>

int main()
{
    float ft, in, kg, g, eu, rup, cel, fahr;
    int dys, yrs, wks, rdys;
    printf("Enter the length in feet: ");
    scanf("%f", &ft);
    in = 12 * ft;
    printf("%f feet in inches is %f\n", ft, in);
    printf("Enter the weight in kilograms: ");
    scanf("%f", &kg);
    g = kg * 1000;
    printf("%f kilograms in grams is %f\n", kg, g);
    printf("Enter amount of money in euros: ");
    scanf("%f", &eu);
    rup = 92.23 * eu;
    printf("%f euros in rupees is %f\n", eu, rup);
    printf("Enter the temperature in celcius: ");
    scanf("%f", &cel);
    fahr = (9.0/5.0)*cel + 32;
    printf("%f celcius in fahrenheit is %f\n", cel, fahr);
    printf("Enter the number of days: ");
    scanf("%d", &dys);
    yrs = dys/365;
    wks = (dys % 365)/7;
    rdys = ((dys % 365) % 7);
    printf("%d days is %d years, %d weeks, and %d days\n", dys, yrs, wks, rdys);
    return 0;
}
