/*Mayolo Valencia
 *11/01/2022
*/

//imports the library
#include <TinyStepper_28BYJ_48.h>

// These are the pins the cables should be in, but can be changed
// to whatever
const int MOTOR_IN1_PIN = 12;
const int MOTOR_IN2_PIN = 11;
const int MOTOR_IN3_PIN = 10;
const int MOTOR_IN4_PIN = 9;

float leftPanel, rightPanel;
const int STEPS_PER_REVOLUTION = 2048;
float step = 0;
// create the stepper motor object
TinyStepper_28BYJ_48 stepper;

void setup()
{
    Serial.begin(9600);

    stepper.connectToPins(MOTOR_IN1_PIN, MOTOR_IN2_PIN, MOTOR_IN3_PIN, MOTOR_IN4_PIN);
}

void loop()
{
    // set the speed and acceleration rates for the stepper motor
    stepper.setSpeedInStepsPerSecond(150);
    stepper.setAccelerationInStepsPerSecondPerSecond(500);

    // gets the amount of steps that would be 20 degrees 
    float oneDeg = STEPS_PER_REVOLUTION/360;
    float twentyDeg = oneDeg*20;

    // moves to this position in steps
    // at 0 goes to step 0, at 20 goes to steps at 20 degrees
    // at 40 goes to steps at 40 degrees and so on...
    stepper.moveToPositionInSteps(step);

    Serial.println(step + " degrees");
    // read and convert bits to voltage
    // Gets and prints the left panel's voltage
    // wire in analog 1
    leftPanel = analogRead(A1)*5.0/1024;
    Serial.print(leftPanel);

    // Gets and prints the left panel's voltage
    // wire in analog 2
    rightPanel = analogRead(A2)*5.0/1024;
    Serial.print("   ");
    Serial.println(rightPanel);

    step+=twentyDeg;
    // This should also work
    // Doesn't have an exit or resets to 0
}