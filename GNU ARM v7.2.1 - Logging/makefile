################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include protocol/bluetooth/lib/EFR32BG13P/GCC/subdir.mk
-include platform/middleware/glib/glib/subdir.mk
-include platform/middleware/glib/dmd/display/subdir.mk
-include platform/emlib/src/subdir.mk
-include platform/emdrv/sleep/src/subdir.mk
-include platform/Device/SiliconLabs/EFR32BG13P/Source/GCC/subdir.mk
-include platform/Device/SiliconLabs/EFR32BG13P/Source/subdir.mk
-include hardware/kit/common/drivers/subdir.mk
-include hardware/kit/common/bsp/subdir.mk
-include app/bluetooth/common/util/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ecen5823-assignments-pshiralagi.axf

# Tool invocations
ecen5823-assignments-pshiralagi.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\efr32bg13p632f512gm48.ld" -Xlinker --gc-sections -Xlinker -Map="ecen5823-assignments-pshiralagi.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -u _printf_float -o ecen5823-assignments-pshiralagi.axf -Wl,--start-group "./app/bluetooth/common/util/infrastructure.o" "./application_properties.o" "./gatt_db.o" "./gecko_main.o" "./graphics.o" "./init_app.o" "./init_board_efr32xg1.o" "./init_mcu_efr32xg1.o" "./pti.o" "./hardware/kit/common/bsp/bsp_stk.o" "./hardware/kit/common/drivers/display.o" "./hardware/kit/common/drivers/displayls013b7dh03.o" "./hardware/kit/common/drivers/displaypalemlib.o" "./hardware/kit/common/drivers/i2cspm.o" "./hardware/kit/common/drivers/mx25flash_spi.o" "./hardware/kit/common/drivers/retargetio.o" "./hardware/kit/common/drivers/retargetserial.o" "./hardware/kit/common/drivers/udelay.o" "./platform/Device/SiliconLabs/EFR32BG13P/Source/GCC/startup_efr32bg13p.o" "./platform/Device/SiliconLabs/EFR32BG13P/Source/system_efr32bg13p.o" "./platform/emdrv/sleep/src/sleep.o" "./platform/emlib/src/em_assert.o" "./platform/emlib/src/em_burtc.o" "./platform/emlib/src/em_cmu.o" "./platform/emlib/src/em_core.o" "./platform/emlib/src/em_cryotimer.o" "./platform/emlib/src/em_crypto.o" "./platform/emlib/src/em_emu.o" "./platform/emlib/src/em_gpio.o" "./platform/emlib/src/em_i2c.o" "./platform/emlib/src/em_letimer.o" "./platform/emlib/src/em_msc.o" "./platform/emlib/src/em_rmu.o" "./platform/emlib/src/em_rtcc.o" "./platform/emlib/src/em_se.o" "./platform/emlib/src/em_system.o" "./platform/emlib/src/em_timer.o" "./platform/emlib/src/em_usart.o" "./platform/middleware/glib/dmd/display/dmd_display.o" "./platform/middleware/glib/glib/bmp.o" "./platform/middleware/glib/glib/glib.o" "./platform/middleware/glib/glib/glib_bitmap.o" "./platform/middleware/glib/glib/glib_circle.o" "./platform/middleware/glib/glib/glib_font_narrow_6x8.o" "./platform/middleware/glib/glib/glib_font_normal_8x8.o" "./platform/middleware/glib/glib/glib_font_number_16x20.o" "./platform/middleware/glib/glib/glib_line.o" "./platform/middleware/glib/glib/glib_polygon.o" "./platform/middleware/glib/glib/glib_rectangle.o" "./platform/middleware/glib/glib/glib_string.o" "./src/cmu.o" "./src/energy.o" "./src/fsm.o" "./src/gpio.o" "./src/i2c.o" "./src/letimer.o" "./src/log.o" "./src/main.o" "./src/temperature.o" "C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\protocol\bluetooth\lib\EFR32BG13P\GCC\libpsstore.a" "C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\protocol\bluetooth\lib\EFR32BG13P\GCC\libbluetooth.a" "C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\protocol\bluetooth\lib\EFR32BG13P\GCC\binapploader.o" "C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\protocol\bluetooth\lib\EFR32BG13P\GCC\libmbedtls.a" "C:\Users\pkshi\SimplicityStudio\v4_workspace\ecen5823-assignments-pshiralagi\platform\radio\rail_lib\autogen\librail_release\librail_efr32xg13_gcc_release.a" -lm -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: ecen5823-assignments-pshiralagi.hex'
	arm-none-eabi-objcopy -O ihex "ecen5823-assignments-pshiralagi.axf" "ecen5823-assignments-pshiralagi.hex"
	@echo ' '

	@echo 'Building bin file: ecen5823-assignments-pshiralagi.bin'
	arm-none-eabi-objcopy -O binary "ecen5823-assignments-pshiralagi.axf" "ecen5823-assignments-pshiralagi.bin"
	@echo ' '

	@echo 'Building s37 file: ecen5823-assignments-pshiralagi.s37'
	arm-none-eabi-objcopy -O srec "ecen5823-assignments-pshiralagi.axf" "ecen5823-assignments-pshiralagi.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "ecen5823-assignments-pshiralagi.axf" -A
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ecen5823-assignments-pshiralagi.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
