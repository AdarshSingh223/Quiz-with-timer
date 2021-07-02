#include<dos.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>

#define TRUE 1

void introScreen()  	                     ;
void loadScreen()   	                     ;
void printQuestion()	                     ;
void helpScreen()   	                     ;
void quitScreen()                            ;
void endScreen()                             ;
void retry()                                 ;
void viewScore()			     ;
void loadingScreenTip(int tipNum)            ;
void questionViewer(int currentQuestionNum)  ;
void showTimer(int minsLeft,int secondsLeft) ;

char checkChar       ;

int currentPosX = 37 ;
int currentPosY = 14 ;

int quitPosX    = 35 ;
int quitPosY    = 14 ;

int endPosX     = 32 ;
int endPosY     = 13 ;

int minsLeft    = 0  ;
int secondsLeft = 70 ;

int currentLineNum   ;

int currentQuestionNum = 1 ;

void introScreen()
{
	clrscr()       ;

	gotoxy(29,8)   ;
	printf("********************");
	gotoxy(29,9)   ;
	printf("****") ;
	gotoxy(45,9)   ;
	printf("****") ;
	gotoxy(29,10)  ;
	printf("**")   ;
	gotoxy(47,10)  ;
	printf("**")   ;
	gotoxy(37,10)  ;
	printf("QUIZ") ;
	gotoxy(29,11)  ;
	printf("****") ;
	gotoxy(45,11)  ;
	printf("****") ;
	gotoxy(29,12)  ;
	printf("********************");

	gotoxy(currentPosX,currentPosY)   ;
	printf("PLAY")                    ;

	gotoxy(currentPosX,currentPosY+2) ;
	printf("HELP")                    ;

	gotoxy(currentPosX,currentPosY+4) ;
	printf("QUIT")                    ;

	gotoxy(currentPosX,currentPosY)   ;

	while(TRUE)
	{
		checkChar = getch() ;

		if(checkChar == 'w' || checkChar == 'W' || checkChar == 72)
		{
			if(currentPosY != 14)
			{
				currentPosY -= 2                ;
				gotoxy(currentPosX,currentPosY) ;
			}
		}
		else if(checkChar == 's' || checkChar == 'S' || checkChar == 80)
		{
			if(currentPosY != 18)
			{
				currentPosY += 2                ;
				gotoxy(currentPosX,currentPosY) ;
			}
		}
		else if(checkChar == 13)
		{
			if(currentPosY == 14)
			{
				loadScreen() ;
			}
			else if(currentPosY == 16)
			{
				helpScreen() ;
			}
			else
			{
				quitScreen() ;
			}
		}
	}

}

void loadScreen()
{
	int i      ;
	int tipNum ;

	srand(time(0))    ;
	tipNum = rand()%3 ;

	clrscr() ;

	for(i = 0 ; i < 3 ; ++i)
	{
		clrscr()                 ;
		gotoxy(35,12)            ;
		printf("LOADING")        ;
		loadingScreenTip(tipNum) ;
		delay(600)               ;

		clrscr()                 ;
		gotoxy(35,12)            ;
		printf("LOADING.")       ;
		loadingScreenTip(tipNum) ;
		delay(600)               ;

		clrscr()                 ;
		gotoxy(35,12)            ;
		printf("LOADING..")      ;
		loadingScreenTip(tipNum) ;
		delay(600)               ;

		clrscr()                 ;
		gotoxy(35,12)            ;
		printf("LOADING...")     ;
		loadingScreenTip(tipNum) ;
		delay(600)               ;
	}
	printQuestion();
}

void helpScreen()
{
	clrscr() ;

	gotoxy(35,4)           ;
	printf("INSTRUCTIONS") ;

	gotoxy(7,8)                                 ;
	printf("> WELCOME TO THE QUIZ WITH TIMER!") ;

	gotoxy(7,9)                                                          ;
	printf("> YOU WILL BE PRESENTED WITH 15 MULTIPLE CHOICE QUESTIONS.") ;

	gotoxy(7,10)                                                               ;
	printf("> EACH QUESTION HAS 4 OPTIONS, OUT OF WHICH ONLY ONE IS CORRECT.") ;

	gotoxy(7,11)                                                                         ;
	printf("> USE ARROW KEYS OR 'W','A','S','D' COMBINATION TO MOVE AROUND THE OPTIONS") ;

	gotoxy(7,12)                                     ;
	printf("> PRESS ENTER KEY TO SELECT AN OPTION.") ;

	gotoxy(7,13)                                                ;
	printf("> YOU CAN ALWAYS GO BACK AND CHANGE YOUR ANSWERS!") ;

	gotoxy(35,22)    ;
	printf("< BACK") ;
	gotoxy(35,22)    ;

	currentPosX = 37 ;
	currentPosY = 14 ;

	checkChar = getch() ;
	if(checkChar == 13)
	{
		introScreen();
	}
}

