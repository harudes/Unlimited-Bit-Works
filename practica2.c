#include <stdio.h>

lower(char l){
	char *p;
	p = &l;
	*p >= 'A' && *p <= 'Z' ? *p+=32: printf("");
	return l;
}
strcat(char destino[],char su[], char sd[]){
	char *pu=su,*pd=sd;
	int i,id;
	
	for (i=0;su[i]!='\0';i++){
		destino[i]=*pu;
		pu++;
	}
	for (id=0;sd[id]!='\0';i++,id++){
		destino[i]=*pd;
		pd++;
	}
}
int strend(char s1[], char s2[]){
	char *pu=s1,*pd=s2;
	for(;*pu!='\0';pu++){}
	pu--;
	for(;*pd!='\0';pd++){}
	pd--;
	for(;*pd!=s2[0];pu--,pd--){
		if(*pd!=*pu)
		   return -1;
	}
	if(*pd!=*pu)
	   return -1;
	return 1;
}
strcopyn (char s1[],char s2[], int n){
	char *p1=s1;
	int i;
	for(i=0;*p1!='\0'&&i<n;p1++,i++){
		s2[i] = *p1;
	}
}

strcatn(char destino[],char su[], char sd[],int n){
	char *pu=su,*pd=sd;
	int i,id;
	
	for (i=0;su[i]!='\0'&&i<n;i++){
		destino[i]=*pu;
		pu++;
	}
	for (id=0;sd[id]!='\0'&&id<n;i++,id++){
		destino[i]=*pd;
		pd++;
	}
}

int strncomp(char s1[],char s2[],int n){
	char *p1=s1,*p2=s2;
	int i;
	for(i=0;i<n;p1++,p2++,i++){
		if(*p1!=*p2)
		   return -1;
	}
	return 1;
}
int atoi(char s[]){
	char *p=s;
	int n=0;
	for (;*p!='\0';p++){
		n = 10*n + (*p-'0');
	}
	return n;
}
invertir(char s[]){
	char temp, *p1=s,*p2=s;
	for(;*p2!='\0';p2++){}
	p2--;
	for ( ;p1<=p2;p1++,p2--){
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
	
}
	

main(){
	char palabra[15]="",s[10]="",palabra2[15]="", inv[7]="palabra";
	strcat(palabra,"aracno","fobia");
	printf(palabra);
	printf("\n%d\n",strend("acrofobia","fobia"));
	strcopyn("programacion",s,6);
	printf(s);
	printf("\n");
	strcatn(palabra2,"aracno","fobia",3);
	printf(palabra2);
	printf("\n%d\n",strncomp("caa","caso",3));
	printf("%d\n",atoi("25"));
	invertir(inv);
	printf(inv);
}

