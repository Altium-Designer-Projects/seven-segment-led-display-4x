#include <SevenSeg.h>

SevenSeg disp(4,5,6,7,8,9,10);  // https://github.com/sigvaldm/SevenSeg
//            A,B,C,D,E,F,G

int digitPins[4]={A0,A1,A2,A3};
//               D1,D2,D3,D4
//               T4,T3,T2,T1

char displaybuffer[4] = "0000";

byte _minute;
byte _second;

void setup() {

 disp.setDigitPins(4, digitPins);
 disp.setCommonAnode();
 disp.setActivePinState(HIGH,HIGH);
 disp.setTimer(2);
 disp.startTimer();

}  

void loop() {

 _minute = 15;
 _second = 26;
 
 displaybuffer[0] = _minute / 10 % 10 + 48;
 displaybuffer[1] = _minute % 10 + 48;
 displaybuffer[2] = _second / 10 % 10 + 48;
 displaybuffer[3] = _second % 10 + 48;

 disp.write(displaybuffer);

}

ISR(TIMER2_COMPA_vect){
  disp.interruptAction();
}
