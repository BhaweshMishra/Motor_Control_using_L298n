
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;
int s1  = 9;
int s2  = 10;
int in=0;




void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(s1,  OUTPUT); 
  pinMode(s2,  OUTPUT);
}


   
void forward(int x){
  
  Serial.println("Going forward");
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(s1,x);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(s2,x);
    
}

void backward(int x){
  Serial.println("Going backward");
  
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(s1,x);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(s2,x);
    
}


void left(){
  Serial.println("Going left");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  analogWrite(s1,255);
  
  
}

void right(){
  Serial.println("Going right");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(s2,255);
}

void stopp(){
  Serial.println("Stopped");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(s1,0);
  analogWrite(s2,0);
}

void loop() {
  if (Serial.available()>0){
    in = Serial.parseInt();
    
    if (in == 8){
      forward(255);
    }
    if (in == 2){
      backward(255);
    }

    if (in == 4){
      left();
    }

    if (in == 6){
      right();
    }

    if (in == 5){
      stopp();
    }
    
  }
  
}


 
