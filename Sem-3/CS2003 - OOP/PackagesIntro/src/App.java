import java.util.Scanner;


public class App {
    public void main(String[] args) throws Exception {
        int x = 10*10 - 30;
        System.out.println(x);
        @SuppressWarnings("resource")
        Scanner read = new Scanner(System.in);
        String hi = read.nextLine();
        System.out.println(hi);
        System.out.println("Hello, World!");
        hello();
        App start = new App();
        start.hello();

    }
    private void hello(){
        System.out.println("Hello there");
    }
    

}