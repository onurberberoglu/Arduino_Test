//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 10); // CE, CSN
//address through which two modules communicate.
char potData[32];
const byte address[6] = "00002";

int pot1 = 0;
int pot2 = 0;
int pot3 = 0;
int pot4 = 0;


void setup()
{
 Serial.begin(9600);
 radio.begin();
 Serial.println("NRF Ok");
 radio.setPALevel(RF24_PA_MAX);//Transmitter RF Power Setting
 //MIN=-18dBm, LOW=-12dBm, HIGH=-6dBm, MAX=0dBm.
 radio.setChannel(100); //above most WiFi frequencies. RF Channel setting 0-125
 radio.setDataRate( RF24_250KBPS ) ;

 //set the address
 radio.openWritingPipe(address);

 //Set module as transmitter
 radio.stopListening();
}
void loop()
{
  pot4 = analogRead(5);
  pot3 = analogRead(4);
  pot2 = analogRead(3);
  pot1 = analogRead(2);

 sprintf(potData, "%d,%d,%d,%d", pot1, pot2, pot3, pot4);
 radio.write(&potData, sizeof(potData));
 Serial.println(potData);
 delay(10);

}









