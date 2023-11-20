################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/middleware/MIDI/midi.c \
../lib/middleware/MIDI/usb_device.c \
../lib/middleware/MIDI/usbd_conf.c \
../lib/middleware/MIDI/usbd_core.c \
../lib/middleware/MIDI/usbd_ctlreq.c \
../lib/middleware/MIDI/usbd_desc.c \
../lib/middleware/MIDI/usbd_ioreq.c \
../lib/middleware/MIDI/usbd_midi.c \
../lib/middleware/MIDI/usbd_midi_if.c 

OBJS += \
./lib/middleware/MIDI/midi.o \
./lib/middleware/MIDI/usb_device.o \
./lib/middleware/MIDI/usbd_conf.o \
./lib/middleware/MIDI/usbd_core.o \
./lib/middleware/MIDI/usbd_ctlreq.o \
./lib/middleware/MIDI/usbd_desc.o \
./lib/middleware/MIDI/usbd_ioreq.o \
./lib/middleware/MIDI/usbd_midi.o \
./lib/middleware/MIDI/usbd_midi_if.o 

C_DEPS += \
./lib/middleware/MIDI/midi.d \
./lib/middleware/MIDI/usb_device.d \
./lib/middleware/MIDI/usbd_conf.d \
./lib/middleware/MIDI/usbd_core.d \
./lib/middleware/MIDI/usbd_ctlreq.d \
./lib/middleware/MIDI/usbd_desc.d \
./lib/middleware/MIDI/usbd_ioreq.d \
./lib/middleware/MIDI/usbd_midi.d \
./lib/middleware/MIDI/usbd_midi_if.d 


# Each subdirectory must supply rules for building sources it contributes
lib/middleware/MIDI/%.o: ../lib/middleware/MIDI/%.c lib/middleware/MIDI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/inc" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/CMSIS/core" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/CMSIS/device" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/HAL_Driver/Inc/Legacy" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/HAL_Driver/Inc" -I"D:/OneDrive - ESEO/I1/DEEP/Projet DEEP/Projet Keylogger/Repo/Utilities/STM32F1xx_Nucleo" -O3 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

