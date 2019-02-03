# Garbinator
This project was created to demonstrate surveillance type approach to the current garbage bin collection system where verification is done using RFID tags.
The idea is that each garbage truck when collecting the garbage from a common big dump needs to swipe the card at the Card Reader that is to be placed on the garbage dump. In case the card is a 100% match with the prestored credentials, then a signal will be sent from the garbage dump using a radio sensor (nRF in this case, it can be replaced with a narrowband radio sensor or also a LORA sensor). THe leads to a server that is within a well defined range (100m for nRF and 1Km for LORA). The common server then using internet logs the data directly to a google sheet using a small Google Script which I would upload in a little while. If there is no card swiped within a period of 24 hours, then we register a complaint.


DEPENDANCIES
1. Radio connection is established wihtout any issue.
2. RFID is correctly read.
3. Radio transmission takes place properly.

Equipment used:
1. Arduino UNo
2. Breadboard
3. nRF sensors (1 for transmission and one for receival.
4. RFID Card reader by REES52 ( only a single unit)
5. Capacitors: 100uF / 25V for nRF sensors (Spherical type)
6. Jumper wires.
7. Buzzer
8. ESP8266 (for server side programming and data transfer)

