int tonePin = 11;
int trigPin = 9;
int echoPin = 10;
int timer = 60000;
int rightBackward = 2;
int rightForward = 3;
int leftBackward = 4;
int leftForward = 5;
long duration;
int distance;

void read_sensor() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 micro seconds long signal and read the travel time of sound wave
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance
  distance = duration*0.34/2;
  Serial.print(distance);
  delay(100);
  Serial.print("\n"); 
}

void setup() {
  // put your setup code here, to run once:
  // Set output and input pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  // Start serial monitor
  Serial.begin(9600);
  // Waits until the taimer goes off
  delay(timer);
  // plays the song once
  midi();

  
  

}

void loop() {
  // Reads the distance and figures out if the sheep is near a wall
  read_sensor();
  if (distance > 100) {
    // If it is not then it goes forwards
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightBackward, LOW);
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, HIGH);
  }
  else if (distance < 100) {
    // If it is the sheep stops, plays the song and goes backwards
    digitalWrite(leftForward, LOW);
    digitalWrite(rightForward, LOW);
    midi();
    digitalWrite(leftBackward, HIGH);
    digitalWrite(rightBackward, HIGH);
    delay(1000);
    read_sensor();
   
  }


}
