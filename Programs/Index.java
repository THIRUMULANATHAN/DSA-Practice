
public class Index {
    public static void main(String [] args) {
        String str = "hello";
        System.out.println(reverse(str));

        String pal = "racecar";
        System.out.println(isPalindrome(pal) ? "Palindrome" : "Not Palindrome");

        int decimal = 294;
        System.out.println(findBinary(decimal, ""));

        int n = 10;
        System.out.println(findSumOfN(n));

        int hr = 1, min = 30;
        System.out.println(degreeFinder(hr, min));
    }

    private static String reverse(String input) {
        if (input.equals("")) {
            return "";
        }

        return reverse(input.substring(1)) + input.charAt(0);
    }

    private static boolean isPalindrome(String input) {
        input.toLowerCase();
        if (input.length() == 0 || input.length() == 1) {
            return true;
        }
    
        if (input.charAt(0) == input.charAt(input.length()-1)) {
            return isPalindrome(input.substring(1, input.length()-1));
        }
        return false;
    }

    private static String
     findBinary(int decimal, String result) {
        if (decimal == 0) {
            return result;
        }

        result = decimal % 2 + result;
        return findBinary(decimal/2, result);
    }

    public static int findSumOfN(int num) {
        if (num<=1) {
            return num;
        }
        return num + findSumOfN(num-1);
    }

    public static double degreeFinder(int hr, int min) {
        int hd = hr*30;
        int md = min*6;
        double dev = min*0.5;
        double degree = Math.abs((hd + dev) - md);

        return degree;
    }

    
}