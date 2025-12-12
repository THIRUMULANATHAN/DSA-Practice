import java.util.Scanner;

class BMI {
    private int weight;
    private double height;

    BMI(int w, double h) {
        this.weight = w;
        this.height = h;
    }

    char getGrade() {
        double bmi = weight / (height * height);

        if (bmi < 18.5) return 'U';
        else if (bmi < 25.0) return 'N';
        else if (bmi < 30.0) return 'H';
        else return 'O';
    }
}

public class Dummy1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int w = sc.nextInt();
        double h = sc.nextDouble();
        sc.close();

        BMI person = new BMI(w, h);
        System.out.print(person.getGrade());
    }
}
