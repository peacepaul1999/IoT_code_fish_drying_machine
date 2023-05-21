/**********lib seting**********/
#include <DHT.h>
#include <Keypad_I2C.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <TridentTD_LineNotify.h>
/**********wifi seting**********/
#define ssid "xxxx"
#define pass "xxxx"
/**********line seting**********/
#define TokenLine "xxxx"
/**********blynk seting*********/
#define BLYNK_TEMPLATE_ID "xxxx"
#define BLYNK_DEVICE_NAME "xxxx"
#define BLYNK_AUTH_TOKEN "xxxx"
/***** set Keypad *****/
#define I2CADDR 0x38
char keys[4][4]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}};
byte rowPins[] = {7,6,5,4};
byte colPins[] = {3,2,1,0};
Keypad_I2C kpd(makeKeymap(keys),rowPins,colPins,4,4,I2CADDR);
/*******LCD 20x4 seting ********/
LiquidCrystal_I2C lcd(0x27,20,4);
/******* seting sensor****/
#define DHTPIN 13
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);
#define relayPin1 16
#define relayPin2 17
/****** set variable ********/
float temperature; 
float humidity;

char num[6];
int m1=1;
int m2=3;
int hh = 0;
int mm = 0;
int t = 0;
long ms = 0;

int sum = 0;
int e = 1;
int s;

/****************************/
void wifi_set()
{
    lcd.begin();
    WiFi.begin(ssid,pass);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Connecting Wifi");
    lcd.setCursor(0, 1);
    while ( WiFi.status() != WL_CONNECTED ) {
      delay ( 500 );
      lcd.print(".");
      Serial.print (F("."));
    }
    lcd.clear();
}
void app_set(String ch)
{
   if(ch == "line") 
   {
     LINE.setToken(TokenLine);
   } 
   else if(ch == "blynk") 
   {
     Blynk.begin(BLYNK_AUTH_TOKEN,ssid,pass);
   }
     
}
void set_sensor()
{
    pinMode(relayPin1,OUTPUT);
    pinMode(relayPin2,OUTPUT);
    kpd.begin();  
}

/************** main program ****************/
void setup()
{
    Serial.begin(9600);
    wifi_set();
    app_set("line");
    app_set("blynk");  
    set_sensor();
    Serial.println("Robojax Solid State Relay ");
}

void loop()
{
    Blynk.run();
    
    float t_temp,t_humi;
    
    t_temp = get_dht("temp"); 
    t_humi = get_dht("humi"); 
    
    Serial.print(F("Humidity is: ")); Serial.println(t_temp, 1);
    Serial.print(F("Temperature is: ")); Serial.println(t_humi, 1);

    temperature = t_temp;
    humidity = t_humi;

    digitalWrite(relayPin1,HIGH);
    digitalWrite(relayPin1,HIGH);
    digitalWrite(relayPin2,HIGH);
    digitalWrite(relayPin2,HIGH);

    t1:
    show_menu();

    char key = kpd.getKey();
    if (key != NO_KEY)
    {
      switch(key)
      {
         case '1' : main_fun("1"); break;
         case '2' : main_fun("2"); break;
         case '3' : main_fun("3"); break;
         default : goto t1; break;
      }
    }

}
/********************************************/
float get_dht(String ch)
{
 
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
  Serial.println(F("Failed to read from DHT sensor!"));
  delay(1500);
  }
 
  if(ch == "temp")
    return t;
  else if(ch == "humi")
    return h;
}

void show_menu()
{
   lcd.clear();
   lcd.setCursor(1,0);
   lcd.print("**** MAINMENU ****");
   lcd.setCursor(0,1);
   lcd.print("1.MEAT");
   lcd.setCursor(0,2);
   lcd.print("2.PLANT");
   lcd.setCursor(0,3);
   lcd.print("3.CUSTOM");
}
 
void main_fun(String ch)
{
    if(ch == "1")
       meat();
    else if(ch == "2")
       plant();
    else if(ch == "3")
       custom();
}

void meat()
{
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("1.MEAT ");
  lcd.setCursor(0,1);
  lcd.print("TEMP= ");
  lcd.setCursor(7,1);
  lcd.print("55");
  lcd.setCursor(0,2);
  lcd.print("TIME= ");
  lcd.setCursor(7,2);
  lcd.print("60 min");
  lcd.setCursor(0,3);
  lcd.print("REALTIMETEMP=");
  ms=3600000;
  
  while(1)
  {
     lcd.setCursor(14,3);
     lcd.print(temperature);
     if((temperature<=59)&&(humidity>=20))
     {
        Serial.println(temperature);
        digitalWrite(relayPin1,LOW);
        Serial.println("Relay ON ");
        Serial.println(humidity);
        digitalWrite(relayPin2,LOW);
        Serial.println("FAN ON ");
     }
     if((temperature>=60)&&(humidity>=20))
     {
        Serial.println(temperature);
        digitalWrite(relayPin1,HIGH); 
        Serial.println("Relay OFF ");
        Serial.println(humidity);
        digitalWrite(relayPin2,LOW);
        Serial.println("FAN ON ");
     }
     if((temperature<=59)&&(humidity<=19))
     {
        Serial.println(temperature);
        digitalWrite(relayPin1,LOW);
        Serial.println("Relay ON ");
        Serial.println(humidity);
        digitalWrite(relayPin2,HIGH);
        Serial.println("FAN OFF ");
     }
     if((temperature>=60)&&(humidity<=19))
     {
        Serial.println(temperature);
        digitalWrite(relayPin1,HIGH);
        Serial.println("Relay OFF ");
        Serial.println(humidity);
        digitalWrite(relayPin2,HIGH);
        Serial.println("FAN OFF ");
     }
     set_app("line");
     Serial.println(ms);
     if(ms>0)
     {
        delay(1500);
        ms=ms-100;
     }
     else {
        break;
     }
  } 
}  

