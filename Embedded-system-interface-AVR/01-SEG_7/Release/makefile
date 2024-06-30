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
SEG_7.lss \

FLASH_IMAGE += \
SEG_7.hex \

EEPROM_IMAGE += \
SEG_7.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: SEG_7.elf secondary-outputs

# Tool invocations
SEG_7.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SEG_7.map -mmcu=atmega32 -o "SEG_7.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SEG_7.lss: SEG_7.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SEG_7.elf  >"SEG_7.lss"
	@echo 'Finished building: $@'
	@echo ' '

SEG_7.hex: SEG_7.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SEG_7.elf  "SEG_7.hex"
	@echo 'Finished building: $@'
	@echo ' '

SEG_7.eep: SEG_7.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SEG_7.elf  "SEG_7.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SEG_7.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SEG_7.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SEG_7.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
