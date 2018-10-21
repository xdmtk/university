
/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!                                                                            #
#                                                                            !
!   Programmer:     Nick Martinez                                            #
#   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
!   Instructor:     Milan Samplewala                                         #
#   Date:           10/10/2018                                               !
!                                                                            #
#          LAB 5 - Expression Evaluation 20.23                               !
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

    Modify EvaluateExpression.java to add operators for the ^ and %. The ^ operator
    has the highest preedence, and the % has the same precedence has * and / operators.
    Your program should prompt the user to enter an expression.


*/

import java.util.Stack;

public class ExpressionEval {

    public static void main(String[] args) {
        // Check number of arguments passed
        if (args.length != 1) {
            System.out.println(
                    "Usage: java EvaluateExpression \"expression\"");
            System.exit(1);
        }
        try {
            System.out.println(evaluateExpression(args[0]));
        }
        catch (Exception ex) {
            System.out.println("Wrong expression: " + args[0]);
        }
    }



    /** Evaluate an expression */
    public static int evaluateExpression(String expression) {

        // Create operandStack to store operands
        Stack<Integer> operandStack = new Stack<>();

        // Create operatorStack to store operators
        Stack<Character> operatorStack = new Stack<>();

        // Insert blanks around (, ), +, -, /, and *
        expression = insertBlanks(expression);

        // Extract operands and operators
        String[] tokens = expression.split(" ");

        // Phase 1: Scan tokens
        for (String token: tokens) {
            if (token.length() == 0) // Blank space
                continue; // Back to the while loop to extract the next token

            else if (token.charAt(0) == '+' || token.charAt(0) == '-') {

                // Process all +, -, *, / in the top of the operator stack
                while (!operatorStack.isEmpty() &&
                        (operatorStack.peek() == '+' ||
                                operatorStack.peek() == '-' ||
                                operatorStack.peek() == '*' ||
                                operatorStack.peek() == '/' ||

                                // New additions: Not from book
                                operatorStack.peek() == '^' ||
                                operatorStack.peek() == '%' )) {

                    processAnOperator(operandStack, operatorStack);
                }

                // Push the + or - operator into the operator stack
                operatorStack.push(token.charAt(0));
            }
            else if (token.charAt(0) == '^' || token.charAt(0) == '%') {

                // New addition, not from book. Process ^ and % as top priority operators
                while (!operatorStack.isEmpty() &&
                        (operatorStack.peek() == '^' ||
                                operatorStack.peek() == '%')) {
                    processAnOperator(operandStack, operatorStack);
                }
                // Push the * or / operator into the operator stack
                operatorStack.push(token.charAt(0));
            }
            else if (token.charAt(0) == '*' || token.charAt(0) == '/') {

                // Process all *, / in the top of the operator stack
                while (!operatorStack.isEmpty() &&
                        (operatorStack.peek() == '*' ||
                                operatorStack.peek() == '/')) {
                    processAnOperator(operandStack, operatorStack);
                }
                // Push the * or / operator into the operator stack
                operatorStack.push(token.charAt(0));
            }
            else if (token.trim().charAt(0) == '(') {
                operatorStack.push('('); // Push '(' to stack
            }
            else if (token.trim().charAt(0) == ')') {

                // Process all the operators in the stack until seeing '('
                while (operatorStack.peek() != '(') {
                    processAnOperator(operandStack, operatorStack);
                }
                operatorStack.pop(); // Pop the '(' symbol from the stack
            }
            else {
                // An operand scanned
                // Push an operand to the stack
                operandStack.push(new Integer(token));
            }
        }

        // Phase 2: Process all the remaining operators in the stack
        while (!operatorStack.isEmpty()) {
            processAnOperator(operandStack, operatorStack);
        }

        // Return the result
        return operandStack.pop();
    }


    /** Process one operator: Take an operator from operatorStack and

     * apply it on the operands in the operandStack */


    public static void processAnOperator(
            Stack<Integer> operandStack, Stack<Character> operatorStack) {
        char op = operatorStack.pop();
        int op1 = operandStack.pop();
        int op2 = operandStack.pop();

        if (op == '+')
            operandStack.push(op2 + op1);
        else if (op == '-')
            operandStack.push(op2 - op1);
        else if (op == '*')
            operandStack.push(op2 * op1);
        else if (op == '/')
            operandStack.push(op2 / op1);

            // Include the math operations corresponding to the operator
        else if (op == '^')
            operandStack.push((int)Math.pow((double) op2, (double) op1));
        else if (op == '%')
            operandStack.push((op2 % op1));
    }


    public static String insertBlanks(String s) {
        String result = "";
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == ')' ||
                    s.charAt(i) == '+' || s.charAt(i) == '-' ||
                    s.charAt(i) == '*' || s.charAt(i) == '/' ||

                    // Include new operators 
                    s.charAt(i) == '%' || s.charAt(i) == '^')
                result += " " + s.charAt(i) + " ";
            else
                result += s.charAt(i);
        }
        return result;
    }
}












