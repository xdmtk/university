import java.io.Reader;
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
    private enum DataReadState {BOARD_SIZE, START_SQUARE, PIECE_MOVEMENT};


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

        /* First we need to instantiate our BufferedReader object to begin parsing the file. */
        BufferedReader br = new BufferedReader(new FileReader(fileName));

        this.move = new ArrayList<Pair>();

        /* Next we declare string buffer for line-by-line parsing */
        String currentLine;

        /* For extra verbosity, we set our enum value to the expected value of the given
         * line, and declare our StringTokenizer object
         */
        DataReadState rs = DataReadState.BOARD_SIZE;
        StringTokenizer st;

        /* Now we can iterate through the file line by line, and exit when EOF is reached */
        while ((currentLine = br.readLine()) != null) {

            /* Making some heavy assumptions about the input format, the first few lines are separated
             * out by colons ( with the exception of the piece movement data, with the label on
             * left side and the values on the right, so we can split the given string and take the
             * right half to parse values
             */
            if (currentLine.contains(":") && rs != DataReadState.PIECE_MOVEMENT){

                /* Now we can read the tokens and assign them accordingly based on the
                 * state of the DataReadState enum
                 */
                st = new StringTokenizer(currentLine.split(":")[1]);
                switch (rs) {

                    case BOARD_SIZE:
                         this.numCols = Integer.parseInt(st.nextToken());
                         this.numRows = Integer.parseInt(st.nextToken());

                        /* We can now instantiate the board with all zeros */
                        this.board = new int[numRows][numCols];
                        for (int r = 0; r < 8; r++)
                            for (int c = 0; c < 8; c++)
                                this.board[r][c] = 0;
                         /* After parsing, we 'increment' our enum to the next line state */
                         rs = DataReadState.START_SQUARE;
                         break;

                    case START_SQUARE:
                        start = new Pair(Integer.parseInt(st.nextToken()),
                                Integer.parseInt(st.nextToken()));
                        rs = DataReadState.PIECE_MOVEMENT;
                        break;
                }
            }
            /* Once we hit the PIECE_MOVEMENT state in our parsing enum, we can skip the initial
             * colon labeled line and start parsing values directly line by line thereafter
             */
            else {
                if (currentLine.contains(":"))
                   continue;

                /* With that data being appending to our ArrayList of legal moves */
                st = new StringTokenizer(currentLine);
                move.add(new Pair(Integer.parseInt(st.nextToken()),
                        Integer.parseInt(st.nextToken())));
            }
        }
   }



    // Be sure to make a copy of everything. Do not have this KnightBoard
    // point to anything in b.
    public KnightBoard(KnightBoard b) {
        // Look at my output in testTours to see what should be happening
        // Hint: use String.valueOf( num ) to convert int num to a String
        // You must be sure the columns line up properly as they do in my
        // output.
        this.board = b.board.clone();
        this.numCols = b.numCols;
        this.numRows = b.numRows;
        this.start = b.start;
        this.move = (ArrayList<Pair>) b.move.clone();
    }

    public String toString () {
        /* Pretty much the same as toString2 except we space
         * and pad out the digit strings, and end each row with a
         * new line character
         */
        StringBuilder res = new StringBuilder(" ");
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {

                String digitStr = String.valueOf(board[row][col]);
                res.append((board[row][col] < 10 ? " " : "") + digitStr + " ");
            }
            res.append("\n ");
        }
        return res.toString();
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
