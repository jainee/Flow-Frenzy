#include<stdio.h>
#include<windows.h>
#include<graphics.h>
int xc,yc;

void background()
{
	setcolor(1);
	rectangle(0,100,1299,699);
	setfillstyle(SOLID_FILL,1);
	floodfill(320,290,1);
}
void grass()
{
	int j;
	for(j=0;j<1100;j+=70)
	{
		int points[]={70+j,630,125+j,699,180+j,630,150+j,699,100+j,699,70+j,630};
		setcolor(2);
        setfillstyle(SOLID_FILL,2);
		fillpoly(6,points);
	}
}
void fish(int x,int y)
{
    int points[]={x+40,y,x+60,y+10,x+60,y-10,x+40,y},points2[]={x,y-30,x+20,y-50,x+30,y-40,x,y-30},points3[]={x,y+30,x+20,y+45,x+30,y+35,x,y+30};
    setcolor(14);
    ellipse(x,y,0,360,40,30);
    setfillstyle(SOLID_FILL,14);
	floodfill(x,y,14);
	setcolor(0);
	circle(x-20,y-10,5);
	setfillstyle(SOLID_FILL,0);
	floodfill(x-20,y-10,0);
	setcolor(10);
	setfillstyle(SOLID_FILL,10);
	fillpoly(4,points);
	setfillstyle(SOLID_FILL,10);
	fillpoly(4,points2);
	setfillstyle(SOLID_FILL,10);
	fillpoly(4,points3);
}
void sfish(int x,int y,int cl)
{
    int points[]={x+20,y,x,y-20,x-30,y+7,x-30,y-7,x,y+20,x+20,y};
    setcolor(cl);
    setfillstyle(SOLID_FILL,cl);
    fillpoly(6,points);
    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    circle(x+5,y-5,3);
    floodfill(x+5,y-5,0);
    setcolor(15);
    setlinestyle(0,4,2);
    line(x,y+19,x,y-19);
}
void bfish(int x,int y)
{
    int points[]={x-80,y,x,y-80,x+100,y+40,x+100,y-40,x,y+80,x-80,y};
    setcolor(7);
    setfillstyle(SOLID_FILL,7);
    fillpoly(6,points);
    setcolor(4);
    setfillstyle(SOLID_FILL,4);
    circle(x-25,y-20,10);
    floodfill(x-25,y-20,4);
    setcolor(0);
    setlinestyle(0,6,2);
    line(x,y+79,x,y-79);
}

int main()
{
    char sc[20];
	int gd=DETECT,gm,i,p=0,ix[10],iy[10],count=0,po[]={200,80,230,150,300,150,250,200,280,270,200,230,120,270,150,200,100,150,170,150,200,80};
	POINT a;
	initwindow(1300,700,"flow frenzy");
	setcolor(9);
	settextstyle(1, HORIZ_DIR, 8);
    outtextxy(320,150,"FLOW FRENZY");
    settextstyle(1, HORIZ_DIR, 5);
    outtextxy(300,400,"Press any key to start the game!");
    setcolor(14);
    setfillstyle(SOLID_FILL,14);
    fillpoly(11,po);
    getch();

    ix[0]=0;
    ix[1]=10;
    ix[2]=20;
    ix[3]=1200;
    ix[4]=30;
    ix[5]=40;
    ix[6]=50;
    ix[7]=60;
    ix[8]=70;
    ix[9]=80;
    iy[0]=rand()%200;
    iy[1]=rand()%400;
    iy[2]=rand()%600;
    iy[3]=rand()%500;
    iy[4]=rand()%200;
    iy[5]=rand()%400;
    iy[6]=rand()%600;
    iy[7]=rand()%500;
    iy[8]=rand()%400;
    while(1)
    {

        setactivepage(p);
        setvisualpage(1-p);

        cleardevice();
        background();
        grass();
        GetCursorPos(&a);

        fish(a.x,a.y);
        sfish(ix[0],iy[0]+100,9);
        sfish(ix[1],iy[1]+100,13);
        sfish(ix[2],iy[2]+100,11);
        if(ix[0]>1000||getpixel(ix[0]+21,iy[0]+100)==14)
        {

            ix[0]=0;
            iy[0]=rand()%200;
            count++;
        }
        ix[0]++;
        ix[1]++;
        ix[2]++;

        if(ix[1]>1200||getpixel(ix[1]+21,iy[1]+100)==14)
        {
            ix[1]=0;
            iy[1]=rand()%400;
            count++;
        }
        if(ix[2]>1200||getpixel(ix[2]+21,iy[2]+100)==14)
        {
            ix[2]=0;
            iy[2]=rand()%600;
            count++;
        }
        if(count>10)
        {
            sfish(ix[4],iy[4]+100,11);
            if(ix[4]>1200||getpixel(ix[4]+21,iy[4]+100)==14)
            {
                ix[4]=0;
                iy[4]=rand()%600;
                count++;
            }
            ix[4]++;
        }
        if(count>20)
        {
            sfish(ix[5],iy[5]+100,12);
            if(ix[5]>1200||getpixel(ix[5]+21,iy[5]+100)==14)
            {
                ix[5]=0;
                iy[5]=rand()%600;
                count++;
            }
            ix[5]++;
        }
        if(count>30)
        {
            sfish(ix[6],iy[6]+100,6);
            if(ix[6]>1200||getpixel(ix[6]+21,iy[6]+100)==14)
            {
                ix[6]=0;
                iy[6]=rand()%600;
                count++;
            }
            ix[6]++;
        }
        if(count>40)
        {
            sfish(ix[7],iy[7]+100,5);
            if(ix[7]>1200||getpixel(ix[7]+21,iy[7]+100)==14)
            {
                ix[7]=0;
                iy[7]=rand()%600;
                count++;
            }
            ix[7]++;
        }
        if(count>50)
        {
            sfish(ix[8],iy[8]+100,4);
            if(ix[8]>1200||getpixel(ix[8]+21,iy[8]+100)==14)
            {
                ix[8]=0;
                iy[8]=rand()%600;
                count++;
            }
            ix[8]++;
        }
        if(count>60)
        {
            sfish(ix[9],iy[9]+100,3);
            if(ix[9]>1200||getpixel(ix[9]+21,iy[9]+100)==14)
            {
                ix[9]=0;
                iy[9]=rand()%600;
                count++;
            }
            ix[9]++;
        }


        if(ix[3]<100)
        {
            ix[3]=1200;
            iy[3]=rand()%500;
        }

        if(getpixel(ix[3]-80,iy[3]+200)==10 || ix[0]==1199 ||ix[1]==1199 ||ix[2]==1199||ix[4]==1199 ||ix[5]==1199 ||ix[6]==1199 ||ix[7]==1199 ||ix[8]==1199 ||ix[9]==1199)
        {
           break;
        }
        bfish(ix[3],iy[3]+200);
        ix[3]--;
        p=1-p;
        delay(10);
    }
    delay(20);
    setactivepage(1);
    cleardevice();
    setcolor(12);
    settextstyle(1, HORIZ_DIR, 8);
    outtextxy(300,200,"Game Over!!");
    sprintf(sc,"Score: %d",count);
    setcolor(14);
    settextstyle(1, HORIZ_DIR, 5);
    outtextxy(300,300,sc);
    setcolor(7);
    settextstyle(1, HORIZ_DIR, 3);
    outtextxy(700,500,"Game by:JAINEE PATEL");
    setactivepage(0);
    setvisualpage(1);
	getch();
	closegraph();
	return 0;
}
