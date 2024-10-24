
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6yM6y36_I"
#define BLYNK_TEMPLATE_NAME "Dieu khien den bang dien thoai"
#define BLYNK_AUTH_TOKEN "tfg1BrksrHv9yI3y2jwonPmEFjBq_T0u"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define m11 D0
#define m12 D1
#define en1 D2


#define m21 D3
#define m22 D4
#define en2 D5

int x=550;
int y=550;

char ssid[] = "Hoang";
char pass[] = "hoang080503";

void forward()
{
  digitalWrite(m11, LOW);
  digitalWrite(m12, HIGH);
  analogWrite(en1, 600);

  digitalWrite(m21, HIGH);
  digitalWrite(m22, LOW);
  analogWrite(en2, 600);
}

void backward()
{
  digitalWrite(m11, HIGH);
  digitalWrite(m12, LOW);
  analogWrite(en1, 500);

  digitalWrite(m21, LOW);
  digitalWrite(m22, HIGH);
  analogWrite(en2, 500);
}

void right()
{
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);
  analogWrite(en1, 0);

  digitalWrite(m21, HIGH);
  digitalWrite(m22, LOW);
  analogWrite(en2, 200);
}

void left()
{
  digitalWrite(m11, LOW);
  digitalWrite(m12, HIGH);
  analogWrite(en1, 200);

  digitalWrite(m21, LOW);
  digitalWrite(m22, LOW);
  analogWrite(en2, 0);
}

void Stop()
{
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);
  analogWrite(en1, 0);
  
  digitalWrite(m21, LOW);
  digitalWrite(m22, LOW);
  analogWrite(en2, 200);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);

  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
}

BLYNK_WRITE(V1)
{
  x = param[0].asInt();
}

BLYNK_WRITE(V0)
{

  y = param[0].asInt();
}

void smartcar() {
  if (y > 700) {
    Serial.println("carForward");
    forward();
  } else if (y < 300) {
    Serial.println("carBackward");
    backward();
  } else if (x < 300) {
    Serial.println("carLeft");
    left();
  } else if (x > 700) {
    Serial.println("carRight");
    right();
  } else if (x < 700 && x > 300 && y < 700 && y > 300) {
    Serial.println("carstop");
    Stop();
  }
}

void loop()
{
  Blynk.run();
  smartcar();
}
