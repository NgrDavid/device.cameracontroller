#ifndef _APP_IOS_AND_REGS_H_
#define _APP_IOS_AND_REGS_H_
#include "cpu.h"

void init_ios(void);
/************************************************************************/
/* Definition of input pins                                             */
/************************************************************************/
// INPUT0                 Description: Input 0

#define read_INPUT0 read_io(PORTA, 0)           // INPUT0

/************************************************************************/
/* Definition of output pins                                            */
/************************************************************************/
// CAM0_TRIG              Description: Camera 0 trigger
// CAM0_SYNC              Description: Camera 0 synchronizer
// CAM1_TRIG              Description: Camera 1 trigger
// CAM1_SYNC              Description: Camera 1 synchronizer

/* CAM0_TRIG */
#define set_CAM0_TRIG set_io(PORTC, 0)
#define clr_CAM0_TRIG clear_io(PORTC, 0)
#define tgl_CAM0_TRIG toggle_io(PORTC, 0)
#define read_CAM0_TRIG read_io(PORTC, 0)

/* CAM0_SYNC */
#define set_CAM0_SYNC set_io(PORTC, 1)
#define clr_CAM0_SYNC clear_io(PORTC, 1)
#define tgl_CAM0_SYNC toggle_io(PORTC, 1)
#define read_CAM0_SYNC read_io(PORTC, 1)

/* CAM1_TRIG */
#define set_CAM1_TRIG set_io(PORTD, 0)
#define clr_CAM1_TRIG clear_io(PORTD, 0)
#define tgl_CAM1_TRIG toggle_io(PORTD, 0)
#define read_CAM1_TRIG read_io(PORTD, 0)

/* CAM1_SYNC */
#define set_CAM1_SYNC set_io(PORTD, 1)
#define clr_CAM1_SYNC clear_io(PORTD, 1)
#define tgl_CAM1_SYNC toggle_io(PORTD, 1)
#define read_CAM1_SYNC read_io(PORTD, 1)


/************************************************************************/
/* Registers' structure                                                 */
/************************************************************************/
typedef struct
{
	uint16_t REG_INPUTS_STATE;
	uint8_t REG_OUTPUTS;
	uint8_t REG_INPUT_CATCH_MODE;
	uint8_t REG_OUTPUT_MODE;
	uint8_t REG_RESERVED0;
	uint8_t REG_RESERVED1;
	uint8_t REG_RESERVED2;
	uint8_t REG_RESERVED3;
	uint8_t REG_EVNT_ENABLE;
} AppRegs;

/************************************************************************/
/* Registers' address                                                   */
/************************************************************************/
/* Registers */
#define ADD_REG_INPUTS_STATE                32 // U16    State of each input (the address is included in the MSbits)
#define ADD_REG_OUTPUTS                     33 // U8     
#define ADD_REG_INPUT_CATCH_MODE            34 // U8     Configures when inputs will be catched
#define ADD_REG_OUTPUT_MODE                 35 // U8     Configures how the output behaves
#define ADD_REG_RESERVED0                   36 // U8     Not used
#define ADD_REG_RESERVED1                   37 // U8     Not used
#define ADD_REG_RESERVED2                   38 // U8     Not used
#define ADD_REG_RESERVED3                   39 // U8     Not used
#define ADD_REG_EVNT_ENABLE                 40 // U8     Enable the Events

/************************************************************************/
/* PWM Generator registers' memory limits                               */
/*                                                                      */
/* DON'T change the APP_REGS_ADD_MIN value !!!                          */
/* DON'T change these names !!!                                         */
/************************************************************************/
/* Memory limits */
#define APP_REGS_ADD_MIN                    0x20
#define APP_REGS_ADD_MAX                    0x28
#define APP_NBYTES_OF_REG_BANK              10

/************************************************************************/
/* Registers' bits                                                      */
/************************************************************************/
#define MSK_ADDRESS                        (3<<14)      // Board's address
#define MSK_INPUTS                         (0x1FF<<0)   // Board's inputs
#define B_INPUT0                           (1<<0)       // Input 0
#define B_INPUT1                           (1<<1)       // Input 1
#define B_INPUT2                           (1<<2)       // Input 2
#define B_INPUT3                           (1<<3)       // Input 3
#define B_INPUT4                           (1<<4)       // Input 4
#define B_INPUT5                           (1<<5)       // Input 5
#define B_INPUT6                           (1<<6)       // Input 6
#define B_INPUT7                           (1<<7)       // Input 7
#define B_INPUT8                           (1<<8)       // Input 8
#define B_OUTPUT0_STATE                    (1<<13)      // Reflects the Output 0 state
#define B_ADRESS0                          (1<<14)      // Address 0
#define B_ADRESS1                          (1<<15)      // Address 1
#define B_OUTPUT0                          (1<<0)       // Output 0
#define MSK_CATCH_MODE                     (15<<0)      // Catch mode
#define GM_INMODE_DISABLED                 (0<<0)       // Catch is disabled
#define GM_INMODE_WHEN_ANY_CHANGE          (1<<0)       // Catched everytime one of the Inputs changes
#define GM_INMODE_RISE_ON_INPUT0           (2<<0)       // Catched when Input 0 have a rising edge
#define GM_INMODE_FALL_ON_INPUT0           (3<<0)       // Catched when Input 0 have a falling edge
#define GM_INMODE_100Hz                    (4<<0)       // Catched at a frequency of 100 Hz
#define GM_INMODE_250Hz                    (5<<0)       // Catched at a frequency of 250 Hz
#define GM_INMODE_500Hz                    (6<<0)       // Catched at a frequency of 500 Hz
#define GM_INMODE_1000Hz                   (7<<0)       // Catched at a frequency of 1 KHz
#define GM_INMODE_2000Hz                   (8<<0)       // Catched at a frequency of 2 KHz
#define MSK_OUTPUT_MODE                    (7<<0)       // Output mode
#define GM_OUTMODE_NOT_USED                (0<<0)       // Not used by the catch
#define GM_OUTMODE_TOGGLE                  (1<<0)       // Output toggles everytime the inputs are catched
#define GM_OUTMODE_INPUT0                  (2<<0)       // Output is equal to Input 0 (bit INPUT0)
#define GM_OUTMODE_PULSE_5mS               (3<<0)       // Output has a positive pulse of 5 milliseconds everytime the inputs are catched
#define GM_OUTMODE_PULSE_2mS               (4<<0)       // Output has a positive pulse of 2 milliseconds everytime the inputs are catched
#define GM_OUTMODE_PULSE_1mS               (5<<0)       // Output has a positive pulse of 1 milliseconds everytime the inputs are catched
#define GM_OUTMODE_PULSE_500uS             (6<<0)       // Output has a positive pulse of 500 microseconds everytime the inputs are catched
#define GM_OUTMODE_PULSE_250uS             (7<<0)       // Output has a positive pulse of 250 microseconds everytime the inputs are catched
#define B_EVT0                             (1<<0)       // Event of register INPUTS_STATE

#endif /* _APP_REGS_H_ */