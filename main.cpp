#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
char auth[] = "9fwK3H2w0Ix8wH-mDRtfYVT8KK4kZrgP";
/* WiFi credentials */
char ssid[] = "Sneha's Galaxy M21";
char pass[] = "snehasneha";
SimpleTimer timer;
int mq135 = A0; // smoke sensor is connected with the analog pin A0
int data = 0;
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, getSendData);
}
void loop()
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();

}
/***************************************************
   Send Sensor data to Blynk
 **************************************************/
void getSendData()
{
  //data = analogRead(mq135);
  data = random(500, 1000);


  Blynk.virtualWrite(V2, data);
  Serial.println(data);
  //virtual pin V3
  if (data > 600 )
  {
    Blynk.notify("Smoke Detected!!!");

  }
}
