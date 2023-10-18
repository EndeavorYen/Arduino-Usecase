/*
  PIR("Passive Infrared Sensor") Motion Sensor, 
  紅外線動作感測器, 或稱人體紅外線感應器
 */

int PIRSensor = 2;              // 紅外線動作感測器 OUT 連接 Arduino pin 2
int ledPin =  13;               // LED 長腳連接 Arduino pin 13
int buzzer = 8;                 // 蜂鳴器正極 (+) 連接 Arduino pin 8

int sensorValue = 0;            // 紅外線動作感測器訊號變數

void setup() {
  pinMode(PIRSensor, INPUT);     //從感應器讀入訊息
  pinMode(ledPin, OUTPUT);        
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  sensorValue = digitalRead(PIRSensor);            //讀取 PIR Sensor 的狀態
  Serial.println(sensorValue);                     //將訊號值印在序列埠螢幕上
                                                   //判斷 PIR Sensor 的狀態
  if (sensorValue == HIGH) {                       //如果訊號值是 HIGH，表示有感應到紅外線位移，有人，警報響起，LED 燈點亮
    digitalWrite(ledPin, HIGH);                  
    digitalWrite(buzzer, HIGH);
  } 
  else {                                           //如果訊號值是 LOW，沒人，則警報不響，LED 燈不亮
    digitalWrite(ledPin, LOW);   
    digitalWrite(buzzer, LOW);
  }
}
