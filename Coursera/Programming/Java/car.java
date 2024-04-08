import java.time.LocalDate;
import java.time.Period;

public class car
{
    private String names;
    public String getNames() {
        return names;
    }
    public void setNames(String names) {
        this.names = names;
    }

    private int speed;
        public int getSpeed() {
        return speed;
    }
    public void setSpeed(int newSpeed) {
        speed = newSpeed;
    }

    private int gasoline;
    private boolean engineState; 

    private LocalDate manufactured;
    public LocalDate getManufacture() {
        return manufactured;
    }
    public void setManufacture(LocalDate manufactured) {
        this.manufactured = manufactured;
    }
	public int getAge() {
		return Period.between(manufactured, LocalDate.now()).getYears();
	}
    
    public static void main(String[] args) {
        car car54 = new car();
        car54.setNames("Car 54");
        car54.setSpeed(20);
        car54.setManufacture(LocalDate.of(1961, 9, 17));
        
        car mach5 = new car();
        mach5.setNames("Mach V");
        mach5.setSpeed(250);
        mach5.setManufacture(LocalDate.of(1967, 4, 2));

        for(car c : new car[] {car54, mach5}) //advance for loop
        {
            System.out.println(c.getNames() + " was manufactured on " + c.getManufacture() + " and is " + c.getAge() + " years old.");
        }


    }
    
}