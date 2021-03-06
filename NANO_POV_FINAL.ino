/*
  POV LED - código para controle de leds junto ao persistencia visual.

  funçoes para acesso igual a um display

  Data 18/09/2016 Prudentópolis-Pr Brasil

  *criador : Emanuel nastroga.
  *
  *ANALISE e DESENVOLVIMENTO de SISTEMAS .ADS
  * 
  *emanuelnastroga@hotmail.com
  *
  *Para fins educacionais.
  *
  *
  
*/



 byte ascii[128][8] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0000 (nul)
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0001
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0002
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0003
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0004
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0005
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0006
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0007
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0008
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0009
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000A
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000B
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000C
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000D
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000E
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000F
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0010
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0011
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0012
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0013
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0014
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0015
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0016
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0017
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0018
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0019
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001A
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001B
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001C
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001D
   { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001E
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001F
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // ' '
    { 0x00, 0x06, 0x5F, 0x5F, 0x06, 0x00, 0x00, 0x00},  // '!'
    { 0x00, 0x07, 0x07, 0x00, 0x07, 0x07, 0x00, 0x00},  // '"'
    { 0x14, 0x7F, 0x7F, 0x14, 0x7F, 0x7F, 0x14, 0x00},  // '#'
    { 0x24, 0x2E, 0x6B, 0x6B, 0x3A, 0x12, 0x00, 0x00},  // '$'
    { 0x46, 0x66, 0x30, 0x18, 0x0C, 0x66, 0x62, 0x00},  // '%'
    { 0x30, 0x7A, 0x4F, 0x5D, 0x37, 0x7A, 0x48, 0x00},  // '&'
 {   0x04, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00},// '''
 {   0x00, 0x1C, 0x3E, 0x63, 0x41, 0x00, 0x00, 0x00}, // '('
 {   0x00, 0x41, 0x63, 0x3E, 0x1C, 0x00, 0x00, 0x00},// ')'
 {   0x08, 0x2A, 0x3E, 0x1C, 0x1C, 0x3E, 0x2A, 0x08}, // '*'
 {   0x08, 0x08, 0x3E, 0x3E, 0x08, 0x08, 0x00, 0x00}, // '+'
 {   0x00, 0x80, 0xE0, 0x60, 0x00, 0x00, 0x00, 0x00},// ','
 {   0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00},// '-'
 {   0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00},// '.'
 {   0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x00}, // '/'
 {   0x3E, 0x7F, 0x71, 0x59, 0x4D, 0x7F, 0x3E, 0x00}, // '0'
 {   0x40, 0x42, 0x7F, 0x7F, 0x40, 0x40, 0x00, 0x00},// '1'
 {   0x62, 0x73, 0x59, 0x49, 0x6F, 0x66, 0x00, 0x00},// '2'
 {   0x22, 0x63, 0x49, 0x49, 0x7F, 0x36, 0x00, 0x00},// '3'
 {   0x18, 0x1C, 0x16, 0x53, 0x7F, 0x7F, 0x50, 0x00},// '4'
 {   0x27, 0x67, 0x45, 0x45, 0x7D, 0x39, 0x00, 0x00},// '5'
 {   0x3C, 0x7E, 0x4B, 0x49, 0x79, 0x30, 0x00, 0x00}, // '6'
 {   0x03, 0x03, 0x71, 0x79, 0x0F, 0x07, 0x00, 0x00}, // '7'
 {   0x36, 0x7F, 0x49, 0x49, 0x7F, 0x36, 0x00, 0x00}, // '8'
 {   0x06, 0x4F, 0x49, 0x69, 0x3F, 0x1E, 0x00, 0x00}, // '9'
 {   0x00, 0x00, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00},// ':'
 {   0x00, 0x80, 0xE6, 0x66, 0x00, 0x00, 0x00, 0x00},// ';'
 {   0x08, 0x1C, 0x36, 0x63, 0x41, 0x00, 0x00, 0x00},// '<'
 {   0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x00, 0x00},// '='
 {   0x00, 0x41, 0x63, 0x36, 0x1C, 0x08, 0x00, 0x00},// '>'
 {   0x02, 0x03, 0x51, 0x59, 0x0F, 0x06, 0x00, 0x00}, // '?'
 {   0x3E, 0x7F, 0x41, 0x5D, 0x5D, 0x1F, 0x1E, 0x00}, // '@'
 {   0x7C, 0x7E, 0x13, 0x13, 0x7E, 0x7C, 0x00, 0x00}, // 'A'
 {   0x41, 0x7F, 0x7F, 0x49, 0x49, 0x7F, 0x36, 0x00}, // 'B'
 {   0x1C, 0x3E, 0x63, 0x41, 0x41, 0x63, 0x22, 0x00}, // 'C'
 {   0x41, 0x7F, 0x7F, 0x41, 0x63, 0x3E, 0x1C, 0x00}, // 'D'
 {   0x41, 0x7F, 0x7F, 0x49, 0x5D, 0x41, 0x63, 0x00}, // 'E'
 {   0x41, 0x7F, 0x7F, 0x49, 0x1D, 0x01, 0x03, 0x00}, // 'F'
 {   0x1C, 0x3E, 0x63, 0x41, 0x51, 0x73, 0x72, 0x00}, // 'G'
  {  0x7F, 0x7F, 0x08, 0x08, 0x7F, 0x7F, 0x00, 0x00},// 'H'
  {  0x00, 0x41, 0x7F, 0x7F, 0x41, 0x00, 0x00, 0x00},// 'I'
  {  0x30, 0x70, 0x40, 0x41, 0x7F, 0x3F, 0x01, 0x00},// 'J'
  {  0x41, 0x7F, 0x7F, 0x08, 0x1C, 0x77, 0x63, 0x00},// 'K'
  {  0x41, 0x7F, 0x7F, 0x41, 0x40, 0x60, 0x70, 0x00}, // 'L'
  {  0x7F, 0x7F, 0x0E, 0x1C, 0x0E, 0x7F, 0x7F, 0x00}, // 'M'
  {  0x7F, 0x7F, 0x06, 0x0C, 0x18, 0x7F, 0x7F, 0x00}, // 'N'
 {   0x1C, 0x3E, 0x63, 0x41, 0x63, 0x3E, 0x1C, 0x00},// 'O'
 {   0x41, 0x7F, 0x7F, 0x49, 0x09, 0x0F, 0x06, 0x00},// 'P'
 {   0x1E, 0x3F, 0x21, 0x71, 0x7F, 0x5E, 0x00, 0x00}, // 'Q'
 {   0x41, 0x7F, 0x7F, 0x09, 0x19, 0x7F, 0x66, 0x00},// 'R'
 {   0x26, 0x6F, 0x4D, 0x59, 0x73, 0x32, 0x00, 0x00},// 'S'
 {   0x03, 0x41, 0x7F, 0x7F, 0x41, 0x03, 0x00, 0x00}, // 'T'
 {   0x7F, 0x7F, 0x40, 0x40, 0x7F, 0x7F, 0x00, 0x00}, // 'U'
 {   0x1F, 0x3F, 0x60, 0x60, 0x3F, 0x1F, 0x00, 0x00}, // 'V'
 {   0x7F, 0x7F, 0x30, 0x18, 0x30, 0x7F, 0x7F, 0x00}, // 'W'
 {   0x43, 0x67, 0x3C, 0x18, 0x3C, 0x67, 0x43, 0x00}, // 'X'
 {   0x07, 0x4F, 0x78, 0x78, 0x4F, 0x07, 0x00, 0x00},// 'Y'
 {   0x47, 0x63, 0x71, 0x59, 0x4D, 0x67, 0x73, 0x00}, // 'Z'
 {   0x00, 0x7F, 0x7F, 0x41, 0x41, 0x00, 0x00, 0x00}, // '['
 {   0x01, 0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x00}, // backslash
 {   0x00, 0x41, 0x41, 0x7F, 0x7F, 0x00, 0x00, 0x00}, // ']'
 {   0x08, 0x0C, 0x06, 0x03, 0x06, 0x0C, 0x08, 0x00}, // '^'
 {   0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80}, // '_'
 {   0x00, 0x00, 0x03, 0x07, 0x04, 0x00, 0x00, 0x00},// '`'
 {   0x20, 0x74, 0x54, 0x54, 0x3C, 0x78, 0x40, 0x00},// 'a'
{    0x41, 0x7F, 0x3F, 0x48, 0x48, 0x78, 0x30, 0x00},// 'b'
{    0x38, 0x7C, 0x44, 0x44, 0x6C, 0x28, 0x00, 0x00}, // 'c'
{    0x30, 0x78, 0x48, 0x49, 0x3F, 0x7F, 0x40, 0x00}, // 'd'
{    0x38, 0x7C, 0x54, 0x54, 0x5C, 0x18, 0x00, 0x00}, // 'e'
{    0x48, 0x7E, 0x7F, 0x49, 0x03, 0x02, 0x00, 0x00},// 'f'
{    0x98, 0xBC, 0xA4, 0xA4, 0xF8, 0x7C, 0x04, 0x00}, // 'g'
{    0x41, 0x7F, 0x7F, 0x08, 0x04, 0x7C, 0x78, 0x00},// 'h'
{    0x00, 0x44, 0x7D, 0x7D, 0x40, 0x00, 0x00, 0x00}, // 'i'
{    0x60, 0xE0, 0x80, 0x80, 0xFD, 0x7D, 0x00, 0x00},// 'j'
{    0x41, 0x7F, 0x7F, 0x10, 0x38, 0x6C, 0x44, 0x00}, // 'k'
{    0x00, 0x41, 0x7F, 0x7F, 0x40, 0x00, 0x00, 0x00}, // 'l'
{    0x7C, 0x7C, 0x18, 0x38, 0x1C, 0x7C, 0x78, 0x00}, // 'm'
{    0x7C, 0x7C, 0x04, 0x04, 0x7C, 0x78, 0x00, 0x00}, // 'n'
{    0x38, 0x7C, 0x44, 0x44, 0x7C, 0x38, 0x00, 0x00}, // 'o'
{    0x84, 0xFC, 0xF8, 0xA4, 0x24, 0x3C, 0x18, 0x00},// 'p'
{   0x18, 0x3C, 0x24, 0xA4, 0xF8, 0xFC, 0x84, 0x00}, // 'q'
{    0x44, 0x7C, 0x78, 0x4C, 0x04, 0x1C, 0x18, 0x00}, // 'r'
{    0x48, 0x5C, 0x54, 0x54, 0x74, 0x24, 0x00, 0x00}, // 's'
{    0x00, 0x04, 0x3E, 0x7F, 0x44, 0x24, 0x00, 0x00}, // 't'
{    0x3C, 0x7C, 0x40, 0x40, 0x3C, 0x7C, 0x40, 0x00}, // 'u'
{    0x1C, 0x3C, 0x60, 0x60, 0x3C, 0x1C, 0x00, 0x00},// 'v'
{    0x3C, 0x7C, 0x70, 0x38, 0x70, 0x7C, 0x3C, 0x00}, // 'w'
{    0x44, 0x6C, 0x38, 0x10, 0x38, 0x6C, 0x44, 0x00}, // 'x'
{    0x9C, 0xBC, 0xA0, 0xA0, 0xFC, 0x7C, 0x00, 0x00}, // 'y'
{    0x4C, 0x64, 0x74, 0x5C, 0x4C, 0x64, 0x00, 0x00}, // 'z'
{    0x08, 0x08, 0x3E, 0x77, 0x41, 0x41, 0x00, 0x00}, // '{'
{    0x00, 0x00, 0x00, 0x77, 0x77, 0x00, 0x00, 0x00}, // '|'
{    0x41, 0x41, 0x77, 0x3E, 0x08, 0x08, 0x00, 0x00}, // '}'
    { 0x6E, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+007E (~)
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}    // U+007F

};
#define clkPin 17
#define datPin 18
#define latPin 19
#define irdPin 5 //pin infravermelho 


