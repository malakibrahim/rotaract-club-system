#include <stdio.h>
#include <string.h>


typedef struct{
	
	char name[15];
	//name can contain 30 char
	int yb[4];
	char position[20];
	char profession[50];
	
}member;
//members is the struct name



typedef	struct{
		char project_name[50];
		char committee[50];
		int na;
		//na=number of attendance
		int nps;
		//nps=number of people served
		
	}projects;
	
	
	
	
	
 typedef struct  {
 				char clubName[50];
 				int year;
 				  member m[5];
 				 projects p[5];
 				// we have 5 projects each contains (name, commity , etc )
 				//when we use type def we dont need to call struct before calling it struct name
 				//members and projects are considered a a struct of struct
}club;

club c;
//global declaration of club cause only have one club which is c , tht we are working on

	
	

 
int i,j;
//globa variables so we dont need to declare each of them on it won in the fns


 
 
 void  read_club(){

	printf("Enter Club name: \n");
	gets(c.clubName);
	printf("Enter Year of foundation : ");
	scanf("%d",& c.year);

	}
	
	
	
	
 void read_member(){
	FILE *mm;
  mm=fopen("member.txt","r");
i=0;
    if(mm!=NULL)
    {
    	while(!feof(mm)){


fscanf(mm,"%[^,],%d,%[^,],%[^\n]\n",c.m[i].name,&c.m[i].yb,c.m[i].position,c.m[i].profession);
i++;
    
}
fclose(mm);
 }
 else
 printf("error in reading file");



 }
void read_project(){
	FILE *mm;
  mm=fopen("project.txt","r");
j=0;
    if(mm!=NULL)
    {
while(!feof(mm)){

fscanf(mm,"%[^,],%[^,],%d,%d\n",c.p[j].project_name, c.p[j].committee , &c.p[j].na, &c.p[j].nps);

j++;



   
}
 fclose(mm);
 }
 else
 printf("error in reading file");

 }

 void save_member_files(){
	FILE *mm;
  mm=fopen("member.txt","a");
printf("enter member name :\n");
	scanf("%s",c.m[i].name);
	//m[i] means we have i number of memebrs array of members echcontain.....
printf("enter year of birth: \n");
	scanf("%d",& c.m[i].yb);
	printf("enter position: \n");

	scanf("%s",c.m[i].position);
printf("enter profession: \n");
	scanf("%s",c.m[i].profession);


    if(mm!=NULL)
    {


	 fprintf(mm ,"%s,%d,%s,%s\n",c.m[i].name,&c.m[i].yb,c.m[i].position,c.m[i].profession);//^n scans string untill the ,
printf("Saved");
i++;
    fclose(mm);
 }
 else
 printf("error in reading file");
}
 
 void save_projects_files(){
 	FILE *p;
   p=fopen("project.txt","a");
    if(p!=NULL)
    {
	printf("\nenter project name: ");
scanf("%s",c.p[j].project_name);
printf("\nenter committee: ");
scanf("%s",c.p[j].committee);
printf("\nenter number of attendance :");
scanf("%d",&c.p[j].na);
printf("\nenter numberof people Served: ");
scanf("%d",&c.p[j].nps);
        fprintf(p,"%s,%s,%d,%d\n ",c.p[j].project_name, c.p[j].committee , c.p[j].na, c.p[j].nps);
 printf("Saved");
        j++;
}


    fclose(p);
 }
 


//linear search
void search(){
int e;
printf("Search results For Members with M :\n\n");
for(e=0;e<i;e++){
	if(c.m[e].name[0]=='m')
printf("%s\n",c.m[e].name);

}
}

//binary search

/*void search(){
	
	int mid,low,high,i;
	
	char t;//target letter
	printf("Enter the Letter you want to be searched for \n");
  scanf("%c",&t);

 scanf("%s",&c.m[i].name);

	low=0;
 high=15-1;
 
 while(low<=high)
 {
 mid=(low+high)/2;
 if (c.m[mid].name[0]==t)
 {
 printf("%s \n",c.m[mid].name);

 }
 else if(c.m[mid].name[0]!=t)
 {
 high=high;
 low=mid+1;
 }
 else
 {
 low=low;
 high=mid-1;
 }
 }
 printf("%s \n",c.m[mid].name);
 }*/




//bubble sort
void sort(){
	int k ; int s; projects a;
	for (k=0; k<10 ; ++k) {
		for (s=k+1 ; s<10; ++s){
			
			if(c.p[k].na>c.p[s].na){
				
				a=c.p[k];
				c.p[k]=c.p[s];
				c.p[s]=a;
			}
		}		}
		
		printf("the number arranged in ascending order is given below \n");
		for(k=0;k<10; ++k)
		printf("%d \t %s \n",c.p[k].na,c.p[k].project_name);
		
	}



void menu()
{
read_member();
read_project();
int choice;
	printf("\n \n  Enter you choice :\n1.Add member\n2.Add project\n3.Search\n4.sort\n");
scanf("%d",&choice);

	if(choice==1){
		printf("Add new member's information\n");
save_member_files();

	}
	else if(choice ==2){
	printf("Add new project Data\n ");
	save_projects_files();
}
	
else if(choice ==3){
printf("search for Members\n");
search();
}

else if (choice==4){
	printf("sorting Projects By number of attendance \n");
 sort();
}
 
	}
	




int main()
{
	printf("Rotaract Club Data Base \n \n");
	
	read_club();
	
  menu();
  
return 0;
}
	





