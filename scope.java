public class scope 
{
    public static void main(String args[])
    {
        int a = 10;
        {
            int b = 20;
            System.out.println(b);
        }
        System.out.println(a);
        int b = 30; //redeclaration of a variable is allowed in different scope
        System.out.println(b);
    }
}
