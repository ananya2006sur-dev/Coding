public class TestE3
{
    public static void main(String[] args)
    {
        int x = 10;
        int y = 0; 
        try
        {
            if(y == 0)
            {
                throw new Exception("Division by zero not allowed");
            }
            else
            {
                System.out.println("The result of " + x + " divided by " + y + " is " + (float)x/y);
            }
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage()); 
        }
    }
}
