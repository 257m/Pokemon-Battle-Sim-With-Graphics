#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// The lexer returns tokens [0-255] if it is an unknown character, otherwise one
// of these for known things.
enum Token {
	tok_eof = -1,

	tok_identifier = -2,
	tok_number = -3,
};

#define IDENTIFIER_MAX 32
#define NUMBER_MAX 384

static char IdentifierStr [IDENTIFIER_MAX]; // Filled in if tok_identifier
static int NumVal;							// Filled in if tok_number

/* Custom String Functions */
bool string_compare(const char* str1,const char* str2)
{
	int charnum = 0;

    while(str1[charnum] == str2[charnum])
    {
        if(str1[charnum] == '\0'|| str2[charnum] == '\0')
            break;
        charnum++;
    }
    
	if(str1[charnum] == '\0' && str2[charnum] == '\0')
        return 1;
	
	return 0;
}

char* CharToNull(char* string,char* output,char c)
{
	unsigned int charnum = 0;
	while (string[charnum] != '\0') {
		if (string[charnum] != c) {
			output[charnum] = string[charnum];
			charnum++;
		}
		else {
			output[charnum] = '\0';
			return output;
		}
	}
	return output;
}

void str_append(char* string,char c)
{
	unsigned int charnum = 0;
	
	while(string[charnum] != '\0')
		charnum++;
	
	string[charnum] = c;
}

void SetStringToChar(char* string,char c)
{
	unsigned int charnum = 0;
	string[charnum++] = c;
	while(string[charnum] != '\0')
		string[charnum++] = '\0';
}

FILE* input;
FILE* output;

static int CurTok = 0;
static int LastTok = 0;
/// gettok - Return the next token from standard input.
static int gettok()
{
	static int LastChar = ' ';

  	// Skip any whitespace.
	while (isspace(LastChar))
    	LastChar = fgetc(input);

	if (isalpha(LastChar) || LastChar == '?') { // identifier: [a-zA-Z][a-zA-Z0-9]*
	  SetStringToChar(IdentifierStr,LastChar);
	  while (isalnum((LastChar = fgetc(input))) || LastChar == '?')
    	str_append(IdentifierStr,LastChar);
  		return tok_identifier;
	}

	if (isdigit(LastChar) || LastChar == '-') {   // Number: [0-9.]+
		char NumStr [NUMBER_MAX] = "";
  		
		do {
    		str_append(NumStr,LastChar);
    		LastChar = fgetc(input);
		} while (isdigit(LastChar) || LastChar == '.');

		NumVal = atoi(NumStr);
		return tok_number;
	}

	// Check for end of file.  Don't eat the EOF.
  	if (LastChar == EOF)
    	return tok_eof;

	// character_return:
  	// Otherwise, just return the character as its ascii value.
  	int ThisChar = LastChar;
  	LastChar = fgetc(input);
  	return ThisChar;
}

#define getNextToken() LastTok = CurTok; (CurTok = gettok())

float ConvertFromCustomEffectiveness(int NumVal) {
	switch(NumVal) {
		case 2:
			return 2.0f;
		case 1:
			return 1.0f;
		case 0:
			return 0.5f;
		default:
			return 0.0f;
	}
}

int main(int argc,char** argv)
{
	if (argc != 2 && argc != 3) {
		fprintf(stderr,"usage: %s input_typechart.txt output_typechart.txt",argv[0]);
		exit(0);
	}
	input = fopen(argv[1],"r");
	if (argc == 2) {
		output = fopen("output.txt","w");
	}
	else {
		output = fopen(argv[2],"w");
	}
	int ident_num = 0;
	fprintf(output,"float TypeChart [][] = {\n");
	while (1) {
		getNextToken();
		switch(CurTok) {
			case tok_identifier:
				if (LastTok == tok_number)
					fprintf(output,"},\n");
				fprintf(output,"// [%d] %s\n{",ident_num,IdentifierStr);
				ident_num++;
				break;
			case tok_number:
				if (LastTok != tok_identifier)
					fprintf(output,",");
				fprintf(output,"%.1f",ConvertFromCustomEffectiveness(NumVal));
				break;
			case tok_eof:
				if (LastTok == tok_number)
					fprintf(output,"}\n");
				goto end;
			default:
				break;
		}
	}
	end:
	fprintf(output,"};");
	fclose(input);
	fclose(output);
	return 0;
}