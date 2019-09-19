import com.sun.org.apache.xpath.internal.operations.Bool;

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
	boolean debugMode = false;


	// just one constructor
	public StringAVLTree() {
        root = null;
	}

	private static StringAVLNode rotateRight(StringAVLNode t) {
        StringAVLNode returnNode = t.getLeft();

        t.setLeft(returnNode.getRight());
        returnNode.setRight(t);
        t.setBalance(findBalance(t));
        returnNode.setBalance(findBalance(returnNode));

        return returnNode;
	}

	private static StringAVLNode rotateLeft(StringAVLNode t) {
        StringAVLNode returnNode = t.getRight();

        t.setRight(returnNode.getLeft());
        returnNode.setLeft(t);
        t.setBalance(findBalance(t));
        returnNode.setBalance(findBalance(returnNode));

        return returnNode;
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
	private static int height(StringAVLNode t) {
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
	private static int findBalance(StringAVLNode t) {
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

		/** Update the root for every insert */
		root = insert(str, root);

		if (debugMode)
			BTreePrinter.printStringAVLNode(root);
	}


	private StringAVLNode insert(String str, StringAVLNode t) {

		/** To keep a single return point in the function, we setup a temporary
		 * pointer to `t`, and modify it as we step through the function.
		 */
		StringAVLNode returnNode = t;

		/** If the given node is null, we've hit the base-case as there is no more
		 * comparison or traversal needed, so create the Node we want to
		 * insert and return it back up the call stack
		 */
		if (returnNode == null)
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

				/** We descend into the left while also calling insert as a parameter to
				 * setLeft(), this way, when we hit the base case, the new node will be generated
				 * at the very bottom of the tree
				 */
				returnNode.setLeft(insert(str, returnNode.getLeft()));
			}

			/** Of course the opposite result and we descend right */
			else if (compareResult > 0) {
				returnNode.setRight(insert(str, returnNode.getRight()));
			}


			/** As we are backtracking up the call stack, we get/set the balance of each node we pass,
			 *  and use it to determine whether we need to rotate any of the subtrees
			 */
			t.setBalance(findBalance(t));
			int balance = t.getBalance();

			/** If we run into an unbalanced situation for the node, we call balanceTrees()
			 * to determine what kind of rotation is required for the given imbalance
			 */
			if (balance > 1 || balance < -1) {
				returnNode = balanceTrees(balance, t);
			}

		}
		return returnNode;
	}



	/**
	 * This function handles the left/right rotates, and double left/double right
	 * rotates (LR, RL)
	 *
	 * @param balance - The balance value of the given node t
	 * @param t - The current node
	 * @return - The balanced root node
	 */
	private StringAVLNode balanceTrees(int balance, StringAVLNode t) {

		StringAVLNode returnNode = t;
		if (debugMode) {
			BTreePrinter.printStringAVLNode(root);
			System.out.println("Tree went out of balance at level " + (height(root) - height(t)));
		}

		if (balance > 1) {

			/** For right heavy nodes, we can determine if we need a double left rotation
			 *  if the right sub-tree is left heavy
			 */
			if (t.getRight() != null && t.getRight().getBalance() < -1) {

				if (debugMode)
					System.out.println("Executing double left rotation");

                t.setRight(rotateRight(t.getRight()));
                returnNode = rotateLeft(t);

			}
			/** If not just do a left rotation */
			else {
				if (debugMode)
					System.out.println("Executing left rotation");
				
				returnNode = rotateLeft(t);
			}
		}
		else if (balance < -1) {

			/** Likewise for left heavy nodes, we can determine if we need a double right
			 * rotation if the left sub-tree is right heavy
			 */
			if (t.getLeft() != null && t.getLeft().getBalance() > 1) {
                t.setLeft(rotateLeft(t.getLeft()));
                returnNode = rotateRight(t);

                if (debugMode)
                	System.out.println("Executing double right rotation");

			}
			/** If not just do a left rotation */
			else {

				if (debugMode)
					System.out.println("Executing right rotation");

                returnNode = rotateRight(t);
			}
		}

		/** returnNode should now have the root of the tree that needed balancing
		 *  so we return it to the caller ( the insert method ) so the 'whole' subtree is
		 *  updated
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








