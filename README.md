# Maze Solver Robot

This project implements an Arduino-based maze solver robot using ultrasonic sensors. The robot is designed to autonomously navigate through a maze while avoiding obstacles using PID control.

## Table of Contents

- [Introduction](#introduction)
- [Components](#components)
- [Code](#code)
- [How It Works](#how-it-works)
- [Collaborators](#collaborators)
- [Achievements](#achievements)

## Introduction

The Maze Solver Robot is a robotics project that demonstrates autonomous navigation using ultrasonic sensors. The robot is equipped with ultrasonic sensors to detect obstacles in its path and employs a PID controller to adjust its movement to navigate through the maze.

## Components

- Arduino Uno
- Motor Driver (L298N)
- DC Motors (2)
- Ultrasonic Sensors (3)
- Chassis
- Wheels (2)
- Power Supply (Battery)
- Jumper Wires

## Code

The main code for the Maze Solver Robot is in `maze_solver_code.ino` file. Below is a brief description of the code:

1. **Pin Definitions**: Define the pins connected to the motors, motor driver, and ultrasonic sensors.
2. **Setup Function**: Set the pin modes and initialize Serial communication.
3. **Loop Function**: Continuously read distance readings from the ultrasonic sensors, calculate PID value, and control motor speeds based on the PID value.

For the complete code, please refer to the `maze_solver_code.ino` file.

## How It Works

1. **Ultrasonic Sensors**: The robot uses three ultrasonic sensors to measure distances to obstacles in front, left, and right directions.
2. **Error Calculation**: The error is calculated based on the difference between the actual distance from the right wall and the desired distance.
3. **PID Controller**: The PID controller calculates the correction needed to minimize the error. The PID value is used to adjust the motor speeds to maintain the desired distance from the wall.
4. **Motor Control**: The motors are controlled using a motor driver. The speeds of the left and right motors are adjusted based on the PID value to steer the robot along the maze path.

## Collaborators

This project was developed by the following collaborators:

- **Mohamed** - [GitHub](https://github.com/mohamed20o03)
- **Collaborator Name 1** - [GitHub](https://github.com/collaborator1)
- **Collaborator Name 2** - [GitHub](https://github.com/collaborator2)
- **Collaborator Name 3** - [GitHub](https://github.com/collaborator3)

## Achievements

- **First Place in Maze Solver Competition**: Our Maze Solver Robot project was awarded first place in the IEEE competitions at Port Said University on May 19, 2024, Our Maze Solver Robot project was recognized for its innovative approach and successful navigation through the maze while avoiding obstacles.

