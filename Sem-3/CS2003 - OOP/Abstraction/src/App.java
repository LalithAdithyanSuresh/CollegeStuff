abstract class hello{
    abstract void printer();
}

// Concrete means that all defenitions of the abstract classes are defined.
// Page : 201 LMS Book

// Any class that contains one or more abstract methods must also be declared abstract
// If a class contains an abstract method it needs to be abstract and vice versa is not true
// If non abstract classs extends an abstract class, then the class must implement all the abstract methods of the abstract class else the concrete has to be declasred as abstract as well.abstract 





// CONSTRUCTORS IN SUB CLASSES
// super() keyword is used to access the parent class constructor
// Super() can call both parametric as well as non-parametric constructors depending upon the situation.
// Call to super() must be first statement in derived Class constructor.
// If a constructor does not explicitly invoke a superclass constructor by using super(), the jabva compiler automatically inserts a call to the no-argument constructor of teh superclass.

// This can be used to call the parents methids and variables



public class App extends hello {
    @Override
    public void printer(){
        System.out.println("HELLO");
    }
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        App hi = new App();
        hi.printer();
        hello ho = new App();
        ho.printer();
    }
}
