class InvalidAgeException extends Exception
{
    InvalidAgeException(String message)
    {
        super(message); 
    }
}

public class TestE5 
{
    public static void main(String[] args) 
    {
        int age = 15;

        try
        {
            if(age < 18)
            {
                throw new InvalidAgeException("You are not an adult");
            }
            else
            {
                System.out.println("You are an adult");
            }
        }

        catch(InvalidAgeException e)
        {
            System.out.println(e.getMessage()); 
        }
    }
}