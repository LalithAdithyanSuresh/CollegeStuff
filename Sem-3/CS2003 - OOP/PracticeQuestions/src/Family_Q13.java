class Family_Q13 {
    private String mobileNumber;
    public Family_Q13(String mobileNumber) {
        this.mobileNumber = mobileNumber;
    }
    private String getMobileNumber() {
        return mobileNumber;
    }
    public void displayMobileNumber() {
        System.out.println("Family Mobile Number: " + getMobileNumber());
    }

    public static void main(String[] args) {
        Family_Q13 myFamily = new Family_Q13("9876543210");
        myFamily.displayMobileNumber();
        
    }
}
