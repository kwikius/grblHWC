#  Part of Grbl
#
#  Copyright (c) 2009-2011 Simen Svale Skogsrud
#  Copyright (c) 2012-2015 Sungeun K. Jeon
#
#  Grbl is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  Grbl is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.

# Makefile for grbl on Mightyboard
# MightyBoard is basically just a Arduino Mega1280

# name of hex file
TARGET = grbl_MightyBoard_HotWire.hex
# system avrdude
AVRDUDE = avrdude
# use local avrdude.conf file with minimal definitions
AVRDUDE_CONF = ./avrdude.conf
# atmega8U2 on Mightyboard used as a usb serial converter
UPLOAD_PORT ?= /dev/ttyACM0
DEVICE     = atmega1280
CLOCK      = 16000000L
AVRDUDE_PARAMS = -C$(AVRDUDE_CONF) -v -v -v -v -p$(DEVICE) -carduino

SOURCE    = main.c motion_control.c gcode.c spindle_control.c coolant_control.c serial.c \
             protocol.c stepper.c eeprom.c settings.c planner.c nuts_bolts.c limits.c \
             print.c probe.c report.c system.c sleep.c jog.c
BUILDDIR = build
SOURCEDIR = grbl

# Compile flags for avr-gcc .
COMPILE = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) -I. -ffunction-sections -flto

OBJECTS = $(addprefix $(BUILDDIR)/,$(notdir $(SOURCE:.c=.o)))

# symbolic targets:
all:	$(TARGET)

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(COMPILE) -MMD -MP -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $(BUILDDIR)/$@
# "-x assembler-with-cpp" should not be necessary since this is the default
# file type for the .S (with capital S) extension. However, upper case
# characters are not always preserved on Windows. To ensure WinAVR
# compatibility define the file type manually.

#.c.s:
	$(COMPILE) -S $< -o $(BUILDDIR)/$@

flash: all
ifneq (, $(shell which $(AVRDUDE)))
	$(AVRDUDE) $(AVRDUDE_PARAMS) -P$(UPLOAD_PORT) -b57600 -D -U flash:w:$(TARGET):i
else
	$(error "Need to install avrdude (and optionally provide path in the AVRDUDE Makefile variable)")
endif

clean:
	rm -f grbl.hex $(BUILDDIR)/*.o $(BUILDDIR)/*.d $(BUILDDIR)/*.elf

# file targets:
$(BUILDDIR)/main.elf: $(OBJECTS)
	$(COMPILE) -o $(BUILDDIR)/main.elf $(OBJECTS) -lm -Wl,--gc-sections

$(TARGET): $(BUILDDIR)/main.elf
	rm -f $(TARGET)
	avr-objcopy -j .text -j .data -O ihex $(BUILDDIR)/main.elf $(TARGET)
	avr-size --format=berkeley $(BUILDDIR)/main.elf
# If you have an EEPROM section, you must also create a hex file for the
# EEPROM and add it to the "flash" target.

# Targets for code debugging and analysis:
disasm:	main.elf
	avr-objdump -d $(BUILDDIR)/main.elf

cpp:
	$(COMPILE) -E $(SOURCEDIR)/main.c

# include generated header dependencies
-include $(BUILDDIR)/$(OBJECTS:.o=.d)
