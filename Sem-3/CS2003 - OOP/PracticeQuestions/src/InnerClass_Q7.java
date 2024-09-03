public class InnerClass_Q7 {

    public static class Pair {
        private int min;
        private int max;

        public Pair(int min, int max) {
            this.min = min;
            this.max = max;
        }

        public int getMin() {
            return min;
        }

        public int getMax() {
            return max;
        }
    }

    public static Pair findMinMax(int[] array) {
        if (array == null || array.length == 0) {
            throw new IllegalArgumentException("Array cannot be null or empty");
        }

        int min = array[0];
        int max = array[0];

        for (int num : array) {
            if (num < min) {
                min = num;
            }
            if (num > max) {
                max = num;
            }
        }

        return new Pair(min, max);
    }

    public static void main(String[] args) {
        int[] numbers = {3, 5, 7, 2, 8, -1, 4};

        Pair result = findMinMax(numbers);
        System.out.println("Min: " + result.getMin());
        System.out.println("Max: " + result.getMax());
    }
}
