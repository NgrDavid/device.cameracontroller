#ifndef _APP_FUNCTIONS_H_
#define _APP_FUNCTIONS_H_
#include <avr/io.h>


/************************************************************************/
/* Define if not defined                                                */
/************************************************************************/
#ifndef bool
	#define bool uint8_t
#endif
#ifndef true
	#define true 1
#endif
#ifndef false
	#define false 0
#endif


/************************************************************************/
/* Prototypes                                                           */
/************************************************************************/
void app_read_REG_START_CAMS(void);
void app_read_REG_STOP_CAMS(void);
void app_read_REG_ENABLE_MOTORS(void);
void app_read_REG_DISABLE_MOTORS(void);
void app_read_REG_SET_OUTPUTS(void);
void app_read_REG_CLR_OUTPUTS(void);
void app_read_REG_OUTPUTS(void);
void app_read_REG_INPUT0(void);
void app_read_REG_CAM0(void);
void app_read_REG_CAM1(void);
void app_read_REG_SYNC0(void);
void app_read_REG_SYNC1(void);
void app_read_REG_MOTORS_STATE(void);
void app_read_REG_RESERVED0(void);
void app_read_REG_SYNC_INTERVAL(void);
void app_read_REG_RESERVED1(void);
void app_read_REG_IN0_MODE(void);
void app_read_REG_CAM0_MODE(void);
void app_read_REG_CAM0_FREQ(void);
void app_read_REG_CAM0_MMODE_PERIOD(void);
void app_read_REG_CAM0_MMODE_PULSE(void);
void app_read_REG_CAM1_MODE(void);
void app_read_REG_CAM1_FREQ(void);
void app_read_REG_CAM1_MMODE_PERIOD(void);
void app_read_REG_CAM1_MMODE_PULSE(void);
void app_read_REG_RESERVED2(void);
void app_read_REG_RESERVED3(void);
void app_read_REG_EVT_EN(void);

bool app_write_REG_START_CAMS(void *a);
bool app_write_REG_STOP_CAMS(void *a);
bool app_write_REG_ENABLE_MOTORS(void *a);
bool app_write_REG_DISABLE_MOTORS(void *a);
bool app_write_REG_SET_OUTPUTS(void *a);
bool app_write_REG_CLR_OUTPUTS(void *a);
bool app_write_REG_OUTPUTS(void *a);
bool app_write_REG_INPUT0(void *a);
bool app_write_REG_CAM0(void *a);
bool app_write_REG_CAM1(void *a);
bool app_write_REG_SYNC0(void *a);
bool app_write_REG_SYNC1(void *a);
bool app_write_REG_MOTORS_STATE(void *a);
bool app_write_REG_RESERVED0(void *a);
bool app_write_REG_SYNC_INTERVAL(void *a);
bool app_write_REG_RESERVED1(void *a);
bool app_write_REG_IN0_MODE(void *a);
bool app_write_REG_CAM0_MODE(void *a);
bool app_write_REG_CAM0_FREQ(void *a);
bool app_write_REG_CAM0_MMODE_PERIOD(void *a);
bool app_write_REG_CAM0_MMODE_PULSE(void *a);
bool app_write_REG_CAM1_MODE(void *a);
bool app_write_REG_CAM1_FREQ(void *a);
bool app_write_REG_CAM1_MMODE_PERIOD(void *a);
bool app_write_REG_CAM1_MMODE_PULSE(void *a);
bool app_write_REG_RESERVED2(void *a);
bool app_write_REG_RESERVED3(void *a);
bool app_write_REG_EVT_EN(void *a);


#endif /* _APP_FUNCTIONS_H_ */