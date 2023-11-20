/**
  ******************************************************************************
  * @file    Bluetooth.c
  * @author  ClÃ©ment CARDOT
  * @date    11-dec-2021
  * @brief   Bluetooth communication fonctions.
  ******************************************************************************
*/
#include <stdint.h>
#include "stm32f1_uart.h"


// Initialisation du Bluetooth
static char buffer[255];
static uint8_t sommetBuffer = 0; // Sommet du buffer (0 == vide)

uint8_t isBluetoothBufferEmpty(void){
	return (sommetBuffer != 0);
}

char getNextCharFromBluetoothBuffer(void){
	for(uint8_t i = 1; i < sommetBuffer; i++){
		buffer[i-1] = buffer[i];
	}
	sommetBuffer--;
	return buffer[0];
}

void addToBluetoothBuffer(char c){
	sommetBuffer++;
	buffer[sommetBuffer] = c;
}

// TEST DU BLUETOOTH avec String --> OK
void sendString(uint8_t * c, uint32_t len){
	UART_puts(UART1_ID, c, len);
}
//

// TEST DU BLUETOOTH avec char --> Envoie le mauvais caractère ???
void sendChar(uint8_t c){
	UART_putc(UART1_ID, c);
}
//
