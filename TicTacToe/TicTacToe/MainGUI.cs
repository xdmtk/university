using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TicTacToe
{
    public partial class MainGUI : Form
    {
        List<Label> squares = new List<Label>(9);

        public bool gameStarted;
        public bool p1turn, p2turn;
        public int p1ScoreVal = 0, p2ScoreVal = 0;




        public MainGUI()
        {
            InitializeComponent();
            InitializeBoard();
        }

        private void MainGUI_Load(object sender, EventArgs e)
        {

        }







        private void InitializeBoard()
        {

            // Initialze game squares
            squares.Add(sq1);
            squares.Add(sq2);
            squares.Add(sq3);
            squares.Add(sq4);
            squares.Add(sq5);
            squares.Add(sq6);
            squares.Add(sq7);
            squares.Add(sq8);
            squares.Add(sq9);
            
            foreach (Label square in squares)
            {
                square.AutoSize = false;
                square.Size = new Size(112, 110);
                square.Text = "";

            }

    
            status.Text = "WAITING TO START...";
            startButton.Text = "START GAME";
            gameStarted = false;
            p1turn = p2turn = false;

        }









        private void startButton_Click(object sender, EventArgs e)
        {
            if (!gameStarted)
            {
                startGame();
            }
            else
            {
                stopGame();
            }
        }


        private bool checkWins(Label obj)
        {
            //Row 1 across
            if ((squares[0].Text == squares[1].Text) && (squares[0].Text == squares[2].Text))
            {

                if ((squares[0].Text != "") && (squares[1].Text != "") && (squares[2].Text != ""))
                {
                    return true;
                }
            }
            // Row 2 accorss
            else if ((squares[3].Text == squares[4].Text) && (squares[3].Text == squares[5].Text))
            {
                if ((squares[3].Text != "") && (squares[4].Text != "") && (squares[5].Text != ""))
                {
                    return true;
                }
            }
            // Row 3 across
            else if ((squares[6].Text == squares[7].Text) && (squares[6].Text == squares[8].Text))
            {
                if ((squares[6].Text != "") && (squares[7].Text != "") && (squares[8].Text != ""))
                {
                    return true;
                }
            }
            // Row 1 Down
            else if ((squares[0].Text == squares[3].Text) && (squares[0].Text == squares[6].Text))
            {
                if ((squares[0].Text != "") && (squares[3].Text != "") && (squares[6].Text != ""))
                {
                    return true;
                }
            }
            // Row 2 Down
            else if ((squares[1].Text == squares[4].Text) && (squares[1].Text == squares[7].Text))
            {
                if ((squares[1].Text != "") && (squares[4].Text != "") && (squares[7].Text != ""))
                {
                    return true;
                }
            }
            // Row 3 Down
            else if ((squares[2].Text == squares[5].Text) && (squares[2].Text == squares[8].Text))
            {
                if ((squares[2].Text != "") && (squares[5].Text != "") && (squares[8].Text != ""))
                {
                    return true;
                }
            }
            // Diag 1 
            else if ((squares[0].Text == squares[4].Text) && (squares[0].Text == squares[8].Text))
            {
                if ((squares[0].Text != "") && (squares[4].Text != "") && (squares[8].Text != ""))
                {
                    return true;
                }
            }
            // Diag 2 
            else if ((squares[2].Text == squares[4].Text) && (squares[2].Text == squares[6].Text))
            {
                if ((squares[2].Text != "") && (squares[4].Text != "") && (squares[6].Text != ""))
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
            return false;
        }

















        private void startGame()
        {

            gameStarted = true;
            p1turn = true;
            startButton.Text = "STOP GAME";
            status.Text = "PLAYER 1 GO";

        }
        private void stopGame()
        {

            gameStarted = false;
            startButton.Text = "START GAME";
            p1turn = p2turn = false;
            InitializeBoard();
        }



        private void squareClicked(object sender, EventArgs e)
        {
            if (gameStarted)
            {
                if (((Label)sender).Text == "")
                {
                    if (p1turn)
                    {
                        ((Label)sender).Text = "X";
                        p1turn = false;
                        p2turn = true;
                        status.Text = "PLAYER 2 GO";
                    }
                    else
                    {
                        ((Label)sender).Text = "O";
                        p1turn = true;
                        p2turn = false;
                        status.Text = "PLAYER 1 GO";

                    }
                    if (checkWins((Label)sender))
                    {
                        MessageBox.Show("You win");
                        if (p2turn)
                        {
                            p1ScoreVal++;
                            scorep1.Text = p1ScoreVal.ToString();
                        }
                        else
                        {
                            p2ScoreVal++;
                            scorep2.Text = p2ScoreVal.ToString();
                        }
                        stopGame();
                    }
                }
                else
                {
                    MessageBox.Show("Invalid move");
                }
            }





        }
    }
}
