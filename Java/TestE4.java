public class TestE4 {
    public static void main(String[] args) {

        try {
            int x = 10 / 5;   // ArithmeticException
            String s = null;
            System.out.println(s.length()); // NullPointerException
        }

        catch (ArithmeticException e) {
            System.out.println("Division by zero");
        }

        catch (NullPointerException e) {
            System.out.println("Null value used");
        }

        catch (Exception e) {
            System.out.println("General exception");
        }

    }
}
