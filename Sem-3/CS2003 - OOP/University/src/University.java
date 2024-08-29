class ComputerScienceDepartment extends Department {
    private int numberOfLabs;

    public ComputerScienceDepartment(String name, int numberOfCourses, int numberOfLabs) {
        super(name, numberOfCourses);
        this.numberOfLabs = numberOfLabs;
    }
    public int getNumberOfLabs() {
        return numberOfLabs;
    }
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Number of Labs: " + numberOfLabs);
    }
}

class MathematicsDepartment extends Department {
    private int numberOfResearchPapers;
    public MathematicsDepartment(String name, int numberOfCourses, int numberOfResearchPapers) {
        super(name, numberOfCourses);
        this.numberOfResearchPapers = numberOfResearchPapers;
    }
    public int getNumberOfResearchPapers() {
        return numberOfResearchPapers;
    }
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Number of Research Papers: " + numberOfResearchPapers);
    }
}

class PhysicsDepartment extends Department {
    private int numberOfExperiments;
    public PhysicsDepartment(String name, int numberOfCourses, int numberOfExperiments) {
        super(name, numberOfCourses);
        this.numberOfExperiments = numberOfExperiments;
    }
    public int getNumberOfExperiments() {
        return numberOfExperiments;
    }
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Number of Experiments: " + numberOfExperiments);
    }
}
