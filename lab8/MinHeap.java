    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           11/16/2018                                               !
    !                                                                            #
    #          LAB 8 - Pattern Matching                                          !
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


    Exercise 22.3 (Pattern Matching)
        
        Write a program that prompts the user to enter two strings
        and tests whether the second string is a substring of the first string. Suppose
        the neighboring characters in the string are distinct. (Don’t use the indexOf
        method in the String class.) Analyze the time complexity of your algorithm.
        Your algorithm needs to be at least O(n) time. Here is a sample run of the
        program:


        Sample output:
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "test"
            String 1: this is a test of the string matching algorithm
            String 2: test
            Matched at index: 10
            Total Execution Time: 114567
            String 2 is a substring of String 1
            
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "testf"
            String 1: this is a test of the string matching algorithm
            String 2: testf
            Total Execution Time: 6830
            No match
            
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "alg"
            String 1: this is a test of the string matching algorithm
            String 2: alg
            Matched at index: 38
            Total Execution Time: 70182
            String 2 is a substring of String 1
            
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "algbbbbb"
            String 1: this is a test of the string matching algorithm
            String 2: algbbbbb
            Total Execution Time: 10129
            No match
            
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "t"
            String 1: this is a test of the string matching algorithm
            String 2: t
            Matched at index: 1
            Total Execution Time: 63160
            String 2 is a substring of String 1
            
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "m"
            String 1: this is a test of the string matching algorithm
            String 2: m
            Matched at index: 29
            Total Execution Time: 57143
            String 2 is a substring of String 1
            
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "z"
            String 1: this is a test of the string matching algorithm
            String 2: z
            Total Execution Time: 7764
            No match
            



*/

 1 public class Heap<E extends Comparable<E>> {
 2 private java.util.ArrayList<E> list = new java.util.ArrayList<>();
 3
 4 /** Create a default heap */
 5 public Heap() {
 6 }
 7
 8 /** Create a heap from an array of objects */
 9 public Heap(E[] objects) {
10 for (int i = 0; i < objects.length; i++)
11 add(objects[i]);
12 }
13
14 /** Add a new object into the heap */
15 public void add(E newObject) {
16 list.add(newObject); // Append to the heap
17 int currentIndex = list.size() - 1; // The index of the last node
18
19 while (currentIndex > 0) {
20 int parentIndex = (currentIndex - 1) / 2;
21 // Swap if the current object is greater than its parent
22 if (list.get(currentIndex).compareTo(
23 list.get(parentIndex)) > 0) {
24 E temp = list.get(currentIndex);
25 list.set(currentIndex, list.get(parentIndex));
26 list.set(parentIndex, temp);
27 }
28 else
29 break; // The tree is a heap now
30
31 currentIndex = parentIndex;
32 }
33 }
34
35 /** Remove the root from the heap */
36 public E remove() {
37 if (list.size() == 0) return null;
38
39 E removedObject = list.get(0);
40 list.set(0, list.get(list.size() - 1));
41 list.remove(list.size() - 1);
42
43 int currentIndex = 0;
44 while (currentIndex < list.size()) {
45 int leftChildIndex = 2 * currentIndex + 1;
46 int rightChildIndex = 2 * currentIndex + 2;
47
48 // Find the maximum between two children
49 if (leftChildIndex >= list.size()) break; // The tree is a heap
50 int maxIndex = leftChildIndex;
51 if (rightChildIndex < list.size()) {
52 if (list.get(maxIndex).compareTo(
53 list.get(rightChildIndex)) < 0) {
54 maxIndex = rightChildIndex;
55 }
56 }
57
58 // Swap if the current node is less than the maximum
59 if (list.get(currentIndex).compareTo(
60 list.get(maxIndex)) < 0) {
61 E temp = list.get(maxIndex);
62 list.set(maxIndex, list.get(currentIndex));
63 list.set(currentIndex, temp);
64 currentIndex = maxIndex;
65 }
66 else
67 break; // The tree is a heap
68 }
69
70 return removedObject;
71 }
72
73 /** Get the number of nodes in the tree */
74 public int getSize() {
75 return list.size();
76 }
77 }