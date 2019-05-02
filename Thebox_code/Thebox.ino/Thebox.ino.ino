
#include <Servo.h>

#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);

Servo myservo;

#define trigPin 7
#define echoPin 6
//function
void thebutton();
void thelcd();
int checkpass(int password[5],int mypassword[5]);
void clearlcd1();
void clearlcd2();
void clearlcd3(int want);
void distancecheck();
void passwordcheck();
void thepassword();
void setpassword();
void setpasswordcheck();
void redbutton();
void lockstate();
void wipemypassword();

//var
const int buttonPin = 2; 
int buttonState = 0;
int default_password[] = {10,10,10,10,10};
int password[5] = {10,10,10,10,10};
int mypassword[5] = {0,0,0,0,0};
int lcdstate = 0;
float duration, distance;
int discheck;
int pos = 0;
int poscheckstat = 0;
int lcdpos = 1;
int turnpage = 1;
int check = 0;
int botton = 0;
int botton1 = 0;
int botton2 = 0;
int botton3 = 0;
int homebutton = 1;
int cursor1 = 0;
int passwordmode = 0;
int setpasswordmode = 0;
int cursorcheck = 0;
int openbox = 0;
int faillcount = 0;
  
void setup() {
  pinMode(buttonPin, INPUT);

  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.setBacklight(255);
  lcd.begin(16,2);
  myservo.attach(9);
  myservo.write(160);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  //button
  thebutton();
  //lcd
  thelcd();
      
  //password
  if(passwordmode == 1){
    distancecheck();
    passwordcheck();
  }
  if(setpasswordmode == 1){
    distancecheck();
    setpasswordcheck();
  }
  if(setpasswordmode == 2){
    distancecheck();
    setpassword();
    
  }

  if(openbox==1){
    lcd.setCursor(5,1);
    lcd.print(">LOCK<");
    if(botton2){
      lcd.clear();
      myservo.write(160);
      lcdpos = 1;
      turnpage = 1;
      openbox=0;
      delay(1000);
      homebutton = 1;
    }
  }
  if(faillcount == 5){
    lockstate();
  }
  
}
void distancecheck(){
  //เช็คระยะห่าง
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration / 2) * 0.0343;
  
  if (distance >= 100 || distance <= 2) {
     distance =99;
  }
  else {
    delay(500);
    clearlcd3(cursor1);
  }
  discheck = distance;
}
void thepassword(){
  //ฟังชั่นรับพาสเวิด
  lcd.setCursor(cursor1,2);
  lcd.print(discheck);
  if (buttonState && poscheckstat == 0) {
    int x = discheck;
     mypassword[pos] = discheck;
     delay(500);
     pos = pos+1;
     while(x>=1){
      x/=10;
      cursorcheck += 1;
     }
     cursor1 += cursorcheck+1;
     Serial.print(cursorcheck+1);
     cursorcheck = 0;
  }
}
void setpassword(){
  //ฟังชั่นตั้งพาสเวิดใหม่
  thepassword();
  if(pos==5){
    
    poscheckstat = 1;
    for(int i=0;i<5;i++)
      password[i]=mypassword[i];
    lcd.clear();
    lcd.print("Complete");
    delay(2000);
    pos = 0;
    cursor1 = 0;
    lcd.clear();
    lcdpos = 1;
    turnpage = 1;
    homebutton = 1;
    setpasswordmode = 0;
  
  }
  Serial.print(pos);
}
void setpasswordcheck(){
  //ฟังชั่นเช็คพาวเวิดเก่า
  thepassword();
  poscheckstat = 0;
  if(pos==5){
    poscheckstat = 1;
    if(checkpass(password,mypassword)){
      lcdpos = 5;
      turnpage = 1;
      setpasswordmode = 2;
      pos = 0;
      cursor1 = 0;
      delay(1000);
      poscheckstat = 0;
    }
    else if(!checkpass(password,mypassword)){
      wipemypassword();
      lcd.clear();
      lcd.print("Wrong");
      delay(2000);
      pos = 0;
      cursor1 = 0;
      lcdpos = 1;
      turnpage = 1;
      homebutton = 1;
      setpasswordmode = 0;
    }
  }
}
void passwordcheck(){
  //ฟังชั่นรับระพาวเวิดทำหรับปลดล็อค
  thepassword();
  if(pos==5){
    poscheckstat = 1;
    if(checkpass(password,mypassword)){
      myservo.write(80);
      pos = 0;
      cursor1 = 0;
      lcd.clear();
      lcd.print("Unlocked");
      homebutton = 0;
      passwordmode = 0;
      faillcount = 0;
      openbox=1;
    }
    else if(!checkpass(password,mypassword)){
      lcd.clear();
      lcd.print("Wrong");
      faillcount += 1;
      delay(2000);
      pos = 0;
      cursor1 = 0;
      lcdpos = 1;
      turnpage = 1;
      homebutton = 1;
      passwordmode = 0;
      for(int i=0;i<5;i++)
       Serial.print(mypassword[i]);
    }
  }
  poscheckstat = 0;
}
int checkpass(int password[5],int mypassword[5]){
  //ฟังชั่นเปรียบเทียบรหัสผาน 2 ชุด
  for(int i=0;i<5;i++){
    if(password[i]==mypassword[i])
      check = check+1;
  }
    if(check==5){
      check = 0;
      return 1;
    }
    else{
      check = 0;
      return 0;
    }
}
void thebutton(){
  //ฟังชั่นส่วนของการรับค่าปุ่ม
  botton1 = digitalRead(3);
  botton2 = digitalRead(4);
  botton3 = digitalRead(5);
  if(botton1 && homebutton){
    lcdpos += 1;
    if(lcdpos >= 2)
      lcdpos = 2;
    turnpage=1;
  }
  else if(botton3 && homebutton){
    lcdpos -= 1;
    if(lcdpos <= 1)
      lcdpos = 1;
    turnpage=1;
    
  }
  else if(botton2 && homebutton){
    if(lcdpos == 1){
      passwordmode = 1;
      lcdpos = 3;
      homebutton = 0;
    }
    if(lcdpos == 2){
      setpasswordmode = 1;
      if(checkpass(password,default_password)){
        lcdpos = 5;
        setpasswordmode = 2;
      }
      else{
        lcdpos = 4;
        setpasswordmode = 1;
      }
      homebutton = 0;
    }
    turnpage=1;
  }
}
void thelcd(){
    //ฟังชั่นส่วนของการแสดงผลจอ
  if(turnpage==1){
    switch(lcdpos){
      case 1:
        clearlcd1();
        lcd.setCursor(0,0);
        lcd.print("Unlock");
        lcd.setCursor(0,1);
        lcd.print("   ");
        lcd.setCursor(13,1);
        lcd.print("-->");
        lcd.setCursor(7,1);
        lcd.print("OK");
        break; 
      case 2:
        clearlcd1();
        lcd.setCursor(0,0);
        lcd.print("Set password");
        lcd.setCursor(13,1);
        lcd.print("   ");
        lcd.setCursor(0,1);
        lcd.print("<--");
        lcd.setCursor(7,1);
        lcd.print("OK");
        break;
       case 3:
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Enter password");
        break;
       case 4:
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Old password");
        break;
       case 5:
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("New password");
        break;
    }
    turnpage=0;
  }
      
}

