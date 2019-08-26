import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;

class KnightBoard {
    private int board[][];
    private int numRows, numCols;
    private Pair start;
    private ArrayList<Pair> move;


    // default constructor -- you might want to add a little to this
    // and use it for debugging
    public KnightBoard() {
        board = new int[8][8];
        for (int row = 0; row < 8; row++)
            for (int col = 0; col < 8; col++)
                board[row][col] = 0;
        move = new ArrayList<Pair>();
        start = new Pair(-1, -1);
    }

        // constructor -- data comes from a file
    public KnightBoard(String fileName) throws IOException {

        // This is how mine starts, just to give you an idea
        // Also, this is an exception to the rule about not changing
        // any of the code. If you are more comfortable accessing
        // the file and/or reading the data a different way, feel
        // free to do so.

        boolean inputError = false;
        int int1, int2;
        StringTokenizer input;
        BufferedReader inFile = new BufferedReader(new FileReader(fileName));
        String lineStart;
        String inputLine = inFile.readLine();
        input = new StringTokenizer(inputLine);
        lineStart = input.nextToken(); // read "board"
        lineStart = input.nextToken(); // read "size:" numRows = Integer.parseInt(input.nextToken());
        numCols = Integer.parseInt(input.nextToken());

        board = new int[numRows][numCols];
    }
    // Be sure to make a copy of everything. Do not have this KnightBoard
    // point to anything in b.
    public KnightBoard(KnightBoard b) {
        // Look at my output in testTours to see what should be happening
        // Hint: use String.valueOf( num ) to convert int num to a String
        // You must be sure the columns line up properly as they do in my
        // output.
    }
    public String toString () {
        return "Foo";
    }
    // For easy checking of your answers
    public String toString2 () {
        String result = new String();
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                result = result + String.valueOf(board[row][col]);
            }
        }
        return result;
    }
    // These are the 3 methods I use to get the job done. You do not have to use
    // these, but I found them useful. Ee sure to use the Pair class as much as
    // possible
    // Check if this is a legal square to move to, i.e., is it actually on
    // the board and has it not been entered yet
    private boolean tryMove (Pair sq){
        return true;
    }
    // The number of legal moves from this square
    private int moveCt (Pair sq){
        return 0;
    }

    // sq is the square the knight is on. Update the square to its new
    // location based on the move and update the board to reflect this new move
    private void makeMove (Pair sq, Pair move){

    }

    // Enter the knight's moves into the board array
    // Here’s how mine begins. It would be nice if yours starts the same way.
    public void solve () {
        int bestMove, i, bestMoveCt;
        Pair curSpot = new Pair(start), nextMove;
        boolean done = false;
        while (!done) {
            done = true;
        }

    }

        // Who are you? Put your name here.
    public static String myName () {
        return "Nicholas Martinez";
    }

}
