#include <Wire.h>
#include <LiquidCrystal_I2C.h>

float voltage;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);   
  lcd.begin(16, 2);
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print(" SISTEMA EOLICO ");
  lcd.setCursor(0, 1);
  lcd.print(" INICIALIZANDO ");
  delay(3000);
  lcd.clear();

}
 
void loop()
{
  unsigned int x=0;
  float AcsValue=0.0,signal=0.0,power=0.0,Samples=0.0,AvgAcs=0.0,AcsValueF=0.0;
  for (int x = 0; x < 10; x++)          //Get 10 samples
  {
    AcsValue = analogRead(A0); 
    signal = analogRead(A1);           
    Samples = Samples + AcsValue;        //Add samples together
    delay (3);                           // let ADC settle before next sample 3ms
  }
  AvgAcs=Samples/10.0;                   //Taking Average of Samples
  voltage=signal*(5.0 / 1024.0);         //((AvgAcs * (5.0 / 1024.0)) is converitng the read voltage in 0-5 volts
  power = (AvgAcs*AvgAcs*voltage)/1000000;

  Serial.print("Raw Voltage:");
  Serial.print(voltage);
  AcsValueF = (-1)*((2.5 - voltage)*1000/0.185); //2.5 is offset,,,   0.185v is rise in output voltage when 1A current flows at input
  Serial.print("\t");
  Serial.print("Motor Current :");
  Serial.print(AcsValueF);               //Print the read current on Serial monitor
  Serial.println(" mA");
  delay(500);

 lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.print(voltage, 1);
  lcd.print("V I:");
  lcd.print(AcsValueF, 2);
  lcd.print("A ");

  lcd.setCursor(0, 1);
  lcd.print("P:");
  lcd.print(power, 1);
  lcd.print("W");

}