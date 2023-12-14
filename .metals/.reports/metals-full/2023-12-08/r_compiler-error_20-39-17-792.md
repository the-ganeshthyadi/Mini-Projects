file:///D:/Github/Mini-Projects/Java/Simple%20Alarm%20Clock.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
offset: 736
uri: file:///D:/Github/Mini-Projects/Java/Simple%20Alarm%20Clock.java
text:
```scala
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.time.LocalTime;

public class SimpleAlarmClock extends JFrame {
    private JLabel timeLabel;
    private JTextField hourField, minuteField;
    private JButton setAlarmButton;
    private Timer timer;

    public SimpleAlarmClock() {
        setTitle("Simple Alarm Clock");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 200);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        timeLabel = new JLabel();
        timeLabel.setHorizontalAlignment(SwingConstants.CENTER);
        updateClock();
        add(timeLabel, BorderLa@@yout.NORTH);

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
            timer.setInitialDelay(0); // Reset alarm
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                SimpleAlarmClock alarmClock = new SimpleAlarmClock();
                alarmClock.setVisible(true);
            }
        });
    }
}

```



#### Error stacktrace:

```
scala.collection.Iterator$$anon$19.next(Iterator.scala:973)
	scala.collection.Iterator$$anon$19.next(Iterator.scala:971)
	scala.collection.mutable.MutationTracker$CheckedIterator.next(MutationTracker.scala:76)
	scala.collection.IterableOps.head(Iterable.scala:222)
	scala.collection.IterableOps.head$(Iterable.scala:222)
	scala.collection.AbstractIterable.head(Iterable.scala:933)
	dotty.tools.dotc.interactive.InteractiveDriver.run(InteractiveDriver.scala:168)
	scala.meta.internal.pc.MetalsDriver.run(MetalsDriver.scala:45)
	scala.meta.internal.pc.HoverProvider$.hover(HoverProvider.scala:34)
	scala.meta.internal.pc.ScalaPresentationCompiler.hover$$anonfun$1(ScalaPresentationCompiler.scala:329)
```
#### Short summary: 

java.util.NoSuchElementException: next on empty iterator