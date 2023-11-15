#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

 bool isLetter(char x)
{
    return (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z');
}

void printmas(int* count1, int n)
{
  for(int i = 0 ; i < n; i++) {
     printf("%d", count1[i]);
     printf("\n");
}
void sort(int* ar, string* words, int n,int up)
{
    int i,j,x;
    string wordx;
    for(i=n-1; i; i--)
        for(j=0; j<i; j++)
        if(up && ar[j]>ar[j+1] || !up && ar[j]<ar[j+1])
        {
            x=ar[j];
            ar[j]=ar[j+1];
            ar[j+1]=x;

            strcpy(words[j], wordx);
	          strcpy(words[j+1], words[j]);
            strcpy( wordx, words[j]);
        }
}
char* strcopy(char *src, char *dst, const size_t n)
{
   char *t = strdup(dst + n);
   strcpy(dst + n, src);
   strcpy(dst + n + strlen(src), t);
   free(t);
   return dst;
}

int capitalize(char *str)
{
    int k = strlen(str);
    for (int i = 0; i < k; i++)
    {
        str[i] = toupper(str[i]);
    }
    return k;
}
int main(int argc, char **argv) {
FILE *fp;

    int nmax=10000;
     int count[nmax], k=1;
     string words[nmax];
     char line[], fname[];
     for (int i=0; i<nmax; i++)
     count[i] =0;
     int  count_str=0;
    if  (argc==1)
    {
 	 printf("Parametrs not input \n");
     printf("input name file Little_Lord_Fauntleroy.txt  /A_Little_Princess.txt \n");
     gets_s(fname);//
    }
	else
	{
	 printf("%s",argv[1]);
	fname=argv[1];;
	}

//	 fname="A_Little_Princess.txt";
   
  if ((fp = fopen(fname, "r")) == NULL)
  {
    printf("Не удалось открыть файл");
    getchar();
    return 0;
  }

    char c;
     fp = fopen(fname, "r");
     {
    while (fscanf(fp, "%s",line) != EOF) {
            capitalize(line);;//преобразуем в единый регистр
 

 string s0 = line;//ss[0];
 string c,c0,w;
 bool inword=false;
 string divs=" \t\r\n";
 // for (int i1=0; i1< count_str; i1++)
  {
 string s=" "+line+" ";
 int len =  strlen(s), start;
 for (int i=1; i<len; i++) {
 string c0 = strcopy(s, s, i-1);
 if (strstr (c0,divs)!=0 && dstrstr (c,divs)!) {
 inword=true; start=i;
 }
 if (strstr (c,divs)!) {
 if (inword) {
 w = s.substr(start,i-start+1);
 int p=strlen(w)-1;
 if (isLetter(w[p])==false) //проверка что символ аоследний буква, а не, можно по другоу if (isalpha((unsigned char)x)) ////97 A 65 a
  strcpy(w,w,p);
 //слово w

 bool dic_bool=false;
 for (int j=1; j<k; j++)
 if  (words[j]==w)
 { dic_bool=true;
    count[j]++;
 	break;
 }
 if (dic_bool==false) {
  words[k]=w;
 k++;
}
 }
 inword = false;
 }
 }
}
       }
     }
    in.close();     // закрываем файл
    //   printmas(count, k);
      sort(count,words,k,0);//сортировка с перестановкой слов
      int n=k;   //  количество слов
     // printmas(count, n);
 printf("%s ---Top 25 frecunetly used words list---\n",fname);
 for (int i=0; i<25; i++)
 if (words[i]!="")
    printf("%s%c%d%c \n ",words[i],"[",count[i] ,"]";
 return 0;
}
