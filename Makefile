CC = clang
CFLAGS_TARGET = --target=armv7m-none-eabi -mcpu=cortex-m3 -mthumb
CFLAGS_COMPILATION = -Wall -Wextra -g -ffreestanding
LDFLAGS = -T linker.ld -nostdlib -fuse-ld=lld

all: main.elf

main.elf: startup.o main.o
	$(CC) $(CFLAGS_TARGET) $(CFLAGS_COMPILATION) $^ -o $@ $(LDFLAGS)

startup.o: startup.c 
	$(CC) $(CFLAGS_TARGET) $(CFLAGS_COMPILATION) -c $< -o $@

main.o: main.c 
	$(CC) $(CFLAGS_TARGET) $(CFLAGS_COMPILATION) -c $< -o $@

clean: 
	rm -f *.o *.elf
