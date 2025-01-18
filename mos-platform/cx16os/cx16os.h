/*
 * cx16os.h
*/

unsigned char getin();
void chrout(unsigned char ch);
void print_str(char *str);

char *get_args(void);

unsigned short parse_num(char *num_str);
unsigned short hex_num_to_string(unsigned char b);

unsigned char kill_process(unsigned char pid);

int wait_process(unsigned char pid);

unsigned char res_extmem_bank(void);
unsigned char free_extmem_bank(unsigned char bank);

unsigned char set_extmem_rbank(unsigned char bank);
unsigned char set_extmem_wbank(unsigned char bank);

unsigned char share_extmem_bank(unsigned char bank, unsigned char pid);

char read_byte_extmem(char *ptr, unsigned offset);
int read_word_extmem(char *ptr, unsigned offset);

void write_byte_extmem(char c, char *ptr, unsigned offset);
void write_word_extmem(unsigned int i, char *ptr, unsigned offset);

unsigned char memmove_extmem(unsigned char dest_bank, void *dest, unsigned char src_bank, void *src, size_t count);
void fill_extmem(unsigned char bank, void *s, size_t count);

int send_message_general_hook(unsigned char hook_num, char *msg, unsigned char msg_len, unsigned char msg_bnk);
int send_byte_chrout_hook(char c);

unsigned char get_general_hook_info(unsigned char hook_num);
void set_own_priority(unsigned char);
void surrender_process_time(void);
void bin_to_bcd(int, unsigned char *);
int set_console_mode(unsigned char);
void set_stdin_read_mode(unsigned char);
void detach_self(unsigned char);
