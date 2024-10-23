import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.LinkedHashMap;
import java.util.Map;

public class VendingMachineSimulator extends JFrame {
    private JTextField amountField;
    private JTextArea resultArea;

    private final int[] denominations = {500, 200, 100, 50, 20, 10, 5, 2, 1}; // Coin denominations in cents

    public VendingMachineSimulator() {
        setTitle("Vending Machine Simulator");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout(10, 10));

        // Create UI components
        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10));
        inputPanel.setBackground(new Color(240, 248, 255));

        JLabel amountLabel = new JLabel("Enter amount to change (in Rupees): ");
        amountLabel.setFont(new Font("Fredoka", Font.BOLD, 16));
        amountLabel.setForeground(new Color(0, 102, 204));
        amountField = new JTextField(10);
        amountField.setFont(new Font("Arial", Font.PLAIN, 16));
        amountField.setBackground(new Color(255, 255, 204));
        amountField.setForeground(new Color(0, 51, 102));

        inputPanel.add(amountLabel);
        inputPanel.add(amountField);

        resultArea = new JTextArea();
        resultArea.setFont(new Font("Arial", Font.PLAIN, 16));
        resultArea.setEditable(false);
        resultArea.setBorder(BorderFactory.createLineBorder(Color.GRAY));
        resultArea.setBackground(new Color(255, 255, 255));
        resultArea.setForeground(new Color(0, 51, 102));
        JScrollPane scrollPane = new JScrollPane(resultArea);

        add(inputPanel, BorderLayout.NORTH);
        add(scrollPane, BorderLayout.CENTER);

        // Add key listener to the amount field to handle Enter key press
        amountField.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    handleCalculateClick();
                }
            }
        });
    }

    private void handleCalculateClick() {
        String amountText = amountField.getText();
        try {
            int amount = Integer.parseInt(amountText);
            if (amount <= 0) {
                JOptionPane.showMessageDialog(this, "Please enter a valid positive amount.", "Invalid Input", JOptionPane.ERROR_MESSAGE);
                return;
            }
            Map<Integer, Integer> change = calculateChange(amount);
            displayChange(change);
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Please enter a valid number.", "Invalid Input", JOptionPane.ERROR_MESSAGE);
        }
    }

    private Map<Integer, Integer> calculateChange(int amount) {
        int remainingAmount = amount;
        Map<Integer, Integer> change = new LinkedHashMap<>();

        for (int coin : denominations) {
            if (remainingAmount >= coin) {
                int count = remainingAmount / coin;
                change.put(coin, count);
                remainingAmount %= coin;
            }
        }

        return change;
    }

    private void displayChange(Map<Integer, Integer> change) {
        resultArea.setText("");
        for (Map.Entry<Integer, Integer> entry : change.entrySet()) {
            int a = entry.getValue();
            if (a == 1) {
                resultArea.append(a + " note of " + entry.getKey() + " Rupee\n");
            } else {
                resultArea.append(a + " notes of " + entry.getKey() + " Rupees\n");
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new VendingMachineSimulator().setVisible(true);
            }
        });
    }
}