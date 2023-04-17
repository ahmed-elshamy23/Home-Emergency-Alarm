int vib_pin=2;
int led_pin=13;
void setup() {
  pinMode(vib_pin,INPUT);
  pinMode(led_pin,OUTPUT);
  Serial.begin(9600);
  Serial.println("peace");
}

void loop() {
  int val;
  val=digitalRead(vib_pin);
  //Serial.print("val=");
  //Serial.println(val);
  if(val==1)
  {
    digitalWrite(led_pin,HIGH);
    Serial.println("shaken! "); 
    delay(1000);
  }else if(val==0){
    digitalWrite(led_pin,LOW);
    Serial.println("peace");
    delay(1000);
  }
   
}