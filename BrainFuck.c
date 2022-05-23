#include <stdio.h>
#define TS 65536

int main(int argc, char const *argv[]) {
  char t[TS],*p=t;
  int h=0,l=0,n=0;
  if(argc<2)return 0;
  while(1){
    switch(argv[1][h]){
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
          switch(argv[1][h]){
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
            switch(argv[1][h]){
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
