#define inputpin A0
int reading ;
float temp ; 
void setup() {
  pinMode(inputpin,INPUT);
  Serial.begin(9600);
}
void loop() {
  reading = analogRead(inputpin)  ;
 // temp = map(reading , 0,1023,-60,150);
  temp= (reading*(5.0f/1024))*100.0f;
  Serial.print("temp sensor: ");
  Serial.println(temp);
  //Serial.print(" sensor reading : ");
  //Serial.println(reading);
  Serial.println("___________________");
  delay(1000);
}
