#include<stdio.h>
#include "Billgenerate.h"
#include <string.h>
#include <stdlib.h>
#define MAX 50



//Read date input from user
void read_date(date_t *ptr_date)
{
	printf("Enter the date : ");
	scanf("%d %d %d",&ptr_date->dd,&ptr_date->mm,&ptr_date->yy);
	
}

//Display date output
void display_date(const date_t *ptr_date)
{
	printf("\n%d-%d-%d ",ptr_date->dd,ptr_date->mm,ptr_date->yy);
	
}

int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

//Validate date 
 void validate_date( date_t *ptr_date1,date_t *ptr_date2,date_t* randate,int* temp,int day)
{	
	

	if((ptr_date1->dd<=mon[ptr_date1->mm])&&(ptr_date2->dd<=mon[ptr_date2->mm]))
	{
	//printf("\n-------------------------------------");
	if(ptr_date1->yy==ptr_date2->yy)
	{
		int y=ptr_date1->yy;
		if(ptr_date1->mm==ptr_date2->mm)
		{
			int m=ptr_date1->mm;
			for (int d=ptr_date1->dd;d<=mon[ptr_date1->mm]&&d<=ptr_date2->dd;++d)
			{
				if(day!=2)
				{
				//printf("\n%d-%d-%d ",d,m,y);
				randate[*temp].dd=d;
				randate[*temp].mm=m;
				randate[*temp].yy=y;
				randate[*temp].day=day;
				++(*temp);
				day++;
				day=day%7;
				}
				else
				{
					printf("\n%d-%d-%d  :holiday",d,ptr_date1->mm,ptr_date1->yy);
					++day;
				}
			}
		}
		else
		{
			int m1=ptr_date1->mm;
			int m2=ptr_date2->mm;
			int diff=m2-m1;
			int dat=ptr_date1->dd;

			while(diff!=0)
				{
					
			
					for (int d1=dat;d1<=mon[m1];++d1)
					{
						if(day!=2)
						{
						//printf("\n%d-%d-%d ",d1,m1,y);
						randate[*temp].dd=d1;
						randate[*temp].mm=m1;
						randate[*temp].yy=y;
						randate[*temp].day=day;
						++(*temp);
						day++;
						day=day%7;
						}
						else
						{
							printf("\n%d-%d-%d  :holiday",d1,m1,ptr_date1->yy);
							++day;
						}
						
					}
					--diff;
					m1++;
					dat=1;
					
				
				}
				//printf("\n-------------------------------------------------------------");
				for(int d2=1;d2<=ptr_date2->dd;++d2)
				{
					if(day!=2)
					{
					//printf("\n%d-%d-%d ",d2,m2,y);
					randate[*temp].dd=d2;
					randate[*temp].mm=m2;
					randate[*temp].yy=y;
					randate[*temp].day=day;
					++(*temp);
					day++;
					day=day%7;
					}
						else
						{
							printf("\n%d-%d-%d  :holiday",d2,ptr_date2->mm,ptr_date1->yy);
							++day;
						}
					
				}
				
			
		}	
	}
	
	else
		{
			printf("\n Enter the correct year");
		}
	
	}
	else
	{
		printf("\nenter the valid date");
	}

}
//Read input from file
void read_names(name_t* n)
{
	FILE* ptr;
	char ch[100];
	int lineend[100];
	// Opening file in reading mode
	ptr = fopen("names.txt", "r");

	if (ptr==NULL) {
		printf("file can't be opened \n");
	}

	
	for(int i=0;i<=MAX;i++)
	{
	 fgets(n[i].detail,49,ptr);
	n[i].detail[strcspn(n[i].detail,"\n")]=0;
	 
	}
		
}

