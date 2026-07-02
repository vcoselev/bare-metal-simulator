#include <stdint.h>

#define CORE_PERIPHERALS_BASE_ADDRESS 0xE000E000
#define STCTRL (*(volatile uint32_t *)(CORE_PERIPHERALS_BASE_ADDRESS + 0x010))
#define STRELOAD (*(volatile uint32_t *)(CORE_PERIPHERALS_BASE_ADDRESS + 0x014))
#define STCURRENT (*(volatile uint32_t *)(CORE_PERIPHERALS_BASE_ADDRESS + 0x018))

void sysTickConfig(void);

int main(){
  sysTickConfig();
  return 0;
}

void sysTickConfig(void){
  STRELOAD = 4999999;
  STCURRENT = 0;
  STCTRL = (1 << 0) | (1 << 1) | (1 << 2);
}
