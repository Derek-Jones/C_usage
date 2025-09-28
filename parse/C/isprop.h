                          /* isprop.h, 13 Apr 10 */


extern BOOL is_dec_point(DIGIT_CHAR ch);
extern BOOL is_zero(DIGIT_CHAR ch);
extern BOOL is_digit(DIGIT_CHAR ch);
extern BOOL is_start_digit(DIGIT_CHAR ch);
extern BOOL is_num_digit(DIGIT_CHAR ch);
extern BOOL is_exp_digit(DIGIT_CHAR ch);
extern BOOL is_mantissa_sign(DIGIT_CHAR ch);
extern BOOL is_exp_sign(DIGIT_CHAR ch);
extern BOOL is_exp_prefix(DIGIT_CHAR ch);
extern BOOL is_number(const char *str);
extern BOOL is_letter(DIGIT_CHAR ch);
extern BOOL is_start_letter(DIGIT_CHAR ch);
extern BOOL is_ident_ch(DIGIT_CHAR ch);

