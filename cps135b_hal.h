#ifndef __CPS135B_H__
#define __CPS135B_H__

#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>

#define ADDRESS 0x6D
#define I2C_DEVICE_PATH "/dev/i2c-1"
#define I2C_WRITE_FAILED -1
#define I2C_READ_FAILED -1

static int cps_fb = 0;
static int cps_device = -1;

void i2c_hal_init(void);

int8_t cps_i2c_hal_read(uint8_t* data, uint16_t count);

int8_t cps_i2c_hal_write(const uint8_t* data, uint16_t count);

void cps_i2c_hal_sleep(uint32_t useconds);

#endif
