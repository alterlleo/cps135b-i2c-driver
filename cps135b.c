/*

   ____ ____  ____  _ _________  ____  
  / ___|  _ \/ ___|/ |___ / ___|| __ ) 
 | |   | |_) \___ \| | |_ \___ \|  _ \ 
 | |___|  __/ ___) | |___) |__) | |_) |
  \____|_|   |____/|_|____/____/|____/ 
                                       

According to datasheet, CPS135B can work in 2 states: it is in SLEEP mode until a measurement request (MR) message occurs. When it comes, the sensor wakes up, measures and stores the measure value in internal registers and then it returns in sleep mode
*/


#include "cps135b.h"

#define CPS_CMD_MEASURE_0   0x30  // MR high byte
#define CPS_CMD_MEASURE_1   0x0A  // MR low  byte
#define CPS_REG_DATA        0x06  // data pointer
#define CPS_CONV_TIME_US    6000  // ~6 ms tot

int cps135b_init(void){
  i2c_hal_init();
}

int cps135b_read(uint32_t* p24, int16_t* t16){
  
}




/*
  _   _      _                    __                  _   _                 
 | | | | ___| |_ __   ___ _ __   / _|_   _ _ __   ___| |_(_) ___  _ __  ___ 
 | |_| |/ _ \ | '_ \ / _ \ '__| | |_| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 |  _  |  __/ | |_) |  __/ |    |  _| |_| | | | | (__| |_| | (_) | | | \__ \
 |_| |_|\___|_| .__/ \___|_|    |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
              |_|                                                           
*/

int cps135b_request_measurement(void){
  uint8_t mex[2] = {CPS_CMD_MEASURE_0, CPS_CMD_MEASURE_1};
  int ret_code = cps_i2c_hal_write(mex, 2);

  if(ret_code){
    return ret_code;
  
  } else{
    cps_i2c_hal_sleep(CPS_CONV_TIME_US);
    return 0;

  }
}

int cps135b_convert(uint32_t p24, int16_t t16, double *kPa, double *tC){
// Scaling tipico: P_raw / 2^5 / 1000 -> kPa ; T_raw / 256 -> °C
  if (kPa)  *kPa  = (double)p24 / 32.0 / 1000.0;
  if (tC) *tC = (double)t16 / 256.0;
}