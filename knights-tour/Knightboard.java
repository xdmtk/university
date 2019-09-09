import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;

class KnightBoard {
    private int board[][];
    private int numRows, numCols, maxDigit;
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

        /** First we need to instantiate our BufferedReader object to begin parsing the file. */
        BufferedReader reader = new BufferedReader(new FileReader(fileName));

        this.move = new ArrayList<Pair>();

        /** Next we declare string buffer for line-by-line parsing */
        String currentLine;

        /** For extra verbosity, we set our enum value to the expected value of the given
         * line, and declare our StringTokenizer object
         */
        DataReadState readState = DataReadState.BOARD_SIZE;
        StringTokenizer tokenizer;

        /** Now we can iterate through the file line by line, and exit when EOF is reached */
        while ((currentLine = reader.readLine()) != null) {

            /** Making some assumptions about the input format, the first few lines are separated
             * out by colons ( with the exception of the piece movement data, with the label on
             * left side and the values on the right, so we can split the given string and take the
             * right half to parse values
             */
            if (currentLine.contains(":") && readState != DataReadState.PIECE_MOVEMENT){

                /** Now we can read the tokens and assign them accordingly based on the
                 * state of the DataReadState enum
                 */
                tokenizer = new StringTokenizer(currentLine.split(":")[1]);
                switch (readState) {

                    case BOARD_SIZE:
                         this.numRows = Integer.parseInt(tokenizer.nextToken());
                         this.numCols = Integer.parseInt(tokenizer.nextToken());

                        /** We can now instantiate the board, and in the case of Java,
                         * by default the instantiation fills the board with zeros
                         */
                        this.board = new int[numRows][numCols];
                         /** After parsing, we 'increment' our enum to the next line state */
                         readState = DataReadState.START_SQUARE;
                         break;

                    case START_SQUARE:
                        start = new Pair(Integer.parseInt(tokenizer.nextToken()),
                                Integer.parseInt(tokenizer.nextToken()));
                        readState = DataReadState.PIECE_MOVEMENT;
                        break;
                }
            }
            /** Once we hit the PIECE_MOVEMENT state in our parsing enum, we can skip the initial
             * colon labeled line and start parsing values directly line by line thereafter
             */
            else {
                if (currentLine.contains(":"))
                   continue;

                /** With that data being appended to our ArrayList of legal moves */
                tokenizer = new StringTokenizer(currentLine);
                move.add(new Pair(Integer.parseInt(tokenizer.nextToken()),
                        Integer.parseInt(tokenizer.nextToken())));
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
        /** Pretty much the same as toString2 except we space
         * and pad out the digit strings, and end each row with a
         * new line character
         */
        StringBuilder result = new StringBuilder(" ");

        /** We get the largest iterative value when traversing the board */
        int maxPadding = 1;

        /** And use it to determine how much padding we need to apply to each
         * digit output
         */
        while ((this.maxDigit/10) > 0) {
            /** We can do this by getting the magnitude of the number by repeatedly
             * dividing it by 10 until its Integer division results in 0
             */
            this.maxDigit /= 10;
            maxPadding++;
        }

        /** Now we begin building the string */
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {

                String digitStr = String.valueOf(board[row][col]);

                /** Here we apply the padding based on what we found with the highest magnitude iteration */
                for (int p=0 ; p < maxPadding - String.valueOf(board[row][col]).length(); p++)
                    result.append(" ");

                result.append(digitStr + " ");
            }
            result.append("\n ");
        }
        return result.toString();
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
        boolean result;
        /** We check whether the move is legal by testing the bounds of the given board and move */
        if (sq.getRow() >= 0 && sq.getRow() < this.numRows
            && sq.getColumn() >= 0 && sq.getColumn() < this.numCols

            /** We likewise check whether the given move has already been hit */
            && this.board[sq.getRow()][sq.getColumn()] == 0) {
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }

    // The number of legal moves from this square
    private int moveCt (Pair sq){
        int moveCounter = 0;
        for (Pair followingMove : move) {
            /** Here we iterate through the list of possible follow-up moves from the given square 'sq'
             *  and call tryMove() repeatedly with the result of applying the possible follow-up move to
             *  the current square
             */
            if (tryMove(new Pair(sq.getRow() + followingMove.getRow(),
                    sq.getColumn() + followingMove.getColumn()))) {

                /** If the move is possible, we can increment the `moveCounter` */
                moveCounter++;
            }
        }
        return moveCounter;
    }

    // Enter the knight's moves into the board array
    // Here’s how mine begins. It would be nice if yours starts the same way.
    public void solve () {

        /** We use i to mark our current move iteration */
        int i = 1;

        Pair curSpot = new Pair(start), nextMove = null;

        /** And we mark our starting point with iteration 1 */
        this.board[curSpot.getRow()][curSpot.getColumn()] = i++;
        boolean done = move.size() <= 0;


        /** As long as we have taken less moves than there are possible moves, and our
         * done flag remains false we can continue in the loop
         */
        while (i <= this.numCols*numRows && !done) {
            /** We set the moveCounter to the maximum integer to keep track of the move
             * that contains the lowest number of follow-up moves
             */
            int moveCounter = Integer.MAX_VALUE;

            /** Now we begin testing each possible move */
            for (Pair potentialMove : move) {

                /** We generate the new Pair object that contains the board coordinates of where we would
                 * end up if we take the given potentialMove
                 */
                Pair newMove = new Pair(curSpot.getRow() + potentialMove.getRow(),
                        curSpot.getColumn() + potentialMove.getColumn());

                /** If tryMove() tells us the move is valid, and the count of follow-up moves is as least
                 * as low as the current lowest move count, we can call this newMove our nextMove
                 */
                if (tryMove(newMove) && moveCt(newMove) <= moveCounter) {

                    /** Set the move counter to the new lowest value */
                    moveCounter = moveCt(newMove);

                    /** If we aren't at the final move, but the possible moves are set to 0, then we
                     * are done
                     */

                    // TODO: Problem is here, if we have multiple potential moves where each move there are
                    // no more following moves, each of them get marked as if we moved there.
                    if (moveCounter == 0 && i != this.numCols*this.numRows) {
                        done = true;
                    }
                    this.maxDigit = i;
                    nextMove = newMove;
                }
            }
            /** Now we can change the current position and mark the new position on the board */
            if (nextMove != null && !done) {

                curSpot.setRow(nextMove.getRow());
                curSpot.setColumn(nextMove.getColumn());

                this.board[curSpot.getRow()][curSpot.getColumn()] = i++;
            }
            /** If we have marked ourselves as done, then we mark what _would have been_
             *  the next move on the board with the iteration number, instead of the current spot
             */
            else if (nextMove != null) {
                this.board[nextMove.getRow()][nextMove.getColumn()] = i++;
            }
        }

    }

        // Who are you? Put your name here.
    public static String myName () {
        return "Nicholas Martinez";
    }

}
