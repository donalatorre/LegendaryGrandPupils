import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Radix {
	private static BufferedReader stdIn = new 
			BufferedReader(new InputStreamReader (System.in));
	private static Scanner in = new Scanner(System.in);
	
	public static void main(String args[]) {
		String numero = in.next();
		int base1 = in.nextInt();
		int base2 = in.nextInt();
		
		// Convierte S de base1 a base10
		int n = Integer.parseInt(numero, base1);
		
		// Conviernte N de base10 a base2
		String s = Integer.toString(n, base2);
		
		System.out.println(n);
		System.out.println(s);
	}
}