🌞 Projeto de Monitoramento de Energia Renovável com ESP32 e MQTT
Este projeto é uma aplicação simulada para monitorar a geração e o consumo de energia utilizando um ESP32 e comunicação via protocolo MQTT. Ele é ideal para simular soluções de IoT (Internet das Coisas) voltadas para energia renovável, permitindo o controle remoto de dispositivos através de um broker MQTT.

🚀 Funcionalidades
Monitoramento da geração de energia (simulado por um potenciômetro).
Monitoramento do consumo de energia (simulado por outro potenciômetro).
Controle remoto de dispositivos através de um relé ativado via mensagens MQTT.
Publicação dos dados de geração e consumo para tópicos MQTT.
Assinatura de um tópico para controle do relé.
📋 Requisitos
Hardware:
ESP32
2 potenciômetros
1 relé
Jumpers e protoboard
Software:
Arduino IDE configurado para ESP32
Biblioteca PubSubClient instalada (para comunicação MQTT)
Biblioteca WiFi.h (já incluída no core do ESP32)
🔧 Montagem do Circuito
Conexões:
Potenciômetro 1 (Geração):
Pino central: GPIO34 do ESP32
VCC: 3.3V do ESP32
GND: GND do ESP32
Potenciômetro 2 (Consumo):
Pino central: GPIO35 do ESP32
VCC: 3.3V do ESP32
GND: GND do ESP32
Relé:
Sinal: GPIO25 do ESP32
VCC: 5V do ESP32 (ou fonte externa compatível)
GND: GND do ESP32
🖥️ Como Usar
Compile e carregue o código no ESP32 usando o Arduino IDE.
Abra o Monitor Serial para verificar se o ESP32 conectou ao Wi-Fi e ao broker MQTT.
Use um cliente MQTT (como MQTT Explorer) para:
Assinar os tópicos:
energia/geracao: Receber os dados de geração de energia.
energia/consumo: Receber os dados de consumo de energia.
Publicar mensagens no tópico energia/dispositivos para controlar o relé:
Enviar "ON" para ligar o dispositivo.
Enviar "OFF" para desligar o dispositivo.
📈 Tópicos MQTT
energia/geracao: Publica o percentual de geração de energia.
energia/consumo: Publica o percentual de consumo de energia.
energia/dispositivos: Recebe comandos (ON/OFF) para ativar/desativar o relé.
📜 Licença
Este projeto é licenciado sob a licença MIT. Consulte o arquivo LICENSE para mais detalhes.

🤝 Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

📧 Feito Por
Fabricio Carlos rm:555017
