# hardware-gabriel-lyra-campos
# Comunicação wireless de 2 arduino uno

# Introdução
Este relatório é referente a um projeto de utilização de um  módulo Wireless NRF24L01+ para emitir e receber sinais de rádio que serão computados pelo arduino. Para que a comunicação ocorra corretamente é importante que o canal utilizado entre os módulos esteja entre 2,400 a 2,525 GH

# 1. Metodologia
## 1.1  Pesquisa e documentação
Inicialmente, procurou-se explorar a biblioteca nrf24 produzida para dar suporte a módulos  NRF24L01+  disponibilizada por TMRh20, que já estabelece uma pinagem base para o desenvolvimento do projeto.

## 1.2. Produção do projeto
Com base nos conhecimentos adquiridos na pesquisa da documentação, iniciou-se a produção do projeto físico onde utilizou-se:
2 arduino uno.
2 módulo RF wireless.
3 botões.
LED, buzzers ou displays gráficos.
A configuração física escolhida de pinos está demonstrada nas Figuras 1, 2, 3 e 4. Assim como a configuração final do projeto e o modelo de pinout do módulo na Figura 5.
Importante lembrar que se deve conectar o VCC do módulo em voltagens menores que 5v para evitar que queime.

![Alt text](Imagen_video/1.JPG)
Figura 1 - Projeto completo já montado com todas pinagens.

![Alt text](Imagen_video/2.JPG)
Figura 2 - Arduino receptor de sinal e suas pinagens. 

![Alt text](Imagen_video/3.JPG)
Figura 3 - Pintagens do arduino transmissor.

![Alt text](Imagen_video/4.JPG)
Figura 4 - Pinagem de referência geral  dos arduinos.

## 1.3 Testes
Após a finalização do projeto, foi feito o teste e foi observado a sequência de acionamento esperado, 1 botão acende o led vermelho e 2 botões o led verde.
Nota-se que diferentes configurações podem ser facilmente aplicadas ao projeto, como mais leds, algum buzzer ou display para mostrar algum texto, até mesmo um sensor de som ou distância no transmissor para, quando acionados, mandar um sinal para o receptor.

#  Observações

Aparentemente o tratamento de dados do tipo text não é lido corretamente e é printado com erro sendo impossível de ler o resultado.
O pino MISO do módulo dependendo do código, pode atrapalhar envio e recebimento de sinal.
Verificar se o os dois arduino estão conectados no usb do PC(ligados).
Verifique se os pinos estão de acordo com o código.

Dicas dadas:
 Tentar primeiro enviar, receber e printar um valor fixo.
 Tentar “forçar” um fim de vetor para a mensagem enviado e recebida com um”\0” para ver se a mensagem é impressa corretamente. 

## Bibliografia

Eletrogate. Guia Definitivo do Módulo Wireless NRF24L01+. Blog eletrogate. 9 de fevereiro de 2021. Disponível em: 
https://blog.eletrogate.com/guia-definitivo-do-modulo-wireless-nrf24l01-2/. Acesso em: 22 de maio de 2024.

Arduino e cia. Comunicação wireless com Arduino e módulo NRF24L01. Arduino e cia. 19 de fevereiro de 2015. Disponível em: 
https://www.arduinoecia.com.br/comunicacao-wireless-arduino-nrf24l01/. Acesso em: 22 de maio de 2024.
Brendan. RF24. Github, nRF24. 22 de Jul de 2015. Disponivel: <https://github.com/tmrh20/RF24>. Acesso em: 22 de maio de 2024.
TMRh20. Optimized high speed nRF24L01+ driver class documentation. 2020. Disponivel em: <https://nrf24.github.io/RF24/>. Acesso em 23 de maio de 2024.
