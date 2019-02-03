#include <SPI.h>
#include <MFRC522.h>
#include <nRF24L01.h>
#include <RF24.h>

 
#define SS_PIN 10
#define RST_PIN 9

RF24 radio(7,8);

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

const byte address_trans1[6] = "00001";
const byte address_recieve1[6] = "00002";

void setup() 
{
  radio.begin();
  
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus

  mfrc522.PCD_Init();   // Initiate MFRC522
  
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  String text = "Authorized access";
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "26 58 60 12") //change here the UID of the card/cards that you want to give access
  {
    radio.openWritingPipe(address_trans1);
    radio.openReadingPipe(0,address_recieve1);
    delay(5);
    radio.stopListening();
    Serial.println("Authorized access");
    radio.write(&text, sizeof(text));
    Serial.println();
    delay(2000);
  }
 
 else   {
    Serial.println(" Access denied");
    delay(3000);
  }
} 
