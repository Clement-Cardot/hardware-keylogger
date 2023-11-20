################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../lib/startup_stm32f103xb.s 

OBJS += \
./lib/startup_stm32f103xb.o 

S_DEPS += \
./lib/startup_stm32f103xb.d 


# Each subdirectory must supply rules for building sources it contributes
lib/%.o: ../lib/%.s lib/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -c -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/inc" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/CMSIS/core" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/CMSIS/device" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/HAL_Driver/Inc/Legacy" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/HAL_Driver/Inc" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/Utilities/STM32F1xx_Nucleo" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

