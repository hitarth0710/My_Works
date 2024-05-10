import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class Prac12_1 extends JFrame {
    private JTextField tfAmount, tfYears, tfRate, tfFutureValue;

    public Prac12_1() {
        // Create labels and text fields
        JLabel lblAmount = new JLabel("Investment Amount");
        tfAmount = new JTextField(10);

        JLabel lblYears = new JLabel("Years");
        tfYears = new JTextField(10);

        JLabel lblRate = new JLabel("Annual Interest Rate");
        tfRate = new JTextField(10);

        JLabel lblFutureValue = new JLabel("Future Value");
        tfFutureValue = new JTextField(10);
        tfFutureValue.setEditable(false);

        // Create a calculate button
        JButton btnCalculate = new JButton("Calculate");
        btnCalculate.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                calculateInvestment();
            }
        });

        // Add components to the frame
        setLayout(new GridLayout(5,2));
        add(lblAmount);
        add(tfAmount);
        add(lblYears);
        add(tfYears);
        add(lblRate);
        add(tfRate);
        add(lblFutureValue);
        add(tfFutureValue);
        add(btnCalculate);

        // Set frame properties
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    private void calculateInvestment() {
        double amount = Double.parseDouble(tfAmount.getText());
        int years = Integer.parseInt(tfYears.getText());
        double rate = Double.parseDouble(tfRate.getText());

        double futureValue = amount * Math.pow(1 + rate / 100, years);
        tfFutureValue.setText(String.format("%.2f", futureValue));
    }

    public static void main(String[] args)
    {
        new Prac12_1();
    }
}

