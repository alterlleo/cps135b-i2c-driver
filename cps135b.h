#ifndef __CPS135B_H__
#define __CPS135B_H__

#include "cps135b_hal.h"

typedef struct{

  uint32_t p24_raw; // 24 bit for pressure
  int16_t  t16_raw; // 16 bit for temperature
  double pressure_kPa;
  double temperature_C;
} cps135b_sample;

int cps135b_init(void);

int cps135b_read(cps135b_sample* output);



#endif

