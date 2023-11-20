/*
 * Bluetooth.h
 *
 *  Created on: 12 déc. 2021
 *      Author: Clement
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "stm32f1_uart.h"

uint8_t isBluetoothBufferEmpty(void);
char getNextCharFromBluetoothBuffer(void);
void addToBluetoothBuffer(char c);
void sendString(uint8_t * c, uint32_t len);
void sendChar(char c);

#endif /* BLUETOOTH_H_ */
