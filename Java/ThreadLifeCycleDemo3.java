class LifeCycleThread extends Thread
{
    public void run()
    {
        System.out.println("Thread is running");
        System.out.println("Thread state inside run() method: " + Thread.currentThread().getState()); 
    }
}

public class ThreadLifeCycleDemo3
{
    public static void main(String[] args)
    {
        LifeCycleThread t = new LifeCycleThread();

        System.out.println("State after creation: " + t.getState()); 

        t.start();
        System.out.println("State after start: " + t.getState()); 

        try
        {
            t.join(); 
        }
        catch(InterruptedException e)
        {
            System.out.println(e); 
        }

        System.out.println("State after completion: " + t.getState()); 

        System.out.println("\nCalling run() directly");
        LifeCycleThread t2 = new LifeCycleThread();
        t2.run();
        System.out.println("State after calling run() directly: " + t2.getState()); 
    }
}