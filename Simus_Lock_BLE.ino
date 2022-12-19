
#define NRF51822
#include <ArduinoJson.h>
DynamicJsonBuffer jsonBuffer;
#include "lp_BLESerial.h"
#include "lp_timer.h"
int led = 2;
bool ledOn = false;
lp_timer ledTimer;
lp_timer BLE_AdvertisingRestartTimer; // the advert restart timer
lp_BLESerial ble(128);
const unsigned long BLE_ADVERTISING_ms = 20 * 1000;// restart advertising every 20sec
const uint16_t BLE_ADVERTISING_TIMEOUT_secs = 10;// run advertising for 2 seconds
// pfodApp needs at least 2sec of advertising to scan and connect

void restartAdvertising() 
{  // called by timer every 20seconds
  ble.setAdvertising(true); // ignored if currently connected
}

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  digitalWrite(led,HIGH);
  Serial.setPins(20,19);
  Serial.begin(115200);
  ble.setLocalName("NRF528320-LED"); // set advertised name, default name is "Nordic BLE UART"
  ble.setDeviceName("NRF528320-LED");
  ble.setAdvertisingTimeout(BLE_ADVERTISING_TIMEOUT_secs); // cài thơi gian averteding là 3s
  BLE_AdvertisingRestartTimer.startTimer(BLE_ADVERTISING_ms, restartAdvertising); // restart advertising every 20sec for 2sec
  ble.setConnectedHandler(Connect); // khi kết nối được tạo 
  ble.setDisconnectedHandler(Disconnect); // khi kết nối bị ngắt hoặc nằm ngoài phạm vi 
 // ble.setTxBuffer(512);
  ble.setTxPower(-40);
  ble.begin(); // start advertising and be ready to accept connections
//  Wire.setPins(10,11);
//  Wire.begin();
 // lcd.begin();

 //ledTimer.startTimer(1000, dao_led); 

 Serial.println("khoi tao");
}

void loop() {
    sleep(); // just sleep here waiting for the timer to trigger
  // check for new BLE cmd  'a' starts blinking, 'b' stops blinking
  if(ble.available())
  {
  //String i="";
  char buff[50]={0};
  while (ble.available() ) {
        for (unsigned int i = 0; i < 50; i++)
    {
        buff[i] =ble.read();
    }
 // i = ble.readString(); 
  }
      Serial.println(buff);
 // Serial.println(i);
//     if (i.indexOf("on")!=-1) {
//      digitalWrite(led, LOW);
//      //ledTimer.startTimer(2000, stt); // start blinking
//    } else if(i.indexOf("off")!=-1) {
//      digitalWrite(led, HIGH);
//      //ledTimer.stop();    // stop blinking
//    }  
  }

 
// ble.poll();
}
void stt() {
    char input[100] =
      "goc: hello world toi la thang pro 2022 axzcvbnm1973"; //chuoi nay cho do dai la 46 => ghep 3 mang,, 
      int len = strlen(input); // do dai chuoi
      int msg_len = 20;
      char *buff1 = (char*)malloc(msg_len);
      char *buff2 = (char*)malloc(msg_len);
      char *buff3 = (char*)malloc(msg_len);
      
      Serial.println(input); 
      if(len<19)
      {
        Serial.println(input);
        //trong dieu kien thoa man
      }
      else
      {
      for(int i=0;i<len;i++)
      {
       if(i<19)
       {
        buff1[i]=input[i];
       }
       else if(i>19 && i<38)
       {
        buff2[i]=input[i];
       }
       else if(i>38)
       {
        buff3[i]=input[i];
       }
        
      }
       Serial.print("chuoi 1:"); Serial.println(buff1);
       Serial.print("chuoi 2:"); Serial.println(buff2);
       Serial.print("chuoi 3:"); Serial.println(buff3);
       free(buff1);
       free(buff2);
       free(buff3);
      }

      
//  if (ledOn) {
//    //Serial.println("on");
//    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
//  } else {
//    //Serial.println("khoi off");
//    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
//  }

  
  if(ble.isConnected())
  {
   ble.print(input);

  //ble.clearTxBuffer();
   ble.flush();
   
 // ble.clearTxBuffer();
   

}
}
void Connect(BLECentral& central)
{
  Serial.println("da ket noi");
   ble.print("123456");
  //ble.clearTxBuffer();
   ble.flush();  
  //xu ly khi ket noi
  nhay_led1();
  //ledTimer.startTimer(2000, stt); // start blinking
}
void Disconnect(BLECentral& central)
{
  //ledTimer.startTimer(2000, stt);
  //xu ly khi ngat ket noi
  Serial.println("da mat ket noi");
  nhay_led();
}

