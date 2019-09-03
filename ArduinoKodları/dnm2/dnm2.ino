#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

// lcd (rs,e,d4,d5,d6,d7);
const int analogPin = A0;
float gerilimDeger = 0;
int sensorDeger = 0;
float sicaklik = 0;


LiquidCrystal lcd(8,7,6,5,4,3);


void setup() {

   Serial.begin(9600); 
   mySerial.begin(9600);
   lcd.begin(16,2);

  
}

void loop() {
sensorDeger = analogRead(analogPin);



 gerilimDeger = analogRead(analogPin);
 gerilimDeger = (5000.0/1023.0)*sensorDeger;


 sicaklik = gerilimDeger / 10.0;

 //Serial.print("Sicaklik Degeri : ");
 //Serial.print(sicaklik);
 //Serial.println(" derece sicaklik var.");
 lcd.clear();
 lcd.print("sicaklik: ");
  lcd.print(sicaklik);

  mySerial.print("Temperature: ");
  mySerial.println(sicaklik);
  
  mySerial.print("Voltage: ");
  
  mySerial.print(gerilimDeger);
 
  
 delay(2000);
}
