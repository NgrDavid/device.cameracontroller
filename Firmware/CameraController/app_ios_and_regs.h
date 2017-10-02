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
	uint8_t REG_START_CAMS;
	uint8_t REG_STOP_CAMS;
	uint8_t REG_ENABLE_MOTORS;
	uint8_t REG_DISABLE_MOTORS;
	uint8_t REG_SET_OUTPUTS;
	uint8_t REG_CLR_OUTPUTS;
	uint8_t REG_OUTPUTS;
	uint8_t REG_INPUT0;
	uint8_t REG_CAM0;
	uint8_t REG_CAM1;
	uint8_t REG_SYNC0;
	uint8_t REG_SYNC1;
	uint8_t REG_MOTORS_STATE;
	uint8_t REG_RESERVED0;
	uint8_t REG_SYNC_INTERVAL;
	uint8_t REG_RESERVED1;
	uint8_t REG_IN0_MODE;
	uint8_t REG_CAM0_MODE;
	uint16_t REG_CAM0_FREQ;
	uint16_t REG_CAM0_MMODE_PERIOD;
	uint16_t REG_CAM0_MMODE_PULSE;
	uint8_t REG_CAM1_MODE;
	uint16_t REG_CAM1_FREQ;
	uint16_t REG_CAM1_MMODE_PERIOD;
	uint16_t REG_CAM1_MMODE_PULSE;
	uint8_t REG_RESERVED2;
	uint8_t REG_RESERVED3;
	uint16_t REG_EVT_EN;
} AppRegs;

/************************************************************************/
/* Registers' address                                                   */
/************************************************************************/
/* Registers */
#define ADD_REG_START_CAMS                  32 // U8     Start cameras triggering
#define ADD_REG_STOP_CAMS                   33 // U8     Stop cameras triggering
#define ADD_REG_ENABLE_MOTORS               34 // U8     Start sending pulses to the motors
#define ADD_REG_DISABLE_MOTORS              35 // U8     Stop sending ulses to the motors
#define ADD_REG_SET_OUTPUTS                 36 // U8     Set the outputs
#define ADD_REG_CLR_OUTPUTS                 37 // U8     Set the outputs
#define ADD_REG_OUTPUTS                     38 // U8     Control outputs' state
#define ADD_REG_INPUT0                      39 // U8     Input0's state (read only)
#define ADD_REG_CAM0                        40 // U8     Camera 0's triggering (read only)
#define ADD_REG_CAM1                        41 // U8     Camera 1's triggering (read only)
#define ADD_REG_SYNC0                       42 // U8     Sync 0 was set (read only)
#define ADD_REG_SYNC1                       43 // U8     Sync 1 was set (read only)
#define ADD_REG_MOTORS_STATE                44 // U8     State of the motors (enabled or disabled) (read only)
#define ADD_REG_RESERVED0                   45 // U8     Reserved
#define ADD_REG_SYNC_INTERVAL               46 // U8     Configures the interval in seconds between each sync pulse
#define ADD_REG_RESERVED1                   47 // U8     Reserved
#define ADD_REG_IN0_MODE                    48 // U8     Select the funcionality of Input 0
#define ADD_REG_CAM0_MODE                   49 // U8     Configures when the camera is triggered
#define ADD_REG_CAM0_FREQ                   50 // U16    Configures the camera 0's sample frequency [1;600]
#define ADD_REG_CAM0_MMODE_PERIOD           51 // U16    Configures the servo motor period (us) when using motor controller mode (sensitive to 2 us)
#define ADD_REG_CAM0_MMODE_PULSE            52 // U16    Configures the servo motor pulse (us) when using motor controller mode (sensitive to 2 us)
#define ADD_REG_CAM1_MODE                   53 // U8     Configures when the camera is triggered
#define ADD_REG_CAM1_FREQ                   54 // U16    Configures the camera 1's sample frequency [1;600]
#define ADD_REG_CAM1_MMODE_PERIOD           55 // U16    Configures the servo motor period (us) when using motor controller mode (sensitive to 2 us)
#define ADD_REG_CAM1_MMODE_PULSE            56 // U16    Configures the servo motor pulse (us) when using motor controller mode (sensitive to 2 us)
#define ADD_REG_RESERVED2                   57 // U8     Reserved for possible future use
#define ADD_REG_RESERVED3                   58 // U8     Reserved for possible future use
#define ADD_REG_EVT_EN                      59 // U16    Enable the Events

