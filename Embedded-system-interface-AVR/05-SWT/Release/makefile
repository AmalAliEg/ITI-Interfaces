################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO_driver/Debug/subdir.mk
-include MCAL/DIO_driver/subdir.mk
-include HAL/SSD_driver/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SWT.lss \

FLASH_IMAGE += \
SWT.hex \

EEPROM_IMAGE += \
SWT.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: SWT.elf secondary-outputs

# Tool invocations
SWT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SWT.map -mmcu=atmega32 -o "SWT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SWT.lss: SWT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SWT.elf  >"SWT.lss"
	@echo 'Finished building: $@'
	@echo ' '

SWT.hex: SWT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SWT.elf  "SWT.hex"
	@echo 'Finished building: $@'
	@echo ' '

SWT.eep: SWT.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SWT.elf  "SWT.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SWT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SWT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SWT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
