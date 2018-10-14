# Arduino BOT Radio transmitter controlled

This code is used to control arduino four wheeled bot. Flysky FS-i6 transmitter and recevier are used in this project along with L298N 
motor driver. Bind the transmitter and receiver and then use.
### Components
1. Arduino UNO
2. L298N Motor Driver
3. 4 x 500rpm DC motor
4. Fysky FS-i6 Transmitter 
5. FS-i6 Receiver
6. 12V Battery

### Connections

* 2 left side motors are parallelly connected to leftside motor output
* 2 right side motors are parallelly connected to rightside motor output

#### Motor driver Pin to Arduino

* enable left = 9
* enable right = 10
* left motor 1 = 8
* left motor 2 = 11
* right motor 1 = 12
* right motor 2 = 13

#### RF Receiver Pin to Arduino

* forward and backward channel (rc_channel1) = 5
* right and left channel (rc_channel2) = 6
* vcc = 5v
* GND = GND
