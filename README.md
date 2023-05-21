# IoT_code_fish_drying_machine
Create a program in C language to control the fish drying machine. in which the machine has already been assembled by the customer The system will start from Getting value from the keypad button installed on the machine In order to choose the operating mode of the machine, there are 3 modes 1.meat 2.plant 3.custom    
1.meat will work by measuring the temperature and humidity values through Sensor DHT22 timer 60 minutes when work is done will notify via line and display temperature and humidity data via blynk application with the following conditions  
   - temperature<=59 oC and humidity>=20%RH : Operate heater and exhaust fan
   - temperature>=60 oC and humidity>=20%RH : Command the heater to not work and the exhaust fan to work.
   - temperature<=59 oC and humidity<=19%RH : The heater is not working and the exhaust fan is not working.
   - temperature>=60 oC and humidity<=19%RH : Command the heater to not work and the exhaust fan to not work.    
  
2.Plart will work by measuring the temperature and humidity through contact. Sensor DHT22 timer 30 minutes when work is done will notify via line and display temperature and humidity data via blynk application with the following conditions    

   - temperature<=54 oC and humidity>=20%RH : Operate heater and exhaust fan
   - temperature>=55 oC and humidity>=20%RH : Command the heater to not work and the exhaust fan to work.
   - temperature<=54 oC and humidity<=19%RH : The heater is not working and the exhaust fan is not working.
   - temperature>=55 oC and humidity<=19%RH : Command the heater to not work and the exhaust fan to not work.    
   
3.custom will work by setting time and temperature by yourself It measures the temperature and humidity values through contact. Sensor DHT22 Set the timer when work is done will notify via line and display temperature and humidity data via blynk application with the following conditions    
  
   Set t=set temperature    

   - temperature<=t oC and humidity>=20%RH : Operate heater and exhaust fan
   - temperature>=t oC and humidity>=20%RH : Command the heater to not work and the exhaust fan to work.
   - temperature<=t oC and humidity<=19%RH : The heater is not working and the exhaust fan is not working.
   - temperature>=t oC and humidity<=19%RH : Command the heater to not work and the exhaust fan to not work.    
 #
 สร้างโปรแกรมด้วย ภาษาC เพื่อควบคุมเครื่องตากปลา โดยที่ตัวเครื่องนั้นลูกค้าได้ทำการประกอบมาแล้ว ระบบการทำงานจะเริ่มจาก การรับค่าจากปุ่มkeypadที่ติดตั้งไว้ตัวเครื่อง เพื่อที่จะได้เลือกโหมดการทำงานของเครื่อง โดยมี 3 mode  1.meat 2.plant 3.custom    
   
1.meat จะทำงานโดยจะวัดค่าอุณหภูมิและค่าความชื้นสัมผัสผ่าน เซนเซอร์DHT22 จับเวลา60นาที เมื่อทำงานเสร็จ จะแจ้งเตือนผ่านline และแสดงข้อมูลอุณหภูมิและความชื้นผ่าน blynk application โดยมีเงื่อนไขดังนี้    
  - temperature<=59 oC and humidity>=20%RH : สั่งให้ฮีตเตอร์ทำงาน และ พัดลมดูดอากกาศทำงาน
  - temperature>=60 oC and humidity>=20%RH : สั่งให้ฮีตเตอร์ไม่ทำงาน และ พัดลมดูดอากกาศทำงาน
  - temperature<=59 oC and humidity<=19%RH : สั่งให้ฮีตเตอร์ไม่ทำงาน และ พัดลมดูดอากกาศไม่ทำงาน
  - temperature>=60 oC and humidity<=19%RH : สั่งให้ฮีตเตอร์ไม่ทำงาน และ พัดลมดูดอากกาศไม่ทำงาน    
  
2.plart จะทำงานโดยจะวัดค่าอุณหภูมิและค่าความชื้นสัมผัสผ่าน เซนเซอร์DHT22 จับเวลา30นาที เมื่อทำงานเสร็จ จะแจ้งเตือนผ่านline และแสดงข้อมูลอุณหภูมิและความชื้นผ่าน blynk application โดยมีเงื่อนไขดังนี้    

  - temperature<=54oC and humidity>=20%RH : สั่งให้ฮีตเตอร์ทำงาน และ พัดลมดูดอากกาศทำงาน
  - temperature>=55 oC and humidity>=20%RH : สั่งให้ฮีตเตอร์ไม่ทำงาน และ พัดลมดูดอากกาศทำงาน
  - temperature<=54 oC and humidity<=19%RH : สั่งให้ฮีตเตอร์ไม่ทำงาน และ พัดลมดูดอากกาศไม่ทำงาน
  - temperature>=55 oC and humidity<=19%RH : สั่งให้ฮีตเตอร์ไม่ทำงาน และ พัดลมดูดอากกาศไม่ทำงาน 
     
3.custom จะทำงานโดยกการกำหนดเวลาและอุณหภูมิโดยตัวเอง โดยจะวัดค่าอุณหภูมิและค่าความชื้นสัมผัสผ่าน เซนเซอร์DHT22 จับเวลาตามที่กำหนด เมื่อทำงานเสร็จ จะแจ้งเตือนผ่านline และแสดงข้อมูลอุณหภูมิและความชื้นผ่าน blynk application โดยมีเงื่อนไขดังนี้ 
  
  กำหนด t=อุณหภูมิที่กำหนด    

  - temperature<=t oC and humidity>=20%RH : สั่งให้ฮีตเตอร์ทำงาน และ พัดลมดูดอากกาศทำงาน
  - temperature>=t oC and humidity>=20%RH : สั่งให้ฮีตเตอร์ไม่ทำงาน และ พัดลมดูดอากกาศทำงาน
  - temperature<=t oC and humidity<=19%RH : สั่งให้ฮีตเตอร์ไม่ทำงาน และ พัดลมดูดอากกาศไม่ทำงาน
  - temperature>=t oC and humidity<=19%RH : สั่งให้ฮีตเตอร์ไม่ทำงาน และ พัดลมดูดอากกาศไม่ทำงาน    
