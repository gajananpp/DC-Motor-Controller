#include<reg52.h>
#include<lcd.h>


//LEDs defined
sbit led_1 = P2^0;
sbit led_2 = P2^1;
sbit led_3 = P2^2;
sbit led_4 = P2^3;
//LCD control pins defined
sbit RS = P3^0;
sbit EN = P3^2;
sbit D0 = P0^0;
sbit D1 = P0^1;
sbit D2 = P0^2;
sbit D3 = P0^3;
sbit D4 = P0^4;
sbit D5 = P0^5;
sbit D6 = P0^6;
sbit D7 = P0^7;
//define motor control pins
sbit motor_pin_1 = P2^5;
sbit motor_pin_2 = P2^6;




unsigned int f = 1;

void delay(int);
void kydelay(void);

void main() {
	int i,j;
	P2=0x00;
	P0=0x00;
	P1=0xFF;
	Lcd8_Init();
	for(i=0;i<30000;i++) {
		if(P1!=0xFF) {
			goto up;
		}
	Lcd8_Clear();
	Lcd8_Set_Cursor(1,4);
	Lcd8_Write_String("DC Motor");
	Lcd8_Set_Cursor(2,3);
	Lcd8_Write_String("Controller");
		for(i=0;i<15;i++)
    {
      delay(100);
      Lcd8_Shift_Left();
			if(P1!=0xFF) {
				goto up;
			}
    }
	Lcd8_Clear();
	Lcd8_Set_Cursor(1,15);
	Lcd8_Write_String("DC Motor");
	Lcd8_Set_Cursor(2,14);
	Lcd8_Write_String("Controller");
		for(i=0;i<12;i++)
    {
      delay(100);
      Lcd8_Shift_Left();
			if(P1!=0xFF) {
				goto up;
			}
    }
	}
		
	
	up:	while(1) {
		if(P1==0xFE) {
			kydelay();
			Lcd8_Clear();
			Lcd8_Set_Cursor(1,2);
			Lcd8_Write_String("Motor Start");
			for(i=0;i<15;i++)
    {
      delay(50);
      Lcd8_Shift_Left();
    }
    	Lcd8_Clear();
			Lcd8_Set_Cursor(1,15);
			Lcd8_Write_String("Motor Start");
		for(i=0;i<12;i++)
    {
      delay(50);
      Lcd8_Shift_Left();
    }
			led_1 = 1;
			led_2 = 0;
			led_3 = 1;
			led_4 = 0;
			motor_pin_1 = 1;
			motor_pin_2 = 0;
			f =1;
		}
		else if(P1==0xFD) {
			kydelay();
			Lcd8_Clear();
			Lcd8_Set_Cursor(1,3);
			Lcd8_Write_String("Motor Stop");
			for(i=0;i<15;i++)
    {
      delay(50);
      Lcd8_Shift_Left();
    }
    	Lcd8_Clear();
			Lcd8_Set_Cursor(1,15);
			Lcd8_Write_String("Motor Stop");
		for(i=0;i<12;i++)
    {
      delay(50);
      Lcd8_Shift_Left();
    }
			led_1 = 0;
			led_2 = 1;
			led_3 = 0;
			led_4 = 0;
			motor_pin_1 = 1;
			motor_pin_2 = 1;
			f =1;
		}
		else if(P1==0xFB) {
			kydelay();
			Lcd8_Clear();
			Lcd8_Set_Cursor(1,2);
			Lcd8_Write_String("Continuous Mode");
	
			for(i=0;i<15;i++)
    {
      delay(50);
      Lcd8_Shift_Left();
    }
    	Lcd8_Clear();
			Lcd8_Set_Cursor(1,15);
			Lcd8_Write_String("Continuous Mode");
		for(i=0;i<14;i++)
    {
      delay(50);
      Lcd8_Shift_Left();
    }
			Lcd8_Clear();
			Lcd8_Set_Cursor(1,1);
			Lcd8_Write_String("Continuous Mode");
			Lcd8_Set_Cursor(2,5);
			Lcd8_Write_String("Default");
			
			led_1 = 1;
			led_2 = 0;
			led_3 = 1;
			led_4 = 0;
			motor_pin_1 = 1;
			motor_pin_2 = 0;
			f=1;
		}
		else if(P1==0xF7) {
			kydelay();
			Lcd8_Clear();
			Lcd8_Set_Cursor(1,2);
			Lcd8_Write_String("Reverse Mode");
			for(i=0;i<15;i++)
    {
      delay(50);
      Lcd8_Shift_Left();
    }
    	Lcd8_Clear();
			Lcd8_Set_Cursor(1,15);
			Lcd8_Write_String("Reverse Mode");
		for(i=0;i<13;i++)
    {
      delay(50);
      Lcd8_Shift_Left();
    }
			led_1 = 1;
			led_2 = 0;
			led_3 = 0;
			led_4 = 1;
			motor_pin_1 = 0;
			motor_pin_2 = 1;
			f=1;
		}
		else if(P1==0xEF) {
			kydelay();
			Lcd8_Clear();
			Lcd8_Set_Cursor(1,2);
			Lcd8_Write_String("Jogging Mode");
			for(i=0;i<15;i++)
    {
      delay(50);
      Lcd8_Shift_Left();
    }
    	Lcd8_Clear();
			Lcd8_Set_Cursor(1,15);
			Lcd8_Write_String("Jogging Mode");
		for(i=0;i<13;i++)
    {
      delay(50);
      Lcd8_Shift_Left();
    }
			led_1 = 1;
			led_2 = 0;
			f=0;
			while(1) {
				
			//	motor_pin_1 = 1;
			//	motor_pin_2 = 1;
				
//				for(i=0;i<3800;i++) {
//					for(j=0;j<100;j++) {
//						if(P1!=0xFF) {
//							goto up;
//						}
//					}
//				}
				led_3 = 1;
				led_4 = 0;
				motor_pin_1 = 1;
				motor_pin_2 = 0;
				for(i=0;i<5000;i++) {
					for(j=0;j<100;j++) {
						if(P1!=0xFF) {
							goto up;
						}
					}
				}
//				motor_pin_1 = 0;
//				motor_pin_2 = 0;
//				
//				for(i=0;i<3800;i++) {
//					for(j=0;j<100;j++) {
//						if(P1!=0xFF) {
//							goto up;
//						}
//					}
//				}
				led_3 = 0;
				led_4 = 1;
				motor_pin_1 = 0;
				motor_pin_2 = 1;
				for(i=0;i<5000;i++) {
					for(j=0;j<100;j++) {
						if(P1!=0xFF) {
							goto up;
						}
					}
				}
			}
		
		}
		
	}
	
	
	
}

void kydelay() {
	int a,b;
	for(a=0;a<50;a++) {
		for(b=0;b<1000;b++) {
		}
	}
}

void delay(int k) {
	int i,j;
	for(i=0;i<k;i++){
		for(j=0;j<100;j++) {}
	}
}

