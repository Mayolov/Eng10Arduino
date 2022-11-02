/*Mayolo Valencia
 *10/29/2022
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

    // Initialize a position counter starting at 20 deg
    float pos = twentyDeg;
    // fo i is less than 18 keep rotating
    for(int i = 0; i<18; i++){
        // moves to this position in steps
        // at 0 goes to step 0, at 20 goes to steps at 20 degrees
        // at 40 goes to steps at 40 degrees and so on...
        stepper.moveToPositionInSteps(pos);

        // Prints the degree position
        Serial.println(pos + " degrees");

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

        // adds 20 degrees in steps to the previous value
        pos+=twentyDeg;
    
        // 6 second delay to record the voltage at this step
        delay(6000);
    }
    // stepper goes back to zero
    stepper.moveToPositionInSteps(0);
    // exit program
    exit(0);
}