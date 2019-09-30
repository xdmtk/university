import java.lang.reflect.Array;
import java.util.ArrayList;




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
		StringAVLNode newRoot = t.getLeft();

		t.setLeft(newRoot.getRight());
		newRoot.setRight(t);

		return newRoot;
	}

	private static StringAVLNode rotateLeft(StringAVLNode t) {
		StringAVLNode newRoot = t.getRight();

		t.setRight(newRoot.getLeft());
		newRoot.setLeft(t);

		return newRoot;
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

	/** Essentially the inverse of height, descending the tree
	 * and taking the minimum heights of the two, with the exceptions where
	 * there is only one path to traverse.
	 */
	private int nadir(StringAVLNode t) {

		int nadir = 0;
		boolean isNull = t == null;
		boolean onlyRight = !isNull && t.getLeft() == null;
		boolean onlyLeft = !isNull && t.getRight() == null;
		boolean isLeaf = !isNull && onlyLeft && onlyRight;

		// No more traversal
		if (isLeaf)
			nadir = 1;
		// Only right node? No choice but to go right
		else if (onlyRight)
			nadir = nadir(t.getRight()) + 1;
		// Only left node? No choice but to go left
		else if (onlyLeft)
			nadir = nadir(t.getLeft()) + 1;
		// Choice of both nodes? Descend into both and take the minimum value
		else if (!isNull)
			nadir = Math.min(nadir(t.getLeft()), nadir(t.getRight())) + 1;

		return nadir;
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
			// Left and right children null? Arrived at a leaf, no more descending
			if (t.getLeft() == null && t.getRight() == null) {
				leafCount = 1;
			}
			else
				// Otherwise continue to descend until the above case is met
				leafCount = leafCt(t.getLeft()) + leafCt(t.getRight());
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
			// For every balanced node during the traversal, add one to the recursive sum
			return balanced(t.getLeft()) + balanced(t.getRight()) + (t.getBalance() == 0 ? 1 : 0);
		}
		return 0;
	}



	// Driver method
	public void insert(String str) {
		root = insert(str, root);
	}

	private StringAVLNode insert(String str, StringAVLNode t) {

		// Arbitrary value for null node balance checks
		final int nullNodeVal = 666;

		// Base case - Hit the last node so just insert the node
		if (t == null)
			t = new StringAVLNode(str);
		else {

			// Get original balances of left/right children before insert, put arbitrary value if node is null
			int oldBalRight = t.getRight() != null ? t.getRight().getBalance() : nullNodeVal;
			int oldBalLeft = t.getLeft() != null ? t.getLeft().getBalance() : nullNodeVal;


			// Make the boolean values easier to read
			boolean leftWasNull = (oldBalLeft == nullNodeVal);
			boolean rightWasNull = (oldBalRight == nullNodeVal);
			boolean twoNullChildren = (leftWasNull && rightWasNull);


			// Perform string comparisons to determine left/right insert
			int compareResult = str.compareToIgnoreCase(t.getItem());
			boolean insertLeft = compareResult < 0;
			boolean insertRight = compareResult > 0;


			// Make left/right insert
			if (insertLeft)
				t.setLeft(insert(str, t.getLeft()));
			else if (insertRight)
				t.setRight(insert(str, t.getRight()));


			/** Determine whether the current sub-tree grew left or right after the insert
			 *
			 *  Example cases:
			 *  Two originally null children, 1 not null after insert -> Tree grew
			 *
			 *  One originally null child and one 0 balance child,
			 *  	0 balance child become +- 1 after insert -> Tree grew
			 *
			 *  One originally null child, now 0 null children after insert -> Technically the tree
			 *  	didnt grow, but the balance gets incremented in the direction of the insert
			 *  	so it will typically 0 out the balance anyways
			 */
			boolean treeGrewLeft = (twoNullChildren && t.getLeft() != null) ||
					(!leftWasNull && oldBalLeft == 0 && t.getLeft().getBalance() != 0) ||
					(leftWasNull && !rightWasNull && t.getLeft() != null);
			boolean treeGrewRight = (twoNullChildren && t.getRight() != null) ||
					(!rightWasNull && oldBalRight == 0 && t.getRight().getBalance() != 0) ||
					(rightWasNull && !leftWasNull && t.getRight() != null);


			// Increment the balance of the node if one of the sub-trees has grown
			if (treeGrewLeft)
				t.setBalance(t.getBalance()-1);
			else if (treeGrewRight)
				t.setBalance(t.getBalance()+1);


			// Check whether trees are still in balance after insertion
			int currentBalance = t.getBalance();
			boolean rightImbalance = currentBalance > 1;
			boolean leftImbalance = currentBalance < -1;


			// If the trees are out of balance, call balanceTrees() to handle rotations
			if (rightImbalance || leftImbalance)
				t = balanceTrees(currentBalance, t);

		}
		return t;
	}



	// Rotation Handler
	private StringAVLNode balanceTrees(int balance, StringAVLNode t) {

		/** Easily readable boolean logic for rotation cases
		 *
		 * Example cases:
		 * Double Left -> Right heavy with a left heavy child node
		 * Double Right -> Left heavy with a right heavy child node
		 * Single Left/Right -> Default rotation when double rotate isn't required
 		 */
		boolean rightHeavy = balance > 1; boolean leftHeavy = balance < -1;
		boolean requiresDoubleLeft = t.getRight() != null && t.getRight().getBalance() <= -1;
		boolean requiresDoubleRight = t.getLeft() != null && t.getLeft().getBalance() >= 1;
		boolean requiresSingleRight = !requiresDoubleRight; boolean requiresSingleLeft = !requiresDoubleLeft;

		if (rightHeavy) {

			if (requiresDoubleLeft) {

				// Get the balance of the right child's left heavy node to determine
				// the correct balance update case
				int rlBalance = t.getRight().getLeft().getBalance();
				boolean rlRightHeavy = rlBalance > 0;
				boolean rlEqual = rlBalance == 0;
				boolean rlLeftHeavy = rlBalance < 0;


				// Execute double rotation
				t.setRight(rotateRight(t.getRight()));
				t = rotateLeft(t);


				// Node that has a right heavy side will rebalance to
				// -1, and the right side should be balanced
				if (rlRightHeavy) {
					t.getLeft().setBalance(-1);
					t.getRight().setBalance(0);
				}
				else {
					// A 0 balance node means the double rotation should
					// 0 out all of the subtree balances
					if (rlEqual) {
						t.getLeft().setBalance(0);
						t.getRight().setBalance(0);
					}
					else if (rlLeftHeavy) {
						t.getLeft().setBalance(0);
						t.getRight().setBalance(1);
					}
				}
				t.setBalance(0);

			}
			else if (requiresSingleLeft) {

				t = rotateLeft(t);

				// Single left rotation zero's the balance of the new left child
				// and the node itself
				t.getLeft().setBalance(0);
				t.setBalance(0);
			}
		}

		/** Do double right rotation by left rotating the left child subtree, then
		 * rotate right
		 */
		else if (leftHeavy) {
			if (requiresDoubleRight) {

				// Everything here is simply the inverse of the Double-Left rotation
				// no comments are necessary

				int lrBalance = t.getLeft().getRight().getBalance();
				boolean lrRightHeavy = lrBalance > 0;
				boolean lrEqual = lrBalance == 0;
				boolean lrLeftHeavy = lrBalance < 0;

				t.setLeft(rotateLeft(t.getLeft()));
				t = rotateRight(t);


				if (lrRightHeavy) {
					t.getLeft().setBalance(-1);
					t.getRight().setBalance(0);
				}
				else {
					if (lrEqual) {
						t.getLeft().setBalance(0);
						t.getRight().setBalance(0);
					}
					else if (lrLeftHeavy) {
						t.getLeft().setBalance(0);
						t.getRight().setBalance(1);
					}
				}
				t.setBalance(0);
			}
			else if (requiresSingleRight) {

				t = rotateRight(t);

				t.getRight().setBalance(0);
				t.setBalance(0);
			}
		}
		return t;
	}


	/** O(logn) when node has a right child
	 *  O(n) when node has no right children ( need to walk the tree )
	 */
	public String successor(String str) {

		String successorString = null;

		// Find the node in the tree
		StringAVLNode node = find(str, root);

		// If the node has a right child, then descend right and then left as far as possible
		// on that right child
		if (node != null && node.getRight() != null) {
			node = node.getRight();
			while (node.getLeft() != null)
				node = node.getLeft();
			successorString = node.getItem();
		}
		// If the node _doesn't_ have a right child, need to scan the whole tree
		else if (node != null) {
			ArrayList<String> itemList = new ArrayList<>();
			String minString = null;
			// Supply ArrayList with values
			successor(root, str, itemList);
			/** If there are values in the list ( possible successors ) then sort the
			 *  values and exit the loop with the next greatest value ( successor ) as
			 *  the value of minString
			 */
			if (itemList.size() > 0) {
				minString = itemList.get(0);
				for (String item : itemList) {
					// If the potential successor is at least as close or closer to the
					// given string value, set it to minString
					if (item.compareToIgnoreCase(minString) <= 0)
						minString = item;
				}
				successorString = minString;
			}

		}
		return successorString;
	}


	// Recursive method to collect all potential successors in the tree
	private static void successor(StringAVLNode t, String str, ArrayList<String> s) {
		if (t != null) {
			if (str.compareToIgnoreCase(t.getItem()) < 0)
				s.add(t.getItem());
			successor(t.getLeft(), str, s);
			successor(t.getRight(), str, s);
		}
	}

	private static StringAVLNode find(String str, StringAVLNode t) {
		StringAVLNode ret;
		// Hit a null node? Not in the tree
		if (t == null)
			ret = null;
		// Node value equal string? Found in the tree
		else if (t.getItem().equals(str))
			ret = t;
		// String to find less than given node? Descend left, otherwise descend right
		else
			ret = find(str, str.compareToIgnoreCase(t.getItem()) < 0 ? t.getLeft() : t.getRight());
		return ret;
	}










    // Unsure whether to leave this in the code or not.
	public void delete(String d) {

	}
    // Unsure whether to leave this in the code or not.
	private StringAVLNode delete(StringAVLNode t, String d) {
		return new StringAVLNode("Foo");
	}



	// who are you? Put your name here!
	public static String myName() {
		return "Nicholas Martinez";
	}
}
