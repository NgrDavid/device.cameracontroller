#include "app_funcs.h"
#include "app_ios_and_regs.h"
#include "hwbp_core.h"


/************************************************************************/
/* Create pointers to functions                                         */
/************************************************************************/
extern AppRegs app_regs;

void (*app_func_rd_pointer[])(void) = {
	&app_read_REG_INPUTS_STATE,
	&app_read_REG_OUTPUTS,
	&app_read_REG_INPUT_CATCH_MODE,
	&app_read_REG_OUTPUT_MODE,
	&app_read_REG_RESERVED0,
	&app_read_REG_RESERVED1,
	&app_read_REG_RESERVED2,
	&app_read_REG_RESERVED3,
	&app_read_REG_EVNT_ENABLE
};

bool (*app_func_wr_pointer[])(void*) = {
	&app_write_REG_INPUTS_STATE,
	&app_write_REG_OUTPUTS,
	&app_write_REG_INPUT_CATCH_MODE,
	&app_write_REG_OUTPUT_MODE,
	&app_write_REG_RESERVED0,
	&app_write_REG_RESERVED1,
	&app_write_REG_RESERVED2,
	&app_write_REG_RESERVED3,
	&app_write_REG_EVNT_ENABLE
};


/************************************************************************/
/* REG_INPUTS_STATE                                                     */
/************************************************************************/
void app_read_REG_INPUTS_STATE(void)
{
	//app_regs.REG_INPUTS_STATE = 0;

}

bool app_write_REG_INPUTS_STATE(void *a)
{
	uint16_t reg = *((uint16_t*)a);

	app_regs.REG_INPUTS_STATE = reg;
	return true;
}


/************************************************************************/
/* REG_OUTPUTS                                                          */
/************************************************************************/
void app_read_REG_OUTPUTS(void)
{
	//app_regs.REG_OUTPUTS = 0;

}

bool app_write_REG_OUTPUTS(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_OUTPUTS = reg;
	return true;
}


/************************************************************************/
/* REG_INPUT_CATCH_MODE                                                 */
/************************************************************************/
void app_read_REG_INPUT_CATCH_MODE(void)
{
	//app_regs.REG_INPUT_CATCH_MODE = 0;

}

bool app_write_REG_INPUT_CATCH_MODE(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_INPUT_CATCH_MODE = reg;
	return true;
}


/************************************************************************/
/* REG_OUTPUT_MODE                                                      */
/************************************************************************/
void app_read_REG_OUTPUT_MODE(void)
{
	//app_regs.REG_OUTPUT_MODE = 0;

}

bool app_write_REG_OUTPUT_MODE(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_OUTPUT_MODE = reg;
	return true;
}


/************************************************************************/
/* REG_RESERVED0                                                        */
/************************************************************************/
void app_read_REG_RESERVED0(void)
{
	//app_regs.REG_RESERVED0 = 0;

}

bool app_write_REG_RESERVED0(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_RESERVED0 = reg;
	return true;
}


/************************************************************************/
/* REG_RESERVED1                                                        */
/************************************************************************/
void app_read_REG_RESERVED1(void)
{
	//app_regs.REG_RESERVED1 = 0;

}

bool app_write_REG_RESERVED1(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_RESERVED1 = reg;
	return true;
}


/************************************************************************/
/* REG_RESERVED2                                                        */
/************************************************************************/
void app_read_REG_RESERVED2(void)
{
	//app_regs.REG_RESERVED2 = 0;

}

bool app_write_REG_RESERVED2(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_RESERVED2 = reg;
	return true;
}


/************************************************************************/
/* REG_RESERVED3                                                        */
/************************************************************************/
void app_read_REG_RESERVED3(void)
{
	//app_regs.REG_RESERVED3 = 0;

}

bool app_write_REG_RESERVED3(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_RESERVED3 = reg;
	return true;
}


/************************************************************************/
/* REG_EVNT_ENABLE                                                      */
/************************************************************************/
void app_read_REG_EVNT_ENABLE(void)
{
	//app_regs.REG_EVNT_ENABLE = 0;

}

bool app_write_REG_EVNT_ENABLE(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_EVNT_ENABLE = reg;
	return true;
}