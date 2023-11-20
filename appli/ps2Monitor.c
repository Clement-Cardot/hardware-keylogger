/**
  ******************************************************************************
  * @file    PS_2.c
  * @author  Clément CARDOT
  * @date    11-dec-2021
  * @brief   PS/2 read and decode fonctions.
  ******************************************************************************
*/
#include <stdint.h>
#include "stm32f1_gpio.h"
#include "stm32f1_uart.h"
#include "Bluetooth.h"

static char buffer[255];  //Buffer des caractères en entrées
static uint8_t sommetBuffer = 0; // Sommet du buffer (0 == vide)

// Tableau de conversion
char char_table[][3] =
{	{0x0e,'|',' '},
	{0x15,'q','Q'},
	{0x16,'1','!'},
	{0x1a,'z','Z'},
	{0x1b,'s','S'},
	{0x1c,'a','A'},
	{0x1d,'w','W'},
	{0x1e,'2','"'},
	{0x21,'c','C'},
	{0x22,'x','X'},
	{0x23,'d','D'},
	{0x24,'e','E'},
	{0x25,'4','$'},
	{0x26,'3',' '},
	{0x29,' ',' '},
	{0x2a,'v','V'},
	{0x2b,'f','F'},
	{0x2c,'t','T'},
	{0x2d,'r','R'},
	{0x2e,'5','%'},
	{0x31,'n','N'},
	{0x32,'b','B'},
	{0x33,'h','H'},
	{0x34,'g','G'},
	{0x35,'y','Y'},
	{0x36,'6','&'},
	{0x39,',',';'},
	{0x3a,'m','M'},
	{0x3b,'j','J'},
	{0x3c,'u','U'},
	{0x3d,'7','/'},
	{0x3e,'8',' '},
	{0x41,',',';'},
	{0x42,'k','K'},
	{0x43,'i','I'},
	{0x44,'o','O'},
	{0x45,'0','='},
	{0x46,'9',' '},
	{0x49,'.',':'},
	{0x4a,'-','_'},
	{0x4b,'l','L'},
	{0x4c,' ',' '},
	{0x4d,'p','P'},
	{0x4e,'+','*'},
	{0x52,' ',' '},
	{0x54,' ',' '},
	{0x55,'\\',' '},
	{0x5a,'\r','\r'},
	{0x5b,' ',' '},
	{0x5d,'\'',' '},
	{0x61,'<','>'},
	{0x66,'\b','\b'},
	{0x69,'1',' '},
	{0x6b,'4',' '},
	{0x6c,'7',' '},
	{0x70,'0',' '},
	{0x71,',',' '},
	{0x72,'2',' '},
	{0x73,'5',' '},
	{0x74,'6',' '},
	{0x75,'8',' '},
	{0x79,'+',' '},
	{0x7a,'3',' '},
	{0x7b,'-',' '},
	{0x7c,'*',' '},
	{0x7d,'9',' '},
	{0,'\0','\0'}
};

uint8_t isPs2BufferEmpty(void){
	return ( sommetBuffer !=0 );
}

void initPs2Monitor(void){
	//Autorise le périphérique GPIO à lever une requête d'interruption
	BSP_GPIO_PinCfg(GPIOB, GPIO_PIN_3, GPIO_MODE_IT_FALLING, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH);

	//Initialisation du port du pin DATA
	BSP_GPIO_PinCfg(GPIOB, GPIO_PIN_4, GPIO_MODE_INPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH);

	//Autorise la demande d'interruption correspondante à interrompre le processeur
	NVIC_EnableIRQ(EXTI3_IRQn);
	HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);

}

char getNextCodeFromPs2Buffer(void){
	for(uint8_t i = 1; i < sommetBuffer; i++){
		buffer[i-1] = buffer[i];
	}
	sommetBuffer--;
	return buffer[0];
}

void set_Buffer(char c){
	sommetBuffer++;
	buffer[sommetBuffer] = c;
}

/*
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    if(GPIO_Pin == GPIO_PIN_3) // INT Source is pin B3
    {
	//Acquittement du flag d'interruption
		__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_3);
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_15);
		sendString("i",1);

		static uint8_t bitcount = 0;
		static unsigned char data = 0x00;
		if(bitcount > 0 && bitcount < 9){
			data >>= 1;
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)){
				data = 0x80;
			}
		}
		bitcount ++;
		if(bitcount == 10){
			sommetBuffer++;
			buffer[sommetBuffer] = data;
			bitcount = 10;
			data = 0x00;
		}
    }
}
*/

// Fonction de décode de caractère
void decodePs2(char c){
		char data = c;
		static int shifted = 0;
		static int released = 0;
		if(released){
			switch(data){
			case 0x59:
				break;
			case 0x12:
				shifted = 0;
				break;
			default:
				break;
			}
		}
		else switch(data){
			case 0x59: //right shift
				break;
			case 0x12: //left shift
				shifted = 1;
				break;
			case 0xF0: //break code
				released = 1;
				break;
			default:
				for(int i = 0; data != char_table[i][0]; i++){
					if(char_table[i][0] == 0) break;
					if(data == char_table[i][0]){
						if(shifted) addToBluetoothBuffer(char_table[i][2]);
						else 		addToBluetoothBuffer(char_table[i][1]);
						break;
					}
				}

		}
		for(uint8_t i = 2; i < sommetBuffer; i++){
			buffer[i-1] = buffer[i];
		}
		sommetBuffer--;
}

