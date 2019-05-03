/* I pledge my honor that I have abided by the Stevens Honor System atartagl */

//appends the src string to the dest string

char* cs392_strncat(char *dest, char *src, unsigned n){
    char *ret = dest;
    while(*dest != '\0'){
      dest++;
    }
    while(*src != '\0'){
      if(n != 0){
        *dest = *src;
        dest++;
        src++;
        n--;
      }else{
        *dest = '\0';
        break;
      }
    }

    if(n!= 0){
      *dest = '\0';
    }
    return ret;
  }
    