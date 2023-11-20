/*
 * PS_2.h
 *
 *  Created on: 12 déc. 2021
 *      Author: Clement
 */

#ifndef PS2MONITOR_H_
#define PS2MONITOR_H_
#include <stdint.h>


uint8_t isPs2BufferEmpty(void);
void initPs2Monitor(void);
char getNextCodeFromPs2Buffer(void);
void set_Buffer(char c);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void decodePs2(char c);

#endif /* PS2MONITOR_H_ */
