import java.util.Scanner;

class multiplication extends Thread {
    private int row;
    private static int[][] A, B, C;
    private static int SIZE;

    public multiplication(int row, int[][] A, int[][] B, int[][] C) {
        this.row = row;
        multiplication.A = A;
        multiplication.B = B;
        multiplication.C = C;
    }

    public void run() {
        for (int j = 0; j < SIZE; j++) {
            C[row][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[row][j] += A[row][k] * B[k][j];
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the matrices: ");
        SIZE = scanner.nextInt();

        int[][] A = new int[SIZE][SIZE];
        int[][] B = new int[SIZE][SIZE];
        int[][] C = new int[SIZE][SIZE];

        System.out.println("\nEnter values for MATRIX A:");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                System.out.print("A[" + i + "][" + j + "]: ");
                A[i][j] = scanner.nextInt();
            }
        }

        System.out.println("\nEnter values for MATRIX B:");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                System.out.print("B[" + i + "][" + j + "]: ");
                B[i][j] = scanner.nextInt();
            }
        }

        multiplication[] threads = new multiplication[SIZE];

        for (int i = 0; i < SIZE; i++) {
            threads[i] = new multiplication(i, A, B, C);
            threads[i].start();
        }

        for (int i = 0; i < SIZE; i++) {
            threads[i].join();
        }

        System.out.println("\nResultant matrix:");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                System.out.print(C[i][j] + " ");
            }
            System.out.println();
        }

        scanner.close();
    }
}
