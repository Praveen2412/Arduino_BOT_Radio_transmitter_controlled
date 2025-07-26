# Arduino Robot with Radio Control

A 4-wheeled Arduino robot controlled by a Flysky FS-i6 radio transmitter. This project demonstrates wireless robot control with variable speed and directional movement using an L298N motor driver.

## Features

- Variable speed control
- Forward/backward movement
- Left/right turning
- Wireless control using Flysky FS-i6 transmitter
- Dual motor control with L298N driver
- Fail-safe on signal loss

## Components Required

1. Arduino UNO
2. L298N Motor Driver
3. 4 × DC Motors (500 RPM)
4. Flysky FS-i6 Transmitter
5. FS-i6 Receiver
6. 12V Battery
7. Chassis and wheels (not included)

## Wiring Instructions

### Motor Configuration
- Left motors: Connect two motors in parallel to left side output of L298N
- Right motors: Connect two motors in parallel to right side output of L298N

### Arduino to L298N Motor Driver
| Arduino Pin | L298N Pin | Function |
|------------|-----------|----------|
| 9 | ENA | Left motors enable |
| 10 | ENB | Right motors enable |
| 8 | IN1 | Left motor control 1 |
| 11 | IN2 | Left motor control 2 |
| 12 | IN3 | Right motor control 1 |
| 13 | IN4 | Right motor control 2 |

### Arduino to FS-i6 Receiver
| Arduino Pin | Receiver Channel | Function |
|------------|------------------|-----------|
| 5 | Channel 1 | Forward/Backward control |
| 6 | Channel 2 | Left/Right control |
| 5V | VCC | Power |
| GND | GND | Ground |

## Setup Instructions

1. Connect all components according to the wiring diagram
2. Upload the provided Arduino code
3. Bind the FS-i6 transmitter with the receiver
4. Power up the system with 12V battery
5. Calibrate the transmitter sticks if needed

## Code Features

- PWM speed control for smooth acceleration
- Deadband implementation for stick centering
- Fail-safe implementation if signal is lost
- Serial debugging output

## Usage

1. Power on the transmitter first, then the robot
2. Use left stick for forward/backward movement
3. Use right stick for left/right turning
4. Speed is proportional to stick movement
5. Robot stops automatically if signal is lost

## Troubleshooting

- No movement: Check power connections and motor driver enable pins
- Erratic movement: Verify receiver binding and channel mapping
- Wrong direction: Swap corresponding motor wires or adjust in code
- Poor response: Check battery voltage and signal strength
