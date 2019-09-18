public class TestAVL1 {

	public static void main(String[] args) {

		/*
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
	 */
		StringAVLTreeXtra t = new StringAVLTreeXtra();
		t.insert("a");
		t.insert("d");
		t.insert("e");
		t.insert("z");
		t.insert("t");
		t.insert("c");
		t.display();
		System.out.println(t.balanced());
		System.out.println(t.leafCt());
		System.out.println(t.height());
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
		int height = 0;
		if (t != null)
			height = Math.max(height(t.getLeft()), height(t.getRight()))+ 1;
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

	/** Similar to the leafCount() method, except the integer we are returning
	 * is only incremented when the balance of the given node is 0
	 * @param t
	 * @return
	 */
	private int balanced(StringAVLNode t) {
		int balanceCount = 0;
		if (t != null) {
			if (t.getLeft() != null) {
				 balanced(t.getLeft());
			}
			if (t.getRight() != null) {
				balanced(t.getRight());
			}
			balanceCount += t.getBalance() == 0 ? 1 : 0;
		}
		return balanceCount;
	}


	/**
	 * Recursively call the height function to calculate
	 * the balance for the given Node
	 */
	private int findBalance(StringAVLNode t) {
		int nodeBalance;

		/** The balance of the node is simply the height of the right sub-tree
		 *  subtracted from the height of the left sub-tree
		 */
		nodeBalance = height(t.getRight()) - height(t.getLeft());
		return nodeBalance;
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

		StringAVLNode newRoot = root;
		/**
		 * If our root node exists, then we need to call our internal
		 * insertion method to decide whether to insert on the left or
		 * the right
		 */
		if (newRoot != null)
			newRoot = insert(str, newRoot);
		/**
		 * If our root node does not exist, our tree is empty, and we can
		 * simply establish the root as a new Node
		 */
		else
			root = new StringAVLNode(str);


		BTreePrinter.printStringAVLNode(root);
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
			if (compareResult < 0) {
				returnNode = insert(str, t.getLeft());

				/** If the left of the current node is null, then we can go ahead
				 * and set this newly created Node, otherwise we still need to descend
				 * further down the tree
				 */
				if (t.getLeft() == null)
					t.setLeft(returnNode);
			}

			/** Of course the opposite result and we descend right */
			else if (compareResult > 0) {
				returnNode = insert(str, t.getRight());

				/** Same logic applies here, if the right child of the given node is
				 * null, we can make the insert, otherwise continue descending
				 */
				if (t.getRight() == null)
					t.setRight(returnNode);
			}

			/** In the case that the strings are equal, we stop making any more calls
			 * and send the unaltered Node back up the call stack
			 */
			else
				returnNode = t;



			/** As we are backtracking up the call stack, we get/set the balance of each node we pass,
			 *  and use it to determine whether we need to rotate any of the subtrees
			 */
			t.setBalance(findBalance(t));
			int balance = t.getBalance();

			// TODO: FIGURE OUT ROTATIONS !!!
			/** For balanced nodes we can skip all rotation logic
			if (balance != 0) {
				balanceTrees(balance, t);
			}
			 */

		}
		return returnNode;
	}

	private StringAVLNode balanceTrees(int balance, StringAVLNode t) {

		StringAVLNode returnNode = t;
		/** For right heavy nodes, we can determine if we need a double left rotation
		 * if the right sub-tree is left heavy
		 */
		if (balance > 1) {
			if (t.getRight() != null && t.getRight().getBalance() < -1) {
				// Do double left rotate
			} else {
				// Do single left rotate
			}
		}
		/** Likewise for left heavy nodes, we can determine if we need a double right
		 * rotation if the left sub-tree is right heavy
		 */
		else if (balance < -1) {
			if (t.getLeft() != null && t.getLeft().getBalance() > 1) {
				// Do double right rotate
			} else {
				// Do single right rotate
			}
		}
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








