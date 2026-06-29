MEMORY
{
  FLASH(rw) : ORIGIN = 0x00000000, LENGTH = 256K
  SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

.stack (NOLOAD) :
{
  . = ALIGN(8);
  . =  + 0x800;
  __stack_top = .;
} > SRAM
