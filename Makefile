CC = clang
CFLAGS_TARGET = -target=armv7m-none-eabi -mcpu=cortex-m3 -mthumb
CFLAGS_COMPILATION = -Wall -Wextra -g -ffreestanding
LDFLAGS = -T linker.ld -nostdlib

all: main.elf

main.elf: startup.o main.o
	$(CC) $(CFLAGS_TARGET) $(CFLAGS_COMPILATION) 

