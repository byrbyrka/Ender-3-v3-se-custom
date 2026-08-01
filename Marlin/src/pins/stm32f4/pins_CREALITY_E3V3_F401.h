/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

/**
 * Creality Ender-3 V3 SE (C14) board pin assignments
 * MCU: STM32F401RET6 (ARM Cortex-M4, 512KB Flash, 96KB RAM)
 * Based on C13 pinout with STM32F4 HAL adaptations.
 */
#pragma once

#include "env_validate.h"

#if HOTENDS > 1 || E_STEPPERS > 1
  #error "Creality E3V3 F401 only supports one hotend / E-stepper. Comment out this line to continue."
#endif

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME      "CR4NS200320C14"
#endif
#ifndef DEFAULT_MACHINE_NAME
  #define DEFAULT_MACHINE_NAME "Ender 3 V3 SE"
#endif

//
// EEPROM (same I2C setup as C13, via Software I2C on PA7/PA8)
//
#if NO_EEPROM_SELECTED
  #define IIC_BL24CXX_EEPROM                      // EEPROM on I2C
  // #define SDCARD_EEPROM_EMULATION
#endif

#if ENABLED(IIC_BL24CXX_EEPROM)
  #define IIC_EEPROM_SDA                    PA7
  #define IIC_EEPROM_SCL                    PA8
  #define MARLIN_EEPROM_SIZE                0x800  // 2Kb (24C16)
#elif ENABLED(SDCARD_EEPROM_EMULATION)
  #define MARLIN_EEPROM_SIZE                0x800  // 2Kb
#endif

//
// Limit Switches
//
#define X_STOP_PIN                          PA5
#define Y_STOP_PIN                          PA6

#if ENABLED(BLTOUCH)
  #define Z_STOP_PIN                          PC14   // BLTouch / CRTouch IN
  #define SERVO0_PIN                          PC13   // BLTouch / CRTouch OUT
#elif ENABLED(PROBE_TARE)
  #define Z_STOP_PIN                          PC14   // Strain gauge (CR Touch) Z-stop
  #define PROBE_TARE_PIN                      PC13   // Strain gauge tare pin
#else
  #define Z_STOP_PIN                          PA15
#endif

//
// Filament Runout Sensor
//
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                    PC15   // "Pulled-high"
#endif

#ifndef CHECKFILAMENT_PIN
  #define CHECKFILAMENT_PIN                 PC15   // Same as runout sensor for DWIN filament check
#endif

//
// Steppers
//
#ifndef X_STEP_PIN
  #define X_STEP_PIN                        PC2
#endif
#ifndef X_DIR_PIN
  #define X_DIR_PIN                         PB9
#endif
#define X_ENABLE_PIN                        PC3

#ifndef Y_STEP_PIN
  #define Y_STEP_PIN                        PB8
#endif
#ifndef Y_DIR_PIN
  #define Y_DIR_PIN                         PB7
#endif
#define Y_ENABLE_PIN                        PC3

#ifndef Z_STEP_PIN
  #define Z_STEP_PIN                        PB6
#endif
#ifndef Z_DIR_PIN
  #define Z_DIR_PIN                         PB5
#endif
#define Z_ENABLE_PIN                        PC3

#ifndef E0_STEP_PIN
  #define E0_STEP_PIN                       PB4
#endif
#ifndef E0_DIR_PIN
  #define E0_DIR_PIN                        PB3
#endif
#define E0_ENABLE_PIN                       PC3

#if HAS_TMC_UART

  #define X_SERIAL_TX_PIN                     PB12
  #define X_SERIAL_RX_PIN                     PB12

  #define Y_SERIAL_TX_PIN                     PB13
  #define Y_SERIAL_RX_PIN                     PB13

  #define Z_SERIAL_TX_PIN                     PB14
  #define Z_SERIAL_RX_PIN                     PB14

  #define E0_SERIAL_TX_PIN                    PB15
  #define E0_SERIAL_RX_PIN                    PB15

  #define X_DIAG_PIN                          PB10
  #define Y_DIAG_PIN                          PB11

  // Reduce baud rate to improve software serial reliability
  #define TMC_BAUD_RATE                       19200
#endif

//
// Temperature Sensors
//
#define TEMP_0_PIN                          PC5   // TH1
#define TEMP_BED_PIN                        PC4   // TB1

//
// Heaters / Fans
//
#define HEATER_0_PIN                        PA1   // HEATER1
#define HEATER_BED_PIN                      PB2   // HOT BED

#ifndef FAN_PIN
  #define FAN_PIN                           PA0   // FAN
#endif
#if PIN_EXISTS(FAN)
  #define FAN_SOFT_PWM
#endif

//
// SD Card (SDIO)
//
#define SD_DETECT_PIN                    PC7
#define SDCARD_CONNECTION                ONBOARD
#define ONBOARD_SPI_DEVICE               1
//#define ONBOARD_SD_CS_PIN                PA4   // Not used with SDIO
#define SDIO_SUPPORT
#define NO_SD_HOST_DRIVE                       // This board's SD is only seen by the printer

//
// LCD (DWIN Creality LCD)
//
#if ENABLED(DWIN_CREALITY_LCD)
  // RET6 DWIN ENCODER LCD
  #define BTN_ENC                           PB1
  #define BTN_EN1                           PA11
  #define BTN_EN2                           PA12

 #ifndef BEEPER_PIN
    #define BEEPER_PIN                     PB0
    #undef SPEAKER
  #endif
#endif

//
// Note: PB4 is NJTRST (JTAG reset) on STM32F4, but GPIO mode is configured
// by the stepper driver code. DISABLE_DEBUG is not supported on STM32F4 HAL.
//

//
// Misc
//
//#define POWER_DETECTION_PIN               PB0   // 24V power detection (shares pin with BEEPER on DWIN LCD; disabled to avoid conflict)
