import java.io.*;
import java.util.*;
// Pair can be used as a row and column of a square on the board and
// also as increment values to represent a generalized knight's move
class Pair {
    private int row, col;
    // Constructor
    public Pair(int row, int col) {
}
    // Copy constructor
    public Pair(Pair p) {
    }

    // Getters and Setters – a total of 4 methods
    // This is one of the four
    public void setRow(int row) {
    }

    // It's almost always a good idea to override Java's default toString
    public String toString() {
        return "(" + String.valueOf(row) + ", " + String.valueOf(col) + ")";
    }
}
