    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           11/30/2018                                               !
    !                                                                            #
    #          LAB 9 - Implementing List, Stacks Queues and Priority Queues      ! 
    !                                                                            #
    #!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!



________/\\\\\\\\\_______/\\\\\__________/\\\\\\\\\\\__________/\\\\\\\\\__/\\\\\\\\\\\_        
_____/\\\////////______/\\\///\\\______/\\\/////////\\\_____/\\\////////__\/////\\\///__       
___/\\\/_____________/\\\/__\///\\\___\//\\\______\///____/\\\/_______________\/\\\_____      
__/\\\______________/\\\______\//\\\___\////\\\__________/\\\_________________\/\\\_____     
_\/\\\_____________\/\\\_______\/\\\______\////\\\______\/\\\_________________\/\\\_____    
_\//\\\____________\//\\\______/\\\__________\////\\\___\//\\\________________\/\\\_____   
__\///\\\___________\///\\\__/\\\_____/\\\______\//\\\___\///\\\______________\/\\\_____  
____\////\\\\\\\\\____\///\\\\\/_____\///\\\\\\\\\\\/______\////\\\\\\\\\__/\\\\\\\\\\\_ 
_______\/////////_______\/////_________\///////////___________\/////////__\///////////__


 _______________________/\\\________/\\\\\\\\\\_____________/\\\\\____________________
  ____________________/\\\\\______/\\\///////\\\________/\\\\////____________________
 ___________________/\\\/\\\_____\///______/\\\______/\\\///___________________________
  ________________/\\\/\/\\\____________/\\\//_____/\\\\\\\\\\\_______________________
 _______________/\\\/__\/\\\___________\////\\\___/\\\\///////\\\______________________
  ____________/\\\\\\\\\\\\\\\\___________\//\\\_\/\\\______\//\\\____________________
 ____________\///////////\\\//___/\\\______/\\\__\//\\\______/\\\___________________
   ____________________\/\\\____\///\\\\\\\\\/____\///\\\\\\\\\/______________________
  _____________________\///_______\/////////________\/////////______________________

        I am providing the following: 

        public static void main(String[] args){
        // Write your code for 1 a here

        // Write code to test insert() here

        // Write code to populate a tree with 10 random numbers between 1-100. Print the tree to test our all three traversal methods. InOrder, PostOrder and PreOrder.

        }  


        1. insert()
        This is a very basic problem with a little pointer manipulation. Write code that builds the following little 1-2-3 binary search tree...

        2
        / \
        1    3

        Write the code in two different ways...
        a: by calling newNode() three times, and using three pointer variables
        b: by calling insert() three times passing it the root pointer to build up the tree

        2. displayTree()
        Given a binary search tree (aka an "ordered binary tree"), iterate over the nodes to print them out in increasing order. So the tree...

        4
        / \
        2   5
        / \
        1   3

        Produces the output "1 2 3 4 5". This is known as an "inorder" traversal of the tree.
        Hint: For each node, the strategy is: recur left, print the node data, recur right.

        3. displayTreePostOrder()
        Given a binary tree, print out the nodes of the tree according to a bottom-up "postorder" traversal -- both subtrees of a node are printed out completely before the node itself is printed, and each left subtree is printed before the right subtree. So the tree...

        4
        / \
        2   5
        / \
        1   3

        Produces the output "1 3 2 5 4". The description is complex, but the code is simple. This is the sort of  bottom-up traversal that would be used, for example, to evaluate an expression tree where a node is an operation like '+' and its subtrees are, recursively, the two subexpressions for the '+'.

        4. displayTreePreOrder()

        5. size()
        This problem demonstrates simple binary tree traversal. Given a binary tree, count the number of nodes in the tree.

        6. minValue()
        Given a non-empty binary search tree (an ordered binary tree), return the minimum data value found in that tree. Note that it is not necessary to search the entire tree. A maxValue() function is structurally very similar to this function. This can be solved with recursion or with a simple while loop.

        7. hasPathSum()
        We'll define a "root-to-leaf path" to be a sequence of nodes in a tree starting with the root node and proceeding downward to a leaf (a node with no children). We'll say that an empty tree contains no root-to-leaf paths. So for example, the following tree has exactly four root-to-leaf paths:

        5
        /   \
        4    8
        /      /   \
        11  13   4
        /  \            \
        7    2           1

        Root-to-leaf paths:
        path 1: 5 4 11 7
        path 2: 5 4 11 2
        path 3: 5 8 13
        path 4: 5 8 4 1

        For this problem, we will be concerned with the sum of the values of such a path -- for example, the sum of the values on the 5-4-11-7 path is 5 + 4 + 11 + 7 = 27.

        Given a binary tree and a sum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum. Return false if no such path can be found. (Thanks to Owen Astrachan for suggesting this problem.)

        int hasPathSum(struct node* node, int sum) {

        8. printPaths()
        Given a binary tree, print out all of its root-to-leaf paths as defined above. This problem is a little harder than it looks, since the "path so far" needs to be communicated between the recursive calls. Hint: In C, C++, and Java, probably the best solution is to create a recursive helper function printPathsRecur(node, int path[], int pathLen), where the path array communicates the sequence of nodes that led up to the current call. Alternately, the problem may be solved bottom-up, with each node returning its list of paths. This strategy works quite nicely in Lisp, since it can exploit the built in list and mapping primitives. (Thanks to Matthias Felleisen for suggesting this problem.)

        Given a binary tree, print out all of its root-to-leaf paths, one per line.

        9. mirror()
        Change a tree so that the roles of the left and right pointers are swapped at every node.

        So the tree...
        4
        / \
        2   5
        / \
        1   3

        is changed to...
        4
        / \
        5   2
        / \
        3   1

        The solution is short, but very recursive. As it happens, this can be accomplished without changing the root node pointer, so the return-the-new-root construct is not necessary. Alternately, if you do not want to change the tree nodes, you may construct and return a new mirror tree based on the original tree.

        10. doubleTree()
        For each node in a binary search tree, create a new duplicate node, and insert the duplicate as the left child of the original node. The resulting tree should still be a binary search tree.

        So the tree...
        2
        / \
        1   3

        is changed to...
        2
        / \
        2   3
        /     /
        1     3
        /

        1

        As with the previous problem, this can be accomplished without changing the root node pointer.

        11. sameTree()
        Given two binary trees, return true if they are structurally identical -- they are made of nodes with the same values arranged in the same way. (Thanks to Julie Zelenski for suggesting this problem.)

        12. countTrees()
        This is not a binary tree programming problem in the ordinary sense -- it's more of a math/combinatorics recursion problem that happens to use binary trees. (Thanks to Jerry Cain for suggesting this problem.)

        Suppose you are building an N node binary search tree with the values 1..N. How many structurally different  binary search trees are there that store those values? Write a recursive function that, given the number of distinct values, computes the number of structurally unique binary search trees that store those values. For example, countTrees(4) should return 14, since there are 14  structurally unique binary search trees that store 1, 2, 3, and 4. The base case is easy, and the recursion is short but dense. Your code should not construct any actual trees; it's just a counting problem.




*/


public class MyBinaryTree
{

    private Node root;
    BinaryTree(){
        root = null;
    }


    public void insert(int x){
        root = insert(root, x);
    }


    private Node insert(Node node, int x){

        if (node==null){
            return node = new Node(x); 
        }
        if (x == node.data){
            return node;  
        }
        else {
            if (x < node.data){
                node.lchild = insert(node.lchild, x);
            }
            else {
                node.rchild = insert(node.rchild, x);
            }
        }
        return node;
    }


    public static void printTree(Node node){
        if (node == null) 
            return;
        printTree(node.lchild);
        System.out.print(node.data + " ");
        printTree(node.rchild);
    }









}
