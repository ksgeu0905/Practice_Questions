import java.util.*;

public class MatrixOperations {
    public static void addition(int[][] arr1, int[][] arr2, int n, int m) {
        int[][] arr3 = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr3[i][j] = arr1[i][j] + arr2[i][j];
            }
        }
        System.out.println("The matrix after addition becomes:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(arr3[i][j] + " ");
            }
            System.out.print("\n");
        }
    }

    public static void subtraction(int[][] arr1, int[][] arr2, int n, int m) {
        int[][] arr3 = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr3[i][j] = arr1[i][j] - arr2[i][j];
            }
        }
        System.out.println("The matrix after subtraction becomes:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(arr3[i][j] + "\t");
            }
            System.out.print("\n");
        }
    }

    public static void multiply(int[][] arr1, int[][] arr2, int n, int m, int a, int b) {
        int[][] arr3 = new int[n][b];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < b; j++)
                arr3[i][j] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b; j++) {
                for (int k = 0; k < m; k++) {
                    arr3[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        System.out.println("The matrix after Multiplication becomes:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b; j++) {
                System.out.print(arr3[i][j] + "\t");
            }
            System.out.print("\n");
        }
    }

    public static void main(String[] args) {
        int n, m, a, b;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of rows and number of columns of matrix 1: ");
        n = sc.nextInt();
        m = sc.nextInt();
        System.out.println("Enter the matrix: ");
        int[][] arr1 = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr1[i][j] = sc.nextInt();
            }
        }
        System.out.print("Enter the number of rows and number of columns of matrix 2: ");
        a = sc.nextInt();
        b = sc.nextInt();
        System.out.println("Enter the matrix: ");
        int[][] arr2 = new int[a][b];

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                arr2[i][j] = sc.nextInt();
            }
        }
        System.out.println("1:- Addition\n2:- Subtraction\n3:- Multiplication\nWhats your choice? :- ");
        int x = sc.nextInt();
        switch (x) {
            case 1:
                addition(arr1, arr2, n, m);
                break;
            case 2:
                subtraction(arr1, arr2, n, m);
                break;
            case 3:
                if (m != a)
                    System.out.println("Not possible because m!=a");
                else
                    multiply(arr1, arr2, n, m, a, b);
                break;
        }
        sc.close();
    }
}
