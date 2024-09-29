**<h2>SprintEdgeComputing</h2>**

**Membros**

Anthony Motobe - RM558488

Arthur Rodrigues - RM555342

Guilherme Abe - RM554743

Gustavo Paulino - RM554779

Victor Pacifico Dias - RM558017

*<h2>Link do projeto: (Feito no site Wokwi)</h2>**
https://wokwi.com/projects/410332464007644161

**<h2>Descrição do Projeto</h2>**
Este projeto busca monitorar o uso da bateria de um carro durante uma corrida e alertar quando o nível da bateria está baixo ou quando o carro está consumindo muita energia. Utilizando um potenciometro( no lugar de um sensor de carga de bateria), o sistema é capaz de enviar dados em tempo real e notificar os usuários sobre condições críticas. O sistema coleta dados em tempo real e envia notificações para um painel de controle via Node-RED.

**<h2>Materiais Necessários para o projeto</h2>**

1.Microcontrolador Esp32

2.Potenciometro

3.Led

4.Protoboard(opcional)

5.Resistor

6.Fios jumper

**<h2>Componentes da Arquitetura</h2>**

<h3>Dispositivos IoT:</h3>

Microcontrolador ESP32: Coleta dados dos sensores de corrente e se conecta à rede Wi-Fi.

Potenciometro: Monitora o nível de carga da bateria do carro.

<h3>Backend:</h3>

Broker MQTT: Gerencia a troca de mensagens entre dispositivos IoT e o sistema de monitoramento (no caso o HiveMQ).

Node-RED: Responsavel pela programação visual para processar os dados recebidos, gerar alertas e exibir informações em tempo real.

<h3>Frontend:</h3>

Dashboard do Node-RED: Interface de usuário para monitorar o status da bateria e receber notificações em tempo real.


**<h2>Draft da Arquitetura</h2>**

![image](https://github.com/user-attachments/assets/8b67290f-61c5-4319-b3ea-ac0744ae6287)

**<h2> Montagem do Sistema</h2>**

<h3>Ligações do Potenciometro</h3>

Conecte a entrada VCC com o 5v do ESP32

Conecte a entrada GND com o GND do ESP32

Conecte a entrada SIG com o pino 34 do ESP32

<h3>ligações do Led</h3>

Conecte o pino dobrado do Led com a entrada 22 do ESP32

Conecte o pino maior do Led a um resistor e o conecte ao GND do ESP32 

**<h2>Configuração do hardware:</h2>**

Para a montagem é necessário a conexão do Potenciometro e do Led com o ESP32 conforme as instruções fornecidas. Certificar-se de que estao todas bem conectadas.

**<h2>Configuração do Software</h2>**

1.instale as bibliotecas necessárias: WiFi.h ; PubSubClient.h

2.Clone ou baixe o código-fonte do projeto

**<h2>Configuração do Node-red</h2>**

1.Acesse o Node-red no navegador]

2.Clique nas 3 barrinhas no canto superior direito e va em importar, em seguida selecione o arquivo json do projeto.

**<h2>Requisitos e Dependências</h2>**

.IDE de Arduino para carregar o código no ESP32

.Bibliotecas do Arduino

.Wifi

.PubSubClient

.Node-RED com os nós MQTT instalados.


