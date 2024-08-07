// CONSTRUCTORS IN SUB CLASSES
// super() keyword is used to access the parent class constructor
// Super() can call both parametric as well as non-parametric constructors depending upon the situation.
// Call to super() must be first statement in derived Class constructor.
// If a constructor does not explicitly invoke a superclass constructor by using super(), the jabva compiler automatically inserts a call to the no-argument constructor of teh superclass.

// This can be used to call the parents methids and variables


public class constructorIn{
    int s1;
    String str;
    constructorIn(int a,String s){
        this.s1 = a;
        this.str = s;
    }

}






public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
    }
}
