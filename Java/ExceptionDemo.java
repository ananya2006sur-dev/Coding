// Exception Handling Demo Program

// Custom Checked Exception
class MyCheckedException extends Exception {
    public MyCheckedException(String message) {
        super(message);
    }
}

// Custom Unchecked Exception
class MyUncheckedException extends RuntimeException {
    public MyUncheckedException(String message) {
        super(message);
    }
}

public class ExceptionDemo {

    // Method using 'throws' keyword
    static void checkAge(int age) throws MyCheckedException {
        if (age < 18) {
            // using 'throw'
            throw new MyCheckedException("Age must be 18 or above.");
        } else {
            System.out.println("Age is valid.");
        }
    }

    // Method to demonstrate unchecked exception
    static void divide(int a, int b) {
        if (b == 0) {
            throw new MyUncheckedException("Cannot divide by zero!");
        }
        System.out.println("Result = " + (a / b));
    }

    public static void main(String[] args) {

        System.out.println("=== Exception Handling Demo ===");

        // 1. Built-in Exception (ArithmeticException)
        try {
            int x = 10 / 0; // causes ArithmeticException
        } catch (ArithmeticException e) {
            System.out.println("Caught ArithmeticException: " + e.getMessage());
        } finally {
            System.out.println("Finally block executed (always runs).");
        }

        // 2. ArrayIndexOutOfBoundsException
        try {
            int arr[] = {1, 2, 3};
            System.out.println(arr[5]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Caught ArrayIndexOutOfBoundsException.");
        }

        // 3. Custom Checked Exception
        try {
            checkAge(16);
        } catch (MyCheckedException e) {
            System.out.println("Custom Checked Exception: " + e.getMessage());
        }

        // 4. Custom Unchecked Exception
        try {
            divide(10, 0);
        } catch (MyUncheckedException e) {
            System.out.println("Custom Unchecked Exception: " + e.getMessage());
        }

        System.out.println("Program continues after handling exceptions...");
    }
}