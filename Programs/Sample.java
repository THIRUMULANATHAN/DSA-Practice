import java.util.*;

class Sample {
    public static void main(String [] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        int n = Integer.parseInt(scan.nextLine());
        
        if (n != s.length()) {
            System.out.println("Error: word_length does not match actual string length");
            scan.close();
            return;
        }
        
        char carr[] = s.toCharArray();
        List<String> sl = new ArrayList<>();
        
        findSubSequence(carr, "", 0, sl);
        
        System.out.print("Subsequences of the word: [");
        for (String S : sl) {
            System.out.print(S + ", ");
        }
        System.out.println("]");   // always end with ]
        
        System.out.println("Count of subsequences: " + sl.size());

        scan.close();
    }
    
    private static void findSubSequence(char[] str, String curr, int index, List<String> sl) {
        if (index == str.length) {
            sl.add(curr);  // includes empty subsequence too
            return;
        }
        
        // include current character
        findSubSequence(str, curr + str[index], index + 1, sl);
        // exclude current character
        findSubSequence(str, curr, index + 1, sl);
    }
}
