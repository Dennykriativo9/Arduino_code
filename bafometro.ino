#define sensor_mq3 0
#define led_vermelho 8
#define led_verde 9
#define rele 10
#define buzina 11


float valor_sensor ; 


void setup()
{

  pinMode(led_vermelho,OUTPUT);
  pinMode(led_verde,OUTPUT);
  pinMode(buzina,OUTPUT);
  pinMode(rele,OUTPUT);
  
 }

 void loop()
 {

  valor_sensor = analogRead(sensor_mq3);
  delay(4000);

  if (valor_sensor >= 400)
  {
    delay(2000);
    digitalWrite(led_vermelho,HIGH);
    digitalWrite(rele,LOW);
    digitalWrite(buzina,HIGH);
    delay(15000);
  
  }
  if (valor_sensor =< 120)
  {
    
    delay(2000);
    digitalWrite(led_vermelho,LOW);
     digitalWrite(led_verde,LOW);
    digitalWrite(rele,HIGH);
    digitalWrite(buzina,LOW);
    delay(15000);
    
  }
  else
  {
    
    digitalWrite(buzina,HIGH);
    delay(2000);
    digitalWrite(buzina,LOW);
    delay(2000);
    
  }
  
 }
