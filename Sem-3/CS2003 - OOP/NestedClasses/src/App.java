public class App {

    class hello{
        void hi(){
            System.out.println("Hi message");
        }
        
    }
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        App externalOBJ = new App();
        App.hello innerOBJ = externalOBJ.new hello();
        innerOBJ.hi();
    }
}
