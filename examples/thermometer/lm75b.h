#if !defined __LM75B_H__
#define __LM75B_H__

void twi_init (void);
void twi_uninit(void);
void LM75B_normal_mode(void);
void LM75B_read_data(void);
ret_code_t LM75B_shutdown(void);
//bool is_xfer_done(void);

uint32_t LM75B_get_tC(void);
uint32_t LM75B_get_tCf(void);



#endif /*__LM75B_H__*/
