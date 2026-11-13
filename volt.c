sbit LCD_RS at RB2_bit;
sbit LCD_EN at RB3_bit;
sbit LCD_D4 at RB4_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D7 at RB7_bit;

sbit LCD_RS_Direction at TRISB2_bit;
sbit LCD_EN_Direction at TRISB3_bit;

sbit LCD_D4_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB7_bit;

// End LCD module connections
float tmp;

char txt[15];
void Main()
{
  Lcd_Init();                          // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);                 // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);            // Cursor off
  ADCON1=0b00000000;
while (1)
{
     tmp = ADC_Read(0);
     tmp=tmp*5/1023;
     FloatToStr(tmp,txt);
     txt[4]=0;
     Lcd_Out(1,1,txt);
	   delay_ms(1000);
     Lcd_Cmd(_LCD_CLEAR);
}
}