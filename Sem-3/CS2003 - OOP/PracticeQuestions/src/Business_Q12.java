class Business_Q12 {
    private String employeeName;
    private String employeeId;
    public static final String COMPANY_NAME = "Codebuzz Limited";
    public static final String BRANCH_NAME = "Teynampet Branch";
    public static final String LOCATION = "Teynampet, Chennai";

    public Business_Q12(String employeeName, String employeeId) {
        this.employeeName = employeeName;
        this.employeeId = employeeId;
    }
    public String getEmployeeName() {
        return employeeName;
    }
    public String getEmployeeId() {
        return employeeId;
    }
    public void displayIDCard() {
        System.out.println("Company Name: " + COMPANY_NAME);
        System.out.println("Branch Name: " + BRANCH_NAME);
        System.out.println("Location: " + LOCATION);
        System.out.println("Employee Name: " + getEmployeeName());
        System.out.println("Employee ID: " + getEmployeeId());
    }

    public static void main(String[] args) {
        Business_Q12 idCard = new Business_Q12("John Doe", "A12345");
        idCard.displayIDCard();
    }
}
