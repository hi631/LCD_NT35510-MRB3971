Display the LCD (NT35510 800x480) on ESP32.<BR>
<BR>
<BR>
#Connect<BR>
As you can see by looking at the program (LCD.ino), connect the following terminals.<BR>
LCD_BL is connected to the power supply (3.3V).<BR>
PARALLEL_0 connects DB0-DB7 with serial numbers to GPIO12 to GPIO19.<BR>
#Define LCD_CS 5<BR>
#Define LCD_RS 4<BR>
#Define LCD_RD 21<BR>
#Define LCD_WR 22<BR>
#Define LCD_RST 23 // Set.Hi (low level reset)<BR>
#Define LCD_BL VCC // Set.Hi (High level light)<BR>
#Define PARALLEL_0 12 // Byte Inpu Start 12(-19)Pin For R/W 8bit.parallel<BR>
　When the above connection is made and the power is turned on, the LCD should dimly glow.<BR>
*Need to change to 8-bit mode. It is necessary to remove the resistor of R3 on the board and change the soldering to the position of R2.<BR>
*Remember to connect BL to VCC.<BR>
<BR>
#Operating principle<BR>
Input/output of data is simple.<BR>
In Read, if cs is set to lo and rd is set to lo, data will appear in parallel.<BR>
For Write, if cs is set to lo and wr is set to lo, data is read from parallel.<BR>
-R/W operation is in 8-bit mode, so it is necessary to execute it twice consecutively.<BR>
Switch register/memory access with rs.<BR>
* However, this was not enough. I need a little nasal medicine.<BR>
<BR>
#soft<BR>
The software is made using arduino libraries. It should work if you put it in the same directory as ino or in the libraries directory.<BR>
-Functions such as letters, straight lines, squares, circles, and fill are possible.<BR>
Please refer to the simple demo after the board initialization.<BR>
<BR>
<BR>
See below for details<BR>
<BR>
[Display LCD (NT35510 800x480) on ESP32] (https://qiita.com/hi631/items/0789110d6f8e912c7d02)<BR>
<BR>
<BR><BR>
<BR>
LCD(NT35510 800x480)をESP32で表示させるぞ<BR>
<BR>
<BR>
#接続<BR>
　プログラム(LCD.ino)を見れば判るが、下記端子の接続を行う。<BR>
　LCD_BLは、電源(3.3V)に接続する。<BR>
　　PARALLEL_0は、GPIO12～GPIO19にDB0-DB7を連番で接続する。<BR>
　　#define LCD_CS   5<BR>
　　#define LCD_RS   4<BR>
　　#define LCD_RD  21<BR>
　　#define LCD_WR  22<BR>
　　#define LCD_RST 23     // Set.Hi (low level reset) <BR>
　　#define LCD_BL  VCC    // Set.Hi (High level light)<BR>
　　#define PARALLEL_0  12 // Byte Inpu Start 12(-19)Pin For R/W 8bit.parallel <BR>
　上記接続を行い電源をいれると、LCDがうっすらと光るはず。<BR>
　　※8bitモードに変更が必要。基板のR3の抵抗を取り外しR2の位置にはんだ付け変更が必要。<BR>
　　※BLをVCCに繋ぐのを忘れないでね。<BR>
<BR>
#動作原理<BR>
　データの入出力は単純。<BR>
　　Readは、csをloにして、rdをloにすると、parallelにデータが出てくる。<BR>
　　Writeは、csをloにして、wrをloにすると、parallelからデータが読み込まれる。<BR>
　　R/W操作は8bitモードなので、連続二回実行する必要が有る。<BR>
　　rsでレジスタ/メモリのアクセスを切り替え。<BR>
　　※ただし、これだけでは済むはずは無かったが。一寸した鼻薬が必要。<BR>
<BR>
#ソフト<BR>
　ソフトはarduinoのlibraries擬きで作っている。inoと同一もしくはlibrariesディレクトリに入れれば動くはず。<BR>
　関数の機能として、文字、直線、四角、円、塗りつぶしなどが可能。<BR>
　ボードの初期化後に、簡単なdemoを行ているので参照されたい。<BR>
<BR>
<BR>
詳しくは下記を参照<BR>
<BR>
[LCD(NT35510 800x480)をESP32で表示させるぞ](https://qiita.com/hi631/items/0789110d6f8e912c7d02)<BR>
