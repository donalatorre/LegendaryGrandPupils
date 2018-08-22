import java.util.Scanner;
import java.util.*;
import java.math.BigInteger;

class bigInteger {
	private static BufferedReader stdIn = new 
			BufferedReader(new InputStreamReader (System.in));
	private static Scanner in = new Scanner(System.in);
		
	public static void main(String[] args) {
		BigInteger d = in.nextBigInteger();
		System.out.println(d);
		
		BigInteger uno = new BigInteger("1");
		BigInteger dos = new BigInteger("2");
		System.out.println(uno.add(dos));
		
		BigInteger arr[] = new BigInteger[5];
		
		for(int i = 0; i < arr.length; i ++) {
			arr[i] = new BigInteger(i + "");
			System.out.println(arr[i]);
		}
	}
}