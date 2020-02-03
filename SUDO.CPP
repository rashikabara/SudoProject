#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>


    int flag;

    char* input1[9][9] =       {{" ","2"," "," "," "," "," "," "," "},
			       {" "," ","9"," "," "," "," "," "," "},
			       {" "," "," "," "," "," "," "," "," "},
			       {" "," "," ","1"," ","4"," "," "," "},
			       {" "," "," "," "," "," "," "," "," "},
			       {" "," "," "," "," "," "," "," "," "},
			       {"3","1","2"," "," "," "," "," ","5"},
			       {"8","5","6"," "," "," "," "," ","5"},
			       {"9","7","4"," "," "," "," "," ","4"}};



    char* input[9][9] =       {{"1","9","4","8","7","5","6","2","3"},
			       {"8","5","3","9","6","2","4","7","1"},
			       {"2","6","7","3","1","4","9","8","5"},
			       {"9","2","1","6","5","8","7","3","4"},
			       {"6","7","8","4","3","1","2","5","9"},
			       {"4","3","5","2","9","7","8","1","6"},
			       {"5","8","6","7","4","3","1","9","2"},
			       {"3","4","2","1","8","9","5","6","7"},
			       {"7","1","9","5","2","6","3","4","8"}};



    /*
    int ip[9][9]  =  {{0,2,0,0,0,0,0,0,0},
		      {0,0,9,0,0,0,0,0,0},
		      {0,0,0,0,0,0,0,0,0},
		      {0,0,0,1,0,4,0,0,0},
		      {0,0,0,0,0,0,0,0,0},
		      {0,0,0,0,0,0,0,0,0},
		      {3,1,2,0,0,0,0,0,5},
		      {8,5,6,0,0,0,0,0,5},
		      {9,7,4,0,0,0,0,0,4}};
     */


    //correct
    int ip[9][9]  =  { {1,9,4,8,7,5,6,2,3},
		      {8,5,3,9,6,2,4,7,1},
		      {2,6,7,3,1,4,9,8,5},
		      {9,2,1,6,5,8,7,3,4},
		      {6,7,8,4,3,1,2,5,9},
		      {4,3,5,2,9,7,8,1,6},
		      {5,8,6,7,4,3,1,9,2},
		      {3,4,2,1,8,9,5,6,7},
		      {7,1,9,5,2,6,3,4,8}};


    /*
    //incorrect
    int a[9][9]  =  { {1,9,4,8,7,5,6,2,3},
		      {8,5,3,9,6,2,4,7,1},
		      {2,6,7,3,1,4,9,8,5},
		      {9,2,1,6,5,8,7,3,4},
		      {6,7,8,4,3,1,2,5,9},
		      {4,3,5,2,9,7,8,1,6},
		      {5,8,6,7,4,3,1,9,2},
		      {3,4,2,1,8,9,5,6,7},
		      {7,1,9,5,2,6,3,4,7}};
    */
    /*
    //incorrect
    int a[9][9]  =  { {1,9,4,8,7,5,6,2,3},
		      {8,5,3,9,6,2,4,7,1},
		      {2,6,7,3,1,4,9,8,5},
		      {9,2,1,6,5,8,7,3,4},
		      {6,7,8,4,3,1,2,5,9},
		      {4,3,5,2,9,7,8,1,6},
		      {2,1,2,7,4,3,1,9,2},
		      {3,3,2,1,8,9,5,6,7},
		      {7,1,9,5,2,6,3,4,8}};
     */
    /*
    //incorrect
    int a[9][9]  =  { {1,9,4,8,7,5,6,2,3},
		      {8,5,3,9,6,2,4,7,1},
		      {2,6,7,3,1,4,9,8,5},
		      {9,2,1,6,5,8,7,3,4},
		      {6,7,8,4,3,1,2,5,9},
		      {4,3,5,2,9,7,8,1,6},
		      {5,8,6,7,4,3,1,9,2},
		      {3,4,2,1,8,9,5,6,7},
		      {7,1,9,5,2,6,3,4,8}};

      */




void drawBox()
{
    int i=0,j=0;
    int y = 0;
    int x = 0;
    for(i=0;i<9;i++)
    {
	for(j=0;j<9;j++)
	{
	   //x += 25;
	   rectangle(145+x,145+y,170+x,170+y);
	   x += 25;

	   //rectangle(145+x,145+y,170+x,170+y);
	   //setfillstyle(SOLID_FILL,0);//11
	   //floodfill(146+x,146+y,WHITE);



	}
	y += 25;
	x = 0;
    }
}



void report(int i,int j)
{
     input1[i][j] = "x";
}


