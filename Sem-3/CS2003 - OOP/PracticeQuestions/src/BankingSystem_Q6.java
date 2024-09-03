import java.util.ArrayList;
import java.util.List;

interface Account {
    void deposit(double amount);
    void withdraw(double amount);
    void calculateInterest();
    double getBalance();
    void viewBalance();
}

class SavingsAccount implements Account {
    private double balance;
    private double interestRate;

    public SavingsAccount(double initialBalance, double interestRate) {
        this.balance = initialBalance;
        this.interestRate = interestRate;
    }

    @Override
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: " + amount);
        } else {
            System.out.println("Deposit amount must be positive.");
        }
    }

    @Override
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrew: " + amount);
        } else {
            System.out.println("Insufficient balance or invalid amount.");
        }
    }

    @Override
    public void calculateInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        System.out.println("Interest added: " + interest);
    }

    @Override
    public double getBalance() {
        return balance;
    }

    @Override
    public void viewBalance() {
        System.out.println("Savings Account Balance: " + balance);
    }
}

class CurrentAccount implements Account {
    private double balance;
    private double overdraftLimit;

    public CurrentAccount(double initialBalance, double overdraftLimit) {
        this.balance = initialBalance;
        this.overdraftLimit = overdraftLimit;
    }

    @Override
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: " + amount);
        } else {
            System.out.println("Deposit amount must be positive.");
        }
    }

    @Override
    public void withdraw(double amount) {
        if (amount > 0 && amount <= (balance + overdraftLimit)) {
            balance -= amount;
            System.out.println("Withdrew: " + amount);
        } else {
            System.out.println("Insufficient balance or overdraft limit exceeded.");
        }
    }

    @Override
    public void calculateInterest() {
        System.out.println("Current Account does not accrue interest.");
    }

    @Override
    public double getBalance() {
        return balance;
    }

    @Override
    public void viewBalance() {
        System.out.println("Current Account Balance: " + balance);
    }
}

class Bank {
    private List<Account> accounts = new ArrayList<>();

    public void addAccount(Account account) {
        accounts.add(account);
        System.out.println("Account added.");
    }

    public void showAllBalances() {
        System.out.println("Showing all account balances:");
        for (Account account : accounts) {
            account.viewBalance();
        }
    }
}

public class BankingSystem_Q6 {
    public static void main(String[] args) {
        Bank bank = new Bank();

        SavingsAccount savings = new SavingsAccount(1000.0, 5.0);
        CurrentAccount current = new CurrentAccount(500.0, 200.0); 

        bank.addAccount(savings);
        bank.addAccount(current);

        savings.deposit(200);
        savings.withdraw(50);
        savings.calculateInterest();
        savings.viewBalance();

        current.deposit(100);
        current.withdraw(600);
        current.viewBalance();
        bank.showAllBalances();
    }
}
