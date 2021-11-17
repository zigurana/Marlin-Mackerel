#ifndef ULTRALCD_H
#define ULTRALCD_H

#include "Mackerel.h"

#ifdef ULTRA_LCD

  void lcd_update();
  void initialize_lcd();
  void lcd_setstatus(const char* message);
  void lcd_setstatuspgm(const char* message);
  void lcd_setalertstatuspgm(const char* message);
  void lcd_reset_alert_level();

  extern int lcd_contrast;
  void lcd_setcontrast(uint8_t value);
  static unsigned char blink = 0;	// Variable for visualization of fan rotation in GLCD

  #define LCD_MESSAGEPGM(x) lcd_setstatuspgm(PSTR(x))
  #define LCD_ALERTMESSAGEPGM(x) lcd_setalertstatuspgm(PSTR(x))

  #define LCD_UPDATE_INTERVAL 100
  #define LCD_TIMEOUT_TO_STATUS 15000

  void lcd_buttons_update();
  extern volatile uint8_t buttons;  //the last checked buttons in a bit array.

  extern int plaPreheatHotendTemp;
  extern int plaPreheatHPBTemp;
  extern int plaPreheatFanSpeed;

  extern int absPreheatHotendTemp;
  extern int absPreheatHPBTemp;
  
  
  extern unsigned long message_millis;
  //FMM section
  extern volatile long e_velocity;  //in steps per second
    
  void lcd_buzz(long duration,uint16_t freq);
  bool lcd_clicked();

  #define EN_C (1<<BLEN_C)
  #define EN_B (1<<BLEN_B)
  #define EN_A (1<<BLEN_A)

  #define LCD_CLICKED (buttons&EN_C)

char *itostr2(const uint8_t &x);
char *itostr31(const int &xx);
char *itostr3(const int &xx);
char *itostr3left(const int &xx);
char *itostr4(const int &xx);

char *ftostr3(const float &x);
char *ftostr31ns(const float &x); // float to string without sign character
char *ftostr31(const float &x);
char *ftostr32(const float &x);
char *ftostr22(const float &x);
char *ftostr21(const float &x);
char *ftostr12(const float &x);
char *ftostr5(const float &x);
char *ftostr51(const float &x);
char *ftostr52(const float &x);
char *ftostr53(const float &x);
char *ftostr6(const float &x);

// DaPo: Copied from hitachi implementation:
// static void lcd_implementation_drawmenu_setting_edit_generic(uint8_t row, const char* pstr, char pre_char, char* data)
// {
//     char c;
//     //Use all characters in narrow LCDs
//   #if LCD_WIDTH < 20
//       uint8_t n = LCD_WIDTH - 1 - 1 - strlen(data);
//     #else
//       uint8_t n = LCD_WIDTH - 1 - 2 - strlen(data);
//   #endif
//     lcd.setCursor(0, row);
//     lcd.print(pre_char);
//     while( ((c = pgm_read_byte(pstr)) != '\0') && (n>0) )
//     {
//         lcd.print(c);
//         pstr++;
//         n--;
//     }
//     lcd.print(':');
//     while(n--)
//         lcd.print(' ');
//     lcd.print(data);
// }
// static void lcd_implementation_drawmenu_setting_edit_generic_P(uint8_t row, const char* pstr, char pre_char, const char* data)
// {
//     char c;
//     //Use all characters in narrow LCDs
//   #if LCD_WIDTH < 20
//       uint8_t n = LCD_WIDTH - 1 - 1 - strlen_P(data);
//     #else
//       uint8_t n = LCD_WIDTH - 1 - 2 - strlen_P(data);
//   #endif
//     lcd.setCursor(0, row);
//     lcd.print(pre_char);
//     while( ((c = pgm_read_byte(pstr)) != '\0') && (n>0) )
//     {
//         lcd.print(c);
//         pstr++;
//         n--;
//     }
//     lcd.print(':');
//     while(n--)
//         lcd.print(' ');
//     lcd_printPGM(data);
// }

#define lcd_implementation_drawmenu_setting_edit_int3_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', itostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_int3(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', itostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float3_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float3(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float32_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr32(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float32(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr32(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float22_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr22(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float22(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr22(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float5_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float5(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float52_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr52(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float52(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr52(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float53_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr53(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float53(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr53(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float51_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr51(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float51(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr51(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float6_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr6(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float6(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr6(*(data)))
#define lcd_implementation_drawmenu_setting_edit_long5_selected(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_long5(row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_bool_selected(row, pstr, pstr2, data) lcd_implementation_drawmenu_setting_edit_generic_P(row, pstr, '>', (*(data))?PSTR(MSG_ON):PSTR(MSG_OFF))
#define lcd_implementation_drawmenu_setting_edit_bool(row, pstr, pstr2, data) lcd_implementation_drawmenu_setting_edit_generic_P(row, pstr, ' ', (*(data))?PSTR(MSG_ON):PSTR(MSG_OFF))

//Add version for callback functions
#define lcd_implementation_drawmenu_setting_edit_callback_int3_selected(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', itostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_int3(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', itostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float3_selected(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float3(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float32_selected(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr32(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float32(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr32(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float22_selected(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr22(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float22(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr22(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float5_selected(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float5(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float53_selected(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr53(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float53(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr53(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float52_selected(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr52(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float52(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr52(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float51_selected(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr51(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float51(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr51(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float6_selected(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr6(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float6(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr6(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_long5_selected(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, '>', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_long5(row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(row, pstr, ' ', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_bool_selected(row, pstr, pstr2, data, callback) lcd_implementation_drawmenu_setting_edit_generic_P(row, pstr, '>', (*(data))?PSTR(MSG_ON):PSTR(MSG_OFF))
#define lcd_implementation_drawmenu_setting_edit_callback_bool(row, pstr, pstr2, data, callback) lcd_implementation_drawmenu_setting_edit_generic_P(row, pstr, ' ', (*(data))?PSTR(MSG_ON):PSTR(MSG_OFF))

#endif //ULTRALCD
#endif //ULTRALCD_H

