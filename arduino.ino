#include <SoftwareSerial.h>

String number = "+YYXXXXXXXXX"; // TODO:: change YY to country code, change XX... to phone number

SoftwareSerial PHONE(10,11);
int led = 13;
int relay = 12;
int buzzer = 9

void setup() {
  PHONE.begin(4800);

  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  bool rightcaller = false;
  PHONE.println("AT+CLIP=1"); // activate number display on call
  if(PHONE.find("RING")) { // check if a call is coming in
    if(PHONE.find("+CLIP")) { // if a number is found
      if(PHONE.readString().indexOf(number) != -1) { // check if number is the right one
        rightcaller = true;
      }
    }
    PHONE.println("ATA"); // accept call
    delay(100);
    PHONE.println("AT+CHUP"); // end call
  }
  if(rightcaller) {
    rightcaller = false;
    action();
  }
}

void ledBeepSeq(int times, int delay, int length = 150) {
  for (int i = 0; i <= times; i++) {
    digitalWrite(led, HIGH);
    tone(buzzer, 2000, length);
    delay(delay); 
    digitalWrite(led, LOW);
    delay(100);
  }
}

void action() {
  ledBeepSeq(20, 500);
  ledBeepSeq(10, 100);
  ledBeepSeq(5, 80);
  ledBeepSeq(1, 0, 1000);

  // activate relay
  digitalWrite(relay, HIGH);
  delay(1250);
  digitalWrite(relay, LOW);
}
