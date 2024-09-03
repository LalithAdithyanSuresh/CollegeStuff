public class Operators_Q2 {

    public static void main(String[] args) {
        int a = 10;
        int b = 5;

        System.out.println("Increment and Decrement Operators:");
        System.out.println("Initial value of a: " + a);
        System.out.println("a++ (post-increment): " + (a++));
        System.out.println("Value of a after post-increment: " + a);
        System.out.println("++a (pre-increment): " + (++a));
        System.out.println("a-- (post-decrement): " + (a--));
        System.out.println("Value of a after post-decrement: " + a);
        System.out.println("--a (pre-decrement): " + (--a));
        
        int c = 6; 
        int bitwiseComplement = ~c;
        System.out.println("\nBitwise Complement Operator:");
        System.out.println("c: " + c);
        System.out.println("Bitwise complement of c: " + bitwiseComplement);
        
        System.out.println("\nArithmetic Operators:");
        System.out.println("a + b = " + (a + b));
        System.out.println("a - b = " + (a - b));
        System.out.println("a * b = " + (a * b));
        System.out.println("a / b = " + (a / b));
        System.out.println("a % b = " + (a % b));
        
        System.out.println("\nRelational Operators:");
        System.out.println("a > b: " + (a > b));
        System.out.println("a < b: " + (a < b));
        System.out.println("a >= b: " + (a >= b));
        System.out.println("a <= b: " + (a <= b));
        System.out.println("a == b: " + (a == b));
        System.out.println("a != b: " + (a != b));
        
        int d = 12;
        int e = 7;  
        System.out.println("\nBitwise Operators:");
        System.out.println("d & e (AND): " + (d & e));
        System.out.println("d | e (OR): " + (d | e));   
        System.out.println("d ^ e (XOR): " + (d ^ e));  
        System.out.println("d << 2 (left shift): " + (d << 2)); 
        System.out.println("d >> 2 (right shift): " + (d >> 2)); 
        
        int max = (a > b) ? a : b;
        System.out.println("\nConditional (Ternary) Operator:");
        System.out.println("The greater of a and b is: " + max);
    }
}