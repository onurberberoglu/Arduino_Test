#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <string.h>
#include <Servo.h>

RF24 radio(9, 10);  // CE, CSN
//address through which two modules communicate.
const byte address[6] = "00001";
char text[32];
void setup() {
  
  Serial.begin(9600);
  Serial.println("Serial is Okey");
  radio.begin();
  delay(3000);
  //Serial.println("Radio is Okey");
  radio.setPALevel(RF24_PA_MAX);  //Transmitter RF Power Setting
  //MIN=-18dBm, LOW=-12dBm, HIGH=-6dBm, MAX=0dBm.
  radio.setChannel(100);  //above most WiFi frequencies. RF Channel setting 0-125
  radio.setDataRate(RF24_250KBPS);
  //set the address
  radio.openReadingPipe(0, address);
  //Set module as receiver
  radio.startListening();

}

void loop() {
   if(radio.available())
  {
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}


