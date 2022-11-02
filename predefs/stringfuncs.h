char* stratt(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
/*
stratt simply returns str1 + str2 without changing str1
*/

char* stratt_free(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    free_enqueue(&garbage_strings,result);
    return result;
}
/*
same as stratt except it puts the string on the queue to be freed
*/

char* str_delete_char(char* string,unsigned int del_char) {
  char lensave = (strlen(string)-del_char)+2;
  for (int i = del_char;i < lensave;i++) {
    string[i] = string[i+1];
  }
  return string;
}

char* str_replace_spaces_with_underscore(const char* string) {
  char *result = malloc(strlen(string) + 1);
  strcpy(result,string);
  for(int i = 0;i < strlen(result)+1;i++) {
    if (result[i] == 32) result[i] = 95;
  }
  return result;
}

char* str_compress(const char* decompressed_string) {
  char* compressed_string = malloc(ceil((strlen(decompressed_string)*5/8)+1)+1);
  for (int i = 0;i < strlen(compressed_string)+1;i++) {
    compressed_string[i] = 0;
  }
  for (int i = 0;i < strlen(decompressed_string)+1;i++) {
      if ((i*5/8) == (((i*5)+4)/8)) {
      compressed_string[i*5/8] |= ((decompressed_string[i] & 31) << (3-((i*5) % 8)));
        } else {
      compressed_string[i*5/8] |= (decompressed_string[i] & 31) >> (((i*5) % 8)-3);
      compressed_string[(i+1)*5/8] |= (decompressed_string[i] & 31) << (11-((i*5) % 8));
       }
  }
   return compressed_string;
}

char* str_format_and_compress(const char* original_decompressed_string) {
  unsigned int decompressed_length = strlen(original_decompressed_string)+1;
  char* decompressed_string = malloc(decompressed_length);
  strcpy(decompressed_string,original_decompressed_string);
  for (int i = 0;i < decompressed_length;i++) {
    if (decompressed_string[i] == 32) decompressed_string[i] = 27;
    else if (decompressed_string[i] == 45) decompressed_string[i] = 28;
  }
  char* compressed_string = malloc(ceil((decompressed_length*5/8)+1)+1);
  unsigned int compressed_length = strlen(compressed_string)+1;
  for (int i = 0;i < compressed_length+1;i++) {
    compressed_string[i] = 0;
  }
  for (int i = 0;i < decompressed_length+1;i++) {
      if ((i*5/8) == (((i*5)+4)/8)) {
      compressed_string[i*5/8] |= ((decompressed_string[i] & 31) << (3-((i*5) % 8)));
        } else {
      compressed_string[i*5/8] |= (decompressed_string[i] & 31) >> (((i*5) % 8)-3);
      compressed_string[(i+1)*5/8] |= (decompressed_string[i] & 31) << (11-((i*5) % 8));
       }
  }
   free(decompressed_string);
   return compressed_string;
}

char* str_format_and_compress_free(const char* original_decompressed_string) {
  unsigned int decompressed_length = strlen(original_decompressed_string)+1;
  char* decompressed_string = malloc(decompressed_length);
  strcpy(decompressed_string,original_decompressed_string);
  for (int i = 0;i < decompressed_length;i++) {
    if (decompressed_string[i] == 32) decompressed_string[i] = 27;
    else if (decompressed_string[i] == 45) decompressed_string[i] = 28;
  }
  char* compressed_string = malloc(ceil((decompressed_length*5/8)+1)+1);
  unsigned int compressed_length = strlen(compressed_string)+1;
  for (int i = 0;i < compressed_length+1;i++) {
    compressed_string[i] = 0;
  }
  for (int i = 0;i < decompressed_length+1;i++) {
      if ((i*5/8) == (((i*5)+4)/8)) {
      compressed_string[i*5/8] |= ((decompressed_string[i] & 31) << (3-((i*5) % 8)));
        } else {
      compressed_string[i*5/8] |= (decompressed_string[i] & 31) >> (((i*5) % 8)-3);
      compressed_string[(i+1)*5/8] |= (decompressed_string[i] & 31) << (11-((i*5) % 8));
       }
  }
   free(decompressed_string);
   free_enqueue(&garbage_strings,compressed_string);
   return compressed_string;
}

char* str_decompress(const char* compressed_string) {
  unsigned int decompressed_length = ceil(strlen(compressed_string)*1.6)+1;
  char* decompressed_string = malloc(decompressed_length);
  for (int i = 0;i < decompressed_length;i++) {
    decompressed_string[i] = 0;
  }
  for (int i = 0;i < decompressed_length;i++) {
    if ((i*5/8) == (((i*5)+4)/8)) {
      decompressed_string[i] |= ((compressed_string[i*5/8] & 255) >> (3-((i*5) % 8))) & 31;
        } else {
      decompressed_string[i] |= (((compressed_string[i*5/8] & 255) << (((i*5) % 8)-3)) & 31) | (((compressed_string[(i+1)*5/8] & 255) >> (11-((i*5) % 8))) & 31);
       }
  }
  return decompressed_string;
}

char* str_decompressed_format(char* decompressed_string) {
  unsigned int strlength = strlen(decompressed_string);
  for (int i = 0;i < strlength;i++) {
    if (decompressed_string[i] < 27) decompressed_string[i] += 96;
    else if (decompressed_string[i] == 27) decompressed_string[i] = 32;
    else if (decompressed_string[i] == 28) decompressed_string[i] = 45;
    else decompressed_string[i] += 64;
  }
  decompressed_string[0] -= 32;
  for (int i = 1;i < strlength;i++) {
    if (decompressed_string[i-1] == 32 || decompressed_string[i-1] == 45 || decompressed_string[i-1] == 95) decompressed_string[i] -= 32;
    }
  return decompressed_string;
}

char* str_decompress_and_format(const char* compressed_string) {
  unsigned int decompressed_length = ceil(strlen(compressed_string)*1.6)+1;
  char* decompressed_string = malloc(decompressed_length);
  for (int i = 0;i < decompressed_length;i++) {
    decompressed_string[i] = 0;
  }
  for (int i = 0;i < decompressed_length;i++) {
    if ((i*5/8) == (((i*5)+4)/8)) {
      decompressed_string[i] |= ((compressed_string[i*5/8] & 255) >> (3-((i*5) % 8))) & 31;
        } else {
      decompressed_string[i] |= (((compressed_string[i*5/8] & 255) << (((i*5) % 8)-3)) & 31) | (((compressed_string[(i+1)*5/8] & 255) >> (11-((i*5) % 8))) & 31);
       }
  }

  decompressed_length = strlen(decompressed_string);
  for (int i = 0;i < decompressed_length;i++) {
    if (decompressed_string[i] < 27) decompressed_string[i] += 96;
    else if (decompressed_string[i] == 27) decompressed_string[i] = 32;
    else if (decompressed_string[i] == 28) decompressed_string[i] = 45;
    else decompressed_string[i] += 64;
  }
  decompressed_string[0] -= 32;
  for (int i = 1;i < decompressed_length;i++) {
    if (decompressed_string[i-1] == 32 || decompressed_string[i-1] == 45 || decompressed_string[i-1] == 95) decompressed_string[i] -= 32;
    }
  return decompressed_string;
}

char* str_decompress_and_format_free(const char* compressed_string) {
  unsigned int decompressed_length = ceil(strlen(compressed_string)*1.6)+1;
  char* decompressed_string = malloc(decompressed_length);
  for (int i = 0;i < decompressed_length;i++) {
    decompressed_string[i] = 0;
  }
  for (int i = 0;i < decompressed_length;i++) {
    if ((i*5/8) == (((i*5)+4)/8)) {
      decompressed_string[i] |= ((compressed_string[i*5/8] & 255) >> (3-((i*5) % 8))) & 31;
        } else {
      decompressed_string[i] |= (((compressed_string[i*5/8] & 255) << (((i*5) % 8)-3)) & 31) | (((compressed_string[(i+1)*5/8] & 255) >> (11-((i*5) % 8))) & 31);
       }
  }

  decompressed_length = strlen(decompressed_string);
  for (int i = 0;i < decompressed_length;i++) {
    if (decompressed_string[i] < 27) decompressed_string[i] += 96;
    else if (decompressed_string[i] == 27) decompressed_string[i] = 32;
    else if (decompressed_string[i] == 28) decompressed_string[i] = 45;
    else decompressed_string[i] += 64;
  }
  decompressed_string[0] -= 32;
  for (int i = 1;i < decompressed_length;i++) {
    if (decompressed_string[i-1] == 32 || decompressed_string[i-1] == 45 || decompressed_string[i-1] == 95) decompressed_string[i] -= 32;
    }
  free_enqueue(&garbage_strings,decompressed_string);
  return decompressed_string;
}

char* str_decompress_format_prealloc(const char* compressed_string,char* decompressed_string) {
  unsigned int decompressed_length = ceil(strlen(compressed_string)*1.6)+1;
  for (int i = 0;i < decompressed_length;i++) {
    decompressed_string[i] = 0;
  }
  for (int i = 0;i < decompressed_length;i++) {
    if ((i*5/8) == (((i*5)+4)/8)) {
      decompressed_string[i] |= ((compressed_string[i*5/8] & 255) >> (3-((i*5) % 8))) & 31;
        } else {
      decompressed_string[i] |= (((compressed_string[i*5/8] & 255) << (((i*5) % 8)-3)) & 31) | (((compressed_string[(i+1)*5/8] & 255) >> (11-((i*5) % 8))) & 31);
       }
  }

  decompressed_length = strlen(decompressed_string);
  for (int i = 0;i < decompressed_length;i++) {
    if (decompressed_string[i] < 27) decompressed_string[i] += 96;
    else if (decompressed_string[i] == 27) decompressed_string[i] = 32;
    else if (decompressed_string[i] == 28) decompressed_string[i] = 45;
    else decompressed_string[i] += 64;
  }
  decompressed_string[0] -= 32;
  for (int i = 1;i < decompressed_length;i++) {
    if (decompressed_string[i-1] == 32 || decompressed_string[i-1] == 45 || decompressed_string[i-1] == 95) decompressed_string[i] -= 32;
    }
  return decompressed_string;
}