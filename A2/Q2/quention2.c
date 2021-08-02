#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DMY_MonthDY(char *buffer, const char *str);
void MonthDY_DMY(char *buffer, const char *str);

void DMY_MonthDY(char *buffer, const char *str) {
  int d, m, y;
  sscanf(str, "%d/%d/%d", &d, &m, &y);
  char myStr[10];
  if(m==1) {
    strcpy(myStr, "January");
  }
  else if(m==2) {
    strcpy(myStr, "February");
  }
  else if(m==3) {
    strcpy(myStr, "March");
  }
  else if(m==4) {
    strcpy(myStr, "April");
  }
  else if(m==5) {
    strcpy(myStr, "May");
  }
  else if(m==6) {
    strcpy(myStr, "June");
  }
  else if(m==7) {
    strcpy(myStr, "July");
  }
  else if(m==8) {
    strcpy(myStr, "August");
  }
  else if(m==9) {
    strcpy(myStr, "September");
  }
  else if(m==10)
    strcpy(myStr, "October");
  }
  else if(m==11)
    strcpy(myStr, "November");
  }
  else
    strcpy(myStr, "December");
  }
  sprintf(buffer, "%-10s %2d, %4d", myStr, d, y);

}

void MonthDY_DMY(char *buffer, const char *str) {
  int d, m, y, i=0;
  char myStr[10];
  sscanf(str, "%s %d, %d", myStr, &d, &y);
  if(strcmp(myStr, "January")==0) {
    m = 1;
  }
  else if(strcmp(myStr, "February")==0) {
    m = 2;
  }
  else if(strcmp(myStr, "March")==0) {
    m = 3;
  }
  else if(strcmp(myStr, "April")==0) {
    m = 4;
  }
  else if(strcmp(myStr, "May")==0) {
    m = 5;
  }
  else if(strcmp(myStr, "June")==0) {
    m = 6;
  }
  else if(strcmp(myStr, "July")==0) {
    m = 7;
  }
  else if(strcmp(myStr, "August")==0) {
    m = 8;
  }
  else if(strcmp(myStr, "September")==0) {
    m = 9;
  }
  else if(strcmp(myStr, "October")==0) {
    m = 10;
  }
  else if(strcmp(myStr, "November")==0) {
    m = 11;
  }
  else {
    m = 12;
  }
  sprintf(buffer, "%02d/%02d/%04d", d, m, y);
}
int main(){
char format1[12][11] = { "01/01/1970"
                       , "10/02/1763"
                       , "15/03/0044"
                       , "18/04/1982"
                       , "05/05/1789"
                       , "06/06/1944"
                       , "01/07/1867"
                       , "03/08/1492"
                       , "02/09/1945"
                       , "24/10/1917"
                       , "11/11/1918"
                       , "08/12/1980"
                       };
char format2[12][19] = { "January    1, 1970" // First Day of History (according to computers)
                       , "February  10, 1763" // France cedes Canada to England
                       , "March     15,   44" // Assassination of Julius Caesar
                       , "April     18, 1982" // Canada Achieves Sovereignty 
                       , "May        5, 1789" // French Revolution
                       , "June       6, 1944" // D-Day Landings of WWII
                       , "July       1, 1867" // Confederation of Canada
                       , "August     3, 1492" // Christopher Columbus Sets Sail for the Americas
                       , "September  2, 1945" // WWII Surrender of Japan
                       , "October   24, 1917" // October Revolution (Julian Calendar)
                       , "November  11, 1918" // WWI Armistice
                       , "December   8, 1980" // Murder of John Lennon
                       };
    
    char buffer1[12][11];
    char buffer2[12][19];
    
    printf ("-- DD\\MM\\YY to Month DD, YYYY\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", format1[i]);
        DMY_MonthDY(buffer2[i], format1[i]);
        printf("-> \"%s\"\n", buffer2[i]);
    }
    
    
    printf ("\n\n-- Month DD, YYYY to DD\\MM\\YY\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", format2[i]);
        MonthDY_DMY(buffer1[i], format2[i]);
        printf("-> \"%s\"\n", buffer1[i]);
    }
}
