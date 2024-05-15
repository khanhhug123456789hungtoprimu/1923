#define BLYNK_TEMPLATE_ID "TMPL66uPguA-k"
#define BLYNK_TEMPLATE_NAME "cam bien to high"
#define BLYNK_AUTH_TOKEN "2U4l0-V2WqDz0PI7U6a42k3aTuRX3Szf"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "KHANH HA";  // type your wifi name
char pass[] = "1152012@ha";  // type your wifi password
int smokeA0 = A0;
int data = 0;
int sensorThres = 100;


BlynkTimer timer;

void sendSensor(){
 
 int data = analogRead(smokeA0);
 Blynk.virtualWrite(V0, data);
  Serial.print("Pin A0: ");
  Serial.println(data);


  if(data > 300){
    //Blynk.email("cambiento@gmail.com", "Cảnh báo", "Nồng Độ Khí Gas Rất Cao");
    Blynk.logEvent("gas_alert","Khí Gas Rất Cao", "Tỉ Lệ Người Do Thái Đang ở gần");
  }
}

void setup(){
  pinMode(smokeA0, INPUT);
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  //dht.begin();
  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}