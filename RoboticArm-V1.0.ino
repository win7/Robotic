#include <Servo.h>

/* init servo */
Servo servo_i;
Servo servo_d;
Servo servo_p;
Servo servo_b;

String data_recived; 
char id = ' ';
String value = "0";
int time_ = 25;
void setup() {
  servo_i.attach(2);
  servo_d.attach(3);
  servo_p.attach(4);
  servo_b.attach(5);
  
  delay(1000);
  servo_b.write(85);
  delay(1000);
  servo_i.write(120);
  delay(1000);
  servo_d.write(5);
  delay(1000);
  servo_d.write(0);
  delay(1000);
  servo_p.write(80);
  delay(1000);
  
  Serial.begin(9600);
  delay(2000);
}

// I start 60 end 180
// D start 0 end 120
// P start 80 end 100
void loop() {
  if (Serial.available()){
    data_recived =  Serial.readStringUntil('\n');
    id = data_recived[0];
    value = data_recived.substring(1,data_recived.length()-1);
    
    Serial.println(data_recived);
    switch (id) {
    case 'I':
      Serial.println(value.toInt());
      if(value.toInt() >= 60 && value.toInt() <= 180){
        servo_i.write(value.toInt());
      }
      break;
    case 'D':
      Serial.println(value);
      if(value.toInt() >= 0 && value.toInt() <= 120){
        servo_d.write(value.toInt());
      }
      break;
    case 'P':
      Serial.println(value);
      if(value.toInt() >= 80 && value.toInt() <= 100){
        servo_p.write(value.toInt());
      }
      break;
    case 'B':
      Serial.println(value);
      if(value.toInt() >= 0 && value.toInt() <= 180){
        servo_b.write(value.toInt());
      }
      break;
    default: 
      break;
    }
  }
}
