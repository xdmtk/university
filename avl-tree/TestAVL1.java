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

	}

	public int getBalance () {
		return 0;
	}

	public void setBalance ( int bal){

	}

	public String getItem () {
		return new String("Hi");
	// no set item
	}

	public StringAVLNode getLeft () {
		return new StringAVLNode("Foo");
	}

	public void setLeft (StringAVLNode pt){

	}

	public StringAVLNode getRight () {

		return new StringAVLNode("Foo");
	}

	public void setRight (StringAVLNode pt){

	}
}
class StringAVLTree {


	// should really be private but I need access
	// for my test program to work
	StringAVLNode root;
	// just one constructor
	public StringAVLTree() {

	}

	// Rotate the node to the right
	private static StringAVLNode rotateRight(StringAVLNode t) {
		return new StringAVLNode("Foo");
	}

	// Rotate the node to the left
	private static StringAVLNode rotateLeft(StringAVLNode t) {
		return new StringAVLNode("Foo");
	}
	// For these next four, be sure not to use any global variables
	// and no extra “counting” parameters in the recursive methods, e.g.,
	// the recursive height method should just have one parameter, the
	// StringAVLNode
	// Return the height of the tree – not to be used anywhere in insert or delete
	public int height() {
		return 0;
	}
	// Return the number of leaves in the tree
	public int leafCt() {
		return 0;
	}
	// Return the number of perfectly balanced AVL nodes
	public int balanced() {
		return 0;
	}
	// Return the inorder successor, i.e., the next larger value in the tree
	// or null if there is none or str is not in the tree
	public String successor(String str) {
		return new String("foo");
	}
	public void insert(String str) {

	}
	private StringAVLNode insert(String str, StringAVLNode t) {
		return new StringAVLNode("Foo");
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
