Display the LCD (NT35510 800x480) on ESP32.


#Connect
As you can see by looking at the program (LCD.ino), connect the following terminals.
LCD_BL is connected to the power supply (3.3V).
PARALLEL_0 connects DB0-DB7 with serial numbers to GPIO12 to GPIO19.
#Define LCD_CS 5
#Define LCD_RS 4
#Define LCD_RD 21
#Define LCD_WR 22
#Define LCD_RST 23 // Set.Hi (low level reset)
#Define LCD_BL VCC // Set.Hi (High level light)
#Define PARALLEL_0 12 // Byte Inpu Start 12(-19)Pin For R/W 8bit.parallel
　When the above connection is made and the power is turned on, the LCD should dimly glow.
*Need to change to 8-bit mode. It is necessary to remove the resistor of R3 on the board and change the soldering to the position of R2.
*Remember to connect BL to VCC.

#Operating principle
Input/output of data is simple.
In Read, if cs is set to lo and rd is set to lo, data will appear in parallel.
For Write, if cs is set to lo and wr is set to lo, data is read from parallel.
-R/W operation is in 8-bit mode, so it is necessary to execute it twice consecutively.
Switch register/memory access with rs.
* However, this was not enough. I need a little nasal medicine.

#soft
The software is made using arduino libraries. It should work if you put it in the same directory as ino or in the libraries directory.
-Functions such as letters, straight lines, squares, circles, and fill are possible.
Please refer to the simple demo after the board initialization.


See below for details

[Display LCD (NT35510 800x480) on ESP32] (https://qiita.com/hi631/items/0789110d6f8e912c7d02)

<BR>

LCD(NT35510 800x480)をESP32で表示させるぞ


#接続
　プログラム(LCD.ino)を見れば判るが、下記端子の接続を行う。
　LCD_BLは、電源(3.3V)に接続する。
　　PARALLEL_0は、GPIO12～GPIO19にDB0-DB7を連番で接続する。
　　#define LCD_CS   5
　　#define LCD_RS   4
　　#define LCD_RD  21
　　#define LCD_WR  22
　　#define LCD_RST 23     // Set.Hi (low level reset) 
　　#define LCD_BL  VCC    // Set.Hi (High level light)
　　#define PARALLEL_0  12 // Byte Inpu Start 12(-19)Pin For R/W 8bit.parallel 
　上記接続を行い電源をいれると、LCDがうっすらと光るはず。
　　※8bitモードに変更が必要。基板のR3の抵抗を取り外しR2の位置にはんだ付け変更が必要。
　　※BLをVCCに繋ぐのを忘れないでね。

#動作原理
　データの入出力は単純。
　　Readは、csをloにして、rdをloにすると、parallelにデータが出てくる。
　　Writeは、csをloにして、wrをloにすると、parallelからデータが読み込まれる。
　　R/W操作は8bitモードなので、連続二回実行する必要が有る。
　　rsでレジスタ/メモリのアクセスを切り替え。
　　※ただし、これだけでは済むはずは無かったが。一寸した鼻薬が必要。

#ソフト
　ソフトはarduinoのlibraries擬きで作っている。inoと同一もしくはlibrariesディレクトリに入れれば動くはず。
　関数の機能として、文字、直線、四角、円、塗りつぶしなどが可能。
　ボードの初期化後に、簡単なdemoを行ているので参照されたい。


詳しくは下記を参照

[LCD(NT35510 800x480)をESP32で表示させるぞ](https://qiita.com/hi631/items/0789110d6f8e912c7d02)
