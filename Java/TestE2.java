public class TestE2 
{
    public static void main(String[] args) 
    {
        int age = 15; 

        try
        {
            if(age < 18)
            {
                throw new Exception("You are not an adult");
            }
            else
            {
                System.out.println("You are an adult");
            }
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage()); //exception message is printed
        }
    }
}
