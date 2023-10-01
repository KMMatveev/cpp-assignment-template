#include <hw03.h>
#include <iostream>
#include <cstring>
using namespace std;

void hw03(char* str, const char* pattern)
{
  bool contains = false;
  char* firstIndex=NULL;
  bool flag=false;
  int strLength=strlen(str);
  int patternLength=strlen(pattern);
  for(int i=0; i<strLength;i++)
  {
     if (*(str+i)==*(pattern))
     {
        flag=true;
        for(int k=0;k<patternLength;k++)
        {
          if (*(str+i+k)!=*(pattern+k))
          {
            flag = false;
            break;
          }
        }
        if (flag)
        {
          contains =true;
          firstIndex=str+i;
        }
     }
  }

  if(contains)
  {
    string buf="";
    for(int i=0;i<strlen(firstIndex)+1;i++)
    {
      *(firstIndex+i)=*(firstIndex+i+patternLength);
    }
  }
}
