#include<Servo.h>

Servo myservo;//实例化一个舵机;
int angle;//定义变量———角度;

void setup() {
  // put your setup code here, to run once:
myservo.attach(9);//设置一个管脚;
}

void loop() {
  // put your main code here, to run repeatedly:
myservo.write(angle=0);//调整舵机角度至0度;
delay(2000);//停顿两秒;
myservo.write(angle=30);//调整舵机角度至30度;
delay(2000);//停顿两秒;
myservo.write(angle=45);//调整舵机角度至45度;
delay(2000);//停顿两秒;
myservo.write(angle=90);//调整舵机角度至90度;
delay(2000);//停顿两秒;
myservo.write(angle=135);//调整舵机角度至135度;
delay(2000);//停顿两秒;
myservo.write(angle=0);//调整舵机角度至0度;
myservo.detach();
}
