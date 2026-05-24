public class DeadLockPreventionDemo 
{
    public static void main(String[] args) 
    {
        final String resource1 = "Printer"; 
        final String resource2 = "Scanner"; 

        Thread t1 = new Thread(() ->
        {
            synchronized(resource1)
            {
                System.out.println("Thread1 locked " + resource1); 
            }

            synchronized(resource2)
            {
                System.out.println("Thread1 locked " + resource2); 
            }
        }); 

        Thread t2 = new Thread(() ->
        {
            synchronized(resource1)
            {
                System.out.println("Thread2 locked " + resource1); 
            }

            synchronized(resource2)
            {
                System.out.println("Thread2 locked " + resource2); 
            }
        });

        t1.start();
        t2.start(); 

        try
        {
            t1.join();
            t2.join(); 
        }
        catch(InterruptedException e)
        {
            System.out.println(e); 
        }

        System.out.println("Both threads successfully completed"); 
    }
}
