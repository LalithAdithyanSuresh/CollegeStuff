interface Test {
    int square(int x);
}
class Arithmetic implements Test {
    public int square(int x) {
        return x * x;
    }
}
abstract class PartialTest implements Test {
}

public class Test_Q11 {
    public static void main(String[] args) {
        Arithmetic arithmetic = new Arithmetic();

        int number = 5;
        int result = arithmetic.square(number);
        System.out.println("The square of " + number + " is: " + result);
    }
}
