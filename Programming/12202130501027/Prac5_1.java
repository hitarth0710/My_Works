class CPU{
    double price;
    CPU(double price)
    {
        this.price=price;
    }
    class Processor{
        double cores;
        double cache;
        String Manufacturer;
        Processor(double cores, String Manufacturer)
        {
            this.cores = cores;
            this.Manufacturer = Manufacturer;
        }
        double getCache(double cache)
        {
            return cache;
        }
        void displayProcessorDetail()
        {
            double cac = getCache(cache);
            System.out.println("Processor Details: ");
            System.out.println("Cores: " + cores);
            System.out.println("Cache: " + cac);
            System.out.println("Manufacturer: " + Manufacturer);
            System.out.println("Price of CPU is "+price);
        }
    }
    class RAM{
        double memory;
        double clockSpeed;
        String Manufacturer;
        RAM(double memory, String Manufacturer)
        {
            this.memory = memory;
            this.Manufacturer = Manufacturer;
        }
        double getClockSpeed(double clockSpeed) 
        {
            return clockSpeed;
        }
        void displayRAMDetails()
        {
            double speed = getClockSpeed(clockSpeed);
            System.out.println("RAM Details: ");
            System.out.println("Memory: " + memory);
            System.out.println("Clock Speed: " + speed);
            System.out.println("Manufacturer: " + Manufacturer);
            System.out.println("Price of CPU is "+price);

        }
        
    }
}


public class Prac5_1 {
    public static void main(String args[])
    {
        CPU cpu = new CPU(50000);
        CPU.Processor processor = cpu.new Processor(8,"Intel");
        CPU.RAM ram = cpu.new RAM(16,"Crucial");
        
        processor.getCache(12);
        ram.getClockSpeed(3200);
        processor.displayProcessorDetail();
        ram.displayRAMDetails();
    }
    
}
