################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../platform/middleware/glib/dmd/display/dmd_display.c 

OBJS += \
./platform/middleware/glib/dmd/display/dmd_display.o 

C_DEPS += \
./platform/middleware/glib/dmd/display/dmd_display.d 


# Each subdirectory must supply rules for building sources it contributes
platform/middleware/glib/dmd/display/dmd_display.o: ../platform/middleware/glib/dmd/display/dmd_display.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__HEAP_SIZE=0xD00' '-D__StackLimit=0x20000000' '-D__STACK_SIZE=0x800' '-DEFR32BG13P632F512GM48=1' -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\middleware\glib\glib" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\middleware\glib\dmd" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\middleware\glib" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\emlib\src" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\emlib\inc" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\Device\SiliconLabs\EFR32BG13P\Include" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\protocol\bluetooth\ble_stack\inc\common" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\CMSIS\Include" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\radio\rail_lib\chip\efr32\efr32xg1x" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\bootloader\api" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\app\bluetooth\common\util" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\emdrv\uartdrv\inc" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\hardware\kit\common\drivers" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\hardware\kit\common\halconfig" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\hardware\kit\EFR32BG13_BRD4104A\config" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\radio\rail_lib\common" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\protocol\bluetooth\ble_stack\inc\soc" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\Device\SiliconLabs\EFR32BG13P\Source\GCC" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\hardware\kit\common\bsp" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\radio\rail_lib\protocol\ieee802154" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\Device\SiliconLabs\EFR32BG13P\Source" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\emdrv\common\inc" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\radio\rail_lib\protocol\ble" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\halconfig\inc\hal-config" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\emdrv\sleep\inc" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\emdrv\sleep\src" -I"C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\bootloader" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"platform/middleware/glib/dmd/display/dmd_display.d" -MT"platform/middleware/glib/dmd/display/dmd_display.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


