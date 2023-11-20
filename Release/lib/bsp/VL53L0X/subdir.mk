################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/bsp/VL53L0X/X-NUCLEO-53L0A1.c \
../lib/bsp/VL53L0X/vl53_x-nucleo-53l0A1_demo.c \
../lib/bsp/VL53L0X/vl53l0_demo.c \
../lib/bsp/VL53L0X/vl53l0a1-f103msp.c \
../lib/bsp/VL53L0X/vl53l0x_api.c \
../lib/bsp/VL53L0X/vl53l0x_api_calibration.c \
../lib/bsp/VL53L0X/vl53l0x_api_core.c \
../lib/bsp/VL53L0X/vl53l0x_api_ranging.c \
../lib/bsp/VL53L0X/vl53l0x_api_strings.c \
../lib/bsp/VL53L0X/vl53l0x_platform.c \
../lib/bsp/VL53L0X/vl53l0x_platform_log.c 

OBJS += \
./lib/bsp/VL53L0X/X-NUCLEO-53L0A1.o \
./lib/bsp/VL53L0X/vl53_x-nucleo-53l0A1_demo.o \
./lib/bsp/VL53L0X/vl53l0_demo.o \
./lib/bsp/VL53L0X/vl53l0a1-f103msp.o \
./lib/bsp/VL53L0X/vl53l0x_api.o \
./lib/bsp/VL53L0X/vl53l0x_api_calibration.o \
./lib/bsp/VL53L0X/vl53l0x_api_core.o \
./lib/bsp/VL53L0X/vl53l0x_api_ranging.o \
./lib/bsp/VL53L0X/vl53l0x_api_strings.o \
./lib/bsp/VL53L0X/vl53l0x_platform.o \
./lib/bsp/VL53L0X/vl53l0x_platform_log.o 

C_DEPS += \
./lib/bsp/VL53L0X/X-NUCLEO-53L0A1.d \
./lib/bsp/VL53L0X/vl53_x-nucleo-53l0A1_demo.d \
./lib/bsp/VL53L0X/vl53l0_demo.d \
./lib/bsp/VL53L0X/vl53l0a1-f103msp.d \
./lib/bsp/VL53L0X/vl53l0x_api.d \
./lib/bsp/VL53L0X/vl53l0x_api_calibration.d \
./lib/bsp/VL53L0X/vl53l0x_api_core.d \
./lib/bsp/VL53L0X/vl53l0x_api_ranging.d \
./lib/bsp/VL53L0X/vl53l0x_api_strings.d \
./lib/bsp/VL53L0X/vl53l0x_platform.d \
./lib/bsp/VL53L0X/vl53l0x_platform_log.d 


# Each subdirectory must supply rules for building sources it contributes
lib/bsp/VL53L0X/%.o: ../lib/bsp/VL53L0X/%.c lib/bsp/VL53L0X/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/inc" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/CMSIS/core" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/CMSIS/device" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/HAL_Driver/Inc/Legacy" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/HAL_Driver/Inc" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/Utilities/STM32F1xx_Nucleo" -O3 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

