all: main avrdude

main: 
	avr-gcc -g -O1 -std=c99 -mmcu=atmega328p -o out.elf deflexer.c
avrdude:
	sudo avrdude -v -patmega328p -P /dev/ttyACM4 -c arduino -U flash:w:"out.elf"
