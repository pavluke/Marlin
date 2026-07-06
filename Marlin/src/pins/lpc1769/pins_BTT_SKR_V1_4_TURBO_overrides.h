#pragma once

#include "env_validate.h"

#undef  USES_DIAG_PINS

#define SDCARD_EEPROM_EMULATION

#undef  SERVO0_PIN
#undef  FIL_RUNOUT_PIN
#define FIL_RUNOUT_PIN          P2_00

#undef  HEATER_0_PIN
#define HEATER_0_PIN			P2_05   // BED

#undef  Z_MIN_PROBE_PIN
#undef  HEATER_BED_PIN
#define HEATER_BED_PIN          P0_10   // PROBE 

#undef  FAN0_PIN
#undef  E0_AUTO_FAN_PIN
#define CONTROLLER_FAN_PIN      P2_03   // FAN0
#define E0_AUTO_FAN_PIN         P2_07   // HE0
#define FAN0_PIN                P2_04   // HE1

/*
Switch E0 to E1 because E0 UART isn't worked for me :-(
*/

#undef TEMP_0_PIN
#undef TEMP_1_PIN

#undef E0_STEP_PIN
#undef E0_DIR_PIN
#undef E0_ENABLE_PIN
#undef E0_CS_PIN

#undef E1_STEP_PIN
#undef E1_DIR_PIN
#undef E1_ENABLE_PIN
#undef E1_CS_PIN

#undef E0_SERIAL_TX_PIN
#undef E1_SERIAL_TX_PIN

#undef E0_DIAG_PIN
#undef E1_DIAG_PIN

#define E0_DIAG_PIN             P1_25       // E1DET

#define TEMP_0_PIN              P0_23_A0    // TH1

#undef  TEMP_PROBE_PIN
#define TEMP_PROBE_PIN          P0_24_A1      // TH0

#define E0_STEP_PIN             P1_15
#define E0_DIR_PIN              P1_14
#define E0_ENABLE_PIN           P1_16
#ifndef E0_CS_PIN
  #define E0_CS_PIN             P1_01
#endif

#define E0_SERIAL_TX_PIN        P1_01


#if ANY(MKS_12864OLED, MKS_12864OLED_SSD1306)
      
    /** Display pinout
    *                   ------
    *   (SCK)     1.30 | 1  2 | 0.28 (BTN_ENC)
    *   (BTN_EN1) 1.18 | 3  4 | 1.19 (RESET)
    *   (BTN_EN2) 1.20 | 5  6 | 1.21 (CS)
    *   (DC)      1.22 | 7  8 | 1.23 (MOSI)
    *              GND | 9 10 | 5V
    *                   ------
    *                    EXP1
    */

	#undef  LCD_PINS_D5
	#undef  LCD_PINS_D6
	#undef  LCD_PINS_D7
		
	#undef  LCD_PINS_EN
    #define LCD_PINS_EN         -1

	#undef  BTN_ENC
	#define BTN_ENC             EXP2_01_PIN

	#undef  BTN_EN1
    #define BTN_EN1             EXP1_08_PIN

	#undef  BTN_EN2
    #define BTN_EN2             EXP1_03_PIN 

	#undef  LCD_PINS_D4
    #define LCD_PINS_D4         EXP1_07_PIN

    #define LCD_PINS_DC         EXP1_07_PIN  // YELLOW DC  P1_22

    #define DOGLCD_A0           EXP1_07_PIN  // GREEN  DC  P1_22
    #define DOGLCD_SCK          EXP2_02_PIN  // BROWN  SCK P0_15
    #define DOGLCD_MOSI         EXP2_06_PIN  // ORANGE SDA P0_18
    #define DOGLCD_CS           EXP1_06_PIN  // BLUE   CS  P1_21

#endif