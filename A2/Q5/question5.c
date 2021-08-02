#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float avgCSV(char *inputName);

float avgCSV(char *inputName){
  float sum = 0;                       
  int count = 0;                      

  FILE *fin ;
  fin = fopen(inputName, "r");      
  if(fin == NULL) {
    return 0;  
  }
  char line[101];                      
  char *word;
  float value;
  int col;

  while(fgets(line, 100, fin)) {
    word = strtok(line, ",");     
    value = atof(word);              
    sum = sum + value;           
    count++;                     

    for(col = 2; col <= 8; col++) {  
      word = strtok(NULL, ",");   
      value = atof(word);          
      sum = sum + value;          
      count++;               
    }

  }
  return sum/count;                  
}

int main () {
	printf("%f\n", avgCSV("multiline1.csv"));
	// Expected Value = 523.899109
	printf("%f\n", avgCSV("multiline2.csv"));
	// Expected Value = 506.371246
}
