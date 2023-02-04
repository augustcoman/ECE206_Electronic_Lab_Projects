# ECE206_Electronic_Lab_Projects

This repository contains electronics projects done in ECE206 electronics lab. The individual projects are separated into "Labs" with the fritzing diagram, embedded arduino code, and photos of the fritzing breadboard layouts and circuit diagrams included. Below are descriptions for the included labs.

## Lab 3A: Rotational Measurement using Rotary Encoder

In this project, the rotational displacement of an incremental rotary encoder will be measured and displayed on a 2-digit seven segment display. Pull-up resistors will be used in the circuit for measuring the states of the A and B pins. The 2-digit seven segment display will display both digits by rapidly alternating and displaying either digit.
As the values of the encoder pins change, the code will interpret that as a state change and advance to another state. Cycling through all states for a rotation will increment the rotation reading on the display. An image of the state diagram used is also included in the project folder.

## Lab 6: H-Bridge and Direction Control

For this project an H-bridge circuit will be constructed to control both the intensity and direction of a basic DC electric motor. This will be constructed with a pair of NMOS and PMOS MOSFET transistors, and controlled using an Arduino with PWM output. The voltage on either side of the H-bridge is controlled by a PWM output on one side for intensity, and a digital switch on the other to toggle direction. In its current configuration, the speed and direction of the motor are dictated by serial signals sent manually via Arduino IDE on the computer, and this can be configured to utilize an encoder or potentiometer as an alternative.

## Other Lab Descriptions and Content

WIP