//to generate bill
void bill_generate(name_t* n,date_t* randate,int temp,bill_t* bills,int* no_of_bills,name_t* items,items_t* peritem)
{
	srand(0);
	int end,low1=20 ,high1=40,count=0,high=5000,low=101,paise_sum=0,sl_no=0,arr[100],no_bill=0,paise,randtime,quantity;
	float total_price,newpaise=0,price_sum=0,price;
	char* ch_arr[]={"8-9am","9-10am","10-11am","11-12pm","12-1pm","4-5pm","5-6pm","6-7pm","7-8pm","8-9pm","9-10pm"};
	
	printf("\n");
	//printf("Sl.No \tDate\t\t\tName\t\t\tPrice");
	for(int k=0;k<MAX;k++)
	{
		arr[k]=k;
	}
	for(int j=0;j<temp;j++)
	{
		
		printf("\n");
		printf("*********************************************************************************************");		
				for(int l=0;l<end;++l)
				{
					int current=arr[l];
					int ran =rand()%MAX;
					arr[l]=arr[ran];
					arr[ran]=current;
					
				}
				sl_no=0;
				//no_bill=no_bill;
				if(randate[j].day==6||randate[j].day==0)
					{
						end=rand()%(40+1-35)+35;
					}
					else
					{
						end=rand()%(high1+1-low1)+low1;
					}
				for(int i=0;i<end;++i)
				{	
					++count;
					
					
					
					if(randate[j].day==6||randate[j].day==0)
					{
						quantity=rand()%(5+1-3)+3;
					}
					else
					{
						quantity=rand()%(5+1-1)+1;
					}
				
					price=peritem[arr[i]].itemprice*quantity;
					peritem[arr[i]].total_quantity-=quantity;
					printf("\n");
					price_sum+=price;
					sl_no++;
					randtime=rand()%11;
					
					
					bills[no_bill].dates.dd=randate[j].dd;
					bills[no_bill].dates.mm=randate[j].mm;
					bills[no_bill].dates.yy=randate[j].yy;
					bills[no_bill].days=randate[j].day;
					bills[no_bill].names=n[arr[i]];
					bills[no_bill].nitems=peritem[arr[i]].items;
					bills[no_bill].quantity=quantity;
					bills[no_bill].nprice=price;
					bills[no_bill].timings=ch_arr[randtime];
					++no_bill;
					
					printf("%d)  %4d-%2d-%2d  %20s\t      %.2frs",sl_no,randate[j].dd,randate[j].mm,randate[j].yy,n[arr[i]].detail,price);
					
				}
			
			
			
	
	printf("\n\n*****************************Total price on %d/%d/%d : %.2frs ***************************************",randate[j].dd,randate[j].mm,randate[j].yy,price_sum);
	price_sum=0;
	printf("\n\n*****************************Total head count per Day : %d ********************************************",count);
	count=0;
	printf("\n");
	if(j<temp-1&&temp!=0)
	printf("Sl.No \t\tDate\t\tName\t\tPrice");
	
	}
	*no_of_bills=no_bill;
}
void display_by_date( bill_t* bills,int no_of_bills)
	{
		char* ch_days[]={"sun","mon","tue","wed","thurs","fri","sat"};
		printf("Sl.No \t\tDate\t\tName\t\t   Price\t   Timings\t   Day \t\t    Item \t\t Quantity");
		printf("\n***************************************************************************************************************************************************");
		for(int i=0;i<no_of_bills;++i)
		{
			printf("\n%d.         %5d-%d-%d%20s        %.2f     %8s     %8s\t\t %8s\t\t%2d",i,bills[i].dates.dd,bills[i].dates.mm,bills[i].dates.yy,bills[i].names,bills[i].nprice,bills[i].timings,ch_days[bills[i].days],bills[i].nitems,bills[i].quantity);
		}
	}

void display_by_name( bill_t* bills,int no_of_bills,name_t* total_name,byname_t* pername)
{
	printf("Sl.No\t Customername\t Total_cost spent");
	printf("\n****************************************************************************************************");
	for(int i=0;i<MAX;++i)
	{
		printf("\n%d %20s            :  %.2f ",i,pername[i].selectedname.detail,pername[i].total_price);
	}

}
void display_by_selected_date(bill_t* bills,int no_of_bills,date_t* selecteddate,date_t* ptr_date1,date_t* ptr_date2)
{
	printf("Customername\t Total_cost spent");
	printf("\n****************************************************************************************************");
	
	if(selecteddate->mm=ptr_date1->mm)
	{
	if(selecteddate->dd>=ptr_date1->dd&&selecteddate->dd<=mon[ptr_date2->dd])
	{
		for(int i=0;i<no_of_bills;i++)
		{
			if(bills[i].dates.dd==selecteddate->dd&&bills[i].dates.mm==selecteddate->mm&&bills[i].dates.yy==selecteddate->yy)
			{
				printf("\n%20s :\t%.2f ",bills[i].names.detail,bills[i].nprice);
			}

		}
	}
	else
	{
		printf("\n enter date should be in the interval ");
	}
	}
	else
	{
		if(selecteddate->mm>=ptr_date1->mm&&selecteddate->mm<=ptr_date2->mm)
		{
			if(selecteddate->dd>=mon[ptr_date1->mm]&&selecteddate->dd<=mon[ptr_date2->mm])
			{
				for(int i=0;i<no_of_bills;i++)
				{
				if(bills[i].dates.dd==selecteddate->dd&&bills[i].dates.mm==selecteddate->mm&&bills[i].dates.yy==selecteddate->yy)
				{
				printf("\n%20s :\t %.2f ",bills[i].names.detail,bills[i].nprice);
				}
				}
			}
		}
	}
}

