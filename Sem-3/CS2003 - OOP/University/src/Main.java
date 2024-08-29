
public class Main {
    public static void main(String[] args) {
        Department csDept = new ComputerScienceDepartment("Computer Science", 20, 5);
        Department mathDept = new MathematicsDepartment("Mathematics", 15, 50);
        Department physicsDept = new PhysicsDepartment("Physics", 10, 30);

        System.out.println("Department Details:");
        System.out.println("-------------------");
        csDept.displayInfo();
        System.out.println();
        mathDept.displayInfo();
        System.out.println();
        physicsDept.displayInfo();
    }
}
