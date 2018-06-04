#include <conio.h>
#include <stdlib.h>
#include <stdio.h>


int main() {

	int state=1;
	char ch, i = 0,  j = 0;
	int broi = 0;
	FILE*f;
	char ime[15];
	
	printf("ime fail:\t");
	gets(ime);
	
	f = fopen("test.txt", "r");
	if (!f){ printf("nqma fail\n"); system("pause"); return 1; }

	while ((ch = fgetc(f)) != EOF) {
		switch (state)
		{
		case 1:switch (ch){
		case '\n':state = 2;break;
		case ' ':state = 2; break;
		case '.':state = 2; break;
		}
		case 2:	switch (ch){
		case '\n':state = 1;break;
		case ' ':state = 1; broi++; break;
		case '.':state = 1; broi++; break;
			}
		}
	}
		 
	rewind(f);

	printf("\nbroi dumi=%d\n\n", broi);
	_getch();
	
	rewind(f);
	printf("Sydyrjanie fail:\n");
	_getch();

	while ((ch = getc(f)) != EOF){
		printf("%c",ch);}
   
	_getch();
	rewind(f);
	fclose(f);
	return 0;
}

