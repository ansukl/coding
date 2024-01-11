/**
 *
 * @author annak
 */

public class DateTime extends Date {
    private int hour;
    private int minute;
    private int second;
    
    public DateTime(int year, int month, int day, int hour, int minute, int second) throws DateException {
        super(year, month, day);
        this.hour = hour;
        this.minute = minute;
        this.second = second;
        
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
            throw new DateException(String.format("Illegal time %02d:%02d:%02d",hour, minute, second));
            }
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
    
    public String toString() {
        String date = super.toString();
        String formatted = String.format("%s %02d:%02d:%02d", date, hour, minute, second);
        return formatted;
    }
}