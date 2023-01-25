#include "mbed.h"
#include "platform/mbed_thread.h"
#include "LCD.h"
#define WARTEN 20ms
#define WARTEN2 2000ms

lcd mylcd;
PortInOut zeilen(PortB,0xF0);
PortIn spalten(PortB,0x0F);
PortOut pc(PortC,0xFF);
DigitalOut pcenable(PC_11);
char ausgabe;

void ausgabezeile()
{
    /*while (zeilen+spalten==0b01111111) 
    { ausgabe='-';
    mylcd.cursorpos(0); //plaziert den Cursor
    mylcd.printf("Taste %c", ausgabe);
    }*/
    if (spalten == 0b1111) {
        ausgabe='-';
        mylcd.cursorpos(0); 
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b01000000;
    }
    //PB7 = 0
    while(zeilen+spalten==0b01110111) {
        ausgabe='1';
        mylcd.cursorpos(0); //plaziert den Cursor
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b00000110;
    }
    while (zeilen+spalten == 0b01111011) {
        ausgabe='2';
        mylcd.cursorpos(0); 
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b01011011;
    }
    while (zeilen+spalten == 0b01111101) {
        ausgabe='3';
        mylcd.cursorpos(0); 
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b01001111;
    }
    while (zeilen+spalten == 0b01111110) {
        ausgabe='A';
        mylcd.cursorpos(0); 
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b01110111;
    }
    //PB6 = 0
    while(zeilen+spalten==0b10110111) {
        ausgabe='4';
        mylcd.cursorpos(0); //plaziert den Cursor
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b01100110;
    }
    while (zeilen+spalten == 0b10111011) {
        ausgabe='5';
        mylcd.cursorpos(0); 
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b01101101;
    }
    while (zeilen+spalten == 0b10111101) {
        ausgabe='6';
        mylcd.cursorpos(0); 
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b01111101;
    }
    while (zeilen+spalten == 0b10111110) {
        ausgabe='B';
        mylcd.cursorpos(0); 
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b01111111;
    }
    //PB5 = 0
    while(zeilen+spalten==0b11010111) {
        ausgabe='7';
        mylcd.cursorpos(0); //plaziert den Cursor
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b00000111;
    }
    while (zeilen+spalten == 0b11011011) {
        ausgabe='8';
        mylcd.cursorpos(0); 
        mylcd.printf("Taste %c", ausgabe);
        
        pc = 0b01111111;
    }
    while (zeilen+spalten == 0b11011101) {
        ausgabe='9';
        mylcd.cursorpos(0); 
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b01101111;
    }
    while (zeilen+spalten == 0b11011110) {
        ausgabe='C';
        mylcd.cursorpos(0); 
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b00111001;
    }
    //PB4 = 0
    while(zeilen+spalten==0b11100111) {
        ausgabe='*';
        mylcd.cursorpos(0); //plaziert den Cursor
        mylcd.printf("Taste %c", ausgabe);
    }
    while (zeilen+spalten == 0b11101011) {
        ausgabe='0';
        mylcd.cursorpos(0); 
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b00111111;
    }
    while (zeilen+spalten == 0b11101101) {
        ausgabe='#';
        mylcd.cursorpos(0); 
        mylcd.printf("Taste %c", ausgabe);
    }
    while (zeilen+spalten == 0b11101110) {
        ausgabe='D';
        mylcd.cursorpos(0); 
        mylcd.printf("Taste %c", ausgabe);

        pc = 0b00111111;
    }
}

// main() runs in its own thread in the OS
int main(){


    zeilen.output();
    zeilen.mode(OpenDrain);
    spalten.mode(PullUp);
    mylcd.clear();


    mylcd.cursorpos(0); 
    mylcd.printf("start..");
    pcenable = 1;

    ThisThread::sleep_for(WARTEN2);
 

    while (true) {

        zeilen=0b01111111;
        ThisThread::sleep_for(WARTEN);
        ausgabezeile();

        zeilen=0b10111111;
        ThisThread::sleep_for(WARTEN);
        ausgabezeile();

        zeilen=0b11011111;
        ThisThread::sleep_for(WARTEN);
        ausgabezeile();

        zeilen=0b11101111;
        ThisThread::sleep_for(WARTEN);
        ausgabezeile();

    }
}

 