import java.util.Scanner;

public class Main {
	public static void main ( String args[] ) {
		Scanner scn = new Scanner ( System.in );
		System.out.println ( "Enter the number of lines : " );
		int n = scn.nextInt(), this_start = 0;
		int arr[][] = new int[n+1][n+1];
		for ( int i = 0 ; i < n ; ++i ) {
			for ( int j = 0 ; j <= i ; ++j ) {
				arr[i][j] = this_start;
				this_start += 2;
			}
		}
		for ( int i = 0 ; i < n ; ++i ) {
			for ( int j = 0 ; j <= i ; ++j ) {
				System.out.print ( arr[i][j] + " " );
			}
			System.out.println ( "" );
		}
	}
}

