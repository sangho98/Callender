#include <stdio.h>
#include <stdlib.h>

void input(int *,int *);
void output(int *,int *,int *,int [][12]);
int isleap(int);
void day(int *,int *,int *,int [][12]);

int main(){

	int *year = NULL, *month = NULL, *d_sum = NULL, days[2][12] = { {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

	year = (int *) malloc(sizeof(int));
	month = (int *) malloc(sizeof(int));
	d_sum = (int *) malloc(sizeof(int));
	
	*d_sum = 0;

	input(year,month);

	day(year,month,d_sum,days);

	output(year,month,d_sum,days);

	return 0;

}

void input(int *year, int *month){

	printf("년도를 입력하세요 : ");
	scanf("%d",year);

	printf("월을 입력하세요 : ");
	scanf("%d",month);

}

void output(int *year, int *month, int *d_sum, int days[2][12]){

	int i,j = 1,k = 1,result;

	result = *d_sum % 7;

	printf("         %d 년 %d 월 \n", *year, *month);

	printf("%4s%4s%4s%4s%4s%4s%4s\n","Mo","Tu","We","Th","Fr","Sa","Su");

	switch(result){

		case 1 : printf("    "); break;
		case 2 : printf("        "); break;
		case 3 : printf("            "); break;
		case 4 : printf("                "); break;
		case 5 : printf("                    "); break;
		case 6 : printf("                        ");break;

	}

	if(isleap(*year) == 1){

		switch(result){

			case 0 : for(i=0;i<7;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;
			case 1 : for(i=0;i<6;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;
			case 2 : for(i=0;i<5;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;
			case 3 : for(i=0;i<4;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;
			case 4 : for(i=0;i<3;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;
			case 5 : for(i=0;i<2;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;
			case 6 : for(i=0;i<1;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;

		}

		for(i=7-result;i<days[1][*month-1];i++){

			printf("%4d",j++);
			if(k++ == 7){
				printf("\n");
				k = 1;
			}
		}

	}else{

		switch(result){

			case 0 : for(i=0;i<7;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;
			case 1 : for(i=0;i<6;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;
			case 2 : for(i=0;i<5;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;
			case 3 : for(i=0;i<4;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;
			case 4 : for(i=0;i<3;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;
			case 5 : for(i=0;i<2;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;
			case 6 : for(i=0;i<1;i++)
						 printf("%4d",j++);
					 printf("\n");
					 break;

		}

		for(i=7-result;i<days[0][*month-1];i++){

			printf("%4d",j++);
			if(k++ == 7){
				printf("\n");
				k = 1;
			}
		}
	}

}

int isleap(int year){

	int isleap;

	isleap = (year % 4) ? 0 : ((year % 100) ? 1 : ((year % 400) ? 0 : 1));

	return isleap;

}

void day(int *year, int *month, int *d_sum, int days[2][12]){

	int i, j, k = 1;

	for(i=0;i<*year-1;i++){

		if(isleap(k++) == 1){

			for(j=0;j<12;j++)
				*d_sum += days[1][j];

		}else{

			for(j=0;j<12;j++)
				*d_sum += days[0][j];

		}

	}


	if(*month == 2){

		if(isleap(*year) == 1){
			*d_sum += days[1][0];
		}

	}else if(*month > 2){

		if(isleap(*year) == 1){

			for(j=0;j<*month-1;j++)
				*d_sum += days[1][j];
		}else{

			for(j=0;j<(*month)-1;j++){
				*d_sum += days[0][j];
			}
		}

	}

	return;


}
