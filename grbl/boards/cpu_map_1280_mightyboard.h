#ifndef CPU_MAP_1280_MIGHTYBOARD_H_INCLUDED
#define CPU_MAP_1280_MIGHTYBOARD_H_INCLUDED

#include "stepper_utils.h"

  // Serial port interrupt vectors
  #define SERIAL_RX USART0_RX_vect
  #define SERIAL_UDRE USART0_UDRE_vect

  // input if high then EX1_PWR and EX2_PWR are disabled
  #define SAFETY_CUTOFF_SR_CHECK_PORT  G
  #define SAFETY_CUTOFF_SR_CHECK_PIN  4  // PG4
  // input/output keep low, make high output to reset
  #define SAFETY_CUTOFF_RESET_PORT  H
  #define SAFETY_CUTOFF_RESET_PIN  1  // PH1
  // input/output
  // input to identify failure condition
  // output to test failure conditon
  #define SAFETY_CUTOFF_TEST_PORT H
  #define SAFETY_CUTOFF_TEST_PIN 0

  #if N_AXIS > 5
  #error MightyBoard only has 5 axes
  #endif

//------- common scl for adjusting  I2c pots
// works with individual Stepper current sda pins
  #define POTS_SCL_PORT J
  #define POTS_SCL_PIN 5

// define stepper pins
///---- x axis index 0
  #define DIRECTION_PORT_0 F
  #define DIRECTION_BIT_0 0 // X axis direction - PF0

  #define STEP_PORT_0 F
  #define STEP_BIT_0 1  // X axis step - PF1

  #define STEPPER_DISABLE_PORT_0 F
  #define STEPPER_DISABLE_BIT_0 2 // X axis enable - PF2

  #define STEPPER_CURRENT_PORT_0 F
  #define STEPPER_CURRENT_BIT_0 3  // X axis current set pot MCP4018 SDA PF3

  #define MIN_LIMIT_PORT_0 L
  #define MIN_LIMIT_BIT_0 0 // X Limit Min - PL0

  #define MAX_LIMIT_PORT_0 L
  #define MAX_LIMIT_BIT_0 1 // X Limit Max - PL1

///---- y axis index 1
  #define DIRECTION_PORT_1 F
  #define DIRECTION_BIT_1 4 // Y axis direction - PF4

  #define STEP_PORT_1 F
  #define STEP_BIT_1 5  // Y axis Step - PF5

  #define STEPPER_DISABLE_PORT_1 F
  #define STEPPER_DISABLE_BIT_1 6 // Y Enable - PF6

  #define STEPPER_CURRENT_PORT_1 F
  #define STEPPER_CURRENT_BIT_1 7  // Y axis current set pot MCP4018 SDA PF7

  #define MIN_LIMIT_PORT_1 L
  #define MIN_LIMIT_BIT_1 2 // Y Limit Min - PL2

  #define MAX_LIMIT_PORT_1 L
  #define MAX_LIMIT_BIT_1 3 // Y Limit Max - PL3

///--- z axis index 2
  #define DIRECTION_PORT_2 K
  #define DIRECTION_BIT_2 0 // Z axis direction - PK0

  #define STEP_PORT_2 K
  #define STEP_BIT_2 1  // Z axis Step - PK1

  #define STEPPER_DISABLE_PORT_2 K
  #define STEPPER_DISABLE_BIT_2 2 // Z Enable - PK2

  #define STEPPER_CURRENT_PORT_2 K
  #define STEPPER_CURRENT_BIT_2 3  // Z axis current set pot MCP4018 SDA PK3

  #define MIN_LIMIT_PORT_2 L
  #define MIN_LIMIT_BIT_2 6 // Z Limit Min - PL6

  #define MAX_LIMIT_PORT_2 L
  #define MAX_LIMIT_BIT_2 7 // Z Limit Max - PL7

  #if N_AXIS > 3
///--- U axis
    #define DIRECTION_PORT_3 A
    #define DIRECTION_BIT_3 2// U Axis direction PA2

    #define STEP_PORT_3 A
    #define STEP_BIT_3 3 // A axis step PA3

    #define STEPPER_DISABLE_PORT_3 A
    #define STEPPER_DISABLE_BIT_3 4 // A Axis disable PA4

    #define STEPPER_CURRENT_PORT_3 A
    #define STEPPER_CURRENT_BIT_3 5  // A axis current set pot MCP4018 SDA PA5

    #define MIN_LIMIT_PORT_3 C
    #define MIN_LIMIT_BIT_3 0 // A axis Limit min PC0

    #define MAX_LIMIT_PORT_3 C
    #define MAX_LIMIT_BIT_3 1 // A axis limit max PC1

  #endif

  #if N_AXIS > 4
