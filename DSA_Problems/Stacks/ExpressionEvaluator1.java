import java.util.*;

public class ExpressionEvaluator1 {
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        String infix = scanner.nextLine();
        String postfix = infixToPostFix(infix);
        System.out.println(evaluatePostfix(postfix));

        scanner.close();
    }

    public static int evaluatePostfix(String expression) {
        Stack<Integer> stack = new Stack<>(); 
        for (char c : expression.toCharArray()) {
            if(Character.isDigit(c)) {
                stack.push(c - '0');
            }
            else {
                int op2 = stack.pop();
                int op1 = stack.pop();

                switch (c) {
                    case '+':
                        stack.push(op1 + op2);
                        break;
                    case '-':
                         stack.push(op1 - op2);
                         break;
                    case '*':
                        stack.push(op1 * op2);
                        break;
                    case '/':
                         stack.push(op1 / op2);
                         break;
                    default:
                        break;
                }
            }
        }
        return stack.pop();
    }

    private static String infixToPostFix(String expression) {
        StringBuilder result = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        for(char c : expression.toCharArray()) {
            if(Character.isLetterOrDigit(c)) {
                result.append(c);
            }
            else if (c == '(') {
                    stack.push(c);
            }
            else if (c == ')'){
                while(!stack.isEmpty() && stack.peek() != '(') {
                    result.append(stack.pop());
                }
                stack.pop();
            }
            else {
                while(!stack.isEmpty() && precedenceFinder(c) <= precedenceFinder(stack.peek())) {
                    if(c == '^' && stack.peek() == '^') {
                        break;
                    }
                    result.append(stack.pop());
                }
                stack.push(c);
            }
        }

        while(!stack.isEmpty()) {
            result.append(stack.pop());
        }

        return result.toString();
    }

    private static int precedenceFinder(char symbol) {
        if (symbol == '+' || symbol == '-') {
            return 1;
        }
        else if (symbol == '*' || symbol == '/' || symbol == '%') {
            return 2;
        }
        else if (symbol == '^') {
            return 3;
        }
        return -1;
    }
}
