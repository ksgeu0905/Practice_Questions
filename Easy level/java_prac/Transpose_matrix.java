import java.util.*;
public class Transpose_matrix {
    public static void main(String[] args){
    int n, m;
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the number of rows and number of columns of matrix : ");
    n = sc.nextInt();
    m = sc.nextInt();
    System.out.println("Enter the matrix: ");
    int[][] arr1 = new int[n][m];
    int[][] arr2 = new int[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr1[i][j] = sc.nextInt();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr2[j][i]=arr1[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            System.out.print(arr2[i][j]+"\t");
        }
        System.out.print("\n");
    }
    sc.close();

}
}
