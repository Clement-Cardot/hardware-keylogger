/**
  ******************************************************************************
  * @file    main.c
  * @author  Clement CARDOT
  * @date    11-dec-2021
  * @brief   Default main function.
  ******************************************************************************
*/
#include "ps2Monitor.h"
#include "stm32f1xx_hal.h"
#include "stm32f1_uart.h"
#include "stm32f1_sys.h"
#include "stm32f1_gpio.h"
#include "stm32f1_extit.h"
#include "macro_types.h"
#include "systick.h"
#include <stdint.h>
#include "Bluetooth.h"

// Test & Debug Functions
void Test(){
   	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_15);
}
void writeLED(bool_e b)
{
	HAL_GPIO_WritePin(LED_GREEN_GPIO, LED_GREEN_PIN, b);
}
void writePcbLed(bool_e b)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, b);
}
bool_e readButton(void)
{
	return !HAL_GPIO_ReadPin(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN);
}
static volatile uint32_t t = 0;
static volatile uint32_t b = 0;
void process_ms(void)
{
	if(t) t--;
	if(b) b--;
}
///////////////////////////////


void initBluePill(){
	//Initialisation de la couche logicielle HAL (Hardware Abstraction Layer)
	//Cette ligne doit rester la premi�re �tape de la fonction main().
	HAL_Init();

	//Initialisation de l'UART2 � la vitesse de 115200 bauds/secondes (92kbits/s) PA2 : Tx  | PA3 : Rx.
		//Attention, les pins PA2 et PA3 ne sont pas reli�es jusqu'au connecteur de la Nucleo.
		//Ces broches sont redirig�es vers la sonde de d�bogage, la liaison UART �tant ensuite encapsul�e sur l'USB vers le PC de d�veloppement.
	UART_init(UART2_ID,115200);

	//Initialisation de l'UART1 qui communique avec le module Bluetooth HC-05
	UART_init(UART1_ID,9600);

	//"Indique que les printf sortent vers le p�riph�rique UART2."
	SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

	//Initialisation du port de la led Verte (carte Nucleo)
	BSP_GPIO_PinCfg(LED_GREEN_GPIO, LED_GREEN_PIN, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);

	//Initialisation du port du bouton bleu (carte Nucleo)
	BSP_GPIO_PinCfg(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);

	//Initialisation du port de la led rouge de Debug
	BSP_GPIO_PinCfg(GPIOA, GPIO_PIN_15, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);

	//On ajoute la fonction process_ms � la liste des fonctions appel�es automatiquement chaque ms par la routine d'interruption du p�riph�rique SYSTICK
	Systick_add_callback_function(&process_ms);
}


int main(void){

	initBluePill();

	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_15);

	initPs2Monitor();

	EXTIT_set_callback(Test, GPIO_PIN_3, 1);

	while(1)	//boucle de tache de fond
	{
		if(!t)
		{
			t = 200;
			HAL_GPIO_TogglePin(LED_GREEN_GPIO, LED_GREEN_PIN);
		}

		if(!b){
			b = 10000;
			sendString("b",1);
		}
		/*
		if(isBluetoothBufferEmpty()){
			sendChar(getNextCharFromBluetoothBuffer());
		}
		if(isPs2BufferEmpty()){
			decodePs2(getNextCodeFromPs2Buffer());
		}
		*/
	}
}
