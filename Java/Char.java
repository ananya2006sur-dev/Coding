public class Char 
{   
    public static void main(String args[])
    {
        char ch1 = 'A';
        System.out.println("The character ch1 is " + ch1 + " and its ASCII value is " + (int)ch1);
        char ch2 = 73;
        System.out.println("The character ch2 is " + ch2 + " and its ASCII value is " + (int)ch2);
        char ch3 = (char)(ch1 + 4);
        System.out.println("The character ch3 is " + ch3 + " and its ASCII value is " + (int)ch3);
    }
}
