ENTRY(resetHandler)

MEMORY
{
  FLASH(rw) : ORIGIN = 0x00000000, LENGTH = 256K
  SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
  .text : {
    *(.vectors)
    *(.text*)
    *(.rodata*)
    . = ALIGN(4);
  } > FLASH

  .ARM.exidx : {
    *(.ARM.exidx*)
    . = ALIGN(4);
  } > FLASH

  _etext = .;

  .data : AT(_etext) {
    _data_start = .;
    *(.data*)
    . = ALIGN(4);
    _data_end = .;
  } > SRAM

  .bss : {
    _bss_start = .;
    *(.bss*)
    . = ALIGN(4);
    _bss_end = .;
  } > SRAM

  .stack (NOLOAD) :
  {
    . = ALIGN(8);
    . = . + 0x800;
    __stack_top = .;
  } > SRAM
}