void insert_names( bill_t* bills,int no_of_bills,name_t* total_name,byname_t* pername)
{
float sum[100]={0};
	printf("Sl.No      \tName  \t\tPrice");
	for(int i=0;i<50;++i)
	{
		
		for(int j=0;j<no_of_bills;++j)
		{
			//printf("\n %s ",total_name[i].detail);
			//printf("\n %s ",bills[j].names.detail);
			if(strcmp(total_name[i].detail,bills[j].names.detail)==0)
			{
				sum[i]+=bills[j].nprice;
				
			}
		strcpy(pername[i].selectedname.detail,total_name[i].detail);
		pername[i].total_price=sum[i];	
			
	}
	
}
}
void display_by_selected_name(char* customername,byname_t* pername)
{
	for(int i=0;i<MAX;++i)
	{
		if(strcmp(customername,pername[i].selectedname.detail)==0)
		{
			printf("%10s : %.2f",pername[i].selectedname.detail,pername[i].total_price);
		}
		
	}
}
void display_by_time(const bill_t* bills,int no_of_bills,date_t* randate,int temp)
{
	char* ch_arr[]={"8-9am","9-10am","10-11am","11-12pm","12-1pm","4-5pm","5-6pm","6-7pm","7-8pm","8-9pm","9-10pm"};
	printf("%d",temp);
	int s=0;
	for(int i=0;i<temp;++i)
	{
		s=0;
		printf("\n %d-%d-%d%",randate[i].dd,randate[i].mm,randate[i].yy);
		for(int j=0;j<no_of_bills;++j)
		{
				if(s==11)
				{
					break;
				}
						
			if(randate[i].dd==bills[j].dates.dd&&randate[i].mm==bills[j].dates.mm&&randate[i].yy==bills[j].dates.yy)
			{
				
				for(int k=j;k<no_of_bills;k++)
				{
				
					
					if(strcmp(ch_arr[s],bills[k].timings)==0)
				
				{
					printf("\n      %20s       %.2f     %2s",bills[k].names,bills[k].nprice,bills[k].timings);
					
				}

				}
					s++;
					
			}
			
				
			}
			
		}
		
}
void display_total_cost_by_time(bill_t* bills,int no_of_bills)
{
	char* ch_arr[]={"8-9am","9-10am","10-11am","11-12pm","12-1pm","4-5pm","5-6pm","6-7pm","7-8pm","8-9pm","9-10pm"};
	float sum=0;
	int s=0;
	for(int i=0;i<11;++i)
	{
	
		sum=0;
		for(int j=0;j<no_of_bills;++j)
		{
		if(strcmp(ch_arr[i],bills[j].timings)==0)
		{
			sum+=bills[j].nprice;
			
		}
		
		}
		
		printf("\n %s  : %.2f ",ch_arr[i],sum);
	}
}
	void display_total_cost_by_day(const bill_t* bills,int no_of_bills,int temp)
	{
		float sum=0;
		char* ch_days[]={"sun","mon","tue","wed","thurs","fri","sat"};
		for(int i=0;i<=6;++i)
		{
			sum=0;
			for(int j=0;j<no_of_bills;++j)
			{
				if(i==bills[j].days)
				{
					sum+=bills[j].nprice;
				}
			}
			
		
			
			
			printf("\n%2s  : %.2f ",ch_days[i],sum);
		
		
	}
	}
	
void read_items(name_t* items)
{
	FILE* ptr;
	char ch[100];
	int lineend[100];
	// Opening file in reading mode
	ptr = fopen("items.txt", "r");

	if (ptr==NULL) {
		printf("file can't be opened \n");
	}

	
	for(int i=0;i<=MAX;i++)
	{
	 fgets(items[i].detail,49,ptr);
	items[i].detail[strcspn(items[i].detail,"\n")]=0;
	 
	}
		
}
void items_price(items_t* peritem,name_t* items)
{
	int price,paise;
	float actualpaise;
	float totalprice;
	for(int i=0;i<MAX;++i)
	{
		price=rand()%(1000+1-100)+100;
		paise=rand()%(100+1-10)+10;
		actualpaise=paise;
		totalprice=price+(actualpaise/100);
		strcpy(peritem[i].items.detail,items[i].detail);
		peritem[i].itemprice=totalprice;
		peritem[i].total_quantity=100;
	}
}
void display_item_price(items_t* peritem)
{
	printf("\n Items\t\t\t     Itemprice \t Total quantity \t Remaining_quantity  \t Quantity sold");
	printf("\n------------------------------------------------------------------------------------------------------------");
	for(int i=0;i<MAX;++i)
	{
		printf("\n%15s \t\t %.2f\t\t%d \t\t %d \t\t\t %d",peritem[i].items.detail,peritem[i].itemprice,100,peritem[i].total_quantity,100-peritem[i].total_quantity);
	}
	
}
void display_by_item(const bill_t* bills,int no_of_bills,name_t* items)
{
	float sum=0;
	int nquantity=0;
	printf("\n Items \t\t Quantitysold \t totalcost");
	printf("\n---------------------------------------------------------------------------");
	for(int i=0;i<MAX;++i)
	{
		sum=0;
		nquantity=0;
		for(int j=0;j<no_of_bills;++j)
		{
			if(strcmp(items[i].detail,bills[j].nitems.detail)==0)
			{
				nquantity+=bills[j].quantity;
				sum+=bills[j].nprice;
			}
		}
		printf("\n%15s   %6d  \t %.2f ",items[i],nquantity,sum);
	}
}