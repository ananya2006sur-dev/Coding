public class arg
{
    public static void main(String[] args)
    {
        int size = args.length; 
        for(int idx = 0; idx < size; idx++) 
        {
            System.out.printf("Argument : %s, Index : %d\n", args[idx], idx); 
        }
    }
}
