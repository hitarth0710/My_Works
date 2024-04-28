import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Prac12_2 extends JFrame implements ActionListener {

    private JButton redButton;
    private JButton blueButton;
    private JButton greenButton;
    private JPanel panel;
    private final Color RED = Color.RED;
    private final Color BLUE = Color.BLUE;
    private final Color GREEN = Color.GREEN;
    private Color currentColor = null;

    public Prac12_2() {
        super("Fill Rectangle");
        setLayout(new FlowLayout());

        redButton = new JButton("Red");
        blueButton = new JButton("Blue");
        greenButton = new JButton("Green");

        panel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                if (currentColor != null) {
                    g.setColor(currentColor);
                    g.fillRect(10, 10, getWidth() - 20, getHeight() - 20);
                }
            }
        };
        panel.setPreferredSize(new Dimension(200, 100));
        panel.setBackground(Color.WHITE);

        redButton.addActionListener(this);
        blueButton.addActionListener(this);
        greenButton.addActionListener(this);

        add(redButton);
        add(blueButton);
        add(greenButton);
        add(panel);

        pack();
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == redButton) {
            currentColor = RED;
        } else if (e.getSource() == blueButton) {
            currentColor = BLUE;
        } else if (e.getSource() == greenButton) {
            currentColor = GREEN;
        }
        panel.repaint();
    }

    public static void main(String[] args) {
        new Prac12_2();
    }
}