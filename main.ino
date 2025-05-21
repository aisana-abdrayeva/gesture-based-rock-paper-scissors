#include <Wire.h>
#include <MPU6050.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 10, 4, 3, 2);

// MPU6050 Sensor
MPU6050 mpu;
int buzzerPin = 13;

// Servo Motors
Servo servoRock;
Servo servoPaper;
Servo servoScissors;

// Servo Motor Pins
const int rockServoPin = 5;
const int paperServoPin = 6;
const int scissorsServoPin = 7;

String playerChoice = "";
String cpuChoice = "";
String result = "";

// Game choices
String choices[] = {"Rock", "Paper", "Scissors"};

void setup() {
  lcd.begin(16, 2);
  lcd.print("Rock Paper Scissors!");
  delay(2000);
  lcd.clear();

  Wire.begin();
  mpu.initialize();

  if (!mpu.testConnection()) {
    lcd.print("MPU6050 Error!");
    while (1);  // Stop if MPU6050 is not detected
  }

  // Initialize Servos
  servoRock.attach(rockServoPin);
  servoPaper.attach(paperServoPin);
  servoScissors.attach(scissorsServoPin);

  // Initialize random seed for CPU choice
  randomSeed(analogRead(0));
}

void loop() {
  detectGesture();  // Detect player movement
  
  if (playerChoice != "") {
    cpuChoice = getCpuChoice();
    result = getGameResult(playerChoice, cpuChoice);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You: " + playerChoice);
    lcd.setCursor(0, 1);
    lcd.print("CPU: " + cpuChoice);
    delay(2000);

    // Move the servo based on CPU's choice
    moveServo(cpuChoice);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Result: " + result);
    delay(2000);

    playerChoice = "";  // Reset for next round
  }
}

void detectGesture() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Detect Rock (steady hand)
  if (abs(ax) < 2000 && abs(ay) < 2000 && abs(az) > 14000) {
    playerChoice = "Paper";
  }
  
  // Detect Paper (tilt forward or backward)
  else if (ay > 10000 ay < -10000) {
    playerChoice = "Rock";
  }
  
  // Detect Scissors (shake)
  else if (abs(gx) > 15000 abs(gy) > 15000) {
    playerChoice = "Scissors";
  }
}

String getCpuChoice() {
  return choices[random(0, 3)];
}

String getGameResult(String player, String cpu) {
  if (player == cpu) return "Draw";
  if ((player == "Rock" && cpu == "Scissors") 
      (player == "Paper" && cpu == "Rock") 
      (player == "Scissors" && cpu == "Paper")) {
    return "You Win!";
  }
  return "CPU Wins!";
}

void moveServo(String move) {
  if (move == "Rock") {
  
  servoRock.write(180);
  delay(200);
  servoRock.write(90);
  delay(1000);
  servoRock.write(0);
  delay(200);
  servoRock.write(90);

  } else if (move == "Paper") {
 
  servoPaper.write(180);
  delay(200);
  servoPaper.write(90);
  delay(1000);
  servoPaper.write(0);
  delay(200);
  servoPaper.write(90);

  } else if (move == "Scissors") {
  
  servoScissors.write(180);
  delay(200);
  servoScissors.write(90);
  delay(1000);
  servoScissors.write(0);
  delay(200);
  servoScissors.write(90);

  }
}
