#include <LiquidCrystal.h>

LiquidCrystal lcd(19, 15, 21, 22, 23, 18);

int trg_enter=25;
int echo_enter=26;

int trg_exit=12;
int echo_exit=13;

int is_active(int range,int trigger,int echo)
{
  float dist;
  digitalWrite(trigger,LOW);
  delayMicroseconds(5);        
  digitalWrite(trigger,HIGH);  
  delayMicroseconds(10);      
  digitalWrite(trigger,LOW); 
  dist=pulseIn(echo,HIGH);      
  dist = dist/58.0;                
  if(dist<range)
  {
    Serial.print(trigger==12?"lower ":"upper ");
    Serial.println(dist);
  	return 1;
  }
  else
  {
    return 0;
  }
  
}
int relay=2;
int person=0;
void setup() 
{
  pinMode(trg_enter, OUTPUT);
  pinMode(echo_enter,INPUT);

  pinMode(relay,OUTPUT);

  pinMode(trg_exit, OUTPUT);
  pinMode(echo_exit,INPUT);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("E-yantra GECK!");
  Serial.begin(115200);

}

int total_in=0;
int total_out=0;
int last=0;
int all_delay=100;
void loop() 
{
  int range=50;
  int flag=0;
  // Entered
  if(is_active(range,trg_enter,echo_enter)==1)
  {
    delay(all_delay);
    int i=1;
    while(i<=10)
    {
      if(is_active(range,trg_exit,echo_exit)==1)
      {
        Serial.println("Someone Entered");
        person++;
        break;
      }
      delay(all_delay);
      i++;
    }
  }
  if(is_active(range,trg_exit,echo_exit)==1)
  {
        delay(all_delay);
        int j=1;
        while(j<=10)
        {
          
          if(is_active(range,trg_enter,echo_enter)==1)
          {
            person--;
            Serial.println("Someone Exited");
            if(person<0)
             {
               Serial.println("Not Valid ");
               person=0;
             }
            break;
          }
          delay(all_delay);
          j++;
        }
  }
  if(person>=1)
  {
    digitalWrite(relay,LOW);
  }
  else
  {
    digitalWrite(relay,HIGH);
  }

  if(person!=last)
  {
   Serial.print("Person Count: ");
   Serial.println(person);
   lcd.setCursor(0,0);
   lcd.print("Person Count: ");
   lcd.print(person);
   
   lcd.setCursor(0,1);
   lcd.print("In : ");
   lcd.print(total_in);

   lcd.print("  Out : ");
   lcd.print(total_out);
   last=person;
  }
  delay(200);
}
