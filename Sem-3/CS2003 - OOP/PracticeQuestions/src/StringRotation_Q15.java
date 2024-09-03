public class StringRotation_Q15 {
    public static boolean isRotatedByTwoPlaces(String str1, String str2) {
        if (str1.length() != str2.length()) {
            return false;
        }
        String clockwiseRotation = str1.substring(str1.length() - 2) + str1.substring(0, str1.length() - 2);
        String anticlockwiseRotation = str1.substring(2) + str1.substring(0, 2);
        return str2.equals(clockwiseRotation) || str2.equals(anticlockwiseRotation);
    }

    public static void main(String[] args) {
        String str1 = "amazon";
        String str2 = "onamaz";
        if (isRotatedByTwoPlaces(str1, str2)) {
            System.out.println(str2 + " can be obtained by rotating " + str1 + " exactly 2 places.");
        } else {
            System.out.println(str2 + " cannot be obtained by rotating " + str1 + " exactly 2 places.");
        }
    }
}
