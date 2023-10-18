#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
char matrix[5][5];

struct max{
int r;
int c;
};
struct min{
char qr;
char qc;
};
char* repeat(char* k)
{
char* res=(char*)malloc(100*sizeof(char));
int i=1;
int j=0;
int ch;
int kl=1;
res[0]=k[0];
while(k[i]!='\0')
{
ch=0;
for(j=0;j<i;j++)
{
if(k[i]==res[j])
{
ch=0;
j=i+1;
}
else
ch=1;
}
if(ch==1)
{
if(k[i]=='j')
k[i]='i';
res[kl]=k[i];
kl++;
}
i++;
}
return res;
}
bool check(int count,char *ptr )
{
int i=0;
while(ptr[i]!='\0')
{
if((count)==ptr[i])
return 0;
i++;
}
return 1;
}
void constmatrix(char *key)
{
int i=0;
int j=0;
int ch=0;
int count=97;
char *ptr=repeat(key);
while(ptr[ch]!='\0')
{
matrix[i][j]=ptr[ch];
ch++;

if(j==4)
{
j=-1;
i++;
}
j++;
}

for(;i<5;i++)
{
int n=0;
for(;j<5;j++)
{
if(check(count,ptr)){
if(count==106)
{
count++;
j--;
}
else{
matrix[i][j]=count;
count++;
}
}
else
{
j--;
count++;
}
n=1;

}
if(n==1)
j=0;
}
for(i=0;i<5;i++){
for(j=0;j<5;j++)
printf("%c ",matrix[i][j]);
printf("\n");}
free (ptr);
}
struct max find(char a)
{
int i,j;
struct max z;
for(i=0;i<5;i++)
for(j=0;j<5;j++)
{
if(matrix[i][j]==a)
{
z.r=i;
z.c=j;
return z;
}
}
}
struct min  plafair(char a,char b)
{
struct max kat[2];
struct min kate;
kat[0]=find(a);
kat[1]=find(b);
if(kat[0].r==kat[1].r)
{
int col=kat[0].c+1;
if(col>=5)
col=0;
kate.qc=matrix[kat[0].r][col];
col=kat[1].c+1;
if(col>=5)
col=0;
kate.qr=matrix[kat[1].r][col];
return kate;
}
else if(kat[0].c==kat[1].c)
{
int row=kat[0].r+1;
if(row>=5)
row=0;
kate.qc=matrix[row][kat[0].c];
row=kat[1].r+1;
if(row>=5)
row=0;
kate.qr=matrix[row][kat[1].c];
return kate;
}
else
{
kate.qc=matrix[kat[0].r][kat[1].c];
kate.qr=matrix[kat[1].r][kat[0].c];
return kate;
}
}
struct min  deplafair(char a,char b)
{
struct max kat[2];
struct min kate;
kat[0]=find(a);
kat[1]=find(b);
if(kat[0].r==kat[1].r)
{
int col=kat[0].c-1;
if(col<0)
col=4;
kate.qc=matrix[kat[0].r][col];
col=kat[1].c-1;
if(col<0)
col=4;
kate.qr=matrix[kat[1].r][col];
return kate;

}
else if(kat[0].c==kat[1].c)
{
int row=kat[0].r-1;
if(row<0)
row=4;
kate.qc=matrix[row][kat[0].c];
row=kat[1].r-1;
if(row<0)
row=4;
kate.qr=matrix[row][kat[1].c];
return kate;
}
else
{

kate.qc=matrix[kat[0].r][kat[1].c];
kate.qr=matrix[kat[1].r][kat[0].c];
return kate;
}

}
int main()
{
char a[25],mes[100];
struct min res[100];
printf("ENTER THE KEY :\n");
scanf("%s",a);
printf("ENTER THE MESSAGE :\n");
scanf("%s",mes);
constmatrix(a);
int i=0;
int count=0;
while(mes[i]!='\0')
{
count++;
i++;
}

i=0;
int ko=0;
int later[100],o=0;
while(i<count)
{
if(i==count-1)
{
res[ko++]=plafair(mes[i],'x');
o=10;
i++;
}
else if(mes[i]!=mes[i+1])
{
res[ko++]=plafair(mes[i],mes[i+1]);

i=i+2;
}
else{
res[ko++]=plafair(mes[i],'x');
later[o++]=i+1;
i++;
}
}
int j;
printf("ENCRPTED MESSAGE = ");
for(j=0;j<ko;j++)
printf("%c%c",res[j].qc,res[j].qr);
printf("\n");
struct min dem[100];
i=0;
j=0;
char se[100];
int h_h=0,k_k=0;
while(i<ko)
{
dem[i]=deplafair(res[i].qc,res[i].qr);
se[h_h++]=dem[i].qc;
se[h_h++]=dem[i].qr;

i++;
}
int lj=0;
if(o==10)
{
se[h_h-1]='\0';
}
printf("DECRPTED MESSAGE = ");
while(se[k_k]!='\0')
{
if(k_k!=later[lj])
{
printf("%c",se[k_k]);
}
else{
lj++;
}
k_k++;
}
}
