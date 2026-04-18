public class TestE 
{
    public static void main(String[] args) 
    {
        int age = 15;
        
        if(age < 18)
        {
            throw new ArithmeticException("You are not an adult");
        }
        else
        {
            System.out.println("You are an adult");
        }
    }
}
