#ifndef GENERAL_H
#define GENERAL_H

double statboostmult(char statboost);
float ppboostmult(char ppboost);
unsigned int map(unsigned int num,unsigned int newmax,unsigned int currentmax);
unsigned int map2(unsigned int num,unsigned int newmax,unsigned int currentmax);
unsigned int power2(char num);
double never0(double num);
extern const char Stagenames [8][16];
extern const char Itemtext[2][11];
extern const char Statusnames [8][12];
extern const char EOPTEXT[8][14];
extern const char TypeNames[32][14];
char* stratt(const char *s1, const char *s2);
char* str_delete_char(char* string,unsigned int del_char);
char* str_replace_spaces_with_underscore(const char* string);
char* str_compress(const char* decompressed_string);
char* str_format_and_compress(const char* original_decompressed_string);
char* str_format_and_compress_free(const char* original_decompressed_string);
char* str_decompress(const char* compressed_string);
char* str_decompressed_format(char* decompressed_string);
char* str_decompress_and_format(const char* compressed_string);
char* str_decompress_and_format_free(const char* compressed_string);
char* str_decompress_format_prealloc(const char* compressed_string,char* decompressed_string);

#endif // GENERAL_H //