///--- B axis

    #define DIRECTION_PORT_4 A
    #define DIRECTION_BIT_4 6 // B axis direction PA6

    #define STEP_PORT_4 A
    #define STEP_BIT_4 7 // B axis step PA7

    #define STEPPER_DISABLE_PORT_4 G
    #define STEPPER_DISABLE_BIT_4 2 // B axis disable PG2

    #define STEPPER_CURRENT_PORT_4 J
    #define STEPPER_CURRENT_BIT_4 6  // B axis current set pot MCP4018 SDA PJ6

    #define MIN_LIMIT_PORT_4 G
    #define MIN_LIMIT_BIT_4 0 // B axis limit min PG0

    #define MAX_LIMIT_PORT_4 G
    #define MAX_LIMIT_BIT_4 1 // B axis limit max PG1
  #endif


  //  #define LIMIT_INT       PCIE0  // Pin change interrupt enable pin
  //  #define LIMIT_INT_vect  PCINT0_vect
  //  #define LIMIT_PCMSK     PCMSK0 // Pin change interrupt register
  //  #define LIMIT_MASK ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)) // All limit bits
  #define DISABLE_HW_LIMITS_INTERUPT
#if (0)
  // Define spindle enable and spindle direction output pins.
  #define SPINDLE_ENABLE_DDR      DDRG
  #define SPINDLE_ENABLE_PORT     PORTG
  #define SPINDLE_ENABLE_BIT      5 // MEGA2560 Digital Pin 4 - Ramps 1.4 Servo 4 Signal pin (D4)
  #define SPINDLE_DIRECTION_DDR   DDRE
  #define SPINDLE_DIRECTION_PORT  PORTE
  #define SPINDLE_DIRECTION_BIT   3 // MEGA2560 Digital Pin 5 - Ramps 1.4 Servo 3 Signal pin (D5)

  // Define flood and mist coolant enable output pins.
  #define COOLANT_FLOOD_DDR   DDRB
  #define COOLANT_FLOOD_PORT  PORTB
  #define COOLANT_FLOOD_BIT   4 // MEGA2560 Digital Pin 10 - Ramps 1.4 12v output
  #define COOLANT_MIST_DDR    DDRH
  #define COOLANT_MIST_PORT   PORTH
  #define COOLANT_MIST_BIT    6 // MEGA2560 Digital Pin 9 - Ramps 1.4 12v output
#endif
#if (0)
  // Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
  // NOTE: All CONTROLs pins must be on the same port and not on a port with other input pins (limits).
  #define CONTROL_DDR       DDRK
  #define CONTROL_PIN       PINK

  #define CONTROL_PORT      PORTK
  #define CONTROL_RESET_BIT         1  // Pin A9 - RAMPS Aux 2 Port
  #define CONTROL_FEED_HOLD_BIT     2  // Pin A10 - RAMPS Aux 2 Port
  #define CONTROL_CYCLE_START_BIT   3  // Pin A11 - RAMPS Aux 2 Port
  #define CONTROL_SAFETY_DOOR_BIT   4  // Pin A12 - RAMPS Aux 2 Port
  #define CONTROL_INT       PCIE2  // Pin change interrupt enable pin

  #define CONTROL_INT_vect  PCINT2_vect

  #define CONTROL_PCMSK     PCMSK2 // Pin change interrupt register
  #define CONTROL_MASK      ((1<<CONTROL_RESET_BIT)|(1<<CONTROL_FEED_HOLD_BIT)|(1<<CONTROL_CYCLE_START_BIT)|(1<<CONTROL_SAFETY_DOOR_BIT))

  // Define probe switch input pin.
  #define PROBE_DDR       DDRK
  #define PROBE_PIN       PINK
  #define PROBE_PORT      PORTK
  #define PROBE_BIT       7  // MEGA2560 Analog Pin 15
  #define PROBE_MASK      (1<<PROBE_BIT)
#endif

  #define SPINDLE_PWM_OFF_VALUE     0

#if 0
  // Advanced Configuration Below You should not need to touch these variables
  // Set Timer up to use TIMER4B which is attached to Digital Pin 8 - Ramps 1.4 12v output with heat sink
  #define SPINDLE_PWM_MAX_VALUE     1024.0 // Translates to about 1.9 kHz PWM frequency at 1/8 prescaler
  #ifndef SPINDLE_PWM_MIN_VALUE
  #define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
  #endif

  #define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)

  //Control Digital Pin 6 which is Servo 2 signal pin on Ramps 1.4 board
  #define SPINDLE_TCCRA_REGISTER    TCCR4A
  #define SPINDLE_TCCRB_REGISTER    TCCR4B
  #define SPINDLE_OCR_REGISTER      OCR4C
  #define SPINDLE_COMB_BIT          COM4C1

  // 1/8 Prescaler, 16-bit Fast PWM mode
  #define SPINDLE_TCCRA_INIT_MASK ((1<<WGM40) | (1<<WGM41))
  #define SPINDLE_TCCRB_INIT_MASK ((1<<WGM42) | (1<<WGM43) | (1<<CS41))
  #define SPINDLE_OCRA_REGISTER   OCR4A // 16-bit Fast PWM mode requires top reset value stored here.
  #define SPINDLE_OCRA_TOP_VALUE  0x0400 // PWM counter reset value. Should be the same as PWM_MAX_VALUE in hex.

  // Define spindle output pins.
  #define SPINDLE_PWM_DDR   DDRH
  #define SPINDLE_PWM_PORT  PORTH
  #define SPINDLE_PWM_BIT   5 // MEGA2560 Digital Pin 8

#endif

#endif // CPU_MAP_1280_MIGHTYBOARD_H_INCLUDED
