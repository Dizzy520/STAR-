#include<SoftwareSerial.h>//库文件

SoftwareSerial BT(8,9);//设置连接接口
char X;//定义一个变量储存数据
void setup() {
Serial.begin(38400);//蓝牙通信速率
Serial.println("蓝牙连接正常");//串口监视器显示

BT.begin(38400);

}

void loop() {
if(Serial.available())//检测【串口】如果数据写入，则执行
{
  X=Serial.read();//把写入的数据给到自定义变量  X
  BT.print(X);//把数据给蓝牙
}
if(BT.available())//检测【蓝牙】如果数据写入，则执行
{
  X=BT.read();//把检测到的数据给到自定义变量X
  Serial.print(X);//把从蓝牙得到的数据显示到串口监视器
}
}
