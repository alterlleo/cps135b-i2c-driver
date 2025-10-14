#ifndef __CPS135B_H__
#define __CPS135B_H__

#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define ADDRESS 0x6D
#define I2C_DEVICE_PATH "/dev/i2c-1"

void i2c_hal_init(void){

  int i2c_success = -1;
  i2c_success = open(I2C_DEVICE_PATH, O_RDWR);
  if(i2c_success == -1){
    return; // no error
  }
}




#endif
