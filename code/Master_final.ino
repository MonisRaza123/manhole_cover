//#include<Wire.h>
#include <SPI.h>
#include <LoRa.h>

#define ss 5
#define rst 21
#define dio0 22

byte MasterNode=0xCC;
byte Slave1=0xAA;
byte Slave2=0xBB;

String SenderNode = "";
String outgoing;              // outgoing message

byte msgCount = 0;            // count of outgoing messages

// Tracks the time since last event fired
unsigned long previousMillis = 0;
unsigned long int previoussecs = 0;
unsigned long int currentsecs = 0;
unsigned long currentMillis = 0;
int interval = 1 ; // updated every 1 second
int Secs = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  while(!Serial);

  Serial.println("LoRa Master Node");

  LoRa.setPins(ss, rst, dio0);

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  

}

void loop() {
  // put your main code here, to run repeatedly:
  currentMillis=millis();
  currentsecs=currentMillis/1000;

   if ((unsigned long)(currentsecs - previoussecs) >= interval) {
    Secs = (Secs + 1)%11;
    
    if ( (Secs >= 1) && (Secs <= 5) )
    {
      Serial.println("sending 10");
      String message = "10";
      sendMessage(message, MasterNode, Slave1);
    }

    if ( (Secs >= 6 ) && (Secs <= 10))
    {
      Serial.println("sending 20");
      String message = "20";
      sendMessage(message, MasterNode, Slave2);
    }

    previoussecs = currentsecs;
  }

  
  // parse for a packet, and call onReceive with the result:
  onReceive(LoRa.parsePacket());

}

void sendMessage(String outgoing, byte MasterNode, byte otherNode) {
  LoRa.beginPacket();                   // start packet
  LoRa.write(otherNode);              // add destination address
  LoRa.write(MasterNode);             // add sender address
  LoRa.write(msgCount);                 // add message ID
  LoRa.write(outgoing.length());        // add payload length
  LoRa.print(outgoing);                 // add payload
  LoRa.endPacket();                     // finish packet and send it
  msgCount++;                           // increment message ID
}

void onReceive(int packetSize) {
  if (packetSize == 0) return;          // if there's no packet, return

  // read packet header bytes:
  int recipient = LoRa.read();          // recipient address
  byte sender = LoRa.read();            // sender address
  if ( sender == 0XAA )
    SenderNode = "Node1:";
  if ( sender == 0XBB )
    SenderNode = "Node2:";
  byte incomingMsgId = LoRa.read();     // incoming msg ID
  byte incomingLength = LoRa.read();    // incoming msg length

  String incoming = "";
  while (LoRa.available()) {
    incoming += (char)LoRa.read();
  }
  
  
  Serial.println("Received from: 0x" + String(sender, HEX));
  Serial.println("Sent to: 0x" + String(recipient, HEX));
  Serial.println("Message ID: " + String(incomingMsgId));
  Serial.println("Message length: " + String(incomingLength));
  Serial.println("Message: " + incoming);
  Serial.println("RSSI: " + String(LoRa.packetRssi()));
  Serial.println("Snr: " + String(LoRa.packetSnr()));
  Serial.println();
  
  
  if (incomingLength != incoming.length()) {   // check length for error
    Serial.println("error: message length does not match length");
    ;
    return;                             // skip rest of function
  }

  // if the recipient isn't this device,
  if (recipient != MasterNode) {
     Serial.println("This message is not for me.");
    ;
    return;                             // skip rest of function
  }

  // if message is for this device, print details:
   
}
  
