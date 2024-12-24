#define in1 2 
#define in2 3
#define in3 4
#define in4 5
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);  
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8,HIGH);
}
int x,y,x1,y1,m1,m2;
void loop() {
 if (Serial.available()) {
   char c = Serial.read();
if(c=='A'){
     x=Serial.parseInt();
    }
    switch (c) {
      case 'F':
        motor(x,x);
        break;
      case 'B':
       motor(-x,-x);
        break;
      case 'L':
        motor(x,-x);
        break;
      case 'R':
        motor(-x,x);
        break;
      case 'G':
        motor(x,x/2);
        break;
      case 'I':
        motor(x/2,x);
        break;
      case 'H':
        motor(-x,-x/2);
        break;
      case 'J':
        motor(-x/2,-x);
        break;
        case 'S':
        motor(0,0);
        break;
        case 'X':
        digitalWrite(8,LOW);
        break;
        case 'x':
        digitalWrite(8,HIGH);
        break;
    }

   

 }
 

}
void motor(int i,int j) {
  if(i>255){
    i=255;
    }
    if(i<-255){
    i=-255;
    }
    if(j>255){
    j=255;
    }
     if(j<-255){
    j=-255;
    }
  if(i>0){
     analogWrite(in1,i);
     analogWrite(in2,0);
    }else{
      analogWrite(in1,0);
     analogWrite(in2,i*(-1));
      }
    if(j>0){
     analogWrite(in3,j);
     analogWrite(in4,0);
    }else{
      analogWrite(in3,0);
     analogWrite(in4,j*(-1));
      }
}
