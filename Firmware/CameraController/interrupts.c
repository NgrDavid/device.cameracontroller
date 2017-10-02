#include "cpu.h"
#include "hwbp_core_types.h"
#include "app_ios_and_regs.h"
#include "app_funcs.h"
#include "hwbp_core.h"

/************************************************************************/
/* Declare application registers                                        */
/************************************************************************/
extern AppRegs app_regs;

/************************************************************************/
/* Interrupts from Timers                                               */
/************************************************************************/
// ISR(TCC0_OVF_vect, ISR_NAKED)
// ISR(TCD0_OVF_vect, ISR_NAKED)
// ISR(TCE0_OVF_vect, ISR_NAKED)
// ISR(TCF0_OVF_vect, ISR_NAKED)
// 
// ISR(TCC0_CCA_vect, ISR_NAKED)
// ISR(TCD0_CCA_vect, ISR_NAKED)
// ISR(TCE0_CCA_vect, ISR_NAKED)
// ISR(TCF0_CCA_vect, ISR_NAKED)
// 
// ISR(TCD1_OVF_vect, ISR_NAKED)
// 
// ISR(TCD1_CCA_vect, ISR_NAKED)

/************************************************************************/ 
/* INPUT0                                                               */
/************************************************************************/
ISR(PORTA_INT0_vect, ISR_NAKED)
{
	if (app_regs.REG_EVT_EN & B_EVT_IN0)
	{
		app_regs.REG_INPUT0 = read_INPUT0 ? B_IN0 : 0;
		core_func_send_event(ADD_REG_INPUT0, true);
	}

	if (app_regs.REG_IN0_MODE != GM_IN0_NOT_USED)
	{
		bool trig0_is_camera = ((app_regs.REG_CAM0_MODE & MSK_CAM0_MODE) == GM_CAM0_MODE_CAM);
		bool trig1_is_camera = ((app_regs.REG_CAM1_MODE & MSK_CAM1_MODE) == GM_CAM1_MODE_CAM);

		if (read_INPUT0)	// Input 0 is high level
		{
			if (app_regs.REG_IN0_MODE == GM_IN0_H_CAM0)
				if (trig0_is_camera) start_camera0();	else enable_motor0();
				
			if (app_regs.REG_IN0_MODE == GM_IN0_H_CAM1)
				if (trig1_is_camera) start_camera1();	else enable_motor1();
			
			if (app_regs.REG_IN0_MODE == GM_IN0_H_BOTH)
			{
				if (trig0_is_camera) start_camera0();	else enable_motor0();
				if (trig1_is_camera) start_camera1();	else enable_motor1();
			}
			
			if (app_regs.REG_IN0_MODE == GM_IN0_L_CAM0)
				if (trig0_is_camera) stop_camera0();	else disable_motor0();
			
			if (app_regs.REG_IN0_MODE == GM_IN0_L_CAM1)
				if (trig1_is_camera) stop_camera1();	else disable_motor1();
			
			if (app_regs.REG_IN0_MODE == GM_IN0_L_BOTH)
			{
				if (trig0_is_camera) stop_camera0();	else disable_motor0();
				if (trig1_is_camera) stop_camera1();	else disable_motor1();
			}
		}
		else   // Input 0 is low level
		{
			
			if (app_regs.REG_IN0_MODE == GM_IN0_H_CAM0)
				if (trig0_is_camera) stop_camera0();	else disable_motor0();
			
			if (app_regs.REG_IN0_MODE == GM_IN0_H_CAM1)
				if (trig1_is_camera) stop_camera1();	else disable_motor1();
			
			if (app_regs.REG_IN0_MODE == GM_IN0_H_BOTH)
			{
				if (trig0_is_camera) stop_camera0();	else disable_motor0();
				if (trig1_is_camera) stop_camera1();	else disable_motor1();
			}
			
			if (app_regs.REG_IN0_MODE == GM_IN0_L_CAM0)
				if (trig0_is_camera) start_camera0();	else enable_motor0();
			
			if (app_regs.REG_IN0_MODE == GM_IN0_L_CAM1)
				if (trig1_is_camera) start_camera1();	else enable_motor1();
			
			if (app_regs.REG_IN0_MODE == GM_IN0_L_BOTH)
			{
				if (trig0_is_camera) start_camera0();	else enable_motor0();
				if (trig1_is_camera) start_camera1();	else enable_motor1();
			}
		}
	}

	reti();
}

extern bool camera0_pulse;
extern bool camera1_pulse;

ISR(TCC0_OVF_vect, ISR_NAKED)
{
	if (camera0_pulse)
	{
		camera0_pulse = false;
		set_CAM0_TRIG;
		
		if (app_regs.REG_EVT_EN & B_EVT_CAMS)
		{
			app_regs.REG_CAM0 = 1;
			core_func_send_event(ADD_REG_CAM0, true);
		}
	}
	else
	{
		camera0_pulse = true;
		clr_CAM0_TRIG;
	}

	reti();
}

ISR(TCD0_OVF_vect, ISR_NAKED)
{
	if (camera1_pulse)
	{
		camera1_pulse = false;
		set_CAM1_TRIG;
		
		if (app_regs.REG_EVT_EN & B_EVT_CAMS)
		{
			app_regs.REG_CAM1 = 1;
			core_func_send_event(ADD_REG_CAM1, true);
		}
	}
	else
	{
		camera1_pulse = true;
		clr_CAM1_TRIG;
	}

	reti();
}