#define IR1 7
#define IR2 8
#define IR3 9
#define IR4 10
#define IR5 11
#define IR6 12
#define IR7 13
#define Motor11 A4 //Right side... 
#define Motor12 A3 //Right side
#define Motor21 A2  //Left side....
#define Motor22 A1  //Left side
#define PWMmotor1 5 //Right side... 
#define PWMmotor2 6//Left side....

int XjunctionCount=0;
int Xcount[1]={0};

int LeftTjunctioncount=0;
int LeftTjunctions[1]={0};

int IR1read=0;
int IR2read=0;
int IR3read=0;
int IR4read=0;
int IR5read=0;
int IR6read=0;
int IR7read=0;

void setup() {

 pinMode(IR1,INPUT);
 pinMode(IR2,INPUT);
 pinMode(IR3,INPUT);
 pinMode(IR4,INPUT);
 pinMode(IR5,INPUT);
 pinMode(IR6,INPUT);
 pinMode(IR7,INPUT);
  
  pinMode(Motor11,OUTPUT);
  pinMode(Motor12,OUTPUT);
  pinMode(Motor21,OUTPUT);
  pinMode(Motor22,OUTPUT);
  pinMode(PWMmotor1,OUTPUT);
  pinMode(PWMmotor2,OUTPUT);

 Serial.begin(9600);
}

void loop() {

   scan();
  
  /*Forward...........................................................*/
  if (IR1read ==1 && IR2read ==1 && IR3read == 0 && IR4read == 0 && IR5read == 0 && IR6read == 1 && IR7read == 1 ) {//ok
    forward();
  }

  if (IR1read ==1 && IR2read ==1 && IR3read == 0 && IR4read == 0 && IR5read == 0 && IR6read == 1 && IR7read == 0 ) {//ok
    forward();
     
  }
  if (IR1read ==1 && IR2read ==1 && IR3read == 1 && IR4read == 0 && IR5read == 1 && IR6read == 1 && IR7read == 1 ) {//ok
    forward();
  }
  if (IR1read ==1 && IR2read ==1 && IR3read == 1 && IR4read == 1 && IR5read == 0 && IR6read == 1 && IR7read == 1 ) {//ok
    forward();
  }
  if (IR1read ==0 && IR2read ==0 && IR3read == 0 && IR4read == 0 && IR5read == 0 && IR6read == 1 && IR7read == 1) {
   forward();
  }
  if (IR1read ==1 && IR2read ==1 && IR3read == 0 && IR4read == 1 && IR5read == 1 && IR6read == 1 && IR7read == 1 ) {//ok
    left();
     delay(20);
  }

  /*Turn Left..........................................................*/
 
  if (IR1read ==0 && IR2read ==0 && IR3read == 0 && IR4read == 0 && IR5read == 0 && IR6read ==0 && IR7read == 1) {//ok
    forward();
    delay(20);
  }
  if (IR1read ==1 && IR2read ==0 && IR3read == 0 && IR4read == 0 && IR5read == 1&& IR6read == 1&& IR7read == 1) {//ok
    left();
    delay(20);
  }
  if (IR1read ==1 && IR2read ==1 && IR3read == 0 && IR4read == 0 && IR5read == 1 && IR6read == 1&& IR7read == 1) {//ok
    left();
    delay(20);
  }
  if (IR1read ==0 && IR2read ==0 && IR3read == 0 && IR4read == 1 && IR5read == 1 && IR6read == 1&& IR7read == 1) {//ok
    left();
    delay(20);
  }
  if (IR1read == 0 && IR2read == 0 && IR3read == 1 && IR4read == 1 && IR5read == 1 && IR6read == 1 && IR7read == 1) {//ok
    left();
    delay(20);
  }
  if (IR1read == 0 && IR2read == 1 && IR3read == 1 && IR4read == 1 && IR5read == 1&& IR6read == 1&& IR7read == 1) {//ok
    left();
    delay(20);
  }
   if (IR1read ==1 && IR2read ==0 && IR3read == 0 && IR4read == 0 && IR5read == 0 && IR6read == 1 && IR7read == 1) {//ok
    left();
    delay(20);
  }
  if (IR1read ==1 && IR2read ==0 && IR3read == 0 && IR4read == 1 && IR5read == 1&& IR6read == 1&& IR7read == 1) {//ok
    left();
    delay(20);
  }
  if (IR1read ==0 && IR2read ==0 && IR3read == 0 && IR4read == 0 && IR5read == 1&& IR6read == 1&& IR7read == 1) {//ok
    left();
    delay(20);
  }
  
  /* Turn Right...........................................................*/
  
  if (IR1read ==1 && IR2read ==1 && IR3read == 0 && IR4read == 0 && IR5read == 0 && IR6read == 0 && IR7read == 0) {//ok
   // right();
   // delay(475);
    Serial.print("*** T Junctinon ***");
   CountingLeftTjunctions();
   
  } 
  if (IR1read ==1 && IR2read ==1 && IR3read == 0 && IR4read == 0 && IR5read == 0 && IR6read == 0 && IR7read == 1) {//ok
    right();
    delay(20);
  } 
  if (IR1read ==1 && IR2read ==1 && IR3read == 1 && IR4read == 0 && IR5read == 0 && IR6read == 0 && IR7read == 0) {//ok
    right();
    delay(20);
  }
  if (IR1read ==1 && IR2read ==1 && IR3read ==1 && IR4read == 1 && IR5read == 0 && IR6read == 0 && IR7read == 0) {//ok
    right();
    delay(25);
  }
  if (IR1read ==1 && IR2read ==1 && IR3read == 1 && IR4read == 0 && IR5read == 0 && IR6read == 0 && IR7read == 1) {//ok
    right();
    delay(20);
  }
  if (IR1read ==1 && IR2read ==1 && IR3read == 1 && IR4read == 1 && IR5read == 1 && IR6read == 0 && IR7read == 0) {//ok
    right();
    delay(20);
  }
  if (IR1read ==1 && IR2read ==1 && IR3read == 1 && IR4read == 1 && IR5read == 1 && IR6read == 1 && IR7read == 0) {//ok
    right();
    delay(50);
  }
  if (IR1read ==1 && IR2read ==1 && IR3read == 1 && IR4read == 1 && IR5read == 0 && IR6read == 0 && IR7read == 1) {//ok
    right();
    delay(20);
  }
   if (IR1read ==1 && IR2read ==1 && IR3read == 1 && IR4read == 0 && IR5read == 0 && IR6read == 1 && IR7read == 1) {//ok
    right();
    delay(20);
  }
  
  /*Stoping Or Back.............................................................. */
  
  if (IR1read ==1 && IR2read ==1 && IR3read == 1 && IR4read == 1 && IR5read == 1&& IR6read == 1 && IR7read == 1) {//ok
     int Bcount =(Xcount[0]);
    Serial.print("!!!!!!!WrongTURN - Back!!!!!!!");
    if(Bcount< 15){
      backward();
      delay(50);
      }
    
    
    //forward();
    // delay(20);
    
    breake();
    delay(20);
   
  }


 if (IR1read ==0 && IR2read ==0 && IR3read == 0 && IR4read == 0 && IR5read == 0 && IR6read == 0 && IR7read == 0) {//ok
      Serial.print("!!!!!!!!!X Junctinon !!!!!!!!!!");
     CountingXJunctions();
  } 

   else {
    breake();
    delay(20);
  }
}

