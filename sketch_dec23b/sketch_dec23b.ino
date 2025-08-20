//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <string.h>
#include <Servo.h>

//create an RF24 object
RF24 radio(9, 10);  // CE, CSN
//address through which two modules communicate.
const byte address[6] = "00002";
char text[32] = { 0 };
String myData = "";
String data1 = "";
String data2 = "";
String data3 = "";
String data4 = "";

Servo myEsc;
Servo myMotor1;
Servo myMotor2;
Servo myMotor3;

int pot1 = 0;
int pot2 = 0;
int pot3 = 0;
int pot4 = 0;

int i = 0;
void setup() {
  Serial.begin(9600);
  /*Serial.println("Serial is Okey");
  radio.begin();
  Serial.println("Radio is Okey");
  radio.setPALevel(RF24_PA_MAX);  //Transmitter RF Power Setting
  //MIN=-18dBm, LOW=-12dBm, HIGH=-6dBm, MAX=0dBm.
  radio.setChannel(100);  //above most WiFi frequencies. RF Channel setting 0-125
  radio.setDataRate(RF24_250KBPS);
  //set the address
  radio.openReadingPipe(0, address);
  //Set module as receiver
  radio.startListening();*/
  myEsc.attach(7);
  //myMotor1.attach(6);
  //myMotor2.attach(5);
  //myMotor3.attach(4);
}
void loop() 
{
  for(i = 0; i <= 180 ; i++)
  {
  myEsc.write(i);
  Serial.println(i);
  delay(50);
  }
  for(i = 180; i >= 0 ; i--)
  {
  myEsc.write(i);
  Serial.println(i);
  delay(50);
  }

  //Read the data if available in buffer
  /*if (radio.available()) {
    radio.read(&text, sizeof(text));
    myData = text;
    int index1 = myData.indexOf(',');
    data1 = myData.substring(0, index1);
    int index2 = myData.indexOf(',', index1 + 1);
    data2 = myData.substring(index1 + 1, index2);
    int index3 = myData.indexOf(',', index2 + 1);
    data3 = myData.substring(index2 + 1, index3);
    data4 = myData.substring(index3 + 1);
    pot4 = data4.toInt();
    //data3.toInt();
    pot2 = data2.toInt();
    pot1 = data1.toInt();
    pot3 = pot1;

    pot1 = map(pot1, 0, 1024, 60, 120);
    pot2 = map(pot2, 0, 1024, 70, 135);
    pot3 = map(pot3, 1024, 0, 120, 60);
    pot4 = map(pot4, 550, 1024, 0, 180);

    Serial.print(pot1);
    Serial.print("-");
    Serial.print(pot2);
    Serial.print("-");
    Serial.print(pot3);
    Serial.print("-");
    Serial.println(pot4);
  }*/

  //myMotor1.write(pot3);
  //myMotor2.write(pot2);
  //myMotor3.write(pot1);
}
