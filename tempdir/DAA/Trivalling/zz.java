// import java.util.*;
import java.util.Scanner;

class Salesman {

    int travel(int a[][], int start) {

        int n = a.length;
        int row = 1 << n;

        int table[][] = new int[row][n];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < n; j++) {
                table[i][j] = -1;
            }
        }

        int minResult = util(a, table, 1, start, start);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(table[i][j] + "   ");
            }
            System.out.println("");
        }
        return minResult;
    }

    int util(int a[][], int table[][], int mask, int pos, int start) {

        if (mask == ((1 << a.length) - 1)) {
            return a[pos][start];
        }

        if (table[mask][pos] != -1) {

            System.out.println("Cache (mask, pos):: " + mask + "   :::  " + pos);
            return table[mask][pos];
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < a.length; i++) {
            if ((mask & (1 << i)) == 0) {
                int temp = a[pos][i] + util(a, table, (mask | (1 << i)), i, start);
                ans = Math.min(ans, temp);
            }
        }
        table[mask][pos] = ans;
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("Enter the number of villages: ");
        Scanner myInput = new Scanner(System.in);
        int n;
        n = myInput.nextInt();
        System.out.println("Enter the cost Matrix: ");
        int a[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            System.out.println("Enter element of Row " + (i + 1));
            for (int j = 0; j < n; j++) {
                a[i][j] = myInput.nextInt();
            }
        }
        Salesman obj = new Salesman();
        // int a[][] = {
        //         { 0, 20, 42, 25 },
        //         { 20, 0, 30, 34 },
        //         { 42, 30, 0, 10 },
        //         { 25, 34, 10, 0 } };
        long startTime = System.nanoTime();
        int result = obj.travel(a, 0);
        long endTime = System.nanoTime();
    
        
        System.out.println("Result:: Minimum path cost :- " + result);
        System.out.println("This Algorithm took " + (endTime - startTime) + " milliseconds");
    }

}

// Enter the number of villages: 
// 4
// Enter the cost Matrix: 
// Enter element of Row 1
// 0 20 42 25
// Enter element of Row 2
// 20 0 30 34
// Enter element of Row 3
// 42 30 0 10
// Enter element of Row 4
// -1   -1   -1   -1
// 85   -1   -1   -1
// -1   -1   -1   -1
// -1   65   -1   -1
// -1   -1   -1   -1
// -1   -1   64   -1
// -1   -1   -1   -1
// -1   59   35   -1
// -1   -1   -1   -1
// -1   -1   -1   60
// -1   -1   -1   -1
// -1   72   -1   52
// -1   -1   -1   -1
// -1   -1   50   54
// -1   -1   -1   -1
// -1   -1   -1   -1
// Result:: Minimum path cost :- 85
// This Algorithm took 6357900 milliseconds