void scan() {
  IR1read = digitalRead(IR1);
  IR2read = digitalRead(IR2);
  IR3read = digitalRead(IR3);
  IR4read = digitalRead(IR4);
  IR5read = digitalRead(IR5);
  IR6read = digitalRead(IR6);
  IR7read = digitalRead(IR7);
  
  
      Serial.print(digitalRead(IR1));
      Serial.print(digitalRead(IR2));
      Serial.print(digitalRead(IR3));
      Serial.print(digitalRead(IR4));
      Serial.print(digitalRead(IR5));
      Serial.print(digitalRead(IR6));
      Serial.print(digitalRead(IR7));
      Serial.println("  ");
}
void backward(){
    delay(30);
    digitalWrite(Motor12,HIGH);
    digitalWrite(Motor11,LOW);
    digitalWrite(Motor22,HIGH);
    digitalWrite(Motor21,LOW);
    analogWrite(PWMmotor1,90);
    analogWrite(PWMmotor2,90);
    delay(10);
  
  }


void forward() {
    digitalWrite(Motor11,HIGH);
    digitalWrite(Motor12,LOW);
    digitalWrite(Motor21,HIGH);
    digitalWrite(Motor22,LOW);
    analogWrite(PWMmotor1,120);
    analogWrite(PWMmotor2,120);
    delay(10);
}

void breake() {
    digitalWrite(Motor11,LOW);
    digitalWrite(Motor12,LOW);
    digitalWrite(Motor21,LOW);
    digitalWrite(Motor22,LOW);
}

