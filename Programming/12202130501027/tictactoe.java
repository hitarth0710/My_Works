import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class TicTacToe extends JFrame {
    private JButton[] buttons = new JButton[9];
    private char currentPlayer = 'X';
    //private int currentButton = 0;

    public TicTacToe() {
        setTitle("Tic-Tac-Toe");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 300);

        Container content = getContentPane();
        content.setLayout(new GridLayout(3, 3));

        for (int i = 0; i < 9; i++) {
            buttons[i] = new JButton(" ");
            buttons[i].addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    JButton buttonClicked = (JButton) e.getSource();
                    if (buttonClicked.getText().equals(" ")) {
                        buttonClicked.setText(String.valueOf(currentPlayer));
                        if (checkWin()) {
                            JOptionPane.showMessageDialog(null, currentPlayer + " wins!");
                            dispose(); // close the game
                        } else {
                            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        }
                    }
                }
            });
            content.add(buttons[i]);
        }
    }

    private boolean checkWin() {
        // check rows, columns, and diagonals for a win condition
        return (checkRow(0, 1, 2) || checkRow(3, 4, 5) || checkRow(6, 7, 8)
                || checkColumn(0, 3, 6) || checkColumn(1, 4, 7) || checkColumn(2, 5, 8)
                || checkDiagonal(0, 4, 8) || checkDiagonal(2, 4, 6));
    }

    private boolean checkRow(int a, int b, int c) {
        return (buttons[a].getText().equals("X") && buttons[b].getText().equals("X")
                && buttons[c].getText().equals("X"));
    }

    private boolean checkColumn(int a, int b, int c) {
        return (buttons[a].getText().equals("X") && buttons[b].getText().equals("X")
                && buttons[c].getText().equals("X"));
    }

    private boolean checkDiagonal(int a, int b, int c) {
        return (buttons[a].getText().equals("X") && buttons[b].getText().equals("X")
                && buttons[c].getText().equals("X"));
    }

    public static void main(String[] args) {
        new TicTacToe();
    }
}

public class tictactoe {
    public static void main(String[] args) {
        new TicTacToe();
    }
}