import java.io.*;
import java.util.*;
// Pair can be used as a row and column of a square on the board and
// also as increment values to represent a generalized knight's move
class Pair {
    private int row, col;
    // Constructor

    public Pair(int row, int col) {
        this.row = row;
        this.col = col;
    }
    // Copy constructor
    public Pair(Pair p) {
        this.row = p.row;
        this.col = p.col;
    }

    // Getters and Setters – a total of 4 methods
    // This is one of the four
    public void setRow(int row) {
        this.row = row;
    }

    public void setColumn(int col) {
        this.col = col;
    }

    public int getRow() {
        return this.row;
    }


    public int getColumn() {
        return this.col;
    }

    public Pair add(Pair addition) {
        return new Pair(this.row + addition.getRow(), this.col = addition.getColumn());
    }

    // It's almost always a good idea to override Java's default toString
    public String toString() {
        return "(" + String.valueOf(row) + ", " + String.valueOf(col) + ")";
    }
}
