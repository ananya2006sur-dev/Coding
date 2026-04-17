
public class Str
{
    public static void main(String[] args)
    {
        String s1 = "Cummins";
        System.out.println("s1: " + s1);

        System.out.println("Length of s1: " + s1.length());

        System.out.println("Character at index 4 of s1: " + s1.charAt(4));

        System.out.println("Index of character n in s1: " + s1.indexOf('n'));
        System.out.println("Index of first occurence of m in s1: " + s1.indexOf('m'));
        System.out.println("Index of second occurence of m in s1: " + s1.indexOf('m', 3)); 

        String s2 = "College";
        System.out.println("s2: " + s2);

        System.out.println("Concatenation of s1 and s2: " + s1.concat(s2));

        String s3 = "cummINS"; 
        System.out.println("s3 : " + s3);

        System.out.println("s1 and s3 are equal: " + s1.equals(s3));

        System.out.println("s1 and s3 are equal (ignoring case): " + s1.equalsIgnoreCase(s3));

        System.out.println("Difference between s1 and s2: " + s1.compareTo(s2)); 

        String s4 = "Fummivs"; 
        System.out.println("s4: " + s4);

        System.out.println("Replacing F with C in s4: " + s4.replace('F', 'C'));
        System.out.println("Replacing v with n in s4: " + (s4.replace('F','C')).replace('v','n'));
    }
}