void nhay_led1()
{
  digitalWrite(led,0);
  delay(500);
  digitalWrite(led,1);
  delay(500);  
  digitalWrite(led,0);
  delay(500);
  digitalWrite(led,1);
  delay(500);    
}
//void dao_led()
//{
//  ledOn = !ledOn; // toggle state
//  if (ledOn) {
// //   Serial.println("on");
//    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
//  } else {
//   // Serial.println("off");
//    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
//  }
//}
void nhay_led()
{
  digitalWrite(led,0);
  delay(50);
  digitalWrite(led,1);
  delay(50);  
  digitalWrite(led,0);
  delay(50);
  digitalWrite(led,1);
  delay(50);    
  digitalWrite(led,0);
  delay(50);
  digitalWrite(led,1);
  delay(50);  
  digitalWrite(led,0);
  delay(50);
  digitalWrite(led,1);
  delay(50);   
}


/*#define NRF51822
#include "lp_BLESerial.h"
#include "lp_timer.h"
//#include <nRFChipInfo.h>
//#include <ArduinoJson.h>
//DynamicJsonBuffer jsonBuffer;
//#include <LiquidCrystal_I2C.h>
//#include <Wire.h>
//LiquidCrystal_I2C lcd(0x27, 16, 2);
// Pin 13 has an LED connected on most Arduino boards, including NanoV2
static const size_t SIZE = 512; // Max data size pfodApp msg
int led = 2;
bool ledOn = false;
lp_timer ledTimer;
lp_timer BLE_AdvertisingRestartTimer; // the advert restart timer
lp_BLESerial ble;
const unsigned long BLE_ADVERTISING_ms = 20 * 1000;// restart advertising every 20sec
const uint16_t BLE_ADVERTISING_TIMEOUT_secs = 3;// run advertising for 2 seconds
// pfodApp needs at least 2sec of advertising to scan and connect

void restartAdvertising() {  // called by timer every 20seconds
  ble.setAdvertising(true); // ignored if currently connected
}

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  Serial.begin(115200);

  ble.setLocalName("NRF528320-LED"); // set advertised name, default name is "Nordic BLE UART"
  ble.setDeviceName("NRF528320-LED");
  ble.setConnectable(false);
  ble.setTxPower(+4);
  ble.setAdvertisingTimeout(BLE_ADVERTISING_TIMEOUT_secs); // cài thơi gian averteding là 3s
  BLE_AdvertisingRestartTimer.startTimer(BLE_ADVERTISING_ms, restartAdvertising); // restart advertising every 20sec for 2sec
  ble.setConnectedHandler(Connect); // khi kết nối được tạo 
  ble.setDisconnectedHandler(Disconnect); // khi kết nối bị ngắt hoặc nằm ngoài phạm vi 
//  ble.setTxBuffer(SIZE);
  ble.begin(); // start advertising and be ready to accept connections
//  Wire.setPins(10,11);
//  Wire.begin();
 // lcd.begin();
  ledTimer.startTimer(4000, stt);
 Serial.println("khoi tao");
}

void loop() {
    sleep(); // just sleep here waiting for the timer to trigger
  // check for new BLE cmd  'a' starts blinking, 'b' stops blinking
  while (ble.available() ) {
    String i = ble.readString();
    if (i.indexOf("start") !=-1) {
     // digitalWrite(led, HIGH);
      ledTimer.startTimer(2000, stt); // start blinking
    }
    else if(i.indexOf("stop")!=-1) {
      //digitalWrite(led, LOW);
      ledTimer.stop();    // stop blinking
    }
    else if (i.indexOf("on")!=-1) {
      digitalWrite(led, LOW);
      //ledTimer.startTimer(2000, stt); // start blinking
    } else if(i.indexOf("off")!=-1) {
      digitalWrite(led, HIGH);
      //ledTimer.stop();    // stop blinking
    }    
  }
}

void stt() {
    char input[100] =
      "{\"cmd\":\"gps\",\"temp\":25.14,\"time\":1000}";
//  JsonObject& obj = jsonBuffer.parseObject(input);
//  obj[String("time")] = (long)(millis()/1000);
//  obj["cmd"] = "bat";
//  obj["temp"] =getChipTemperature();
//  String output;
//  obj.printTo(output);
//  output+=sizeof(output);
//  ledOn = !ledOn; // toggle state
  if (ledOn) {
    Serial.println("on");
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  } else {
    Serial.println("khoi off");
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  }
  if(ble.isConnected())
  {

// //x+=nRF52Variant(); x+="/";
//  x+=(String)nRF52RamKb(); x+="/";
//  x+=(String)nRF52FlashKb();
  
//  ble.setAdvertisedName(x.c_str());  
   ble.print("xin chao ");
   ble.flush();
   ble.clearTxBuffer();
    // ble.setAdvertisedName(input); 

  }
}
void Connect(BLECentral& central)
{
  //xu ly khi ket noi
  nhay_led();
}
void Disconnect(BLECentral& central)
{
  //xu ly khi ngat ket noi
  nhay_led();
}
void nhay_led()
{
  digitalWrite(led,0);
  delay(50);
  digitalWrite(led,1);
  delay(50);  
  digitalWrite(led,0);
  delay(50);
  digitalWrite(led,1);
  delay(50);    
  digitalWrite(led,0);
  delay(50);
  digitalWrite(led,1);
  delay(50);  
  digitalWrite(led,0);
  delay(50);
  digitalWrite(led,1);
  delay(50);   
}
*/