void execute()
{
    int i=0,j=0;
    for(j=0;j<9;j++)
    {
       flag=0x0000;
       for(i=0;i<9;i++)
	  flag|=1<<(ip[i][j]-1);
       if(flag!=0x01FF)
	 //report("row",i-1,j);
	  report(i-1,j);
    }



    //check column

    for(j=0;j<9;j++)
    {
       flag=0x0000;
       for(i=0;i<9;i++)
	  flag|=1<<(ip[i][j]-1);
       if(flag!=0x01FF)
	  //report("col",i-1,j);
	  report(i-1,j);
    }

    //check square
    int si=0,sj=0;
    for(si=0;si<3;si++)
    {
	for(sj=0;sj<3;sj++)
	{
	    flag=0x0000;
	    for(i=0;i<3;i++)
	    {
		for(j=0;j<3;j++)
		   flag|=1<<(ip[si*3+i][sj*3+j]-1);

	    }
		if(flag!=0x01FF)
		    //report("square",si*3+i-1,sj*3+j-1);
		    report(si*3+i-1,sj*3+j-1);
	}
     }
}



void eraze()
{
     setcolor(0);
     outtextxy(445,200,"Sudoku is Not Solve");
     outtextxy(445,200,"Sudoku is Solve");
     setcolor(15);
}


void Solve()
{
    int i=0,j=0;
    int y = 0;
    int x = 0;
    int check = 0;
    //int x1 = 145;
    //int y1 = 145;
    for(i=0;i<9;i++)
    {
	for(j=0;j<9;j++)
	{
	   //x += 25;
	   //setcolor()
	   if(strcmp(input1[i][j],"x"))
	   {
	       //rectangle(145+x,145+y,170+x,170+y);
	       //x += 25;

		rectangle(145+x,145+y,170+x,170+y);
		setfillstyle(SOLID_FILL,0);//11
		floodfill(146+x,146+y,WHITE);
		x += 25;


	       //outtextxy(500,400,
	   }
	   else
	   {
		rectangle(145+x,145+y,170+x,170+y);
		setfillstyle(SOLID_FILL,12);//11
		floodfill(146+x,146+y,WHITE);
		x += 25;

		check = 1;
	   }
	}
	y += 25;
	x = 0;
    }

    eraze();


    if(check == 1)
    {
	outtextxy(445,200,"Sudoku is Not Solve");
    }
    else if(check == 0)
    {
       outtextxy(445,200,"Sudoku is Solve");
    }



}



void dispNum(char* input[9][9])
{
     int i=0,j=0;
     int x = 0;
     int y = 0;
     for(i=0;i<9;i++)
     {
	  for(j=0;j<9;j++)
	  {
	     if(input[i][j] == "0")
	     {
		//outtextxy(155+x,155+y," ");
		x += 25;
	     }
	     else if(input[i][j] != "0");
	     {
		setcolor(15);
		outtextxy(155+x,155+y,input[i][j]);
		x += 25;
		setcolor(0);
	     }
	  }
	  y += 25;
	  x = 0;
     }

}


void clearNum(char* input[9][9])
{
     int i=0,j=0;
     int x = 0;
     int y = 0;
     for(i=0;i<9;i++)
     {
	  for(j=0;j<9;j++)
	  {
	     if(input[i][j] == "0")
	     {
		//outtextxy(155+x,155+y," ");
		x += 25;
	     }
	     else if(input[i][j] != "0");
	     {
		setcolor(0);
		outtextxy(155+x,155+y,input[i][j]);
		x += 25;
		setcolor(15);
	     }
	  }
	  y += 25;
	  x = 0;
     }

}




