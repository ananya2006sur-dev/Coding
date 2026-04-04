import java.util.Scanner;

class Complex
{
    double real; 
    double imaginary; 

    Complex(double real, double imaginary)
    {
        this.real = real; 
        this.imaginary = imaginary; 
    }

    Complex add(Complex other)
    {
        return new Complex(this.real + other.real, this.imaginary + other.imaginary);
    }

    Complex subtract(Complex other)
    {
        return new Complex(this.real - other.real, this.imaginary - other.imaginary);
    }

    Complex multiply(Complex other)
    {
        return new Complex(this.real * other.real - this.imaginary * other.imaginary, this.real * other.imaginary + this.imaginary * other.real);
    }

    Complex divide(Complex other)
    {
        return new Complex((this.real * other.real + this.imaginary * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary), (this.imaginary * other.real - this.real * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary));
    }

    void display()
    {
        System.out.println(this.real + " + " + this.imaginary + "i");
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
        System.out.println("First complex number: ");
        c1.display();
        System.out.println("Second complex number: ");
        c2.display();
        System.out.println("Addition of the two complex numbers: ");
        Complex sum = c1.add(c2);
        sum.display();
        System.out.println("Subtraction of the two complex numbers: ");
        Complex difference = c1.subtract(c2);
        difference.display();
        System.out.println("Multiplication of the two complex numbers: ");
        Complex product = c1.multiply(c2);
        product.display();
        System.out.println("Division of the two complex numbers: ");
        Complex quotient = c1.divide(c2);
        quotient.display();
        sc.close();
    }
}