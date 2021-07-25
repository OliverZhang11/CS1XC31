#include <stdio.h>
int disp(int*arr,int size) {
int i,value, j, c=0,temp;

for(i=1;i<sizeli++) {
  value=arr[i];
  j=i;
  
  while( (j>0)&&(arr[j-1]>arr[j]) {
    if(arr[j-1]>arr[j]) {
    c++;
    }
  temp=arr[j-1];
  arr[j-1]=arr[j]    
  arr[j]=temp;
  j--;
  }
c++;
}

for(int i=0;i<size;++i) {
  printf("%d", arr[i]);
  }
  printf("\n");
  return c;
}

int main() {
  int size;
  printf("enter size of array:\n");
  scanf("%d",&size);
  int arr[size];
    for(int i=0;i<size;i++) {
      scanf("%d",&arr[i]);
      }
    int comparisons=disp(arr,size);
    printf("%d\n", comparisons);
    return 0;
}
