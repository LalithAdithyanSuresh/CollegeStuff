public class PrivateInnerclass {
    int x = 10;
    private class hello{
        int y = 11;
        void hi(){
            System.out.println("Hi message");
        }
    }
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        PrivateInnerclass externalOBJ = new PrivateInnerclass();
        PrivateInnerclass.hello innerOBJ = externalOBJ.new hello();
        innerOBJ.hi();
        System.out.println(externalOBJ.x);
        System.out.println(innerOBJ.y);
    }
}
