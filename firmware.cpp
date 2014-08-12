#include <Arduino.h>

/*
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
*/

const int countRows=7;
const int countColumns=7;

const int outputPins[7]={A0, A1, A2, 5, A4, A5, A6};
const int inputPins[7]={6, 7, 8, 9, 10, 11, 12};

int pressed_state[countRows][countColumns]={{0}};

//const int outputPins[7]={A0, A1, A2, A3, A4, A5, A6};
//const int inputPins[7]={6, 7, 8, 9, 10, 11, 12};

void setup()
{
	// initialize the digital pin as an output.
	// Pin 13 has an LED connected on most Arduino boards:
	pinMode(13, OUTPUT);

	for (int ii=0; ii<countRows; ++ii)
        pinMode(outputPins[ii], INPUT_PULLUP);
	for (int ii=0; ii<countColumns; ++ii)
        pinMode(inputPins[ii], INPUT_PULLUP);
}

int iterations=0;

void print(bool released, int row, int column)
{
    Serial.print(released ? "released: " : "pressed: ");
    Serial.print(column);
    Serial.print(" ");
    Serial.println(row);
}

void setOutput(int index)
{
	for (int ii=0; ii<countRows; ++ii)
        pinMode(outputPins[ii], (ii==index ? OUTPUT : INPUT_PULLUP));
    digitalWrite(outputPins[index], LOW);
}

void loop()
{
    iterations++;
    if (iterations%200==0)
    {
        Serial.print("iterations: ");
        Serial.println(iterations);
    }

//    setOutput(3);
//    for (int ii=0; ii<10; ++ii)
//    {
//        for (int jj=0; jj<countRows; ++jj)
//        {
//            int value=digitalRead(inputPins[jj]);
//            Serial.print(value==HIGH ? 1 : 0);
//        }
//        Serial.println();
//        delay(100);
//    }

    for (int column=0; column<countColumns; ++column)
    {
        pinMode(outputPins[column], OUTPUT);

        digitalWrite(outputPins[column], LOW);
        for (int row=0; row<countRows; ++row)
        {
            int pressed=!digitalRead(inputPins[row]);
            int &state=pressed_state[row][column];
            if (pressed)
            {
                state++;
                if (state==10)
                    print(false, row, column);
            }
            else if (state>=10)
            {
                state=0;
                print(true, row, column);
            }
        }

        digitalWrite(outputPins[column], HIGH);
        pinMode(outputPins[column], INPUT_PULLUP);
    }
    delay(1);
}
