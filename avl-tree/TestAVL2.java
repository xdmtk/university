public class TestAVL2 {

	public static void main(String[] args) {
		StringAVLTreeXtra t = new StringAVLTreeXtra();
		String str;
		int ct, ran = 87, ransave=0, line = 1, ansct=0, num;
		boolean delete = false;
		char action;
		String s = "oimaoinaoioaoipaoiqaoilaoikaoikdikgikfikeoinaikgikaiqaioaoI20oI99onI30os30";
		String ans[] = {
/*  1 */	"0 0 0 0",
/*  2 */	"(ma)(0)1 1 1 1",
/*  3 */	"(ma(na))(1(0))1 2 1 2",
/*  4 */	"((ma)na(oa))((0)0(0))2 2 3 2",
/*  5 */	"((ma)na(oa(pa)))((0)1(1(0)))2 3 2 2",
/*  6 */	"((ma)na((oa)pa(qa)))((0)1((0)0(0)))3 3 4 2",
/*  7 */	"(((la)ma)na((oa)pa(qa)))(((0)-1)0((0)0(0)))3 3 5 3",
/*  8 */	"(((ka)la(ma))na((oa)pa(qa)))(((0)0(0))0((0)0(0)))4 3 7 3",
/*  9 */	"(((ka)kd((ke)kf))kg((la(ma))na((oa)pa(qa))))(((0)1((0)-1))0((1(0))0((0)0(0))))5 4 8 3",
/* 10 */	"(((ka)kd((ke)kf))kg((la(ma))na((oa)pa(qa))))(((0)1((0)-1))0((1(0))0((0)0(0))))5 4 8 3",
/* 11 */	"((((((aqu)cdf)ejc((hdo)ka(kae)))kd((ke)kf))kg(((la)lhx(lzc))ma(mlh(mrg))))na((((naj)oa(orq))pa(pln(pqr)))qa(((qiq(sgb))tvb(uem))uwp(yfo(zif)))))((((((0)-1)0((0)0(0)))-1((0)-1))-1(((0)0(0))0(1(0))))0((((0)0(0))0(1(0)))1(((1(0))-1(0))-1(1(0)))))13 6 20 5",
/* 12 */	"(((((((aka(apa))aqs(aqu(axb)))cdf(((cff)chj)clw((cug)cxs(ddg))))dkr((dpx)dsx((dvd)dyp(edc))))ejc((((epa)esn((fgq)fwu))gbg((giz(gly))gma(gws)))hdo((((hkx)hqv)iry((ive)ixt(ixy)))jgz((joh)jyc))))ka((((kae(kao))kd((ke)kf))kg((((kjj)kpc)la(lds))lev(lhx(lne))))loj(((lsc)lzc)ma(((mfc)mlh)mrg(mrj(mwq))))))na((((((naj)net(nmn))nnq((nps)nvq))oa(((ocx)ogx((onb)orq(otq)))pa((pln)pph(pqr(pzv)))))qa((((qei)qez(qiq))qpx((qrs)qsm((qyc)rfn)))rku(((rmq)rpr((rxu)seh))sgb(((shl)shv(ssz))tdl(tje(tqf))))))tvb((((ucx)uel((uem)uio(uje)))uwp((((vco)vik(vlx))vod((vzc)wdk(wkp)))wmh((wua)xic)))xjt((((xmp)xvh(xvz))yan(ybh))yfo(((yil)ynt(ysk))zfc(zif(zqc)))))))(((((((1(0))0(1(0)))0(((0)-1)0((0)0(0))))-1((0)1((0)0(0))))0((((0)1((0)-1))0((1(0))-1(0)))0((((0)-1)0((0)0(0)))-1((0)-1))))0((((1(0))0((0)-1))1((((0)-1)-1(0))-1(1(0))))-1(((0)-1)1(((0)-1)0(1(0))))))0((((((0)0(0))0((0)-1))1(((0)1((0)0(0)))0((0)1(1(0)))))0((((0)0(0))1((0)1((0)-1)))0(((0)1((0)-1))0(((0)0(0))0(1(0))))))0((((0)1((0)0(0)))1((((0)0(0))0((0)0(0)))-1((0)-1)))-1((((0)0(0))-1(0))0(((0)0(0))0(1(0)))))))55 8 88 6",
/* 13 */	"(((((blp)bpj(bxa))cer((cfw)cst(fcl)))gxc(((hcr)icj)iei((iod)khx(lov))))mld((((nfn)njv(nrm))our((pih)pmt))sjv(((sjw)vkg(wcs))xeh((yif(yzm))znv(zue)))))(((((0)0(0))0((0)0(0)))0(((0)-1)0((0)0(0))))1((((0)0(0))0((0)-1))1(((0)0(0))1((1(0))-1(0)))))14 6 23 5",
/* sc */	"hcr nfn yif zue bpj fcl lov nrm mld iod gxc sjw cfw bxa yzm xeh pih NULL sjv vkg our njv iei znv cer khx wcs icj pmt cst NULL NULL NULL NULL NULL ",
		};

		do {
			action = s.charAt(0);
			if (action == 'i') {   // insert
				str = s.substring(1,3);
				s = s.substring(3, s.length());
				t.insert(str);
			} else if (action == 'j') {   // insert
				str = s.substring(1,4);
				s = s.substring(4, s.length());
				t.insert(str);
			} else if (action == 'n') {  // new tree -- wipe out the tree and start over
				s = s.substring(1, s.length());
				t = new StringAVLTreeXtra();
			} else if (action == 'I') {
				ransave = ran;
	            num = (s.charAt(1) - '0') * 10 + s.charAt(2) - '0';
	            s = s.substring(3, s.length());
	            for (ct = 1; ct <= num; ct++) {
	               ran = (ran * 101 + 103) % 1000003;
	               str= String.valueOf((char) (ran%26+'a'));
	               ran = (ran * 101 + 103) % 1000003;
	               str+= String.valueOf((char) (ran%26+'a'));
	               ran = (ran * 101 + 103) % 1000003;
	               str+= String.valueOf((char) (ran%26+'a'));
	               t.insert(str);
	            }
			} else if (action == 's') {
				String res = new String(), succ;
				ran = ransave;
	            num = (s.charAt(1) - '0') * 10 + s.charAt(2) - '0';
	            s = s.substring(3, s.length());
	            for (ct = 1; ct <= num; ct++) {
	               ran = (ran * 101 + 103) % 1000003;
	               str= String.valueOf((char) (ran%26+'a'));
	               ran = (ran * 101 + 103) % 1000003;
	               str+= String.valueOf((char) (ran%26+'a'));
	               ran = (ran * 101 + 103) % 1000003;
	               str+= String.valueOf((char) (ran%26+'a'));
	               succ = t.successor(str);
	               if (succ != null)
	            	   res += succ + " ";
	               else
	            	   res += "NULL ";
	            }
			   succ = t.successor("aaa");
			   if (succ != null)
				   res += succ + " ";
			   else
				   res += "NULL ";
			   succ = t.successor("ccc");
			   if (succ != null)
				   res += succ + " ";
			   else
				   res += "NULL ";
			   succ = t.successor("nnn");
			   if (succ != null)
				   res += succ + " ";
			   else
				   res += "NULL ";
			   succ = t.successor("vvv");
			   if (succ != null)
				   res += succ + " ";
			   else
				   res += "NULL ";
			   succ = t.successor("zzz");
			   if (succ != null)
				   res += succ + " ";
			   else
				   res += "NULL ";
				if (res.compareTo(ans[ansct]) == 0)
					System.out.println("     Answers match in successor.   ");
				else {
					System.out.println("   *** NO MATCH IN SUCCESSOR ***   ");
					System.out.println(res);
				}
				//t.display(); System.out.println();
				ansct++;
	        } else {  // no other choice, then compare
				s = s.substring(1, s.length());
				System.out.print(line++ + ". ");
				if (t.toString2().compareTo(ans[ansct]) == 0) {
					System.out.print(" Answers match.   ");
					if ( line % 4 == 1)
						System.out.println();
				}
				else {
					System.out.println("   *** NO MATCH ***   ");
					System.out.println(t.toString2());
				}
//				System.out.println(); t.display(); System.out.println();
//				System.out.println();
//				System.out.println(t.toString2());
				
				ansct++;
			}
		} while (s.length() != 0);
		System.out.println("Programmed by: " + StringAVLTree.myName());
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
			if (t.getItem().length() == 3)
				System.out.print(" ");
			if (t.getBalance() == -1)
				System.out.print(t.getBalance());
			else
				System.out.print(" " + t.getBalance());
			bal_out(t.getRight());
			System.out.print(")");
		}
	}
	
	public String paren_out1(StringAVLNode t) {
		String s;
		if (t == null) {
			s = new String();
		} else {
			s="(" + paren_out1(t.getLeft())+t.getItem()+paren_out1(t.getRight())+")";
		}
		return s;
	}

	public String bal_out1(StringAVLNode t) {
		String s;
		if (t == null) {
			s = new String();
		} else {
			s="("+bal_out1(t.getLeft())+t.getBalance()+bal_out1(t.getRight())+")";
		}
		return s;
	}
	
	public String toString2() {
			String s = new String();
			s = paren_out1(getRoot())+bal_out1(getRoot())+String.valueOf(this.leafCt())+" "+
			    String.valueOf(this.height())+" "+String.valueOf(this.balanced())+" "+
				String.valueOf(this.nadir());
			return s;
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
			if (t.getLeft() == null && t.getRight() == null) {
				leafCount = 1;
			}
			else
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
