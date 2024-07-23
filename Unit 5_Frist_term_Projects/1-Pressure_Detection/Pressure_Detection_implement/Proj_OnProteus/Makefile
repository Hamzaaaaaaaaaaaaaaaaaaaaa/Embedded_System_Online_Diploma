 ###############################
 # Makeefile                   #
 #                             #
 #  Created on: Jul 13, 2024   #
 #      Author: Hamza Ahmed    #
 ###############################

#==============================================

CC=arm-none-eabi-
CFLAGS=-g -mthumb -mcpu=cortex-m3
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
AS_OBJ=$(AS:.s=.o)
LINKER=$(wildcard *.ld)
PROJ_NAME=Pressure_Detection_Hamza
##############################################

all: $(PROJ_NAME).bin
	@echo "============Bulding Process is done==========="
#-------------------------------------------------------------------

%.o:%.c
	$(CC)gcc.exe -std=c99 -c $(CFLAGS) $(INCS) $< -o $@
#-------------------------------------------------------------------

%.o:%.s
	$(CC)as.exe  $(CFLAGS)  $< -o $@
#-------------------------------------------------------------------

$(PROJ_NAME).elf: $(OBJ) $(AS_OBJ)
	$(CC)ld.exe -T $(LINKER) $(INCS) $(OBJ) -Map=Map_File.map -o $@
#-----------------------------------------------------------------------
$(PROJ_NAME).bin : $(PROJ_NAME).elf
	$(CC)objcopy.exe -O binary $< $@
#-----------------------------------------------------------------------
clean:
	rm *.elf *.bin 
clean_all:
	rm *.o *.elf *.bin 
	   @echo "==================It is been cleaned================"




