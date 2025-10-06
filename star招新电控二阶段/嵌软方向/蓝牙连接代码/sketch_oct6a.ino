#include <SoftwareSerial.h> // 软件串口库
#include <Servo.h>          // 舵机控制库

// 定义蓝牙模块连接引脚
#define BT_RXD 2  // HC05的TXD接Arduino的2号引脚
#define BT_TXD 3  // HC05的RXD接Arduino的3号引脚

Servo myServo;              // 创建舵机对象
SoftwareSerial bluetooth(BT_RXD, BT_TXD); // 创建软串口对象
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);       // 启动硬件串口（用于调试）
  bluetooth.begin(9600);    // 启动蓝牙串口（默认波特率9600）
  myServo.attach(9);        // 舵机信号线接数字引脚9
  myServo.write(90);        // 初始位置设为90度
  Serial.println("System Ready!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetooth.available()) {  // 检查蓝牙数据
    String angleStr = bluetooth.readStringUntil('\n'); // 读取字符串直到换行符
    angleStr.trim();            // 去除首尾空白
    
    // 转换为整数并验证范围
    int angle = angleStr.toInt();
    if (angle >= 0 && angle <= 180) {
      myServo.write(angle);     // 转动舵机
      
      // 调试信息（可选）
      Serial.print("Set angle: ");
      Serial.println(angle);
    }
  }
}
