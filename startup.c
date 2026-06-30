typedef void (*isr_t)(void);

const isr_t vector_table[] = {
  Reset_Handler,
  Default_Handler,
};