void clearlcd1(){
  //ฟังชั่นเคลียหน้าจอบรรทัดบน
  for(int i=0;i<16;i++){
    lcd.setCursor(i,0);
    lcd.print(" ");
  }
}
void clearlcd2(){
  //ฟังชั่นเคลียหน้าจอบรรทัดล่าง
  for(int i=0;i<16;i++){
    lcd.setCursor(i,1);
    lcd.print(" ");
  }
}
void clearlcd3(int want){
  //ฟังชั่นเคลียหน้าบรรทัดจอล่าง แบบเลือกจำนวนได้
  for(int i=want;i<16;i++){
    lcd.setCursor(i,1);
    lcd.print(" ");
  }
}
void lockstate(){
  //ฟังชั่นส่วนในการล็อคหน้าจอ
  homebutton = 0;
  lcd.clear();
  lcd.print("Worng=5:locked");
  for(int i=300;i>0;i--){
    clearlcd2();
    lcd.setCursor(12,1);
    lcd.print(i/60);
    lcd.print(":");
    lcd.print(i%60);
    delay(1000);

  }
    lcd.clear();
    faillcount = 0;
    pos = 0;
    cursor1 = 0;
    lcdpos = 1;
    turnpage = 1;
    homebutton = 1;
}
void wipemypassword(){
  //รีเช็ตรหัสผ่านที่รับมา(เผื่อใช้)
  for(int i=0;i<5;i++)
      password[i]=0;
}
