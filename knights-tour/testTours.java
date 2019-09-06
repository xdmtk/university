/*   My output from running this program
   
 Test 1 for Sam Loyd
  2 27  4 25 46 43 14 39
  5 24  1 42 15 40 49 44
 28  3 26 47 58 45 38 13
 23  6 55 16 41 48 63 50
 18 29 22 59 54 57 12 37
  7 32 17 56 21 62 51 64
 30 19 34  9 60 53 36 11
 33  8 31 20 35 10 61 52
Answers match

Test 2 for Sam Loyd
  13  15  17  19  96  26  22  99  29  46  90  59  55  63
  24 107  82  21  98  28  84  71  58  87  62  52  45  89
  20  97  27  23 106   0  86  91   0  56 100  30  47  61
  16  12  14  25  18  95  73   0   0  85  60   0  64  54
  81  77   0  93  83   0  57 101  70  72  53  88  51  44
   8   1   0  80   0 105  92 103  66  68   0  48  38  31
   4   0  11   7  78  41  94   0  74  37 102  65  34   0
   6   0  76   3   0  10  69   0  40  33  50  43  36   0
   2  79   9   5   0  75 104  67  42  35   0  39  32  49
Answers match

Done with Sam Loyd's test run. It seems to be working.

 */

import java.io.*;

public class testTours {

	// You will need to tweak DataLocation to suit your computer situation. Or you may be able to find a folder to put
	// the test files in so that you don't need it at all.
	final static String DataLocation = new String("C:\\Users\\overc\\IdeaProjects\\cosci282\\data\\");

	public static void main(String[] args) throws IOException {
		String answers[] = {
				"22742546431439524142154049442832647584538132365516414863501829225954571237732175621625164301934960533611338312035106152",
				"1315171996262299294690595563241078221982884715887625245892097272310608691056100304761161214251895730085600645481770938"+
				"305710170725388514481080010592103666804838314011778419407437102653406076301069040335043360279950751046742350393249"};
		KnightBoard b = null;
		boolean working = true;
		for (int i = 1; i <= 2; i++) {
			b = new KnightBoard(DataLocation + "test" + i + ".txt");
			b.solve();
			System.out.println("Test " + i + " for " + KnightBoard.myName());
			System.out.print(b);
			if (b.toString2().compareTo(answers[i-1]) == 0)
				System.out.println("Answers match");
			else {
				working = false;
				System.out.println(" *** NO MATCH ***");
			}
			System.out.println();
		}
		System.out.print("Done with " + KnightBoard.myName() + "'s test run.");
		if (working)
		System.out.println(" It seems to be working.");
		else
			System.out.println(" There seem to be problems.");
	}
}
