#include <stdio.h>

lower(char l){
	char *p;
	p = &l;
	*p >= 'A' && *p <= 'Z' ? *p+=32: printf("");
	return l;
}

int strindex(char s[], char t){
	int i,pos;
	pos = -1;
	
	for(i=0;s[i]!='\0';i++){
		if (s[i] == t)
			pos = i;
	}
	return pos;
}

float power(float n, int p){
	int i,m,b=0;
	m=n;
	if (p == 0)
		return 1;
	if (p < 0){
		b=1;
		p*=-1;
	}
	for(i=1;i<p;i++)
		n*=m;
	if (b==1)
		n = 1/n;
	return n;
}

float ecuacion(char e[]){
	int i=0,poweru=1,powerd=0,p=1;
	float n=0.0,f=0.0;
	for (;e[i]!='.';i++){
		n = 10*n + (e[i]-'0');
	}
	i++;
	for (;e[i]!='e';i++){
		f += (e[i]-'0')/(power(10,poweru));
		poweru++;
	}
	i++;
	for(;e[i]!='\0';i++){
		if(e[i]=='-')
			p = -1;
		else{
			powerd = 10*powerd + (e[i]-'0');
		}
	}
	powerd *= p;
	return (f+n)*power(10,powerd);

}
invertir(char s[],int i, int e){
	char temp;
	if ( i>=e)
		return ;
	temp = s[i];
	s[i] = s[e];
	s[e] = temp;
	return invertir(s,++i,--e);
}

main() {
	char a='F',b='d',s[]="Caracol";
	lower(a);
	lower(b);
	printf("%c%c\n",lower(a),lower(b));
	printf("%d\n",strindex("programacion",'a'));
	printf("%.15f\n",ecuacion("28.45e-8"));
	invertir(s,0,6);
	printf(s);
	
}