void left() {
    digitalWrite(Motor11,HIGH);
    digitalWrite(Motor12,LOW);
    digitalWrite(Motor21,HIGH);
    digitalWrite(Motor22,LOW);
    analogWrite(PWMmotor1,120);
    analogWrite(PWMmotor2,0);
    
}
void leftTX() {
    digitalWrite(Motor11,LOW);
    digitalWrite(Motor12,HIGH);
    digitalWrite(Motor21,HIGH);
    digitalWrite(Motor22,LOW);
    analogWrite(PWMmotor1,120);
    analogWrite(PWMmotor2,40);
    
}
void rightTX() {
    digitalWrite(Motor11,HIGH);
    digitalWrite(Motor12,LOW);
    digitalWrite(Motor21,LOW);
    digitalWrite(Motor22,HIGH);
    analogWrite(PWMmotor1,40);
    analogWrite(PWMmotor2,120);
}
void right() {
    digitalWrite(Motor11,HIGH);
    digitalWrite(Motor12,LOW);
    digitalWrite(Motor21,HIGH);
    digitalWrite(Motor22,LOW);
    analogWrite(PWMmotor1,0);
    analogWrite(PWMmotor2,120);
}

void CountingXJunctions(){
  int i=0;
  while(i<10) {
  int count =(Xcount[0]);
  count=count+1;
  Xcount[0]=count;
  
  Serial.println("  ");
  Serial.print("count :");
  Serial.print(count);
  Serial.println("  ");
  
 //int StartX=(LeftTjunctions[0]);
 //if(StartX>1){
  
  if(count == 1){
    leftTX();
    delay(100);
    forward();
    delay(50);
    Serial.println("Take turn & Go Forwad...X1... ");
    }

 else if(count == 2){
    forward();
    delay(100);
    Serial.println("...... Go Forwad.... ");
    }
  
  else if(count == 3){
   forward();
    delay(100);
    Serial.println("...... Go Forwad.... ");
    }

  else if(count == 4){
    forward();
    delay(100);
    Serial.println("...... Go Forwad.... ");
   } 

 else if(count == 5){
    //left();
    //delay(475);
    forward();
    delay(100);
    Serial.println("...... Go Forwad.... ");
    
    }
 else if(count == 6){
    leftTX();
    delay(475);
    //forward();
    //delay(50);
    Serial.println("Take turn...X6... ");
    }
  else if(count == 7){
    leftTX();
    delay(470);
    //forward();
    //delay(100);
    Serial.println("Take turn...X7... ");
   }    
   else if(count == 8){
    forward();
    delay(100);
    Serial.println("...... Go Forwad.... ");
   } 
   else if(count == 9){
    forward();
    delay(100);
    Serial.println("...... Go Forwad.... ");
   }
   else if(count ==10){
   
     forward();
    delay(100);
    Serial.println("...... Go Forwad.... ");
    }  
 
  else if(count == 11){
    
    Serial.println("Take turn....X11... ");
    rightTX();
    delay(475);
    //forward();
   //delay(100);
    // right();
    //delay(475);
   }
  
  else if(count == 12){
  forward();
  delay(100);
   //right();
   // delay(475);
   Serial.println("...... Go Forwad.... ");
   }
   
   else if(count == 13){
   forward();
   delay(120); 
   //rightTX();
   // delay(482);
   Serial.println("...... Go Forwad.... ");
   }
   else if(count == 14){
  Serial.println("Take turn....X14.. ");
  rightTX();
  delay(350);
   
   //forward();
   //delay(200);
   //breake();
    
   }
   else if(count == 15){
  Serial.println("####Stop.... ");
  
  digitalWrite(Motor11,HIGH);
    digitalWrite(Motor12,LOW);
    digitalWrite(Motor21,HIGH);
    digitalWrite(Motor22,LOW);
    analogWrite(PWMmotor1,50);
    analogWrite(PWMmotor2,50);
    


   
   delay(720);
   breake(); 
   delay(1000000);
   //right();
   //delay(475);
   }
  /* else if(count == 16){
    breake();
    
   }  */      
 else{delay(100);}
  
  break;
    //}
  }
 }


void CountingLeftTjunctions(){//Wam pasata harim...
  int i=0;
  while(i<10) {
  int count =(LeftTjunctions[0]);
  count=count+1;
  LeftTjunctions[0]=count;
  
  Serial.println("  ");
  Serial.print("countLeftTs :");
  Serial.print(count);
  Serial.println("  ");
  
  if(count == 1){
    forward();
    delay(150);
    Serial.println("...... Go Forwad...From-T... ");
    }
  else if(count == 2){
    rightTX();
    delay(440);
    Serial.println("...... Take turn....From T.... ");
    }/*
  else if(count == 3){
    forward();
    delay(30);
    
    }*/
  else{
    forward();
    Serial.println("...... Go Forwad....From-T... ");
    }
  break;
  }
 }

















  