/************************************************************************/
/* PWM Generator registers' memory limits                               */
/*                                                                      */
/* DON'T change the APP_REGS_ADD_MIN value !!!                          */
/* DON'T change these names !!!                                         */
/************************************************************************/
/* Memory limits */
#define APP_REGS_ADD_MIN                    0x20
#define APP_REGS_ADD_MAX                    0x3B
#define APP_NBYTES_OF_REG_BANK              35

/************************************************************************/
/* Registers' bits                                                      */
/************************************************************************/
#define B_START_CAM0                       (1<<0)       // Start camera 0
#define B_START_CAM1                       (1<<1)       // Start camera 1
#define B_STOP_CAM0                        (1<<0)       // Stop camera 0
#define B_STOP_CAM1                        (1<<1)       // Stop camera 1
#define B_EN_MOTOR0                        (1<<0)       // Enable motor 0
#define B_EN_MOTOR1                        (1<<1)       // Enable motor 1
#define B_DIS_MOTOR0                       (1<<0)       // Disable motor 0
#define B_DIS_MOTOR1                       (1<<1)       // Disable motor 1
#define B_OUT_CAM_TRIG0                    (1<<0)       // Camera 0
#define B_OUT_CAM_TRIG1                    (1<<1)       // Camera 1
#define B_OUT_CAM_SYNC0                    (1<<2)       // Sync 0
#define B_OUT_CAM_SYNC1                    (1<<3)       // Sync 1
#define B_IN0                              (1<<0)       // Input 0
#define B_CAM0                             (1<<0)       // Camera 0 was triggered
#define B_CAM1                             (1<<0)       // Camera 1 was triggered
#define B_SYNC0                            (1<<0)       // Camera 0's sync changed the state
#define B_SYNC1                            (1<<0)       // Camera 1's sync changed the state
#define B_MOTOR0                           (1<<0)       // State of motor 0 (enabled = 1)
#define B_MOTOR1                           (1<<1)       // State of motor 1 (enabled = 1)
#define MSK_IN0_MODE                       (7<<0)       // 
#define GM_IN0_H_CAM0                      (0<<0)       // When logic 1: enable camera 0 or motor 0
#define GM_IN0_H_CAM1                      (1<<0)       // When logic 1: enable camera 1 or motor 1
#define GM_IN0_H_BOTH                      (2<<0)       // When logic 1: enable both cameras or motors
#define GM_IN0_L_CAM0                      (3<<0)       // When logic 0: enable camera 0 or motor 0
#define GM_IN0_L_CAM1                      (4<<0)       // When logic 0: enable camera 1 or motor 1
#define GM_IN0_L_BOTH                      (5<<0)       // When logic 0: enable both cameras or motors
#define GM_IN0_NOT_USED                    (6<<0)       // Used as a digital input only
#define MSK_CAM0_MODE                      (1<<0)       // Options for CAM0
#define GM_CAM0_MODE_CAM                   (0<<0)       // The camera 0 is triggered at a configured frequency
#define GM_CAM0_MODE_MOTOR                 (1<<0)       // Used in servo motor controller mode
#define MSK_CAM1_MODE                      (1<<0)       // Options for CAM1
#define GM_CAM1_MODE_CAM                   (0<<0)       // The camera 1 is triggered at a configured frequency
#define GM_CAM1_MODE_MOTOR                 (1<<0)       // Used in servo motor controller mode
#define B_EVT_CAMS                         (1<<0)       // Events of registers CAMs and SYNCs
#define B_EVT_IN0                          (1<<1)       // Event of register INPUT0

#endif /* _APP_REGS_H_ */