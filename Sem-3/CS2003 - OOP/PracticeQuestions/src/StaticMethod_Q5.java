public class StaticMethod_Q5 {
    private static int staticVariable = 0;
    private int instanceVariable;
    static {
        System.out.println("Static block executed");
        staticVariable = 10;
    }
    public StaticMethod_Q5(int instanceVariable) {
        this.instanceVariable = instanceVariable;
        staticVariable++;
    }

    public static void staticMethod() {
        System.out.println("Static method called");
        System.out.println("Value of staticVariable inside staticMethod: " + staticVariable);
    }
    public void instanceMethod() {
        System.out.println("Instance method called");
        System.out.println("Value of staticVariable inside instanceMethod: " + staticVariable);
        System.out.println("Value of instanceVariable: " + instanceVariable);
    }

    public static void main(String[] args) {
        System.out.println("Main method started");
        StaticMethod_Q5.staticMethod();
        StaticMethod_Q5 obj1 = new StaticMethod_Q5(5);
        StaticMethod_Q5 obj2 = new StaticMethod_Q5(10);
        
        obj1.instanceMethod();
        obj2.instanceMethod();
        System.out.println("Value of staticVariable directly accessed from main method: " + StaticMethod_Q5.staticVariable);
    }
}
