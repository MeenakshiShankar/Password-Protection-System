#include<reg51.h>
sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;
//4*3 keypad connections //
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
//lcd control lines //
sbit motp=P3^3;
sbit motn=P3^4;
// motor connections//
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void lcddis(unsigned char *, unsigned char);
void delay();
void check();
unsigned char pwd[10], x;
void main()
{
lcdcmd(0x38);
lcdcmd(0x01);
lcdcmd(0x10);
lcdcmd(0x0c);
lcdcmd(0x80);
lcddis("Password Protection",19);
lcdcmd(0xc0);
lcddis("System",7);
lcdcmd(0x01);
	lcddis("Enter Password",14);
	lcdcmd(0xc0);
while(1)
{
	
	r1=0;
	if(c1==0)
	{
		pwd[x]= '1';
		delay();delay();delay();delay();delay();delay();delay();delay();
		delay();delay();
		lcddat('*');
		x=x+1;
	}
  if(c2==0)
	{
		pwd[x]='2';
		delay();delay();delay();delay();delay();delay();delay();delay();
		delay();delay();
		lcddat('*');
		x=x+1;
	}
	if(c3==0)
	{
		pwd[x]='3';
		delay();delay();delay();delay();delay();delay();delay();delay();
		delay();delay();
		lcddat('*');
		x=x+1;
	}
	r2=0; r1=1;
	if(c1==0)
	{
		pwd[x]= '4';
		delay();delay();delay();delay();delay();delay();delay();delay();
		delay();delay();
		lcddat('*');
		x=x+1;
	}
  if(c2==0)
	{
		pwd[x]='5';
		delay();delay();delay();delay();delay();delay();delay();delay();
		delay();delay();
		lcddat('*');
		x=x+1;
	}
	if(c3==0)
	{
		pwd[x]='6';
		delay();delay();delay();delay();delay();delay();delay();delay();
		delay();delay();
		lcddat('*');
		x=x+1;
	}
	r3=0;r2=1;
	if(c1==0)
	{
		pwd[x]= '7';
		delay();delay();delay();delay();delay();delay();delay();delay();
		delay();delay();
		lcddat('*');
		x=x+1;
	}
  if(c2==0)
	{
		pwd[x]='8';
		delay();delay();delay();delay();delay();delay();delay();delay();
		delay();delay();
		lcddat('*');
		x=x+1;
	}
	if(c3==0)
	{
		pwd[x]='9';
		delay();delay();delay();delay();delay();delay();delay();delay();
		delay();delay();
		lcddat('*');
		x=x+1;
	}
	r4=0;r3=1;
	if(c1==0)
	{
		pwd[x]= '*';
		delay();delay();delay();delay();delay();delay();delay();delay();
		delay();delay();
		lcddat('*');
		x=x+1;
	}
  if(c2==0)
	{
		pwd[x]='0';
		delay();delay();delay();delay();delay();delay();delay();delay();
		delay();delay();
		lcddat('*');
		x=x+1;
	}
	if(c3==0)
	{
		check();
		delay();delay();delay();delay();delay();delay();delay();delay();
		delay();delay();
		delay();
		
	}
	r4=1;
}
}

void check()
{
	if(pwd[0]=='8'&&pwd[1]=='5'&&pwd[2]=='8'&&pwd[3]=='9'&&pwd[4]=='0'&&pwd[5]=='1'&&
		pwd[6]=='9'&&pwd[7]=='0'&&pwd[8]=='6'&&pwd[9]=='2')
	{
		motp=1;
		motn=0;
		lcdcmd(0x01);
		lcddis("Password Matched",16);
		delay();
	}
	else
	{
		lcdcmd(0x01);
		lcddis("Password Wrong",14);
	}
}

void lcdcmd(unsigned char val)
{
	P2=val;
	rs=0;
	rw=0;
	en=1;
	delay();delay();
	en=0;
}

void lcddat(unsigned char dat)
{
	P2=dat;
	rs=1;
	rw=0;
	en=1;
	delay();delay();
	en=0;
}

void lcddis(unsigned char *s,unsigned char r)
{
	unsigned char w;
	for(w=0;w<r;w++)
	{
		lcddat(s[w]);
		delay();
	}
}

void delay()
{
	unsigned int i,j;
	for(i=0;i<4000;i++);
	for(j=0;j<100;j++);
	
}