#define F_CPU = 16000000;
int s1=A0;
int s2=A1;
int s3=A2;
int s4=A3;
int s5=A4;
int l1=8;
int l2=9;
int r1=10;
int r2=11;
int a=0,b=0,c=0,d=0,e=0,x=0,l=0,r=0,s=0;
int ref=500;
void setup()
{
  Serial.begin(9600);
pinMode(s1,INPUT);
pinMode(s2,INPUT);
pinMode(s3,INPUT);
pinMode(s4,INPUT);
pinMode(s5,INPUT);
pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(r1,OUTPUT);
pinMode(r2,OUTPUT);
}

void loop()
{
  int test=0;
if(abs((analogRead(s1)-analogRead(s4)))<100&&abs((analogRead(s4)-analogRead(s5)))>700)
{
  l=l+1;
  test=1;
  }
if(abs((analogRead(s5)-analogRead(s2)))<100&&abs((analogRead(s2)-analogRead(s1)))>700)
{
  r=r+1;
  test=1;
}
if(abs(analogRead(s1)>700 && analogRead(s5))>700)
{
  s=s+1;
  test=1;
}
if(test==0)
{
  linefoll();
}
if(l==1)
{
  leftsharp();
linefoll();
}
if(l==2)
{
  straight();
linefoll();
}
if(l==3)
{leftsharp();
linefoll();}
if(l==4)
{leftsharp();
linefoll();}
if(r==1)
{straight();
linefoll();}
if(r==2)
{rightsharp();
linefoll();}
if(r==3)
{rightsharp();
linefoll();}
if(r==4)
{straight();
linefoll();}
if(r==5)
{rightsharp();
linefoll();}
if(r==6)
{rightsharp();
linefoll();}
if(s==1)
{straight();
linefoll();
}}
void linefoll()
{
  if(analogRead(s1)<ref)
  a=0;
  if(analogRead(s1)>ref)
  a=1;
  if(analogRead(s2)<ref)
  b=0;
  if(analogRead(s2)>ref)
  b=1;
  if(analogRead(s3)<ref)
  c=0;
  if(analogRead(s3)>ref)
  c=1;
  if(analogRead(s4)<ref)
  d=0;
  if(analogRead(s4)>ref)
  d=1;
  if(analogRead(s5)<ref)
  e=0;
  if(analogRead(s5)>ref)
  e=1;
  x=(a*10+b*20+c*30+d*40+e*50)/(a+b+c+d+e);
  if(x==30)
  {
    digitalWrite(l1,HIGH);
digitalWrite(l2,LOW);
digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);
}
  if(x>30)
  {
    digitalWrite(l1,HIGH);
digitalWrite(l2,LOW);
digitalWrite(r1,LOW);
digitalWrite(r2,LOW);
}
  if(x<30)
 {
  digitalWrite(l1,LOW);
digitalWrite(l2,LOW);
digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);} 
}
void straight()
{
  digitalWrite(l1,HIGH);
digitalWrite(l2,LOW);
digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);
delay(750);
}
void leftsharp()
{
  digitalWrite(l1,LOW);
digitalWrite(l2,LOW);
digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);
delay(2000);
}
void rightsharp()
{
  digitalWrite(l1,HIGH);
digitalWrite(l2,LOW);
digitalWrite(r1,LOW);
digitalWrite(r2,LOW);
delay(2000);
}

