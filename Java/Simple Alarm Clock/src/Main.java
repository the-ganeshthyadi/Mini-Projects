import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.time.LocalTime;

public class Main extends JFrame {
    private JLabel timeLabel;
    private JTextField hourField, minuteField;
    private JButton setAlarmButton;
    private Timer timer;

    public Main() {
        setTitle("Simple Alarm Clock");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 200);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        timeLabel = new JLabel();
        timeLabel.setHorizontalAlignment(SwingConstants.CENTER);
        updateClock();
        add(timeLabel, BorderLayout.NORTH);

        JPanel alarmPanel = new JPanel(new FlowLayout());
        JLabel hourLabel = new JLabel("Hour:");
        JLabel minuteLabel = new JLabel("Minute:");
        hourField = new JTextField(2);
        minuteField = new JTextField(2);
        setAlarmButton = new JButton("Set Alarm");
        alarmPanel.add(hourLabel);
        alarmPanel.add(hourField);
        alarmPanel.add(minuteLabel);
        alarmPanel.add(minuteField);
        alarmPanel.add(setAlarmButton);
        add(alarmPanel, BorderLayout.CENTER);

        setAlarmButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setAlarm();
            }
        });

        timer = new Timer(1000, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                updateClock();
                checkAlarm();
            }
        });
        timer.start();
    }

    private void updateClock() {
        LocalTime currentTime = LocalTime.now();
        String timeText = currentTime.toString();
        timeLabel.setText("Current Time: " + timeText.substring(0, 5));
    }

    private void setAlarm() {
        try {
            int hour = Integer.parseInt(hourField.getText());
            int minute = Integer.parseInt(minuteField.getText());
            if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59) {
                JOptionPane.showMessageDialog(this, "Alarm set for " + hour + ":" + minute);
                timer.setInitialDelay(calculateDelay(hour, minute));
            } else {
                JOptionPane.showMessageDialog(this, "Please enter a valid hour (0-23) and minute (0-59).");
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Please enter valid numeric values.");
        }
    }

    private int calculateDelay(int hour, int minute) {
        LocalTime currentTime = LocalTime.now();
        LocalTime alarmTime = LocalTime.of(hour, minute);
        int delay = (int) currentTime.until(alarmTime, java.time.temporal.ChronoUnit.SECONDS) * 1000;
        return (delay > 0) ? delay : 86400000 + delay; // If the alarm time is earlier than the current time, set it for the next day
    }

    private void checkAlarm() {
        if (timer.getInitialDelay() == 0) {
            return; // Alarm not set
        }
        LocalTime currentTime = LocalTime.now();
        int secondsUntilAlarm = timer.getInitialDelay() / 1000;
        if (secondsUntilAlarm <= 0) {
            JOptionPane.showMessageDialog(this, "Alarm triggered!");
            // Create a new window or dialog when the alarm rings
            JFrame alarmWindow = new JFrame("Alarm!");
            alarmWindow.setSize(300, 200);
            alarmWindow.setLocationRelativeTo(null);
            JLabel alarmLabel = new JLabel("Wake up! Alarm is ringing!");
            alarmLabel.setHorizontalAlignment(SwingConstants.CENTER);
            alarmWindow.add(alarmLabel);
            alarmWindow.setVisible(true);

            // Reset alarm after showing the alarm window
            timer.setInitialDelay(0);
        }
    }


    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                Main alarmClock = new Main();
                alarmClock.setVisible(true);
            }
        });
    }
}
