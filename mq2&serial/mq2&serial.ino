 #include <MQ2.h>
#define Analog_Input A0
#define buzzer 2
int led = 13;
float lpg, co, smoke;
//MQ2 mq2(Analog_Input);
void setup() 
{
  Serial.begin(9600);
  //mq2.begin();
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(Analog_Input,INPUT_PULLUP);
}
void loop() 
{
   //float* values= mq2.read(true); //set it false if you don't want to print the values in the Serial
  int val=digitalRead(Analog_Input) ;
  Serial.println("__________________");
  Serial.print("val: ");
  Serial.println(val);
  if(val==HIGH){
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    digitalWrite(led, LOW);
    val=0;
  }

  
 /* //lpg = values[0];
  lpg = mq2.readLPG();
  //co = values[1];
  co = mq2.readCO();
  //smoke = values[2];
  smoke = mq2.readSmoke();

  Serial.print("LPG:");
  Serial.println(lpg);
  Serial.print(" CO:");
  Serial.println(co);
  Serial.print("SMOKE:");
  Serial.print((smoke*100.0)/1000000.0);
  Serial.println(" %");
  Serial.println(" ");
  Serial.println(" ");*/
  delay(1000);
}


