/*
 
My output:
 
Test #1:  Topological Sort  -- Santa Claus
=======
g a d b e c f 

Test #2:  Topological Sort  -- Santa Claus
=======
Loop

Test #3:  Topological Sort  -- Santa Claus
=======
f l c e g k d b i h a j 

=======
f l c e g k d b i h a j 

Done with Santa Claus's test run.

 */


import java.io.*; // for IOException

public class TestTopologicalSort {

	// Set this string similar to the way you did it for the first (sudoku) assignment
	final static String GraphLocation = new String(
			"/home/xdmtk/school/cosci282/graphs/");

	public static void main(String[] args) throws IOException {
		GraphTopSort g;

		for (int i = 1; i <= 3; i++) {
			g = new GraphTopSort();
			g.input(GraphLocation + "Graph" + i + ".txt");
			g.output();
			System.out.println("Test #" + i + ":  Topological Sort  -- " + GraphTopSort.myName());
			System.out.println("=======");
			g.outputTopSort();
			System.out.println();
			if (i == 3) {
				System.out.println("=======");
				g.outputTopSort();
				System.out.println();

			}
		}
		System.out.println("Done with " + GraphTopSort.myName() + "'s test run.");
	}
}
