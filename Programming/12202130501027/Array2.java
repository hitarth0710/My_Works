import java.util.Scanner;

class Matrix {
    int row, column;
    float mat[][];

    Matrix(int a[][]) {
        row = a.length;
        column = a[0].length;
        mat = new float[row][column];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                mat[i][j] = a[i][j];
            }
        }
    }

    Matrix() {
        row = 3;
        column = 3;
        mat = null;
    }

    Matrix(int r, int c) {
        row = r;
        column = c;
        mat = new float[row][column];
    }

    void readMatrix() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter elements of the matrix:");
        mat = new float[row][column]; // Initialize mat array with appropriate size
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                mat[i][j] = scanner.nextFloat();
            }
        }
        scanner.close();
    }

    float[][] transpose() {
        float[][] result = new float[column][row];
        for (int i = 0; i < column; i++) {
            for (int j = 0; j < row; j++) {
                result[i][j] = mat[j][i];
            }
        }
        return result;
    }

    float[][] matrixMultiplication(Matrix second) {
        if (column != second.row) {
            System.out.println("Matrix multiplication not possible.");
            return null;
        }
        float[][] result = new float[row][second.column];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < second.column; j++) {
                for (int k = 0; k < column; k++) {
                    result[i][j] += mat[i][k] * second.mat[k][j];
                }
            }
        }
        return result;
    }

    void displayMatrix(float[][] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }

    void displayMatrix() {
        displayMatrix(mat);
    }

    float maximum_of_array() {
        float max = mat[0][0];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (mat[i][j] > max) {
                    max = mat[i][j];
                }
            }
        }
        return max;
    }

    float average_of_array() {
        float sum = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                sum += mat[i][j];
            }
        }
        return sum / (row * column);
    }
}

public class Array2 {
    public static void main(String[] args) {
        int[][] arr1 = {{1, 2, 3}, {4, 5, 6}};
        Matrix matrix1 = new Matrix(arr1);
        Matrix matrix2 = new Matrix();
        Matrix matrix3 = new Matrix(3, 3);

        matrix2.readMatrix();
        matrix3.readMatrix();

        System.out.println("Matrix 1:");
        matrix1.displayMatrix();
        System.out.println("Transpose of Matrix 1:");
        matrix1.displayMatrix(matrix1.transpose());
        System.out.println("Matrix 2:");
        matrix2.displayMatrix();
        System.out.println("Matrix 3:");
        matrix3.displayMatrix();
        System.out.println("Matrix 1 multiplied by Matrix 3:");
        matrix1.displayMatrix(matrix1.matrixMultiplication(matrix3));
        System.out.println("Maximum element of Matrix 1: " + matrix1.maximum_of_array());
        System.out.println("Average of Matrix 1: " + matrix1.average_of_array());
    }
}
