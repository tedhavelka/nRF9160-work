#ifndef KX132_1211_H
#define KX132_1211_H


// For following defines see Kionix document
// KX132-1211-Technical-Reference-Manual-Rev-3.0.pdf

#define MAN_ID (0x00)
#define PART_ID (0x01)

// KX132-1211 I2C sensor address with ADDR pin connected to IO_VDD:
#define KX132_I2C_ADDRESS_PRIMARY (0x1F)
#define KX132_I2C_ADDRESS_FLIPPED (0x1D)
#define KX132_I2C_SENSOR_ADDRESS KX132_I2C_ADDRESS_PRIMARY


#define CMD_KX132_REQUEST_MANUFACTURER_ID { KX132_I2C_SENSOR_ADDRESS, MAN_ID }

#define CMD_KX132_REQUEST_PART_ID { KX132_I2C_SENSOR_ADDRESS, PART_ID }



#endif