void blink()
{

     //int ci=0,cj=0;

     int x = 0;
     int y = 0;

     int i=0,j=0;


     while(1)
     {

	 //clrscr();

	 dispNum(input);

	 //drawBox();

	 //dispNum();

	 //drawBox();

	 outtextxy(155,155,"_");

	 int ch = getch();


	 //outtextxy(155,155,"-");

	 if(ch == 72) // up
	 {
	    //input[i][j] = "_";
	    //cout<<"\n\t Up";
	    outtextxy(155+x,155+y,"_");
	    if(i>0)
	    {
	      i--;
	      y -= 25;
	    }
	    setcolor(15);
	    outtextxy(155+x,155+y,"_");
	    setcolor(0);

	 }
	 else if(ch == 80) //down
	 {
	    //input[i][j] = "_";
	    outtextxy(155+x,155+y,"_");
//	    cout<<"\n\t Down";
	    if(i<8)
	    {
	      i++;
	      y += 25;
	    }
	    setcolor(15);
	    outtextxy(155+x,155+y,"_");
	    setcolor(0);
	 }
	 else if(ch == 77) //right
	 {
	    outtextxy(155+x,155+y,"_");
//	    cout<<"\n\t Right";
	    if(j<8)
	    {
	      j++;
	      x += 25;
	    }
	    setcolor(15);
	    outtextxy(155+x,155+y,"_");
	    setcolor(0);
	 }
	 else if(ch == 75)// left
	 {
	    outtextxy(155+x,155+y,"_");
//	    cout<<"\n\t Left";
	    if(j>0)
	    {
	      j--;
	      x -= 25;
	    }
	    setcolor(15);
	    outtextxy(155+x,155+y,"_");
	    setcolor(0);
	 }
	 else if(ch == 49)   //1
	 {
	    if(strcmp(input[i][j]," "))
	    {
	       //input[i][j] = "1";
	    }
	    else
	    {
	       input[i][j] = "1";
	    }
	    if(ip[i][j] == 0)
	    {
	       ip[i][j] = 1;
	    }
	 }
	 else if(ch == 50)   //2
	 {
	    if(strcmp(input[i][j]," "))
	    {
	       //input[i][j] = "1";
	    }
	    else
	    {
	       input[i][j] = "2";
	    }
	    if(ip[i][j] == 0)
	    {
	       ip[i][j] = 2;
	    }

	 }
	 else if(ch == 51)   //3
	 {
	    if(strcmp(input[i][j]," "))
	    {
	       //input[i][j] = "1";
	    }
	    else
	    {
	       input[i][j] = "3";
	    }
	    if(ip[i][j] == 0)
	    {
	       ip[i][j] = 3;
	    }
	 }
	 else if(ch == 52)   //4
	 {
	    if(strcmp(input[i][j]," "))
	    {
	       //input[i][j] = "1";
	    }
	    else
	    {
	       input[i][j] = "4";
	    }
	    if(ip[i][j] == 0)
	    {
	       ip[i][j] = 4;
	    }

	 }
	 else if(ch == 53)   //5
	 {
	    if(strcmp(input[i][j]," "))
	    {
	       //input[i][j] = "1";
	    }
	    else
	    {
	       input[i][j] = "5";
	    }
	    if(ip[i][j] == 0)
	    {
	       ip[i][j] = 5;
	    }

	 }
	 else if(ch == 54)   //6
	 {
	    if(strcmp(input[i][j]," "))
	    {
	       //input[i][j] = "1";
	    }
	    else
	    {
	       input[i][j] = "6";
	    }
	    if(ip[i][j] == 0)
	    {
	       ip[i][j] = 6;
	    }

	 }
	 else if(ch == 55)   //7
	 {
	    if(strcmp(input[i][j]," "))
	    {
	       //input[i][j] = "1";
	    }
	    else
	    {
	       input[i][j] = "7";
	    }
	    if(ip[i][j] == 0)
	    {
	       ip[i][j] = 7;
	    }

	 }
	 else if(ch == 56)   //8
	 {
	    if(strcmp(input[i][j]," "))
	    {
	       //input[i][j] = "1";
	    }
	    else
	    {
	       input[i][j] = "8";
	    }
	    if(ip[i][j] == 0)
	    {
	       ip[i][j] = 8;
	    }

	 }
	 else if(ch == 57)   //9
	 {
	    if(strcmp(input[i][j]," "))
	    {
	       //input[i][j] = "1";
	    }
	    else
	    {
	       input[i][j] = "9";
	    }
	    if(ip[i][j] == 0)
	    {
	       ip[i][j] = 9;
	    }

	 }
	 clearNum(input);
	 if(ch == 48)
	 {
	    if(strcmp(input[i][j]," "))
	    {
	       input[i][j] = " ";
	    }
	    else
	    {

	    }
	    if(ip[i][j] != 0)
	    {
	       ip[i][j] = 0;
	    }

	 }
	 else if(ch == 's')
	 {

	     //strcpy(input1,input);
	     //input1 = (char *)&input;
	     //outtextxy(20,20,"S----S");
	     int m=0,n=0;
	     for(m=0;m<9;m++)
	     {
		 for(n=0;n<9;n++)
		 {
		     input1[m][n] = input[m][n];
		 }
	     }
	     execute();
	     Solve();

	 }
	 else if(ch == 'e')
	 {
	     break;
	     //ch =  'n';
	 }
	 //clearNum(input);
    }
}






void main()
{
    clrscr();


    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");

    errorcode = graphresult();
    if (errorcode != grOk)
    {
	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1);
    }


      //setcolor(RED);
      //rectangle(245,245,270,270);

      //setcolor(15);

      //settextstyle(2,0,5);
      outtextxy(480,152," : Shows Errors");
      outtextxy(445,240,"0  : Eraze");
      outtextxy(445,270,"e  : Exit ");
      outtextxy(445,300,"s  : Solve");


      rectangle(445,145,470,170);
      setfillstyle(SOLID_FILL,12);//11
      floodfill(446,146,WHITE);




       drawBox();
       blink();

       //Solve();





    getch();
    closegraph();



/*
    int i=0,j=0;

    for(i=0;i<9;i++)
    {
	for(j=0;j<9;j++)
	{
	cout<<"   "<<ip[i][j];
	}
	cout<<"\n";
    }
*/




    getch();
}