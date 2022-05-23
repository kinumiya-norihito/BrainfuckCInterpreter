#include <stdio.h>
#define TS 65536
#define a(h) s[0]?s[h]:argv[2][h]

char eq(char*,char*);

int main(int argc, char const *argv[]) {
  char t[TS],*p=t,s[TS]="";
  int h=0,l=0,n=0;
  FILE *fp;

  if(argc<2)return 0;
  if(eq("-a",(char*)argv[1])){
    if(argc<3)return 0;
  }
  else{
    if((fp=fopen(argv[1],"r"))==NULL){
      printf("\"%s\"というファイルは存在しない\n",argv[1]);
      return -1;
    }
    fseek(fp,SEEK_SET,0);
    fread(s,sizeof(char),65536,fp);
  }

  while(1){
    switch(a(h)){
      case 0:
        return 0;
      case '+':
        (*p)++;
        break;
      case '-':
        (*p)--;
        break;
      case '>':
        p++;
        break;
      case '<':
        p--;
        break;
      case ']':
        n=l;
        while(1){
          switch(a(h)){
            case '[':
              l--;
              break;
            case ']':
              l++;
              break;
          }
          if(l==n)break;
          h--;
        }
      case '[':
        l++;
        if((*p)==0){
          n=l;
          while(1){
            switch(a(h)){
              case '[':
                l++;
                break;
              case ']':
                l--;
                break;
            }
            if(l==n){
              l--;
              break;
            }
            h++;
          }
        }
        break;
      case '.':
        putchar((int)(*p));
        break;
      case ',':
        (*p)=(char)getchar();
        break;
    }
    h++;
  }
}

char eq(char* s0,char* s1){
  char x;
  int i=0;
  while(s0[i]&&s1[i]){
    x|=s0[i]^s1[i];
    i++;
  }
  return !(x|(s0[i]^s1[i]));
}
