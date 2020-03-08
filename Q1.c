#include<stdio.h> 
#include<string.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<sys/stat.h>
#include<sys/types.h>
char buff[1000001],buff2[1000001];
 void reverse(char *string, int size)
 {   char temp = 0;
     int x = 0;
     for(int i=size-1;x<i;i--)
     {
        temp = string[i];
         string[i] = string[x];
         string[x] = temp;
         x++; 
     }
 }
 void string(int t)
 { 
     //printf("%d\n", t);
     int i=2;
     while(i != 0)
     {
        buff2[i] = t%10 + '0';
        t/=10;
        i--; 

     }
     buff2[3] = '%';
     buff2[4] = '\0';
 }
 
int main(int argc, char *argv[])
{    


    char rex[100] = "Assignment/";


     int l=0;
     int m=0;
     int o = 11;
      while (argv[1][m])
      {
        if(argv[1][m++]=='/')
        l=m;
      }
      
      while(argv[1][l])
      {
          rex[o++] = argv[1][l++];
           
      }
      rex[o] = '\0';


     long long int i=0,s,size1,ans; 
     int ch = 0;
     int fp1 = open(argv[1], O_RDONLY);
     mkdir("Assignment",511);
    int fp2 = creat(rex,511);

     long long int cnt = lseek(fp1,0,SEEK_END);
    
      
            
     while(i < cnt/1000000)
     {
         i++;
         
         lseek(fp1,-i*1000000,SEEK_END);
         read(fp1,buff,1000000);
         reverse(buff,1000000);
         write(fp2,buff,1000000);
           
         ans = (i*100000000)/cnt;//
         string(ans);
         write(1, "\r",1);
         write(1,buff2,5);
         
     }
    
    int yo = cnt%1000000;
    
    lseek(fp1,0,SEEK_SET);
    
    read(fp1,buff,yo);
   // printf("%s\n",buff);
    reverse(buff,yo);
   // printf("%s\n",buff);

    write(fp2,buff,yo);
    write(1,"\r",1);
    write(1,"Done\n",6); 

    return 0;
}