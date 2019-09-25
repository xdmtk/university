
import java.util.ArrayList;

public class TestAVL1 {

	public static void main(String[] args) {

			StringAVLTreeXtra t = new StringAVLTreeXtra();

			String str;
			int line = 1;
			char action;
			String s = "imaoinaoioaoipaoiqaoilaoikaoikdikgikfikeo";

			// add lines like this when you have delete working
			// s = s + "dkeodkfodpao";
			do {
				action = s.charAt(0);
				if (action == 'i') {   // insert
					str = s.substring(1,3);
					s = s.substring(3, s.length());
					t.insert(str);
				} else if (action == 'd') {  // delete
					str = s.substring(1,3);
					s = s.substring(3, s.length());
					t.delete(str);
				} else if (action == 'n') {  // new tree -- wipe out the tree and start over
					s = s.substring(1, s.length());
					t = new StringAVLTreeXtra();
				} else {  // no other choice, then output the tree
					s = s.substring(1, s.length());
					t.display();
					System.out.println(" - " + line++ + ".\n");
				}
			} while (s.length() != 0);
		t.display();
	}
}

class StringAVLTreeXtra extends StringAVLTree {

	public StringAVLTreeXtra() {
		super();
	}
	
	public StringAVLNode getRoot() {
		return root;
	}

	public void display() {
		paren_out(getRoot());
		System.out.println();
		bal_out(getRoot());
	}

	public void paren_out(StringAVLNode t) {
		if (t == null) {
		} else {
			System.out.print("(");
			paren_out(t.getLeft());
			if (t.getItem().length() <= 1)
				System.out.print(" ");
			System.out.print(t.getItem());
			paren_out(t.getRight());
			System.out.print(")");
		}
	}

	public void bal_out(StringAVLNode t) {
		if (t == null) {
		} else {
			System.out.print("(");
			bal_out(t.getLeft());
			if (t.getBalance() == -1)
				System.out.print(t.getBalance());
			else
				System.out.print(" " + t.getBalance());
			bal_out(t.getRight());
			System.out.print(")");
		}
	}

}

class StringAVLNode {
	private String item;
	private int balance;
	private StringAVLNode left, right;

	// just one constructor, please
	public StringAVLNode(String str) {
		item = str;
		balance = 0;
		left = null; right = null;
	}

	public int getBalance () {
		return balance;
	}

	public void setBalance ( int bal){
		balance = bal;
	}

	public String getItem () {
		return item;
	}

	public StringAVLNode getLeft () {
		return left;
	}

	public void setLeft (StringAVLNode pt){
		left = pt;
	}

	public StringAVLNode getRight () {
		return right;
	}

	public void setRight (StringAVLNode pt){
		right = pt;
	}


}



class StringAVLTree {


	StringAVLNode root;

	// just one constructor
	public StringAVLTree() {
        root = null;
	}


	// TODO: Find a way to balance these without calling height
	private static StringAVLNode rotateRight(StringAVLNode t) {
        StringAVLNode returnNode = t.getLeft();

        t.setLeft(returnNode.getRight());
        returnNode.setRight(t);
        t.setBalance(findBalance(t));
        returnNode.setBalance(findBalance(returnNode));

        return returnNode;
	}

	// TODO: Find a way to balance these without calling height
	private static StringAVLNode rotateLeft(StringAVLNode t) {
        StringAVLNode returnNode = t.getRight();

        t.setRight(returnNode.getLeft());
        returnNode.setLeft(t);
        t.setBalance(findBalance(t));
        returnNode.setBalance(findBalance(returnNode));

        return returnNode;
	}



	public int height() {
		return height(root);
	}

	/** Find height by descending the tree based on node balance
	 * factor
	 */
	private static int height(StringAVLNode t) {
		int height = 0;
		if (t != null) {
			if (t.getBalance() > 0)
				height = height(t.getRight()) + 1;
			else
				height = height(t.getLeft()) + 1;
		}
		return height;
	}




	public int nadir() {
		return nadir(root);
	}

