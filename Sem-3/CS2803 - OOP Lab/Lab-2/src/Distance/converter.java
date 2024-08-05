package Distance;

public class converter {
    public static double KmToM(double curr){
        return curr * 1000;
    }
    public static double MTKm(double curr){
        return curr / 1000;
    }
    public static double KmToMile(double curr){
        return curr / 1.609;
    }
    public static double MileToKm(double curr){
        return curr * 1.609;
    }
}
