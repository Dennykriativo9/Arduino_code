#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define endereco 0x27
#define colunas 16
#define linhas  2
#define vermelho 7
#define verde 6
#define sinal 2
#define buzina 8



LiquidCrystal_I2C lcd(endereco, colunas, linhas);//SDA porta A4 e SCL porta A5

int valor_sinal;

void setup() {
  pinMode(buzina, OUTPUT); // Configura o pino do buzzer como saída
  pinMode(sinal, INPUT); // Configura o pino do sensor de corrente como entrada
  pinMode(vermelho,OUTPUT);
  pinMode(verde,OUTPUT);
  Serial.begin(9600); // Inicializa a comunicação serial

  digitalWrite(vermelho,HIGH);
  digitalWrite(verde,HIGH);
  digitalWrite(buzina,HIGH);
  delay(500);
  
  digitalWrite(vermelho,LOW);
  digitalWrite(verde,LOW);
  digitalWrite(buzina,LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.begin(16, 2); // Initialize LCD

  lcd.clear();
  lcd.setCursor(0,0); // informacao do lcd
  lcd.print("SISTEMA INICIADO!"); // informacao do lcd
  lcd.setCursor(0,1); // informacao do lcd
  lcd.print("ANTI-FURTO!"); // informacao do lcd
  lcd.setCursor(7,1); // informacao do lcd
  delay(1000);
  lcd.clear();
}

void loop() 
{
  int valor_sinal = digitalRead(sinal); // Lê o valor do sensor de corrente

  Serial.print("Corrente: ");
  Serial.print(valor_sinal);
  Serial.println(" A");

  if (valor_sinal == 0)
  { 
    digitalWrite(buzina, HIGH); // Liga o buzzer
    digitalWrite(vermelho,HIGH);
    digitalWrite(verde,LOW);
    lcd.setCursor(1,0);
    lcd.print("Atividade");
    lcd.setCursor(0,1);
    lcd.print("Em Furto!");
    delay(4000); 

  }
  
  else {
    
    digitalWrite(buzina, LOW);
    digitalWrite(vermelho,LOW);
    digitalWrite(verde,HIGH);
    lcd.setCursor(1,0);
    lcd.print("Atividade");
    lcd.setCursor(0,1);
    lcd.print("Tudo em ordem!");
    delay(4000);
  }
}
