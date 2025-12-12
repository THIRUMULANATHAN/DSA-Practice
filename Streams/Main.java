import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(9, 8, 1, 7, 2, 5, 3);
        System.out.println("Filtered Elements: ");
        arr.stream()
            .filter(n -> n%2 != 0)
            .sorted()
            .map(n -> n*2)
            .forEach(n -> System.out.println(n));
        
        System.out.println("Added Value: ");
        int result = arr.stream()
            .filter(n -> n%2 != 0)
            .sorted()
            .map(n -> n*2)
            .reduce(0, (c,e) -> c+e);
        System.out.println(result);
    }
}