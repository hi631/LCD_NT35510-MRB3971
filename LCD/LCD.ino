#include "MRB3971.h" 

#define LCD_CS   5
#define LCD_RS   4
#define LCD_RD  21
#define LCD_WR  22
#define LCD_RST 23     // Set.Hi (low level reset) 
#define LCD_BL  xx     // Set.Hi (High level light)
#define PARALLEL_0  12 // Byte Inpu Start 12(-19)Pin For R/W 8bit.parallel 

MRB3971 LCD = MRB3971(LCD_CS, LCD_RS, LCD_RD, LCD_WR, LCD_RST, PARALLEL_0);
extern uint16_t POINT_COLOR, BACK_COLOR;

//--  Demo  ----------------------------
uint16_t rndw(){ return random(0,799);}
uint16_t rndh(){ return random(0,479);}
uint16_t rnd16(){ return random(0,65000);}

void drawdemo(){
  // Draw Demo
  uint16_t sx=0,sy=0,ex,ey;
  LCD.Clear(3, WHITE); LCD.Clear(3, BLACK); 
  for(int i=0;i<20;i++) { POINT_COLOR = rnd16(); LCD.Fill(rndw(),rndh(),rndw(),rndh());}
  for(int i=0;i<10;i++) { POINT_COLOR = rnd16(); LCD.DrawCircle(rndw(),rndh(),rndh()/2+50);}
  for(int i=0;i<10;i++) { POINT_COLOR = rnd16(); ex=rndw(); ey=rndh(); LCD.DrawLine(sx,sy,ex,ey); sx=ex; sy=ey;}
  for(int i=0;i<10;i++) { POINT_COLOR = rnd16(); LCD.DrawRectangle(rndw(),rndh(),rndw(),rndh());}
  for(int i=0;i<20;i++) LCD.paint(rndw(),rndh(),rnd16());
  POINT_COLOR = WHITE; LCD.ShowString(10,10,(uint8_t *)"LCD Draw Demo");
}
//--  Start UP  --------------------------
void setup() {            
  LCD.Init(); LCD.Clear(0,BLACK); BACK_COLOR=BLACK; POINT_COLOR=WHITE;
  //Serial.begin(115200); Serial.println(""); Serial.print("Start\n");
  //Serial.printf("\r\nID= %X\r\n", LCD.Read_ID());
  drawdemo(); 
}

int ledmd = 0;
void loop() {
  delay(200); ledmd = 1-ledmd;
  if(ledmd==0) LCD.ledon();  // digitalWrite(LED_BUILTIN, HIGH); 
  else         LCD.ledoff(); // digitalWrite(LED_BUILTIN, LOW);
}
