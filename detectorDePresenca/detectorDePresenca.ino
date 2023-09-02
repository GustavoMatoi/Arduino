const int trigPin = 11;
const int echoPin = 10;
const int ledAmarelo = 9;
const int buzzerPin = 8;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration *0.034/2;
  int doh = 262;
  int re = 294;
  int mi = 330;
  int fa = 349;

  if(distance < 30 && distance > 0){
    digitalWrite(ledAmarelo, HIGH);
    tone(buzzerPin, re);  
    delay(500);           
    noTone(buzzerPin);    
    delay(100);         
    tone(buzzerPin, mi);
    delay(500);
    noTone(buzzerPin);
    delay(100);
    tone(buzzerPin, fa); 
    delay(500);
    noTone(buzzerPin);
    delay(100);
  } else {
    digitalWrite(ledAmarelo, LOW);
  }
}
