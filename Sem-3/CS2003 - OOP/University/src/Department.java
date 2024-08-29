public class Department {
    
    private String name;
    private int numberOfCourses;
    public Department(String name, int numberOfCourses) {
        this.name = name;
        this.numberOfCourses = numberOfCourses;
    }
    public String getName() {
        return name;
    }
    public int getNumberOfCourses() {
        return numberOfCourses;
    }
    public void displayInfo() {
        System.out.println("Department Name: " + name);
        System.out.println("Number of Courses: " + numberOfCourses);
    }
}
    
