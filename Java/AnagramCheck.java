import java.util.Scanner;

/**
 * Checks if two strings are anagrams: same letters, same counts, different order allowed.
 * Ignores spaces and letter case (e.g. "Listen" and "Silent" -> anagrams).
 */
public class AnagramCheck {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("First string:  ");
        String a = scanner.nextLine();

        System.out.print("Second string: ");
        String b = scanner.nextLine();

        if (areAnagrams(a, b)) {
            System.out.println("They are anagrams.");
        } else {
            System.out.println("They are NOT anagrams.");
        }

        scanner.close();
    }

    /** True if both strings are anagrams after normalizing (lowercase, spaces removed). */
    public static boolean areAnagrams(String s1, String s2) {
        String x = normalize(s1);
        String y = normalize(s2);

        if (x.length() != y.length()) {
            return false;
        }

        char[] letters1 = x.toCharArray();
        char[] letters2 = y.toCharArray();

        sortChars(letters1);
        sortChars(letters2);

        return sameChars(letters1, letters2);
    }

    private static void sortChars(char[] letters) {
        for (int i = 0; i < letters.length - 1; i++) {
            for (int j = 0; j < letters.length - 1 - i; j++) {
                if (letters[j] > letters[j + 1]) {
                    char tmp = letters[j];
                    letters[j] = letters[j + 1];
                    letters[j + 1] = tmp;
                }
            }
        }
    }

    private static boolean sameChars(char[] a, char[] b) {
        if (a.length != b.length) {
            return false;
        }
        for (int i = 0; i < a.length; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    private static String normalize(String s) {
        return s.replaceAll("\\s+", "").toLowerCase();
    }
}
