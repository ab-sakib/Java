#include <stdio.h>
struct cse12{
  char name[20];
  int sid;
  double cgpa;
};
void output(struct cse12 student[]){
  printf("output\n");
  for(int i=0;i<10;i++)
  printf("%s%d%lf\n",student[i].name,student[i].sid,student[i].cgpa);
}
void input(struct cse12 student[]){
  printf("INPUt \n");
  for(int i=0;i<10;i++){
    scanf("%s%d%lf",student[i].name,&student[i].sid,&student[i].cgpa);
  }
}
void namesort(struct cse12 student[]){
  for(int i=0;i<10;i++){
    for(int j=1+i;j<10;j++){
      if(strcmp(student[i].name,student[j].name)>0){
        struct cse12 temp;
        strcpy(temp.name,student[i].name);
        strcpy(student[i],student[j]);
        strcpy(student[j].name,temp);
      }
    }
  }
}
int main(){
  struct cse12 student[10];
  namesort(student);
  return 0;
}