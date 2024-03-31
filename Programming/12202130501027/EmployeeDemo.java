import java.util.Scanner;

class Employee {
    private String name;
    private double basicSalary;
    private double dearnessAllowance;

    public Employee(String name, double basicSalary, double dearnessAllowance) {
        this.name = name;
        this.basicSalary = basicSalary;
        this.dearnessAllowance = dearnessAllowance;
    }

    public double calculateGrossSalary() {
        return basicSalary + dearnessAllowance;
    }

    public double calculateTDS() {
        double grossSalary = calculateGrossSalary();
        // Calculate TDS based on gross salary using your TDS rate table
        // For example, if TDS is 10% of gross salary
        double tds = 0.10 * grossSalary;
        return tds;
    }

    public double calculateNetSalary() {
        return calculateGrossSalary() - calculateTDS();
    }

    public void printSalaryDetails() {
        System.out.println("Name: " + name);
        System.out.println("Basic Salary (Yearly): " + basicSalary * 12);
        System.out.println("Dearness Allowance: " + dearnessAllowance);
        System.out.println("Gross Salary: " + calculateGrossSalary());
        System.out.println("TDS: " + calculateTDS());
        System.out.println("Net Salary: " + calculateNetSalary());
    }
}

public class EmployeeDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter employee name:");
        String name = scanner.nextLine();

        System.out.println("Enter basic salary:");
        double basicSalary = scanner.nextDouble();

        System.out.println("Enter dearness allowance:");
        double dearnessAllowance = scanner.nextDouble();

        Employee employee = new Employee(name, basicSalary, dearnessAllowance);
        employee.printSalaryDetails();

        scanner.close();
    }
}
