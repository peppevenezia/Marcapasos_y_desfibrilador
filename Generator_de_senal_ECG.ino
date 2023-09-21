#define pin_out 6
#define suma 10
#define resta 11

int ecg[90] =
{236, 238, 236, 232, 234, 236, 238, 236, 234, 238, 238, 236, 238, 240, 238, 244, 242, 246, 256, 250, 254, 260, 250, 234,
236, 242, 240, 232, 234, 236, 238, 234, 236, 264, 318, 400, 226, 78, 0, 24, 122, 190, 248, 272, 276, 278, 276, 276, 280, 
286, 286, 288, 292, 296, 296, 302, 300, 310, 312, 318, 324, 334, 340, 348, 354, 362, 368, 374, 378, 380, 380, 372, 356, 
340, 314, 292, 278, 266, 252, 244, 242, 240, 238, 238, 234, 234, 234, 234, 236, 238};
int c=0;
int ritmo = 10;
int setting = 0;
bool taqui1 = 0;
bool normal1 = 0;
bool bradi1 = 0;
unsigned long i=0;
int senal =0;

void setup() {
  Serial.begin(9600);
  pinMode(pin_out, OUTPUT);
  pinMode(suma, INPUT);
  pinMode(resta, INPUT);  
}

void loop() {  
  if (digitalRead(suma) == HIGH){
    ritmo += 2;
    delay(150);   
  }
  else if (digitalRead(resta) == HIGH){
    ritmo = ritmo - 6;
    delay(150);
  }
   
 
  Serial.println(map(ecg[c], 0, 380, 0, 255));
  analogWrite(pin_out, map(ecg[c], 0, 380, 0, 255));

  if (c == 89){
    
    c=0;
    i = millis();
    while((millis()-i) <= 1590-97.5*ritmo) {
       if (digitalRead(suma) == HIGH){
          ritmo += 2;
          delay(150);   
       }
       else if (digitalRead(resta)){
          ritmo = ritmo - 6;
          delay(150);
       }
       Serial.println(map(ecg[89], 0, 380, 0, 255));
       analogWrite(pin_out, map(ecg[89], 0, 380, 0, 255));
        
    }
  }
  else c++;  
 
}
