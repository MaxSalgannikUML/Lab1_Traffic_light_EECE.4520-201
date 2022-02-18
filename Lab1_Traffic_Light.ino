  //Name: Max Salgannik, Phine Kim, Yolmorakatpanhcharong Lim
  //Desc: EECE.4520-201 LAB 1 Traffic Light Controller
  //Date: 2/20/22
  //Property of UML (UMASS LOWELL)

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
digitalWrite(RED, LOW);
digitalWrite(GREEN, LOW);
digitalWrite(YELLOW, LOW);
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
  delay(17000); // Wait for 20000 millisecond(s) (including the 3000 millisecond(s) with buzzer active)
  digitalWrite(RED, HIGH);
  digitalWrite(buzzer,HIGH);
  delay(3000);
  digitalWrite(RED, LOW);
  digitalWrite(buzzer,LOW);
  
  digitalWrite(GREEN, HIGH);
  delay(17000); // Wait for 20000 millisecond(s) (including the 3000 millisecond(s) with buzzer active)
  digitalWrite(GREEN, HIGH);
  digitalWrite(buzzer,HIGH);
  delay(3000);
  digitalWrite(GREEN, LOW);
  digitalWrite(buzzer,LOW);
  
  digitalWrite(YELLOW, HIGH);
  delay(3000); // Wait for 3000 millisecond(s)
  digitalWrite(YELLOW, LOW);
  digitalWrite(buzzer,HIGH);
  for (i=0;i<7;i++){        //loop adds up to 2800 millisecond(s), and final 200 millisecond(s) delay adds to the 3000 millisecond(s) needed
  delay(200); // Wait for 200 millisecond(s) 
  digitalWrite(YELLOW, HIGH);
  digitalWrite(buzzer,HIGH);
  delay(200); // Wait for 200 millisecond(s)
  digitalWrite(YELLOW, LOW);
  digitalWrite(buzzer,HIGH);
  }
  digitalWrite(buzzer,LOW);
  delay(200); // Wait for 200 millisecond(s)
  lightChange();
}
