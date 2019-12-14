
 boolean fire = false;
/*-------defining Inputs------*/
#define Left_S A1      // left sensor
#define Right_S A2      // right sensor
#define Forward_S A0  //forward sensor
 
/*-------defining Outputs------     */
#define LM1 6       // left motor
#define LM2 9       // left motor
#define RM1 5       // right motor
#define RM2 10       // right motor
#define pump 3      //pump motor  
#define servo 11    //servo motor



void setup()
{ 
  pinMode(Left_S, INPUT);
  pinMode(Right_S, INPUT);
  pinMode(Forward_S, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, INPUT);
  pinMode(servo, OUTPUT);

}

void put_off_fire()
{
       delay (500);
       
      analogWrite(LM1, 0);
      analogWrite(LM2, 0);
      analogWrite(RM1, 0);
      analogWrite(RM2, 0); 
       
     analogWrite(pump, 255); 
     
     delay(500);
   
            int x=0;
            int y=255;
             
             for (x; x<255; x++){
             analogWrite(servo, x);
             delay(5);
             }
             
             for (y; y>0; y--){
             analogWrite(servo, y);
             delay(5);
             }
 
    analogWrite(pump,0);
    fire=false;
}

void cal_fire(){

int Lval = analogRead(Left_S);
int Rval = analogRead(Right_S);
int Fval = analogRead(Forward_S); 

  if (Lval <= 1000 || Rval <= 1000 || Fval <= 1000){
      fire = true;
    }
    else{
      fire = false;
      }

  }

void loop(){

int Lval = analogRead(Left_S);
int Rval = analogRead(Right_S);
int Fval = analogRead(Forward_S);

            if (Lval >= 20 & Lval > Fval & Lval > Rval){

 
                          analogWrite(LM1, 10);
                          analogWrite(LM2, 0);
                          analogWrite(RM1, 0);
                          analogWrite(RM2, 0);

                          
                          }
            else if(Rval >= 20 & Rval > Fval & Rval > Lval){

                          analogWrite(LM1, 0);
                          analogWrite(LM2, 0);
                          analogWrite(RM1, 10);
                          analogWrite(RM2, 0);

                          
                          }
            else if(Fval >= 20 & Fval > Lval & Fval > Rval){

 
                          analogWrite(LM1, 10);
                          analogWrite(LM2, 0);
                          analogWrite(RM1, 10);
                          analogWrite(RM2, 0);
                          
                          cal_fire();
                          }
            else{
                  analogWrite(LM1, 0);
                  analogWrite(LM2, 0);
                  analogWrite(RM1, 0);
                  analogWrite(RM2, 0);
                  }
         while (fire == true){
             put_off_fire();
                }
       
} 
                        
