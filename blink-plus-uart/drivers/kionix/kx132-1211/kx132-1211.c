/**
 * Cornel Pump IIoT, Pulse Stage 1 firmware work
 * @author Ted Havelka (thavelka@cornellpump.com)
 * @copyright Copyright Cornell Pump 2021
 */

#define DT_DRV_COMPAT kionix_kx132

#include <math.h>
#include <device.h>
#include <drivers/i2c.h>
#include <drivers/sensor.h>
#include "kx132-1211.h"

#include <logging/log.h>
LOG_MODULE_REGISTER(kx132, CONFIG_SENSOR_LOG_LEVEL);



// Note:  struct sensor_value is defined in Zephyr's sensor.h header
// file.  In Nordic ncs v1.6.1 SDK this file found in
// nsc/v1.6.1/zephyr/include/drivers
//----------------------------------------------------------------------

struct kx132_data
{
    const struct device *i2c_dev;
    union device_string string_id_manufacturer;
    union device_string string_id_part;
    struct sensor_value accel_axis_x;
    struct sensor_value accel_axis_y;
    struct sensor_value accel_axis_z;
};



static int kx132_device_id_fetch(const struct device *dev, enum sensor_channel channel)
{
    int error = 0;
    struct kx132_data *dat = (struct kx132_data *)dev->data;

    uint8_t cmd[] = CMD_KX132_REQUEST_MANUFACTURER_ID;
    uint8_t rx_buf[] = {0, 0, 0, 0};


    // request manufacturer ID string from Kionix KX132-1211 sensor
    err = i2c_write_read(dat->i2c_dev, DT_INST_REG_ADDR(0),
                         cmd, sizeof(cmd), rx_buf, sizeof(rx_buf));
    if (error)
    {
        LOG_WRN("Unable to read manufacturer ID string. Err: %i", error);
        return error;
    }

    printk("sensor manufacturer id: %s\n", rx_buf);

}


static int kx132_device_id_get(const struct device *dev, enum sensor_channel channel)
{

}


static int kx132_sample_fetch(const struct device *dev, enum sensor_channel channel)
{

}


static int kx132_sample_get(const struct device *dev, enum sensor_channel channel)
{

}



// FEATURE - initializating function in KX132-1211 driver:

static int kx132_init(const struct device *dev)
{
    struct kx132_data *data = dev->data;

    data->i2c_dev = device_get_binding(DT_INST_BUS_LABEL(0));

    if (data->i2c_dev == NULL)
    {
        LOG_ERR("Unable to get I2C Master.");
        return -EINVAL;
    }

    return 0;
}


// FEATURE - structure to capture pointers to KX132 driver functions:

static const struct sensor_driver_api kx132_api = {
    .device_id_fetch = &kx132_device_id_fetch,
    .device_id_get = &kx132_device_id_get,
    .device_sample_fetch = &kx132_device_sample_fetch,
    .device_sample_get = &kx132_device_sample_get,
};


static struct kx132_data kx132_data;


DEVICE_DEFINE(kx132-1211,
              DT_INST_LABEL(0),
              kx132_init,
              NULL,
              &kx132_data,
              NULL,
              POST_KERNEL,
              CONFIG_SENSOR_INIT_PRIORITY,
              &kx132_api
);

// --- EOF ---
