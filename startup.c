#include <stdint.h>

extern uint32_t _etext;
extern uint32_t _data_start;
extern uint32_t _data_end;
extern uint32_t _bss_start;
extern uint32_t _bss_end;
extern uint32_t __stack_top;

void resetHandler(void);
void defaultHandler(void);
void sysTickHandler(void);

typedef void (*isr_t)(void);

__attribute__((section(".vectors"), used))
const isr_t vector_table[] = {
    (isr_t)&__stack_top,   // 0: Start SP
    resetHandler,          // 1: Reset
    defaultHandler,        // 2: NMI
    defaultHandler,        // 3: HardFault
    defaultHandler,        // 4: MemManage
    defaultHandler,        // 5: BusFault
    defaultHandler,        // 6: UsageFault
    0,                     // 7: reserved
    0,                     // 8: reserved
    0,                     // 9: reserved
    0,                     // 10: reserved
    defaultHandler,        // 11: SVCall
    defaultHandler,        // 12: Debug Monitor
    0,                     // 13: reserved
    defaultHandler,        // 14: PendSV
    sysTickHandler,        // 15: SysTick
    // IRQs 16..59 (44 interruptions)
    defaultHandler, defaultHandler, defaultHandler, defaultHandler,
    defaultHandler, defaultHandler, defaultHandler, defaultHandler,
    defaultHandler, defaultHandler, defaultHandler, defaultHandler,
    defaultHandler, defaultHandler, defaultHandler, defaultHandler,
    defaultHandler, defaultHandler, defaultHandler, defaultHandler,
    defaultHandler, defaultHandler, defaultHandler, defaultHandler,
    defaultHandler, defaultHandler, defaultHandler, defaultHandler,
    defaultHandler, defaultHandler, defaultHandler, defaultHandler,
    defaultHandler, defaultHandler, defaultHandler, defaultHandler,
    defaultHandler, defaultHandler, defaultHandler, defaultHandler,
    defaultHandler, defaultHandler, defaultHandler, defaultHandler
};

extern int main();

void resetHandler(void){
  uint32_t* src = &_etext;
  uint32_t* dst = &_data_start;
  uint32_t* dst_end = &_data_end;

  while(dst < dst_end){
    *dst = *src;
    dst++;
    src++;
  }

  uint32_t* bss = &_bss_start;
  uint32_t* bssEnd = &_bss_end;

  while (bss < bssEnd){
    *bss = 0;
    bss++;
  }

  main();
  while(1);
}

void defaultHandler(void){
  while(1){

  }
}

volatile uint32_t tick = 0;
void sysTickHandler(void){
  tick++;
}
