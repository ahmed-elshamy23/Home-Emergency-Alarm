#define motor 10
#define motorG 9
void setup() {
pinMode(motor, OUTPUT);
pinMode(motorG, OUTPUT);
}

void loop() {
digitalWrite(motor , HIGH );
digitalWrite(motorG , LOW );
}