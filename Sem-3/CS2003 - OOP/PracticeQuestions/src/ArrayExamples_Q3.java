public class ArrayExamples_Q3 {

    public static void main(String[] args) {
        int[] oneDimArray = {10, 20, 30, 40, 50};
        
        System.out.println("One-Dimensional Array:");
        System.out.println("Length of oneDimArray: " + oneDimArray.length);
        for (int i = 0; i < oneDimArray.length; i++) {
            System.out.println("Element at index " + i + ": " + oneDimArray[i]);
        }

        int[][] twoDimArray = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        
        System.out.println("\nTwo-Dimensional Array:");
        int rows = twoDimArray.length;
        int cols = twoDimArray[0].length;
        System.out.println("Number of rows: " + rows);
        System.out.println("Number of columns: " + cols);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(twoDimArray[i][j] + " ");
            }
            System.out.println();
        }

        int[][][] multiDimArray = {
            {
                {1, 2},
                {3, 4}
            },
            {
                {5, 6},
                {7, 8}
            },
            {
                {9, 10},
                {11, 12}
            }
        };
        
        System.out.println("\nThree-Dimensional Array:");
        int depth = multiDimArray.length;
        int rowsIn3D = multiDimArray[0].length;
        int colsIn3D = multiDimArray[0][0].length;
        System.out.println("Depth: " + depth);
        System.out.println("Number of rows in each 2D slice: " + rowsIn3D);
        System.out.println("Number of columns in each 2D slice: " + colsIn3D);
        
        for (int i = 0; i < depth; i++) {
            System.out.println("2D slice " + (i + 1) + ":");
            for (int j = 0; j < rowsIn3D; j++) {
                for (int k = 0; k < colsIn3D; k++) {
                    System.out.print(multiDimArray[i][j][k] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}