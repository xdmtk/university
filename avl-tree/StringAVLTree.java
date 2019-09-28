/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prog2;

/**
 *
 * @author tarna_000
 */
public class StringAVLTree {
    StringAVLNode root;
 // just one constructor
 public StringAVLTree() {
     root = null;
 }

 // Rotate the node to the right, done if the left subtree is unbalanced
 private static StringAVLNode rotateRight(StringAVLNode t) {
     
     //rotate by placeing nodes in temporary holders to make moves without losing 
     //pointers locations
     StringAVLNode temp = t.getLeft();
     t.setLeft(temp.getRight());
     temp.setRight(t);
     
     return temp;
 }

 // Rotate the node to the left. Can be done if the right subtree is unbalanced
 private static StringAVLNode rotateLeft(StringAVLNode t) {
     
     StringAVLNode temp = t.getRight();     
     t.setRight(temp.getLeft());
     temp.setLeft(t);
     
     return temp;
 }
//// For these next four, be sure not to use any global variables
// and no extra “counting” parameters in the recursive methods, e.g.,
// the recursive height method should just have one parameter, the
// StringAVLNode
 // Return the height of the tree – not to be used anywhere in insert or delete
 public int height(StringAVLNode n) {
     int h = 0, bal = 0, leftH = 0, rightH = 0;
     
     bal = n.getBalance();
     
     if (n == null){
         h = 0;
     } else if (n.getBalance() > 0){
         //traverse and sum up height of left subtree
         leftH= height(n.getRight()) + 1;        
     } else if (n.getBalance() < 0){
         //traverse and sum up height of left subtree
         rightH = height(n.getLeft())+ 1;
     }     
     if (leftH > rightH){
         h = leftH + 1;
     } else{
         h = rightH + 1;
     }
     return h;
 }
 
 
// } else if (n.getBalance() > 0){
//         leftH = height(n.getLeft());
//         rightH = height(n.getRight());        
//     }
//     if (leftH > rightH){
//         h = leftH + 1;
//     } else{
//         h = rightH + 1;
//     }
 // Return the number of leaves in the tree
 public int leafCt() {
        return leafCt(root);
 }
 private int leafCt(StringAVLNode t){
     int sum = 0;
    if (t == null){ 
            //do nothing and keep count at 0 
    } else if (t.getLeft() == null && t.getRight() == null){
        //has no children must be leaf
            sum = 1; 
    } else {
        //traverse and add leaves of right and left sides of tree
            sum = leafCt(t.getLeft()) + leafCt(t.getRight()); 
    }
    return sum;
 }
//  Return the number of perfectly balanced AVL nodes
 public int balanced() {
      return balanced(root);
 }
 private int balanced(StringAVLNode t){
     int total = 0;
     if (t == null){ 
            //do nothing and keep count at 0
    } else if (t.getLeft() == null && t.getRight() == null){
        //no children therefore balanced   
        total = 1; 
    } else if(t.getBalance() == 0){
        //balanced node, add to sum and check the status of its children
        total = balanced(t.getLeft()) + balanced(t.getRight()) + 1;
     } else {
        //not balanced but has children, check if they are balanced
         total = balanced(t.getLeft()) + balanced(t.getRight());
     }
     return total;
 }
 // Return the inorder successor, i.e., the next larger value in the tree
 // or null if there is none or str is not in the tree
 public String successor(String str) {
     str = successor(str,this.root);     
     return str;
 }
 
 private String successor(String str, StringAVLNode t){
     if (root == null){
          str = null;
     }else{     
     while (compareStrings(str,t) == 0 || compareStrings(str,t) == -1){
         t = t.getRight();
     }
     str = t.getItem();
     }
     return str;
 }
 
 public void insert(String str) {
     this.root = insert(str, this.root);
 }
private StringAVLNode insert(String str, StringAVLNode t) {
    //if tree has not be created then newe tree is created
    if (t == null) {
        t = new StringAVLNode(str);
    } //comparisons to recursively traverse the tree
    else if (compareStrings(str,t) == 1) {
        //check to make sure you dont over add for the root
        if (t.getLeft() == null && t.getRight() == null){
            t.setRight(insert(str, t.getRight()));
            t.setBalance(t.getBalance() + 1);               
        } else {
        t.setRight(insert(str, t.getRight()));
        t.setBalance(t.getBalance() + 1);
        }
    } else if (compareStrings(str,t) == -1){
        if (t.getLeft() == null && t.getRight() == null){
            t.setLeft(insert(str, t.getLeft()));
            t.setBalance(t.getBalance() -1);
        } else {
            t.setLeft(insert(str, t.getLeft()));
            t.setBalance(t.getBalance() -1);
        }
    } 
       //check balance to determine what rotations are needed 
       if(t.getBalance() >= 2){

           if(t.getRight().getBalance() > 0){
               t.setBalance(t.getBalance()-1);
               t = rotateLeft(t);            
           } else if (t.getRight().getBalance() < 0){
             t = rotateRight(t);
             t = rotateLeft(t);  
             t.setBalance(t.getBalance()-1);
           }
        } else if (t.getBalance() <= -2){

           if( t.getBalance() < 0){               
           t = rotateRight(t);
           t.setBalance(t.getBalance()+1);
           } else if (t.getLeft().getBalance() > 0){
               t = rotateLeft(t); 
               t = rotateRight(t);
               t.setBalance(t.getBalance()+1);
       }    
    }
    return t;
}
 //method to check the two strings by summing their ascii values and comparing the sum   
private int compareStrings(String str, StringAVLNode t){
    //put both string to lowercase so comparison is case insensitive
    str = str.toLowerCase();
    String temp = t.getItem().toLowerCase();
    int newStr = 0, currentNode = 0, c1, c2;
    int result = 0;
    
    //loop to convert each character to its ascii int value then compile them into one sum
    for (int i = 0; i <str.length(); i++){
        c1 = (int) str.toLowerCase().charAt(i);
        newStr += c1;
    }
    //loop to compile sum of other string
    for (int i = 0; i <temp.length(); i++){
        c2 = (int) temp.toLowerCase().charAt(i);
        currentNode += c2;
    }
    //comparison sets the value of result to either -1 or 1 which in turn lets 
    //the insert method have direction to recursively traverse the tree
    if (newStr > currentNode){
        result = 1;
    } else if (newStr < currentNode){
        result = -1;
    }
    return result;
} 
     //returns my name
 public static String myName() {
 return "Arnaldo Torres";
 }
}