void quitScreen()
{
	clrscr();

	gotoxy(30,12)                  ;
	printf("DO YOU WANT TO QUIT?") ;

	gotoxy(35,14) ;
	printf("YES") ;
	gotoxy(42,14) ;
	printf("NO")  ;
	gotoxy(35,14) ;

	while(TRUE)
	{
		checkChar = getch();

		if(checkChar == 'D' || checkChar == 'd' || checkChar == 77)
		{
			if(quitPosX == 35)
			{
				quitPosX += 7             ;
				gotoxy(quitPosX,quitPosY) ;
			}
		}

		else if(checkChar == 'A' || checkChar == 'a' || checkChar ==  75)
		{
			if(quitPosX == 42)
			{
				quitPosX -= 7             ;
				gotoxy(quitPosX,quitPosY) ;
			}
		}
		else if(checkChar == 13)
		{
			if(quitPosX == 35)
			{
				exit(0);
			}
			else
			{
				quitPosX = 35    ;
				currentPosX = 37 ;
				currentPosY = 14 ;

				introScreen()    ;
			}
		}
	}
}

void loadingScreenTip(int tipNum)
{
	switch(tipNum)
	{
		case 0 : gotoxy(35,19)     ;
			 printf("PRO TIP") ;

			 gotoxy(25,20)                          ;
			 printf("READ THE QUESTIONS PROPERLY!") ;

			 break;

		case 1 : gotoxy(35,19)     ;
			 printf("PRO TIP") ;

			 gotoxy(16,20)                                             ;
			 printf("YOU CAN ALWAYS GO BACK AND CHANGE YOUR ANSWERS!") ;

			 break ;

		case 2 : gotoxy(35,19)     ;
			 printf("PRO TIP") ;

			 gotoxy(27,20)                       ;
			 printf("KEEP AN EYE ON THE TIMER!") ;

			 break ;
	}
}

void printQuestion()
{
	int i    ;
	clrscr() ;

	while(TRUE)
	{
		clrscr();

		showTimer(minsLeft,secondsLeft);
		gotoxy(3,12);
		questionViewer(currentQuestionNum);
		delay(1000);

		secondsLeft--;
		if(secondsLeft == -1)
		{
			minsLeft--;
			secondsLeft = 59;
		}
		if(minsLeft == -1)
		{
			endScreen();
		}
	}
}

void showTimer(int minsLeft,int secondsLeft)
{
	gotoxy(29,4);
	printf("*********************");
	gotoxy(29,5);
	printf("**");
	gotoxy(35,5);
	printf("TIME LEFT");
	gotoxy(48,5);
	printf("**");
	gotoxy(29,6);
	printf("**");
	gotoxy(36,6);
	if(secondsLeft > 9)
	{
		printf("%02d : %d",minsLeft,secondsLeft);
	}
	else
	{
		printf("%02d : %02d",minsLeft,secondsLeft);
	}
	gotoxy(48,6);
	printf("**");
	gotoxy(29,7);
	printf("****");
	gotoxy(46,7);
	printf("****");
	gotoxy(29,8);
	printf("*********************");
}

void endScreen()
{
	clrscr() ;

	gotoxy(25,10)                          ;
	printf("THANK YOU FOR PARTICIPATING!") ;

	gotoxy(35,11) ;
	viewScore()   ;

	gotoxy(32,13)   ;
	printf("RETRY") ;

	gotoxy(42,13)  ;
	printf("MENU") ;

	gotoxy(32,13);

	while(TRUE)
	{
		checkChar = getch();

		if(checkChar == 'a' || checkChar == 'A' || checkChar == 75)
		{
			if(endPosX == 42)
			{
				endPosX -= 10           ;
				gotoxy(endPosX,endPosY) ;
			}
		}
		else if(checkChar == 'd' || checkChar == 'D' || checkChar == 77)
		{
			if(endPosX == 32)
			{
				endPosX += 10		;
				gotoxy(endPosX,endPosY) ;
			}
		}
		else if(checkChar == 13)
		{
			if(endPosX == 42)
			{
				introScreen();
			}
			else
			{
				retry();
			}
		}
	}

	checkChar = getch();
	if(checkChar == 13)
	{
		exit(0);
	}
}

void retry()
{
	currentPosX = 37 ;
	currentPosY = 14 ;

	quitPosX = 35 ;
	quitPosY = 14 ;

	endPosX = 32 ;
	endPosY = 13 ;

	minsLeft    = 7  ;
	secondsLeft = 30 ;

	currentQuestionNum = 1 ;

	loadScreen();
}
void questionViewer(int currentQuestionNum)
{
	char line[256]      ;
	FILE *filePointer   ;
	int lineCounter = 1 ;

	filePointer = fopen("questions.txt","r");
	if(filePointer == NULL)
	{
		printf("FAILED : ");
	}

	currentLineNum = currentQuestionNum * 3 - 2;
	while(fgets(line,sizeof(line),filePointer) != NULL)
	{
		if(lineCounter == currentLineNum)
		{
			fputs(line,stdout) ;
			if((currentLineNum + 2) % 3 == 0)
			{
				printf("\n") ;
			}
			currentLineNum++   ;

			if((currentLineNum -1) % 3 == 0)
			{
				lineCounter = 1 ;
				break           ;
			}
		}

		lineCounter++ ;
	}

	fclose(filePointer) ;

}
void viewScore()
{
	printf("This function was called");
}
int main(int argc, char *argv[])
{
	introScreen();
	getch();
	return 0;
}