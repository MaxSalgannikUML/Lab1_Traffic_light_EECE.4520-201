#define RED 3
#define GREEN 5
#define YELLOW 6
int buttonpin = 2;
int buzzer = 7;
int i;
void setup() {
  // put your setup code here, to run once:
pinMode(buttonpin, INPUT_PULLUP);
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(YELLOW, OUTPUT);
digitalWrite(GREEN, LOW);
digitalWrite(YELLOW, LOW);
digitalWrite(RED, LOW);
pinMode(buzzer,OUTPUT);
}
  // put your main code here, to run repeatedly:
void loop()
{
  if (digitalRead(buttonpin) == LOW){
        delay(15); // software debounce
        if (digitalRead(buttonpin) == LOW) {
             lightChange();
        }
    }
  digitalWrite(RED, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(RED, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  }

void lightChange()
{
  digitalWrite(RED, HIGH);
  delay(17000); // Wait for 20000 millisecond(s)
  digitalWrite(RED, HIGH);
  digitalWrite(buzzer,HIGH);
  delay(3000);
  digitalWrite(RED, LOW);
  digitalWrite(buzzer,LOW);
  digitalWrite(GREEN, HIGH);
  delay(17000); // Wait for 20000 millisecond(s)
  digitalWrite(GREEN, HIGH);
  digitalWrite(buzzer,HIGH);
  delay(3000);
  digitalWrite(GREEN, LOW);
  digitalWrite(buzzer,LOW);
  digitalWrite(YELLOW, HIGH);
  delay(3000); // Wait for 3000 millisecond(s)
  digitalWrite(YELLOW, LOW);
  digitalWrite(buzzer,HIGH);
  for (i=0;i<7;i++){
  delay(200); // Wait for 200 millisecond(s)
  digitalWrite(YELLOW, HIGH);
  digitalWrite(buzzer,HIGH);
  delay(200); // Wait for 200 millisecond(s)
  digitalWrite(YELLOW, LOW);
  digitalWrite(buzzer,HIGH);
  }
  delay(200); // Wait for 200 millisecond(s)
  digitalWrite(buzzer,LOW);
  lightChange();
}
