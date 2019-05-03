/* I pledge my honor that I have abided by the Stevens Honor System atartaglia */

//copies the string pointed to by src

char *cs392_strcpy(char *dest, char *src){
  while(*src != '\0'){
    *dest=*src;
    src++;
    dest++;
  }
  *dest = '\0';
  return dest;
}