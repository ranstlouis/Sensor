const int xP = 16;
const int yP = 5;
float err_estimate, err_measure,current_estimate, last_estimate, kalman_gain,q;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(xP, INPUT);
  pinMode(yP, INPUT);
  err_estimate = 1; /*P*/
  err_measure = .000734;  /*R*/
  q = 0.0001; /*Q*/
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int px, py;
  float ax, ay;
  px = pulseIn(xP, HIGH);
  py = pulseIn(yP, HIGH);

  ax = ((px / 10) - 500) * 8;
  ay = ((py / 10) - 500) * 8;
  ay = map(ay,-1048,964,-9.8,9.8);
  ax = map(ax,-1048,904,-9.8,9.8);
  kalman_gain = err_estimate/(err_estimate + err_measure); /*K = P/(P+R)*/
  current_estimate = last_estimate + kalman_gain * (ay - last_estimate); /*x = x + K(y-x), ax = y(measured)*/
  err_estimate =  (1.0 - kalman_gain) * (err_estimate + q); 
  last_estimate = current_estimate;
  

  //Serial.print(ax);
  Serial.print("\t");
  Serial.print(current_estimate);
  Serial.print("\t");
  Serial.print(ay);
  Serial.print("\t");
  Serial.println();
  delay(100);
}



float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
