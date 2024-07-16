import java.util.Scanner;


public class hello{
    public static void main(String[] args){
        try (Scanner read = new Scanner(System.in)) {
            System.out.println("What is your name? ");
            String name = read.nextLine();
            System.out.println("Hello there");
            System.out.println(name);
        }
    }
}