/*
	
	Example code to control a bot with variable speed
	using a L298N driver board, an Arduino, and a typical RC Controller
	
	driver board: 
	    https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=L298N
	
	flysky rc controller transmitter and receiver: $50
	    https://www.amazon.com/s/ref=nb_sb_noss_2?url=search-alias%3Daps&field-keywords=fs-t6&rh=i%3Aaps%2Ck%3Afs-t6
	

*/


int in1 = 8;
int in2 = 11;
int in3 = 12;
int in4 = 13;

//the following are all ~PWM capable ports 
int enable1 = 9;
int enable2 = 10;
int rc_channel1 =5;
int rc_channel4 =6;
int switchD = 3;

void setup() {
  pinMode(rc_channel1, INPUT);
  pinMode(rc_channel2, INPUT);
  pinMode(switchD, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  int pwm = 0;
  int swd = pulseIn(switchD, HIGH, 25000);
  int rc1 = pulseIn(rc_channel1, HIGH, 25000);
  int rc2 = pulseIn(rc_channel2, HIGH, 25000);
  
  //Serial.print("switch ");
  //Serial.print(swd);
  Serial.print(" raw channel1: ");
  Serial.print(rc1);
   Serial.print(" raw channel2: ");
  Serial.print(rc2);
  
  if(rc1==0){
      Serial.println(" no signal");
      analogWrite(in1, 0);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, 0);
      digitalWrite(enable1, LOW);
      digitalWrite(enable2, LOW);
  }
  else if(rc1 > 1530){ 
      pwm = map(rc1, 1530, 2000, 0, 255); //map our speed to 0-255 range
      analogWrite(in1, 0);
      analogWrite(in2, pwm);
      digitalWrite(enable1, HIGH);
      analogWrite(in3, 0);
      analogWrite(in4, pwm);
      digitalWrite(enable2, HIGH);
      Serial.print(" Forward ");
      Serial.println(pwm);
  }
  else if(rc1 < 1460){
      pwm = map(rc1, 1460, 1000, 0, 255); //map our speed to 0-255 range
      analogWrite(in1, pwm);
      analogWrite(in2, 0);
      digitalWrite(enable1, HIGH);
      analogWrite(in3, pwm);
      analogWrite(in4, 0);
      digitalWrite(enable2, HIGH);
      Serial.print(" backward ");
      Serial.println(pwm);
      
  }
   //Turning program
    else if(rc2 < 1460){ //left
      pwm = map(rc2, 1460, 1000, 0, 255); //map our speed to 0-255 range
      analogWrite(in1, pwm);
      analogWrite(in2, 0);
      digitalWrite(enable1, HIGH);
      analogWrite(in3, 0);
      analogWrite(in4, pwm);
      digitalWrite(enable2, HIGH);
      Serial.print(" left ");
      Serial.println(pwm);
    }
        else if(rc2 > 1530){ //right
      pwm = map(rc2, 1530, 2000, 0, 255); //map our speed to 0-255 range
      analogWrite(in1, 0);
      analogWrite(in2, pwm);
      digitalWrite(enable1, HIGH);
      analogWrite(in3, pwm);
      analogWrite(in4, 0);
      digitalWrite(enable2, HIGH);
      Serial.print(" right");
      Serial.println(pwm);
   
  }
  else{
      Serial.println(" stick centered");
      analogWrite(in1, 0);
      analogWrite(in2, 0);
      digitalWrite(enable1, LOW);
      analogWrite(in3, 0);
      analogWrite(in4, 0);
      digitalWrite(enable2, LOW);
  }
  
  delay(10);
}
