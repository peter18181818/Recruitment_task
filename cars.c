#include <stdio.h>
#include <stdlib.h>

struct st_local_db
{
  int ID;
  char brand[20];
  char model[20];
  int production_year;
  double price;
};

struct st_local_db local_db[20];
FILE *fp;

int print_database(void)
{
  fp=fopen("cars_base.bin","r+");

  int i,j,database_size;
  char z;
  fseek(fp,0,SEEK_END); 
  database_size=ftell(fp)/sizeof(local_db);
  fseek(fp,0,0);

  for(j=0;j<database_size;j++)
  {
    fread(&local_db,sizeof(local_db),1,fp); 

    for (i=0;i<1;i++)
    {
      printf("\nCar ID: %d",local_db[i].ID);
      printf("\nCar brand: %s",local_db[i].brand);
      printf("\nCar model: %s",local_db[i].model);
      printf("\nYear of production: %d",local_db[i].production_year);
      printf("\nPrice: %.2f\n",local_db[i].price);
    }
  }
  fclose(fp);

  printf("\nDatabase printed");
  main();
}

void create_database(void)
{
  fp=fopen("cars_base.bin","w+");
  int i=0,database_size;
  char y,n;
  do
  { 
    printf("Type in the brand of the car: ");
    scanf("%s",&local_db[i].brand);  
    printf("\nType in the model of the car: ");
    scanf("%s",&local_db[i].model);  
    printf("\nType in year of production: ");
    scanf("%d",&local_db[i].production_year);  
    printf("\nType in the price of the car: ");
    scanf("%lf",&local_db[i].price); 
    local_db[i].ID=i+1;
    fwrite(&local_db[i],sizeof(local_db),1,fp);
    i++;
    database_size=i;
    printf("\nWould you like to add another car to database? (press \"y\" for yes)\n");
    scanf(" %c", &y);
  }while (y=='y');

  fclose(fp);
  main();
}

int add_record(void)
{
  fp=fopen("cars_base.bin","a+");
  int i;
  char y,n;
  fseek(fp,0,SEEK_END);
  i=ftell(fp)/sizeof(local_db);
  fseek(fp,0,SEEK_END);

  do
  { 
    printf("Type in the brand of the car: ");
    scanf("%s",&local_db[i].brand);  
    printf("\nType in the model of the car: ");
    scanf("%s",&local_db[i].model);  
    printf("\nType in year of production: ");
    scanf("%d",&local_db[i].production_year);  
    printf("\nType in the price of the car: ");
    scanf("%lf",&local_db[i].price); 
    local_db[i].ID=i+1;
    fwrite(&local_db[i],sizeof(local_db),1,fp);
    i++;
    printf("\nWould you like to add another car to database? (press \"y\" for yes)\n");
    scanf(" %c", &y);
  }while (y=='y');

  fclose(fp);
  main();
}  

int edit()
{
  char a;
  int b;
  int i=0;
  char t;
  fp=fopen("cars_base.bin","r+");

  printf("Type in car ID which you want to edit: ");
    
  scanf(" %d", &i);
  printf("You selected car no %d: ", i);

  fseek(fp, sizeof(local_db) * (i-1), SEEK_SET);
  
  printf("\nType in the brand of the car: ");
  scanf("%s",&local_db[i-1].brand);  
  printf("\nType in the model of the car: ");
  scanf("%s",&local_db[i-1].model);  
  printf("\nType in year of production: ");
  scanf("%d",&local_db[i-1].production_year);  
  printf("\nType in the price of the car: ");
  scanf("%lf",&local_db[i-1].price); 
  local_db[i-1].ID=i;
  fwrite(&local_db[i-1],sizeof(local_db),1,fp);
 
  printf("\nChanges saved\n");

  fclose(fp);
  main();
}