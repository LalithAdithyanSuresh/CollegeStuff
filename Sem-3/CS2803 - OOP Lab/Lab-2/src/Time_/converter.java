package Time_;

public class converter {
    public static double HourToSec(double curr){
        return curr * 3600;
    }
    public static double HourToMin(double curr){
        return curr * 60;
    }
    public static double SecToHour(double curr){
        return curr / 3600;
    }
    public static double MinToHour(double curr){
        return curr / 60;
    }
}
