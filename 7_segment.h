#define ZERO 0x3F
#define ONE 0x06
#define TWO 0x5B
#define THREE 0x4F
#define FOUR 0x66
#define FIVE 0x6D
#define SIX 0x7D
#define SEVEN 0x07
#define EIGHT 0x7F
#define NINE 0x6F

#define DIGIT0 0x01
#define DIGIT1 0x02
#define DIGIT2 0x03
#define DIGIT3 0x04

void init_7_segment();
void print_7_segment_1_digit(char number, char digit);
char get_7_segment_digit_from_number(char number);
char get_7_segment_number_from_ascii(char number);