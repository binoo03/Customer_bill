#include<stdio.h>
#include "Billgenerate.h"
#include <string.h>
#include <stdlib.h>

int main()
{
	int temp=0,term=1,input=0,day=0;
	char customername[100];
	bill_t bills[5000];
	byname_t pername[100];
	int no_of_bills=0;
	date_t randate[100];
	name_t n[50];
	name_t items[50];
	name_t total_name[50];
	items_t peritem[50];
	date_t d1,d2,d3;
	read_date(&d1);
	read_date(&d2);
	display_date(&d1);
	display_date(&d2);
	read_items(items);
	read_names(n);
	read_names(total_name);
	items_price(peritem,items);
	printf("\nenter the day (0-sun/1-mon/2-tue/3-wed/4-thurs/5-fri/6-sat):");
	scanf("%d",&day);
	validate_date(&d1,&d2,randate, &temp,day);
	bill_generate(n,randate,temp,bills,&no_of_bills,items,peritem);
	insert_names( bills,no_of_bills, total_name,pername);
	
	while(term!=0)
	{
	printf("\n*****************************************************************************************");
	printf("\n\t1.Display Bills by date \n\t2.Display by all name"
	"\n\t3.Display the bill on selected date \n\t4.Display the Bill by Person\n\t5.Display the Bill by time Interval \n\t6.Display Bill of all Days\n\t7.Display Bill of item and price\n\t8.Display Bill of all item \n\t9.Display Bill of total cost for time interval  \n\t 0 to exit \n");
	scanf("%d",&input);
	switch(input)
	{
		case 0:term=0;
		break;
		case 1:display_by_date(bills,no_of_bills);
		break;
		case 2:display_by_name(bills,no_of_bills,total_name,pername);
		break;
		case 3:read_date(&d3);
			   display_by_selected_date(bills,no_of_bills,&d3,&d1,&d2);
			   break;
		case 4:
		printf("\nEnter the person name to display  :");
		scanf("%s",customername);
		display_by_selected_name(customername,pername);
		break;
		case 5:
			display_by_time(bills,no_of_bills,randate,temp);
			break;
		case 9:
			display_total_cost_by_time(bills,no_of_bills);
			break;
		case 6:
			display_total_cost_by_day(bills , no_of_bills,temp);
			break;
		case 7:
			 display_item_price(peritem);
			 break;
		case 8:
			display_by_item(bills,no_of_bills,items);
			break;
		default:
		printf("invalid choice ");
		break;
	}
	}
	
	
}