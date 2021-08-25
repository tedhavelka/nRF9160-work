#ifndef _NN_SENSOR_DRIVERS_H
#define _NN_SENSOR_DRIVERS_H

#include <zephyr/types.h>
#include <drivers/sensor.h>

/**
 * @brief Define sensors supported and planned for near term:
 * 
 */
enum nn_sensor_type
{
    NN_SENSOR_TYPE_FIRST = 0,
    NN_ACCELEROMETER_IIS2DH,
    NN_ACCELEROMETER_KX132_1211,
    NN_SENSOR_TYPE_LAST
};

#endif // NN_SENSOR_DRIVERS_H
