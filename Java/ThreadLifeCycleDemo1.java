class MyThread extends Thread {
    public void run() {
        try {
            System.out.println("Thread going to sleep...");
            Thread.sleep(5000); // thread sleeps for 5 seconds
            System.out.println("Thread woke up normally");
        } catch (InterruptedException e) {
            System.out.println("InterruptedException caught!");
            System.out.println("Thread was interrupted while sleeping");
        }
    }
}

public class ThreadLifeCycleDemo1 {
    public static void main(String[] args) {
        MyThread t = new MyThread();
        t.start();

        try {
            Thread.sleep(1000); // main thread waits 1 second
        } catch (InterruptedException e) {}

        t.interrupt(); // interrupting the sleeping thread
    }
}