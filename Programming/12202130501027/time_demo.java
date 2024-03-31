class Time 
{
    private int hour;
    private int minute;
    private int second;

    public Time(int hour, int minute, int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public Time sum(Time t1, Time t2) {
        int secondSum = t1.second + t2.second;
        int minuteSum = t1.minute + t2.minute;
        int hourSum = t1.hour + t2.hour;

        if (secondSum >= 60) {
            minuteSum += secondSum / 60;
            secondSum %= 60;
        }

        if (minuteSum >= 60) {
            hourSum += minuteSum / 60;
            minuteSum %= 60;
        }

        return new Time(hourSum, minuteSum, secondSum);
    }
    public int getHour() {
        return this.hour;
    }

    public int getMinute() {
        return this.minute;
    }

    public int getSecond() {
        return this.second;
    }
}

public class time_demo 
{
    public static void main(String[] args) {
        // Create two Time objects
        Time time1 = new Time(1, 30, 30);
        Time time2 = new Time(2, 45, 50);

        // Sum the two Time objects
        Time timeSum = time1.sum(time1, time2);

        // Print the result
        System.out.println("Time sum: " + timeSum.getHour() + " hours, " + timeSum.getMinute() + " minutes, " + timeSum.getSecond() + " seconds");
    }
}
