/* I pledge my honor that I have abided by the Stevens Honor System atartagl */

//compares the two strings s1 and s2

int cs392_strcmp(char *s1, char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
		if (*s1 > *s2) {
			return 1;
		} else if (*s1 < *s2) {
		    return -1;
		}
		s1++;
		s2++;    
    }
	if(*s1 == '\0' && *s2 == '\0'){
        return 0;
    }
    if (*s2 == '\0') {
        return 1;
    } else if (*s1 == '\0') {
        return -1;
    }
    return 0;
}