
#include <Arduino.h>
#include <SPI.h>
//bibliotecas que facilitam a programcao de modulos similares a nRF24
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(9, 10); // CE, CSN
//configuracao dos enderecoes do canal de comunicacao pipe que sera usado
const byte addresses[][6] = {"00001", "00002"};
//numero do pino dos butoes
const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
// variavais para armazenar estado bos butoes
bool estadopin1 = 0;  
bool estadopin2 = 0;
bool estadopin3 = 0;

//declaracao das variaveis e funcoes gerais
void setup() {
  //Inicia a comunicação serial em 9600 bits por segundo 
  Serial.begin(9600);
  //definicao dos botoes como entra, na configuracao pullup
  pinMode(buttonPin1, INPUT_PULLUP); 
  pinMode(buttonPin2, INPUT_PULLUP); 
  pinMode(buttonPin3, INPUT_PULLUP); 
  //inicar a comunicação com o módulo nRF24L01,
  radio.begin();

  //define o endereço do pipe pelo qual os dados serão enviados. 
  radio.openWritingPipe(addresses[1]); // 00002
  //define o endereço do pipe pelo qual os dados serão recebidos. 
  radio.openReadingPipe(1, addresses[0]); // 00001
  //define a potência de transmissão do modulo nRF24L01 como mín, poupando energia
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  estadopin1 = digitalRead(buttonPin1);
  estadopin2 = digitalRead(buttonPin2);
  estadopin3 = digitalRead(buttonPin3);

  radio.stopListening();
  if (estadopin1 == LOW and estadopin2 == HIGH and estadopin3 ==HIGH) {
      
    // turn LED on:
    radio.write(&ledV, sizeof(int));

  } 
  else if(estadopin1 == LOW and estadopin2 == LOW and estadopin3 ==HIGH){
    radio.write(&ledVE, sizeof(int));

  }else{
    Serial.println(0);

  }

}