struct Pov{
private:
        int pinClk;
        int pinLatch;
        int pinData;
        //char selectedChar;
        char frase1[15];
        char frase2[15];
        int  draw[320];


public:
        Pov(int clk, int dat,int lat)
        {
          pinData  = dat;
          pinClk   = clk;
          pinLatch = lat;
          pinMode(pinData, OUTPUT);
          pinMode(pinClk,  OUTPUT);
          pinMode(pinLatch,OUTPUT);
          
        }

        void print(int x,int y,String text)
        {
          int Length=text.length();//informa quantos caracteres
          int limitX;
          
          if(y>1)
          {
            y=1;
          }
          
          if(x+Length>15)
          {
            limitX=15;
          }
          
          else
          {
            limitX=x+Length;
          }
                    
          //for(int line=x; line<x+Length; line++)
          for(int line=x; line<limitX; line++)
          {
            if(y==0)
            {
              frase1[line]=text.charAt(line-x);
            }
            else if(y==1)
            {
              frase2[line]=text.charAt(line-x);
            }
          }
 
        }

        void write(int vetorDraw[])
        {
          for(int i=0; i<160; i++)
          {
             draw[i]=vetorDraw[i];
             draw[i+160]=vetorDraw[i+160];           
          }
        }

        void update()
        {    
          for(int caracter=0; caracter<15; caracter++)
          {
            for(int asciiBits=0; asciiBits<8; asciiBits++)
            {
              digitalWrite(pinLatch,LOW);
              shiftOut(pinData,pinClk,MSBFIRST,ascii[frase1[caracter]][asciiBits]);
              shiftOut(pinData,pinClk,MSBFIRST,ascii[frase2[caracter]][asciiBits]);
              digitalWrite(pinLatch,HIGH);
              delayMicroseconds(500);
                  
            }
          }
        } 

          void clear()
          {
             
              digitalWrite(pinLatch,LOW);
              shiftOut(pinData,pinClk,MSBFIRST,0);
              shiftOut(pinData,pinClk,MSBFIRST,0);
              digitalWrite(pinLatch,HIGH);
          }
        

  
};

Pov propeller(clkPin,datPin,latPin);//(int clk, int dat,int lat)

void setup() 
{
  propeller.print(0,0,"NASTROGA TECH");
  propeller.print(0,1," * EMANUEL * ");
  propeller.clear();
pinMode(irdPin,INPUT_PULLUP);
}

void loop() 
{
  
 if(digitalRead(irdPin)==LOW)
 {
     propeller.update();
     propeller.clear();
 }

}
