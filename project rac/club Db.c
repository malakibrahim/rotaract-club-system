#include <stdio.h>
#include <string.h>


typedef struct{
	
	char name[30];
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
 				// we have 100 projects each contains (name, commity , etc )
}club;

club c;

	
	

 
int i,j;
// function that reads from user (console)


 
 
 void  read_club(){
printf("enteryear");
	scanf("%d",& c.year);
	printf("entername");
	gets(c.clubName);

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
printf("%s",c.p[0].project_name);
   
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
printf("enter year: \n");
	scanf("%d",& c.m[i].yb);
	printf("enter position\n");

	scanf("%s",c.m[i].position);
printf("enter profession \n");
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


void search(){
int e;
printf("Search results:\n\n");
for(e=0;e<i;e++){
	if(c.m[e].name[0]=='m')
printf("%s\n",c.m[e].name);

}



}




void sort(){
	int k ; int s; projects a;
	for (k=0; k<10 ; ++k) {
		for (s=i+1 ; s<10; ++s){
			if(c.p[k].na>c.p[s].na){
				
				a=c.p[k];
				c.p[k]=c.p[s];
				c.p[s]=a;
			}
		}		}
		
		printf("the number arranged in ascending order is given below \n");
		for(k=0;k<10; ++k)
		printf("%d \n",c.p[k].na);
		
	}



void menu()
{
read_member();
read_project();
int choice;
	printf("Enter you choice :\n1.Add member\n2.Add project\n3.Search\n4.sort\n");
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
	printf("sorting Projects By number of attendance");
 sort();
}
 
	}
	




int main(){
	printf("Rotaract Club Data Base \n");
	

									 menu();
return 0;
}