void plant()
{
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("2.PLANT");
  lcd.setCursor(0,1);
  lcd.print("TEMP= ");
  lcd.setCursor(7,1);
  lcd.print("50");
  lcd.setCursor(0,2);
  lcd.print("TIME= ");
  lcd.setCursor(7,2);
  lcd.print("30 min");
  lcd.setCursor(0,3);
  lcd.print("REALTIMETEMP=");
  ms=1800000;
  while(1)
  {
    lcd.setCursor(14,3);
    lcd.print(temperature);
    if((temperature<=54)&&(humidity>=20))
    {
       Serial.println(temperature);
       digitalWrite(relayPin1,LOW);
       Serial.println("Relay ON ");
       Serial.println(humidity);
       digitalWrite(relayPin2,LOW);
       Serial.println("FAN ON ");
    }
    if((temperature>=55)&&(humidity>=20))
    {
       Serial.println(temperature);
       digitalWrite(relayPin1,HIGH);
       Serial.println("Relay OFF ");
       Serial.println(humidity);
       digitalWrite(relayPin2,LOW);
       Serial.println("FAN ON ");
    }
    if((temperature<=54)&&(humidity<=19))
    {
       Serial.println(temperature);
       digitalWrite(relayPin1,LOW); 
       Serial.println("Relay ON ");
       Serial.println(humidity);
       digitalWrite(relayPin2,HIGH);
       Serial.println("FAN OFF ");
   }
   if((temperature>=55)&&(humidity<=19))
   {
      Serial.println(temperature);
      digitalWrite(relayPin1,HIGH);
      Serial.println("Relay OFF ");
      Serial.println(humidity);
      digitalWrite(relayPin2,HIGH);
      Serial.println("FAN OFF ");
   }
   set_app("line");
   Serial.println(ms);
   if(ms>0)
   {
      delay(1500);
      ms=ms-100;
   }
   else {
     break;
    }
  }
}

void custom()
{
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("3.CUSTUM");
  lcd.setCursor(0,1);
  lcd.print("TEMP=");
  lcd.setCursor(0,2);
  lcd.print("TIME= ");
  lcd.setCursor(13,2);
  lcd.print("Hr:min");
  lcd.setCursor(0,3);
  lcd.print("REALTIMETEMP=");
  lcd.setCursor(9,2);
  lcd.print(":");
  lcd.setCursor(7,1);
  while(1)
  {
     char key3 = kpd.getKey();
     if ((key3 != NO_KEY) && (key3>=48) && (key3<=57))
     {
       lcd.print(key3);
       s=key3-48;
       if(e==1)
       {
        sum=sum+(s*10);e--;
       }
       else
       {
          sum=sum+s;
          t=sum;
          break;
       }
     }
  }
  delay(500);
  lcd.setCursor(6,2);
  e=1;
  sum=0;
  while(1)
  {
     char key4 = kpd.getKey();
     if ((key4 != NO_KEY) && (key4>=48) && (key4<=57))
     {
        lcd.print(key4);
        s=key4-48;
     if(e==1){
       sum=sum+(s*10);e--;
     }
     else
     {
       sum=sum+s;
       hh=sum;
       break;
     }
    }
  }
  delay(500);
  lcd.setCursor(10,2);
  e=1;
  sum=0;
  while(1)
  {
     char key5 = kpd.getKey();
     if ((key5 != NO_KEY) && (key5>=48) && (key5<=57))
     {
        lcd.print(key5);
        s=key5-48;
        if(e==1)
        {
          sum=sum+(s*10);
          e--;
        }
        else
        {
           sum=sum+s;
           mm=sum;
           break;
        }
      }
   }
   ms=(hh*1200000)+(mm*60000);
   while(1)
   { 
      lcd.setCursor(14,3);
      lcd.print(temperature);
      if((temperature<=(t-1))&&(humidity>=20))
      {
         Serial.println(temperature);
         digitalWrite(relayPin1,HIGH); 
         Serial.println("Relay ON ");
         Serial.println(humidity);
         digitalWrite(relayPin2,HIGH); 
         Serial.println("FAN ON ");
      }
      if((temperature>=t)&&(humidity>=20))
      {
         Serial.println(temperature);
         digitalWrite(relayPin1,LOW);
         Serial.println("Relay OFF ");
         Serial.println(humidity);
         digitalWrite(relayPin2,HIGH);
         Serial.println("FAN ON ");
      }
      if((temperature<=(t-1))&&(humidity<=19))
      {
         Serial.println(temperature);
         digitalWrite(relayPin1,HIGH);
         Serial.println("Relay ON ");
         Serial.println(humidity);
         digitalWrite(relayPin2,LOW);
         Serial.println("FAN OFF ");
      }
     if((temperature>=t)&&(humidity<=19))
     {
         Serial.println(temperature);
         digitalWrite(relayPin1,LOW);
         Serial.println("Relay OFF ");
         Serial.println(humidity);
         digitalWrite(relayPin2,LOW);
         Serial.println("FAN OFF ");
     }
     set_app("line");
     Serial.println(ms);
     if(ms>0)
     {
         delay(1000);
         ms=ms-100;
     }
     else
     {
        break;
     }
  }
}

void set_app(String ch)
{
    if(ch == "line")
    {
        LINE.notify("Temperature is:"+String(temperature)+" C");
        LINE.notify("Humidity is: "+String(humidity)+" %");
    }  
    else if(ch == "blynk")
    {
        Blynk.virtualWrite(V2,String(temperature));
        Blynk.virtualWrite(V3,String(humidity));
    }
}
