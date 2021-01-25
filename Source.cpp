#include "iGraphics.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int fflag=0,flag=0,x_co=178,y_co=5,x_bad=0,y_bad=690,i=0 ;

int n[30]={90,100,200,300,-110,-60,-120,-400,70,160,320,70,-600,620,70,-150,-360,120,230,150,-150,-30,60,80,-200,-20,-110,90,10,480};

int x_bad2=192,y_bad2=690,j=0,

int n2[30]={140,150,90,-60,-100,-50,220,-80,50,-60,110,-70,80,-20,-90,150,60,-520,-30,50,-150,-30,300,80,-200,-20,-110,90,410,-80};

int x_bad3=150,y_bad3=690,k=0 ;

int n3[30]={140,80,90,-100,120,-336,220,-80,-50,-160,310,70,80,-120,-40,140,-90,80,-130,120,-100,130,-50,140,-60,20,-100,90,10,-80};

int scr=0;char outscr[20],pre_scor=0;


//poka 1
void baddie_movement(){

	iShowBMP(x_bad,y_bad,"poka.bmp");
	y_bad=y_bad-3;

	if(y_bad<0){
		scr++;
		y_bad=700;
		x_bad=(x_bad+n[i]);
		i++;
	}
}

void baddie_movement2(){
	
	iShowBMP(x_bad2,y_bad2,"ant.bmp");
	y_bad2=y_bad2-1;

	if(y_bad2<0){
		scr++;
		y_bad2=700;
		x_bad2=(x_bad2+n2[j]);
		j++;
	}
}

void baddie_movement3(){
	
	iShowBMP(x_bad3,y_bad3,"spider.bmp");
	y_bad3=y_bad3-1;

	if(y_bad3<0){
		scr++;
		y_bad3=500;
		x_bad3=(x_bad3+n3[k]);
		k++;
	}
}

void iDraw()

{	 
	//home page
	if(flag==0)
	{
		scr=0;
		iClear();
		iShowBMP(0,0,"bg1.bmp");
	}
	//home page done


	//gameplay
	if(flag==1)
	{	
		
		//iClear();
		
		iSetColor(255,255,255);
		iShowBMP(0,0,"bg2.bmp");
		

		//most important

		iShowBMP(x_co,y_co,"ninja.bmp");
		if(((x_co<=(x_bad+80) && (x_co+100)>=x_bad) && (y_bad)==128) ||((x_co<=(x_bad2+80) && (x_co+100)>=x_bad2) && (y_bad2)==128) || ((x_co<=(x_bad3+80) && (x_co+100)>=x_bad3) && (y_bad3)==128)){
			flag=3;

	}

		else{			
		baddie_movement();
		baddie_movement2();
		baddie_movement3();
		iSetColor(0 ,0 ,0);
		
		
		sprintf(outscr,"%d",scr);
		
		iText(65,680,outscr,GLUT_BITMAP_HELVETICA_18);
		iText(10,680,"Score: ",GLUT_BITMAP_HELVETICA_18);
		
	
	}
			
}

	//highscore
	if(flag==2)
	{
		iClear();
		iShowBMP(0,0,"score.bmp");
		
		iSetColor(0,0,0);
		FILE *fp;

		fp = fopen("Encode copy.txt","r");

		fscanf(fp,"%s",outscr);

		fclose(fp);
		iText(350,450,outscr,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(250,300,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//high score done

    if(flag==3){
		

		iClear();

		iText(250,400,"Game Over",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(250,350,"Score: ",GLUT_BITMAP_HELVETICA_18);
		iText(310,350,outscr,GLUT_BITMAP_HELVETICA_18);
		iText(250,300,"Exit",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(250,250,"Retry",GLUT_BITMAP_TIMES_ROMAN_24);
		FILE *fp;

		fp = fopen("Encode copy.txt","w");

		fprintf(fp,"%s",outscr);

		fclose(fp);
	}
}


void iMouseMove(int mx, int my)
{
//place your codes here
}

void iMouse(int button, int state, int mx, int my)

{
	//place your codes here

	printf("mouse cliked at: %d %d\n",mx,my);
	
	if(mx>58 && mx<330 && my>315 && my<338)
	{
		flag=1;
	}

	if(mx>50 && mx<280 && my>250 && my<272)
	{
		flag=2;
	}

	if(mx>96 && mx<278 && my>71 && my<123)
	{
		flag=0;
	}

/*	if(mx>44 && mx<134 && my>184 && my<210)
	{
		exit(0);
	}
	if(mx>250 && mx<318 && my>300 && my<318)
	{
		flag=0;
	}
*/
}

void iKeyboard(unsigned char key)

{

//place your codes here

}

void iSpecialKeyboard(unsigned char key)

{
	if(x_co>8){
	if(key == GLUT_KEY_LEFT)
	{
		x_co=x_co-10;	
	}
}
	if(x_co<697){
	if(key == GLUT_KEY_RIGHT)
	{
		x_co=x_co+10;	
	}
}
	/*if (y_co<519)
	{
		if(key == GLUT_KEY_UP)
		{
			y_co+=10;
		}
	}
	
	if(y_co>6){
		if(key == GLUT_KEY_DOWN)
		{
			y_co-=10;
		}
	}*/

//place your codes for other keys here

}

int main()
{
	//place your own initialization codes here.

	iSetTimer(27,baddie_movement);
	iSetTimer(13,baddie_movement2);

	iInitialize(800, 700,"Game");

	return 0;

}


