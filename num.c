#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>


void btos(int *src, int len){
	int tem;
		for(int i=0;i<len;i++){
			for(int j = 0;j<len-i-1 ; j++){
				if(src[j] < src[j+1]){
				tem=src[j];
				src[j] = src[j+1];
				src[j+1] = tem;
				}
			}
		}
}


void sort(int *src, int len){
	int tem;
		for(int i=0;i<len;i++){
			for(int j = 0;j<len-i-1 ; j++){
				if(src[j] > src[j+1]){
				tem=src[j];
				src[j] = src[j+1];
				src[j+1] = tem;
				}
			}
		}

}


int main(){
	int a[5];
char buffer[10];
int c,i=0,e;

FILE*fptr=fopen("case.txt","r");
FILE*fp=fopen("num.txt","w");

	memset(a,0,sizeof(a));

	if(fptr){
	while(fgets(buffer , 10, fptr)!=NULL){
	e = atoi(buffer);
	a[i]=e;
	i++;
	printf("%d\n",e);
}

	printf("How many numbers in the case = %d\n",sizeof(a)/4);
	printf("Increment(1) or Decreasoing(2)?\n");
	scanf ("%d",&c);
		if(c==1){
	sort(a,5);
	for(int i=0;i<5;i++)
		printf("%d\n",a[i]);
}
	if(c==2){
	btos(a,5);
	for(int i =0;i<5;i++)
		printf("%d\n",a[i]);

}
	//return 0;
	for(int i =0;i<5;i++){
		fprintf(fp,"%d\n",a[i]);}


}
fclose(fptr);
fclose(fp);


}
