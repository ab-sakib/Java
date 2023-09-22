#include <stdio.h>
#include <string.h>

//data to work with
int studentid[50];
char studentname[50][50];
float cgpa[50];
int n;

//function to swapp integer
void swapInt(int *a,int *b){
  int temp =*a;
  *a=*b;
  *b=temp;
}
void swapFloat(float *a,float *b){
  float temp=*a;
  *a=*b;
  *b=temp;
}

void swapstring(char a[50],char b[50]){
  char temp[50];
  strcpy(temp,a);
  strcpy(a,b);
  strcpy(b,temp);
}
//sorting by name
void sortname(char name[][50],int ids[],float cpgpas[],int n){
  for(int i=0;i<n;i++){
    for(int j=1+i;j<n;j++){
      if(strcmp(name[i],name[j])>0){
        swapstring(name[i],name[j]);
        swapInt(&ids[i],&ids[j]);
        swapFloat(&cpgpas[i],&cpgpas[j]);
      }
    }
  }
}

void sortid(char name[][50],int ids[],float cpgpas[],int n){
  for(int i=0;i<n;i++){
    for(int j=1+i;j<n;j++){
      if(ids[i]>ids[j]){
        swapInt(&ids[i],&ids[j]);
        swapstring(name[i],name[j]);
        swapFloat(&cpgpas[i],&cpgpas[j]);
      }
    }
  }
}

void sortcgpa(char name[][50],int ids[],float cpgpas[],int n){
  for(int i=0;i<n;i++){
    for(int j=1+i;j<n;j++){
      if(cpgpas[i]<cpgpas[j]){
        swapInt(&ids[i],&ids[j]);
        swapstring(name[i],name[j]);
        swapFloat(&cpgpas[i],&cpgpas[j]);
      }
    }
  }
}

int main(){
  printf("Total student?\n");
  scanf("%d",&n);
  printf("Enter name,id & cgpa chronologically...\n");
  for(int i=0;i<n;i++){
    scanf("%s %d %f",studentname[i],&studentid[i],&cgpa[i]);
  }
  printf("\n");
  printf("======================================\n");



  sortname(studentname,studentid,cgpa,n);
  for(int i=0;i<n;i++){
    printf("%d ----- %s ----- %.2f\n",studentid[i],studentname[i],cgpa[i]);
  }
  printf("\n");
  sortid(studentname,studentid,cgpa,n);
  for(int i=0;i<n;i++){
    printf("%d ----- %s ----- %.2f\n",studentid[i],studentname[i],cgpa[i]);
  }
  printf("\n");
  sortcgpa(studentname,studentid,cgpa,n);
  for(int i=0;i<n;i++){
    printf("%d ----- %s ----- %.2f\n",studentid[i],studentname[i],cgpa[i]);
  }

  return 0;
}