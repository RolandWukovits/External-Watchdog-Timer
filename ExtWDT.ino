
// external Watchdog Timer
#define ExtWDTpin 8        // enter the digital pin of your MC
unsigned long ExtWDTstartmillis;
unsigned long ExtWDTinterval=5000;         // interval of ext. WDT reset puls in ms (set max. 5000)


void setup() {
  // put your setup code here, to run once:

// Ext WDT
  pinMode(ExtWDTpin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Main Watchdog reset
  resetExtWDT();
  
}


void resetExtWDT() {

 if (millis()>=(ExtWDTstartmillis+ExtWDTinterval)) {
    digitalWrite(ExtWDTpin,HIGH);
    delay(50);                               // you can try different puls width
    digitalWrite(ExtWDTpin,LOW);
    ExtWDTstartmillis=millis();
 }

} 
