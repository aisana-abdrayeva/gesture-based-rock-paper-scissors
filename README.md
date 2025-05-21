# gesture-based-rock-paper-scissors
"Gesture based Rock, Paper and Scissors" is a more innovative and engaging version of the game "Rock, Paper, Scissors" with recognition of the sensor movements of the player. The sensors read the hand movement as a certain hand gesture and transmit it to the machine, and the machine itself raises a stick with a hand gesture via servo motors. Thus, the winner of the round is displayed on the screen. Some limitations of our project are the motion recognition sensor, as it sometimes recognizes movements with errors due to technical inaccuracy or wear of the device. Despite this, errors are rare, and the game itself remains exciting.

List of Materials:
1) Arduino Board
2) Breadboard
3) 3 Servo Motors
4) Accelerometer
5) Active Buzzer
6) I2C LCD1602 Display
7) Potentiometer
8) Wires


The program turns on with the buzzer sound. The display lights up with the phrase "Rock Paper Scissors!". The sensor reads the movement of the player's hands and at the same time the program picks up a random stick with a hand gesture using a servo motor and displays the names of these gestures on the display. Example of display output:
"You: Scissors 
  CPU: Paper" 

Then it gives one of the results:
1) Results: CPU wins
2) Results: You win
3) Results: Draw

In this case, the player wins and it is displayed on the screen as “Results: You win”. Specific gesture patterns are mapped to Rock, Paper, and Scissors using acceleration thresholds. For example, a steady hand is interpreted as "Rock," a forward tilt as "Paper," and a quick shake or swipe as "Scissors."

We made it so that when the sensor moves along certain axes, it reads hand gestures like Rock, Paper or Scissors. For users to properly play the game, we sewed the accelerometer to the glove. 

# Contributions:
Aisana Abdrayeva wrote the code for each of the servo motors, sensor and other parts of the construction.
Ulmeken Totanova and Amina Aidyn worked on the circuit design, building of the construction, implementation and testing of the work of the project.
