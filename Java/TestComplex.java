import java.util.Scanner;
class Complex
{
    double real; 
    double imaginary;

    Complex()
    {
        this(0, 0);
        System.out.println("Inside the default Complex constructor");
    }

    Complex(double real, double imaginary)
    {
        this.real = real; 
        this.imaginary = imaginary; 
    }

    void display()
    {
        System.out.println("The complex number is: " + this.real + " + " + this.imaginary + "i");
    }

    Complex add(Complex other)
    {
        return new Complex(this.real + other.real, this.imaginary + other.imaginary); 
    }

    Complex sub(Complex other)
    {
        return new Complex(this.real - other.real, this.imaginary - other.imaginary); 
    }

    Complex mul(Complex other)
    {
        return new Complex(((this.real * other.real) - (this.imaginary * other.imaginary)), ((this.real * other.imaginary) + (this.imaginary * other.real)));
    }

    Complex div(Complex other)
    {
        Complex num = new Complex(((this.real * other.real) + (this.imaginary * other.imaginary)), ((this.imaginary * other.real) - (this.real * other.imaginary)));
        double den = (other.real * other.real) + (other.imaginary * other.imaginary);
        return new Complex(num.real / den, num.imaginary / den);
    }
}

public class TestComplex
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the real part of the first complex number: ");
        double real1 = sc.nextDouble();
        System.out.println("Enter the imaginary part of the first complex number: ");
        double imaginary1 = sc.nextDouble();
        System.out.println("Enter the real part of the second complex number: ");
        double real2 = sc.nextDouble();
        System.out.println("Enter the imaginary part of the second complex number: ");
        double imaginary2 = sc.nextDouble();
        Complex c1 = new Complex(real1, imaginary1);
        Complex c2 = new Complex(real2, imaginary2);
        System.out.println("The sum of the two complex numbers is: ");
        Complex c3 = c1.add(c2);
        System.out.println("The difference of the two complex numbers is: ");
        Complex c4 = c1.sub(c2);
        System.out.println("The product of the two complex numbers is: ");
        Complex c5 = c1.mul(c2);
        System.out.println("The quotient of the two complex numbers is: ");
        Complex c6 = c1.div(c2);
        c3.display();
        c4.display();
        c5.display();
        c6.display();
        sc.close();
    }
}