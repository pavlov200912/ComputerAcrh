all: main avrdude

main: 
	avr-gcc -g -O1 -std=c99 -mmcu=atmega328p -o out.elf hello.c
avrdude:
	sudo avrdude -v -patmega328p -P /dev/ttyACM0 -c arduino -U flash:w:"out.elf"
