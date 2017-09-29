#include <avr/io.h>
#include "hwbp_core_types.h"
#include "app_ios_and_regs.h"

/************************************************************************/
/* Configure and initialize IOs                                         */
/************************************************************************/
void init_ios(void)
{	/* Configure input pins */
	io_pin2in(&PORTA, 0, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // INPUT0

	/* Configure input interrupts */
	io_set_int(&PORTA, INT_LEVEL_LOW, 0, (1<<0), false);                 // INPUT0

	/* Configure output pins */
	io_pin2out(&PORTC, 0, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // CAM0_TRIG
	io_pin2out(&PORTC, 1, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // CAM0_SYNC
	io_pin2out(&PORTD, 0, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // CAM1_TRIG
	io_pin2out(&PORTD, 1, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // CAM1_SYNC

	/* Initialize output pins */
	clr_CAM0_TRIG;
	clr_CAM0_SYNC;
	clr_CAM1_TRIG;
	clr_CAM1_SYNC;
}

/************************************************************************/
/* Registers' stuff                                                     */
/************************************************************************/
AppRegs app_regs;

uint8_t app_regs_type[] = {
	TYPE_U16,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8
};

uint16_t app_regs_n_elements[] = {
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1
};

uint8_t *app_regs_pointer[] = {
	(uint8_t*)(&app_regs.REG_INPUTS_STATE),
	(uint8_t*)(&app_regs.REG_OUTPUTS),
	(uint8_t*)(&app_regs.REG_INPUT_CATCH_MODE),
	(uint8_t*)(&app_regs.REG_OUTPUT_MODE),
	(uint8_t*)(&app_regs.REG_RESERVED0),
	(uint8_t*)(&app_regs.REG_RESERVED1),
	(uint8_t*)(&app_regs.REG_RESERVED2),
	(uint8_t*)(&app_regs.REG_RESERVED3),
	(uint8_t*)(&app_regs.REG_EVNT_ENABLE)
};