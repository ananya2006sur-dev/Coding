class scp 
{
    static void main(String args[])
    {
        int a = 10;
        {
            int b = 20;
            System.out.println("The value of b is " + b);
        }
        System.out.println("The value of a is " + a);
        int b = 30; //redeclaration of a variable is allowed in different scope
        System.out.println("The value of b is " + b);
    }
}
