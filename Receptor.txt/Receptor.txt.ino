//// nrf24_server.pde
//// -*- mode: C++ -*-
//// Example sketch showing how to create a simple messageing server
//// with the RH_NRF24 class. RH_NRF24 class does not provide for addressing or
//// reliability, so you should only use RH_NRF24  if you do not need the higher
//// level messaging abilities.
//// It is designed to work with the other example nrf24_client
//// Tested on Uno with Sparkfun NRF25L01 module
//// Tested on Anarduino Mini (http://www.anarduino.com/mini/) with RFM73 module
//// Tested on Arduino Mega with Sparkfun WRL-00691 NRF25L01 module
//
//#include <SPI.h>
//#include <RH_NRF24.h>
//
//// Singleton instance of the radio driver
//RH_NRF24 nrf24;
//// RH_NRF24 nrf24(8, 7); // use this to be electrically compatible with Mirf
//// RH_NRF24 nrf24(8, 10);// For Leonardo, need explicit SS pin
//// RH_NRF24 nrf24(8, 7); // For RFM73 on Anarduino Mini
//
//void setup() 
//{
//  Serial.begin(9600);
//  while (!Serial) ; // wait for serial port to connect. Needed for Leonardo only
//  if (!nrf24.init())
//    Serial.println("init failed");
//  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
//  if (!nrf24.setChannel(1))
//    Serial.println("setChannel failed");
//  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
//    Serial.println("setRF failed");    
//}
//
//void loop()
//{
//  if (nrf24.available())
//  {
//    // Should be a message for us now   
//    uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
//    uint8_t len = sizeof(buf);
//    if (nrf24.recv(buf, &len))
//    {
////      NRF24::printBuffer("request: ", buf, len);
//      Serial.print("got request: ");
//      Serial.println((char*)buf);
//      
//      // Send a reply
//      uint8_t data[] = "And hello back to you";
//      nrf24.send(data, sizeof(data));
//      nrf24.waitPacketSent();
//      Serial.println("Sent a reply");
//    }
//    else
//    {
//      Serial.println("recv failed");
//    }
//  }
//}
//---------------------------------------------------------------

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int ledPin =  7; // the number of the LED pin
const int ledPinVE =  6; 
RF24 radio(10, 9); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};

int b1 = 0;



void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPinVE, OUTPUT);
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00001
  radio.openReadingPipe(1, addresses[1]); // 00002
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if(radio.available()) {
    radio.read(&b1, sizeof(int));
    if(b1 == 1){
      digitalWrite(ledPin, HIGH);
//      delay(500);
    }else if(b1==2){
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPinVE, HIGH);
//      delay(500);
    }
    Serial.print(b1);
    
  }else{
     digitalWrite(ledPin, LOW);
     digitalWrite(ledPinVE, LOW);
     Serial.println("sem sinal");

  }
}
//
////---------------------------
//
//#include <RH_NRF24.h>
//
//const int receive_pin = 10;
//const int led_pin = 13;
//
//RH_NRF24 nrf24(receive_pin, 9); // CE, CS
//
//void setup() {
//  Serial.begin(9600);
//  if (!nrf24.init()) {
//    Serial.println("Failed to initialize RF module.");
//    while (1);
//  }
//  nrf24.setChannel(1);
//  nrf24.setTxPower(20);
//  nrf24.setPALevel(RH_NRF24::PA_MAX);
//  nrf24.setDataRate(RH_NRF24::RF24_250KBPS);
//  nrf24.setAutoAck(false);
//  nrf24.setCRCLength(RH_NRF24::RF24_CRC_8);
//  nrf24.setPromiscuous(true);
//}
//
//void loop() {
//  uint8_t buf[1];
//  uint8_t len = sizeof(buf);
//  if (nrf24.available()) {
//    if (nrf24.recv(buf, &len)) {
//      if (buf[0] == 1) {
//        digitalWrite(led_pin, HIGH);
//      } else {
//        digitalWrite(led_pin, LOW);
//      }
//    }
//  }
//}

//---------------------------

//
//#include <RH_NRF24.h>
//
//const int receive_pin = 10;
//const int led_pin = 13;
//
//RH_NRF24 nrf24(receive_pin, 9); // CE, CS
//
//void setup() {
//  Serial.begin(9600);
//  if (!nrf24.init()) {
//    Serial.println("Failed to initialize RF module.");
//    while (1);
//  }
//  nrf24.setChannel(1);
//  nrf24.setTxPower(20);
//  nrf24.setPALevel(RH_NRF24::PA_MAX);
//  nrf24.setDataRate(RH_NRF24::RF24_250KBPS);
//  nrf24.setAutoAck(false);
//  nrf24.setCRCLength(RH_NRF24::RF24_CRC_8);
//  nrf24.setPromiscuous(true);
//}
//
//void loop() {
//  uint8_t buf[1];
//  uint8_t len = sizeof(buf);
//  if (nrf24.available()) {
//    if (nrf24.recv(buf, &len)) {
//      if (buf[0] == 1) {
//        digitalWrite(led_pin, HIGH);
//      } else {
//        digitalWrite(led_pin, LOW);
//      }
//    }
//  }
//}
