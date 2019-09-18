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
		BTreePrinter.printStringAVLNode(getRoot());
		/*
		paren_out(getRoot());
		System.out.println();
		bal_out(getRoot());
		
		 */
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

	private static StringAVLNode rotateRight(StringAVLNode t) {
		return new StringAVLNode("Foo");
	}

	private static StringAVLNode rotateLeft(StringAVLNode t) {
		return new StringAVLNode("Foo");
	}

	/** For these next four, be sure not to use any global variables
	 * and no extra “counting” parameters in the recursive methods, e.g.,
	 * the recursive height method should just have one parameter, the
	 * StringAVLNode
	 * Return the height of the tree – not to be used anywhere in insert or delete
	 */
	public int height() {
		return height(root);
	}

	/**
	 * Recursively descend both left and right nodes to get the
	 * height of the tree
	 */
	private int height(StringAVLNode t) {
		int height;
		if (t != null)
			height = Math.max(height(t.getLeft()), height(t.getRight()))+ 1;
		else
			height = -1;
		return height;
	}


	// Return the number of leaves in the tree
	public int leafCt() {
		return leafCt(root);
	}


	/** Recursively traverse every node in the tree,
	 * adding one to the total recursive sum with each
	 * function return
	 */
	private int leafCt(StringAVLNode t) {

		int leafCount;
		if (t != null) {
			leafCount = leafCt(t.getLeft()) + 1;
			leafCount += leafCt(t.getRight()) + 1;
		}
		else
			leafCount = -1;
		return leafCount;
	}


	// Return the number of perfectly balanced AVL nodes
	public int balanced() {

	}

	private int balance(StringAVLNode t) {



	}

	// Return the inorder successor, i.e., the next larger value in the tree
	// or null if there is none or str is not in the tree
	public String successor(String str) {
		return new String("foo");
	}

	/**
	 * Public insertion method handling the empty tree case and a
	 * typical insertion case
	 *
 	 * @param str - Value to be inserted in the tree
	 */
	public void insert(String str) {

		/**
		 * If our root node exists, then we need to call our internal
		 * insertion method to decide whether to insert on the left or
		 * the right
		 */
		if (root != null)
			root = insert(str, root);
		/**
		 * If our root node does not exist, our tree is empty, and we can
		 * simply establish the root as a new Node
		 */
		else
			root = new StringAVLNode(str);
	}


	private StringAVLNode insert(String str, StringAVLNode t) {

		/** To keep a single return point in the function, we declare a placeholder
		 * for the Node pointer we are going to return
		 */
		StringAVLNode returnNode = null;

		/** If t is null, we've hit the base-case as there is no more
		 * comparison or traversal needed, so create the Node we want to
		 * insert and return it back up the call stack
		 */
		if (t == null)
			returnNode = new StringAVLNode(str);

		/** If t isn't null, then we need to decide whether to descend left
		 * or right
		 */
		else {

			/** We can do this by using the String compare functions built into the
			 * Java String class
			 */
			int compareResult = str.compareToIgnoreCase(t.getItem());

			/** The result from compareToIgnoreCase() gives an integer that tells us the
			 * ASCII difference between the two strings. A sub-zero number means the comparing
			 * string is greater than the string compared, so we descend left
			 */
			if (compareResult < 0)
				returnNode = insert(str,t.getLeft());

			/** Of course the opposite result and we descend right */
			else if (compareResult > 0)
				returnNode = insert(str, t.getRight());

			/** In the case that the strings are equal, we stop making any more calls
			 * and send the unaltered Node back up the call stack
			 */
			else
				returnNode = t;
		}

		/** Now that we've defined the Node we are to return, we must calculate the balance
		 *  as we backtrack up the call stack
		 */

		return returnNode;
	}


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








