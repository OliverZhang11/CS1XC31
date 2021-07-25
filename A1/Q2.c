#include <stdio.h>
#include <string.h>

//reverse
void reverse(char str[]) {
int len=0;

while(str[len]!='\0')
  len++;

  for(int i=0;i<len/2;i++) {
    char c;
    c=str[i];
    str[i]=str[len-i-1];
    str[len-i-1]=c;
    }
}

//count
int countVowel(char str[]) {
int vowel=0, i=0;
char c;
while(str[i]!='\0') {
  uf(c == 'a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') {
    vowel++;
    }i++;
  }returen vowel;
}
int main()
char str[]="Oliver";
reverse(str);

printf("The reverse string is: %s",str);
printf("\nThe number of vowels is: %d,countVowel(str));

return 0;
}
