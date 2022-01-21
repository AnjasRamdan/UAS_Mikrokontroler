//Pendeteksi kelembaban tanah
#define NOTE_C4 262 // Bunyi buzzer DO
#include <LiquidCrystal.h> //Library LCD

const int pinDigital = A0; //inisialisasi pin sensor
const int relay = 2;       //inisialisasi pin relay 
const int ledGreen = 3;    //inisialisasi pin led hijau
const int ledYellow = 4;   //inisialisasi pin led kuning
const int ledRed = 5;      //inisialisasi pin hijau
const int pinSpeaker = 6;  //inisialisasi pin buzzer
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;  //inisialisasi pin lcd
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin (16,2);             //memulai lcd 16x2
  Serial.begin (9600);          //memanggil serial monitor
  pinMode(pinDigital, INPUT);   //menetapkan pin A0 sebagai input
  pinMode(relay, OUTPUT);       //menetapkan pin 6 sebagai output
  pinMode(ledGreen, OUTPUT);    //menetapkan pin 7 sebagai output
  pinMode(ledYellow, OUTPUT);   //menetapkan pin 8 sebagai output
  pinMode(ledRed, OUTPUT);      //menetapkan pin 9 sebagai outputG
  pinMode(pinSpeaker, OUTPUT);  //mmenetapkan pin 10 sebagai ouput
}

void loop() {
    int dataAnalog = analogRead (pinDigital);  //membaca nilai dari pin sensor
    
    //jika nilai A0 kurang dari 500, print kata serta nyalakan led hijau dan matikan led kuning, merah dan juga relay
    if (dataAnalog < 500) { 
      lcd.setCursor(4,0);
      lcd.print("A0 : ");
      lcd.print(dataAnalog);
      lcd.setCursor(0,1);
      lcd.print("Air Sudah Cukup ");
      digitalWrite (ledGreen, HIGH);
      digitalWrite (ledYellow, LOW);
      digitalWrite (ledRed, LOW);
      digitalWrite (relay, LOW);
      }
    
     //tetapi, jika nilai A0 kurang dari 800, print kata serta nyalakan led kuning dan relay kemudian matikan led hijau dan juga merah
     else if (dataAnalog  < 800) {
      lcd.setCursor(4,0);
      lcd.print("A0 : ");
      lcd.print(dataAnalog);
      lcd.setCursor(2,2);
      lcd.print("Tanah Lembab");
      digitalWrite (ledGreen, LOW);
      digitalWrite (ledYellow, HIGH);
      digitalWrite (ledRed, LOW);
      digitalWrite (relay, HIGH);
      }
    
     //selain dari itu, hanya nyalakan led merah, relay dan buzzer
     else {
      lcd.setCursor(4,0);
      lcd.print("A0 : ");
      lcd.print(dataAnalog);
      lcd.setCursor(0,1);
      lcd.print("Perlu Tambah Air");
      digitalWrite (ledGreen, LOW);
      digitalWrite (ledYellow, LOW);
      digitalWrite (ledRed, HIGH);
      digitalWrite (relay, HIGH);
      tone(pinSpeaker, NOTE_C4, 500);
      }
      delay(500);
}
