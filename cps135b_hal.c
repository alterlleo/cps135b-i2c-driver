#include "cps135b_hal.h"

void i2c_hal_init(void){

  cps_fb = open(I2C_DEVICE_PATH, O_RDWR);
  
  if(cps_fb >= 0){

    if(ioctl(cps_fb, I2C_SLAVE, ADDRESS) >= 0){

      return;
    }
  }
}


int8_t cps_i2c_hal_read(uint8_t* data, uint16_t count){

  if (read(cps_fb, data, count) != count) {
    return I2C_READ_FAILED;
  }
    return 0;
}

int8_t cps_i2c_hal_write(const uint8_t* data, uint16_t count){
  
  if(write(cps_fb, data, count) != count){
    return I2C_WRITE_FAILED;
  }
  
}

void cps_i2c_hal_sleep(uint32_t useconds){
  usleep(useconds);
}



/*

  _____         _                     _       
 |_   _|__  ___| |_   _ __ ___   __ _(_)_ __  
   | |/ _ \/ __| __| | '_ ` _ \ / _` | | '_ \ 
   | |  __/\__ \ |_  | | | | | | (_| | | | | |
   |_|\___||___/\__| |_| |_| |_|\__,_|_|_| |_|
                                              

*/

int main(void){

  i2c_hal_init();
  return 0;
}

