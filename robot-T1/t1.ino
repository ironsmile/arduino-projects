/*
*** Arduino i L293D kontrolirat 2 motora ***

Nikvi prava zapazeni - Simeon Ianchev / RobotevCom 2009

*/

int motor1APin = 4; //izbor na pin za 1A (v sluchaq Arduino pin 4)
int motor2APin = 5; //izbor na pin za 2A
int motor1ENPin = 9; //izbor na pin za 1,2EN
int motor3APin = 6; //izbor na pin za 3A
int motor4APin = 7; //izbor na pin za 4A
int motor2ENPin = 10; //izbor na pin za 3,4EN

void setup() 
{

pinMode(motor1APin, OUTPUT); //zadawa che shte izpolzvame EN i A pinovete kato izhodi
pinMode(motor2APin, OUTPUT);
pinMode(motor1ENPin, OUTPUT);
pinMode(motor3APin, OUTPUT);
pinMode(motor4APin, OUTPUT);
pinMode(motor2ENPin, OUTPUT);

}

void loop() {

/* tazi chast ot koda
vyrti motorite po-byrzo v ednata posoka
*/

analogWrite(motor1ENPin, 255); //kontrolira skorostta na vyrtene (priema stojnosti ot 0 do 255)
digitalWrite(motor1APin, HIGH); //zaedno s dolniyq red kontrolira na posokata na vyrtene
digitalWrite(motor2APin, LOW);
analogWrite(motor2ENPin, 255);
digitalWrite(motor3APin, LOW);
digitalWrite(motor4APin, HIGH);
delay(3000); //zadyrja motorite vklyucheni za 3 sekundi

/*tazi chast spira vyrteneto
na motorite
*/

analogWrite(motor1ENPin, 0);
digitalWrite(motor1APin, LOW);
digitalWrite(motor2APin, LOW);
analogWrite(motor2ENPin, 0);
digitalWrite(motor3APin, LOW);
digitalWrite(motor4APin, LOW);
delay(2000); //zadyrja motorite izklyucheni za 2 sekundi

/* tazi chast ot koda
namalya skorostta na motorite i obrushta posokata im na vyrtene
*/

analogWrite(motor1ENPin, 255);
digitalWrite(motor1APin, LOW);
digitalWrite(motor2APin, HIGH);
analogWrite(motor2ENPin, 255);
digitalWrite(motor3APin, HIGH);
digitalWrite(motor4APin, LOW);
delay(3000); //zadyrja motorite vklyucheni za 3 sekundi

/*tazi chast spira vyrteneto
na motorite
*/

analogWrite(motor1ENPin, 0);
digitalWrite(motor1APin, LOW);
digitalWrite(motor2APin, LOW);
analogWrite(motor2ENPin, 0);
digitalWrite(motor3APin, LOW);
digitalWrite(motor4APin, LOW);
delay(2000); //zadyrja motorite izklyucheni za 2 sekundi

}