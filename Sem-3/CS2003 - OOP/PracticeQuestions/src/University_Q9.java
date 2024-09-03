abstract class Staff {
    private String name;
    private int id;

    public Staff(String name, int id) {
        this.name = name;
        this.id = id;
    }
    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }
    public abstract void performDuties();
}

class TeachingStaff extends Staff {
    private String department;
    private String designation; 

    public TeachingStaff(String name, int id, String department, String designation) {
        super(name, id);
        this.department = department;
        this.designation = designation;
    }

    @Override
    public void performDuties() {
        System.out.println(getName() + " is teaching in the " + department + " department as a " + designation);
    }
}

class NonTeachingStaff extends Staff {
    private String role; 

    public NonTeachingStaff(String name, int id, String role) {
        super(name, id);
        this.role = role;
    }

    @Override
    public void performDuties() {
        System.out.println(getName() + " is working in the " + role + " department.");
    }
}

class Department {
    private String name;
    private String[] programs; 
    public Department(String name, String[] programs) {
        this.name = name;
        this.programs = programs;
    }

    public void showDetails() {
        System.out.println("Department: " + name);
        System.out.print("Programs offered: ");
        for (String program : programs) {
            System.out.print(program + " ");
        }
        System.out.println();
    }
}

public class University_Q9 {
    public static void main(String[] args) {
        Department aiDepartment = new Department("Artificial Intelligence and Data Science", new String[]{"B.Tech", "M.Tech", "Ph.D"});
        Department iotDepartment = new Department("Internet of Things and Cyber Security", new String[]{"B.Tech", "M.Tech"});
        aiDepartment.showDetails();
        iotDepartment.showDetails();
        TeachingStaff profJohn = new TeachingStaff("John Doe", 101, "Artificial Intelligence and Data Science", "Professor");
        TeachingStaff profJane = new TeachingStaff("Jane Smith", 102, "Internet of Things and Cyber Security", "Associate Professor");
        NonTeachingStaff adminAlice = new NonTeachingStaff("Alice Brown", 201, "Administrative");
        NonTeachingStaff hrBob = new NonTeachingStaff("Bob White", 202, "HR");
        profJohn.performDuties();
        profJane.performDuties();
        adminAlice.performDuties();
        hrBob.performDuties();
    }
}
