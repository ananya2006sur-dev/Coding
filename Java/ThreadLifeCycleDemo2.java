class MyThread extends Thread {
    public void run() {
        try {
            System.out.println("Child thread started...");
            Thread.sleep(3000);
            System.out.println("Child thread finished work");
        } catch (InterruptedException e) {
            System.out.println("Child thread interrupted");
        }
    }
}

public class ThreadLifeCycleDemo2 {
    public static void main(String[] args) {
        Thread mainThread = Thread.currentThread(); // reference to main thread

        MyThread t = new MyThread();
        t.start();

        Thread interrupter = new Thread(() -> {
            try {
                Thread.sleep(1000);
                System.out.println("Interrupting main thread...");
                mainThread.interrupt(); // interrupt main thread
            } catch (InterruptedException e) {}
        });

        interrupter.start();

        try {
            System.out.println("Main thread waiting using join...");
            t.join(); // main thread waits
            System.out.println("Main thread resumed normally");
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted while waiting on join()");
        }
    }
}
