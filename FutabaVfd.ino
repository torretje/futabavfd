/* NA202SD08FA VFD Display
 Karel Reinhard 04/13/2016
 Basic code for NA202SD08FA 20x2 VFD
 With 14 pin connector see http://torretje.nl/futaba for pinout and datasheet
 */
 
//NA202SD08FA 14 pin connector 2 pins for powersupply and pin 1 and 13 NC :
const int RST = 11; //J1-14
const int WR =  10; //J1-2
const int DB0 =  2; //J1-10
const int DB1 =  3; //J1-9
const int DB2 =  4; //J1-8
const int DB3 =  5; //J1-7
const int DB4 =  6; //J1-6
const int DB5 =  7; //J1-5
const int DB6 =  8; //J1-4
const int DB7 =  9; //J1-3
//Add all data ports to an Array 
int outData[8]={DB0,DB1,DB2,DB3,DB4,DB5,DB6,DB7};



void setup() {
  // set the digital pin as output:
  pinMode(RST, OUTPUT);   
  pinMode(WR, OUTPUT);      
  pinMode(DB0, OUTPUT);      
  pinMode(DB1, OUTPUT);      
  pinMode(DB2, OUTPUT);      
  pinMode(DB3, OUTPUT);      
  pinMode(DB4, OUTPUT);      
  pinMode(DB5, OUTPUT);      
  pinMode(DB6, OUTPUT);      
  pinMode(DB7, OUTPUT);
  //RESET      
  digitalWrite(RST, 1);
  delay(500);
  digitalWrite(RST, 0);
  //Clear screen cursor home
  setData(0x14);
}

void loop()
{
  

  for(int y=0x20;y<0x7F;y++){
    setData(0x16);//Cursor Home
    for(int i=0;i<40;i++){
        setData(y);
     }
           delay(100);
  }

    for(int y=0xA0;y<0xFF;y++){
      setData(0x16);//Cursor Home
      for(int i=0;i<40;i++){
        setData(y);
        
      }
      delay(100);
    }

}

void setData(byte data){
   int i=0;
   for (byte mask = B00000001; mask>0; mask <<= 1) { 
     if (data & mask){ // if bitwise AND resolves to true
       digitalWrite(outData[i],HIGH);
    }else{ //if bitwise and resolves to false
       digitalWrite(outData[i],LOW);
    }
    i++;
  }
  digitalWrite(WR, 1);
  delayMicroseconds(250);
  digitalWrite(WR, 0);
}