	/** Essentially the inverse of height, descend the tree
	 * in the direction of the less heavy node
	 */
	private static int nadir(StringAVLNode t) {
		int nadir = 0;
		if (t != null) {
			if (t.getBalance() > 0 )
				nadir = nadir(t.getLeft()) + 1;
			else
				nadir = nadir(t.getRight()) + 1;
		}
		return nadir ;

	}




	// Return the number of leaves in the tree
	public int leafCt() {
		return leafCt(root);
	}

	/** Recursively traverse every node in the tree, adding one to the
	 *  total recursive sum with each function return
	 */
	private int leafCt(StringAVLNode t) {

		int leafCount = 0;
		if (t != null) {
			leafCount = leafCt(t.getLeft()) + leafCt(t.getRight()) + 1;
		}
		return leafCount;
	}






	// Return the number of perfectly balanced AVL nodes
	public int balanced() {
		return balanced(root);
	}

	/** Similar to the leafCount() method, except the integer returned
	 *  is only incremented when the balance of the given node is 0
	 */
	private int balanced(StringAVLNode t) {
		if (t != null) {
				 return balanced(t.getLeft()) + balanced(t.getRight()) + (t.getBalance() == 0 ? 1 : 0);
		}
		return 0;
	}






	/**
	 * TODO: DELETE THIS METHOD - SHOULD FIND BALANCE WITHOUT CALLING HEIGHT
	 */
	private static int findBalance(StringAVLNode t) {
		int nodeBalance;

		nodeBalance = height(t.getRight()) - height(t.getLeft());
		return nodeBalance;
	}






	// Not used - For delete only
	public String successor(String str) {
		return new String("foo");
	}



	public void insert(String str) {
		root = insert(str, root);
	}


	private StringAVLNode insert(String str, StringAVLNode t) {

		// Base case - Just insert the node
		if (t == null)
			t = new StringAVLNode(str);
		else {

			// Perform string comparisons to determine left/right insert
			int compareResult = str.compareToIgnoreCase(t.getItem());
			if (compareResult < 0) {
				t.setLeft(insert(str, t.getLeft()));
			}
			else if (compareResult > 0) {
				t.setRight(insert(str, t.getRight()));
			}


			// TODO: THIS IS WRONG - NEED TO FIND A WAY TO UPDATE BALANCE WITHOUT CALLING HEIGHT
			t.setBalance(findBalance(t));
			int balance = t.getBalance();


			// Verbosify booleans
			boolean rightImbalance = balance > 1; boolean leftImbalance = balance < -1;

			// Imbalance tree situation calls balanceTrees() to handle the rotation logic
			// ( Keeps insert() succinct )
			if (rightImbalance || leftImbalance)
				t = balanceTrees(balance, t);

		}
		return t;
	}



	// Rotation Handler
	private StringAVLNode balanceTrees(int balance, StringAVLNode t) {

		// Verbosify boolean values
		boolean rightHeavy = balance > 1; boolean leftHeavy = balance < -1;
		boolean requiresDoubleLeft = t.getRight() != null && t.getRight().getBalance() <= -1;
		boolean requiresDoubleRight = t.getLeft() != null && t.getLeft().getBalance() >= 1;

		if (rightHeavy) {

			/** Do double left rotation by right rotating the right child subtree, then
			 * rotate left
			 */
			if (requiresDoubleLeft) {

                t.setRight(rotateRight(t.getRight()));
                t = rotateLeft(t);

			}
			else {
				t = rotateLeft(t);
			}
		}

		/** Do double right rotation by left rotating the left child subtree, then
		 * rotate right
		 */
		else if (leftHeavy) {
			if (requiresDoubleRight) {

				t.setLeft(rotateLeft(t.getLeft()));
                t = rotateRight(t);

			}
			else {
                t = rotateRight(t);
			}
		}
		return t;
	}


	// TODO: Unused
	public void delete(String d) {

	}
	private StringAVLNode delete(StringAVLNode t, String d) {
		return new StringAVLNode("Foo");
	}



	// who are you? Put your name here!
	public static String myName() {
		return "Nicholas Martinez";
	}
}








