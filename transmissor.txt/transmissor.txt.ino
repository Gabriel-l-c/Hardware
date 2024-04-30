//// nrf24_client.pde
//// -*- mode: C++ -*-
//// Example sketch showing how to create a simple messageing client
//// with the RH_NRF24 class. RH_NRF24 class does not provide for addressing or
//// reliability, so you should only use RH_NRF24 if you do not need the higher
//// level messaging abilities.
//// It is designed to work with the other example nrf24_server.
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
//  while (!Serial) 
//    ; // wait for serial port to connect. Needed for Leonardo only
//  if (!nrf24.init())
//    Serial.println("init failed");
//  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
//  if (!nrf24.setChannel(1))
//    Serial.println("setChannel failed");
//  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
//    Serial.println("setRF failed");    
//}
//
//
//void loop()
//{
//  Serial.println("Sending to nrf24_server");
//  // Send a message to nrf24_server
//  uint8_t data[] = "Hello World!";
//  nrf24.send(data, sizeof(data));
//  
//  nrf24.waitPacketSent();
//  // Now wait for a reply
//  uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
//  uint8_t len = sizeof(buf);
//
//  if (nrf24.waitAvailableTimeout(500))
//  { 
//    // Should be a reply message for us now   
//    if (nrf24.recv(buf, &len))
//    {
//      Serial.print("got reply: ");
//      Serial.println((char*)buf);
//    }
//    else
//    {
//      Serial.println("recv failed");
//    }
//  }
//  else
//  {
//    Serial.println("No reply, is nrf24_server running?");
//  }
//  delay(400);
//}

//---------------------------
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(9, 10); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};

const int buttonPin1 = 2; // the number of the pushbutton pin
const int buttonPin2 = 3;
const int buttonPin3 = 4;
bool estadopin1 = 0;  // variable for reading the pushbutton status
bool estadopin2 = 0;
bool estadopin3 = 0;

int ledV = 1;
int ledVE = 2;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT_PULLUP); 
  pinMode(buttonPin2, INPUT_PULLUP); 
  pinMode(buttonPin3, INPUT_PULLUP); 
  radio.begin();
  radio.openWritingPipe(addresses[1]); // 00002
  radio.openReadingPipe(1, addresses[0]); // 00001
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  estadopin1 = digitalRead(buttonPin1);
  estadopin2 = digitalRead(buttonPin2);
  estadopin3 = digitalRead(buttonPin3);

  radio.stopListening();
  if (estadopin1 == LOW and estadopin2 == HIGH and estadopin3 ==HIGH) {
//    Serial.println(1);
      
    // turn LED on:
    radio.write(&ledV, sizeof(int));
//    delay(100);
  } 
  else if(estadopin1 == LOW and estadopin2 == LOW and estadopin3 ==HIGH){
    radio.write(&ledVE, sizeof(int));
//    delay(100);
  }else{
    Serial.println(0);
//    delay(100);
  }
  //    Serial.println(1);
//  delay(500);
}

//---------------------------

//#include <RH_NRF24.h>
//
//const int transmit_pin = 9;
//const int data = 1;
//
//RH_NRF24 nrf24(transmit_pin, 10); // CE, CS
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
//}
//
//void loop() {
//  uint8_t buf[1];
//  buf[0] = data;
//  nrf24.send(buf, sizeof(buf));
//  delay(1000);
//}
