#ifndef BILLGENERATE_H
#define BILLGENERATE_H
struct date{
	int dd;
	int mm;
	int yy;
	int day;
};

struct name
{
	char detail[100];
};
struct items{
	struct name items;
	float itemprice;
	int total_quantity;
};
struct bill
{
	struct date dates;
	struct name names;
	struct name nitems;
	int quantity;
	float nprice;
	int no_of_bills;
	char* timings;
	int days;
	
};
struct byname{
	struct name selectedname;
	float total_price;
	
};
typedef struct bill bill_t;
typedef struct name name_t;
typedef struct date date_t;
typedef struct byname byname_t;
typedef struct items items_t;
void read_date(date_t *ptr_date1);
void display_date(const date_t *ptr_date1);
void validate_date( date_t *ptr_date1,date_t *ptr_date2,date_t* randate,int* temp,int day);
void read_names(name_t* n);
void bill_generate(name_t* n,date_t* randate,int temp,bill_t* bills,int* no_of_bills,name_t* items,items_t* peritem);
void display_by_date( bill_t* bills,int no_of_bills);
void display_by_name( bill_t* bills,int no_of_bills,name_t* total_name,byname_t* pername);
void display_by_selected_date(bill_t* bills,int no_of_bills,date_t* selecteddate,date_t* ptr_date1,date_t* ptr_date2);
void display_by_selected_name(char* customername,byname_t* pername);
void insert_names( bill_t* bills,int no_of_bills,name_t* total_name,byname_t* pername);
void display_by_time(const bill_t* bills,int no_of_bills,date_t* randate,int temp);
void display_total_cost_by_time(bill_t* bills,int no_of_bills);
void display_total_cost_by_day(const bill_t* bills,int no_of_bills,int temp);
void read_items(name_t *items);
void items_price(items_t* peritem,name_t* items);
void display_item_price(items_t* peritem);
void display_by_item(const bill_t* bills,int no_of_bills,name_t* items);
#endif