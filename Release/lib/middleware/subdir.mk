################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/middleware/dialog.c 

OBJS += \
./lib/middleware/dialog.o 

C_DEPS += \
./lib/middleware/dialog.d 


# Each subdirectory must supply rules for building sources it contributes
lib/middleware/%.o: ../lib/middleware/%.c lib/middleware/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/inc" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/CMSIS/core" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/CMSIS/device" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/HAL_Driver/Inc/Legacy" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/HAL_Driver/Inc" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/Utilities/STM32F1xx_Nucleo" -O3 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

