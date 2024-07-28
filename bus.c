#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char scity[30],des[30];int per,sno[100],total=80;float amt=0;char name[30],cn[12],email[30],uname[30],pass[30],cpass[30],date[30];
void booking()
{
    char ans;
    printf("\n\n-----Welcome to Bharat Bus-----\n");
    printf("\nEnter Source City : ");
    gets(scity);
    printf("\nEnter Destination : ");
    gets(des);fflush(stdin);
    printf("\nEnter Date of Travel : ");
    gets(date);
    printf("\nEnter Total Number of Persons : ");
    scanf("%d",&per);
    printf("\n\nAvailable Bus Timings : %d%d : %d%d",(rand()%1),(rand()%9),(rand()%5),(rand()%9));
    printf("\nWould you like to Book Tickets ? (y/n) : ");fflush(stdin);
    scanf("%c",&ans);
    if(ans=='n')
    printf("\nThank You!! \n");
    else 
    {
        int k=11;
        printf("\nPlease Select the Seats from below : \n");
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<20;j++)
            {
                printf("  O%d ",k++);
            }
            printf("\n");
            if(i==1)
            printf("\n");
            else if(i==3)
            printf("\n");
        }
        for(int i=0;i<per;i++)
        {
            printf("\nEnter Seat Number : ");
            scanf("%d",&sno[i]);
             total--;
        }
        printf("\nDo you want to view Seats Left in Bus ? (y/n) : ");
        char ans;fflush(stdin);
        scanf("%c",&ans);
        if(ans=='y')
        printf("\nTotal Seats Left : %d ",total);

        printf("\n\nBus Charges Per Person : 500/-");
        amt=500*per;
        printf("\nGST : 20 percent ");
        printf("\nTotal Amount : %f", (amt+(0.2*amt)));
        printf("\nTickets Booked Successfully...\n");

    }
}
void reg()
{
    printf("\n-----Registration Page-----");
    printf("\nEnter Name : ");fflush(stdin);
    gets(name);
    while(1)
    {
    printf("\nEnter Contact Number : ");
    gets(cn);
    if(strlen(cn)!=10)
    {
        printf("\nInvalid Contact Number !! ");
    }
    else
    break;
    }
    int eg=0;
    while(1)
    {
     printf("\nEnter Email ID : ");
     gets(email);
      for(int i=0;email[i];i++)
      {
        if(email[i]>'A' && email[i]<='Z')
         eg++;
      }
       if(eg>0)
       printf("\nInvalid Email ID !! ");
       else 
       {
         break;
       }
    }
    printf("\nEnter User Name : ");
    gets(uname);
    int cp=0,sl=0,dg=0,sp=0;
    while(1)
    {
        printf("\nEnter Password : (Must contain single Capital and Small Aplhabet, single Digit and a special symbol) : ");
        gets(pass);
        for(int i=0;pass[i];i++)
        {
        if(pass[i]>='a' && pass[i]<='z')
        sl++;
        else if(pass[i]>='A' && pass[i]<='Z')
        cp++;
        else if(pass[i]>='0' && pass[i]<='9')
        dg++;
        else 
        sp++;
        }
        if(sl==0 || cp==0|| dg==0||sp==0)
        printf("\nPlease Enter Strong Password !! ");
        else 
        break;
    }
    while(1)
    {
        printf("\nConfirm Password : ");
        gets(cpass);
        if(strcmp(pass,cpass)!=0)
        {
        printf("\nInvalid Confirm Password !! ");
        }
        else 
        {
            printf("\nYou have Successfully Logged in...");break;
        }
    }
    booking();
}
void book()
{
     printf("\nEnter : \n1. Sign-in (Already a User)\n2. Sign-up (New User)");int ch;
     printf("\nEnter Your Choice : ");
     scanf("%d",&ch);
     if(ch==1)
     {
        char uname[10]="FullName";
        char pass[15]="Password_123";
        char nuname[10],npass[15];
        printf("\n-----Login Page-----");
        printf("\nEnter Name : ");fflush(stdin);
        gets(name);
        while(1)
        {
         printf("\nEnter Contact Number : ");
         gets(cn);
         if(strlen(cn)!=10)
         {
             printf("\nInvalid Contact Number !! ");
         }
           else
           {
           break;
           }
        }
        while(1)
        {
         printf("\n\nEnter User Name : ");fflush(stdin);
         gets(nuname);
        if(strcmp(uname,nuname)!=0)
        {
            printf("\nInvalid User Name !! ");
        }
        else 
        {
            break;
        }
        }
        while(1)
        {
        printf("\n\nEnter Password : ");
        gets(npass);
        if(strcmp(pass,npass)!=0)
        {
            printf("\nInvalid Password !! ");
        }
        else 
        {
            break;
        }
        }
        booking();
     }
     else 
     {
        reg();
     }
}
char nname[30];int nt;
void cancel()
{
     printf("\n-----Ticket Cancellation-----");
     printf("\nEnter Name : ");fflush(stdin);
     gets(nname);
     if(strcmp(nname,name)!=0)
     return ;
     else 
     {
        printf("\nEnter Number of Tickets You want to Cancel : ");
        scanf("%d",&nt);
        if(nt<=per)
        {
             for(int i=0;i<nt;i++)
             {
                total++;
             }
             per=per-nt;
             printf("\n100 Percent Return Policy :- Amount returned :  %d",(500*nt));
             amt=amt-(500*nt);
            for(int i=0;date[i];i++)
             {
                date[i]='\0';
             }
             printf("\nBooking Cancelled Successfully...\n");
        }
        else 
        {
            printf("\nInvalid !! ");
        }
     }
}
void details()
{
  printf("\n----------Details----------\n");
  printf("\nName : %s",name);
  printf("\nContact Number : %s",cn);
  printf("\nSource City : %s",scity);
  printf("\nDestination : %s",des);
  printf("\nDate of Travel : %s,date);
  printf("\nTotal Persons : %d",per);
  printf("\nSeat Numbers : ");
  for(int i=0;i<per;i++)
  {
    printf("\t%d",sno[i]);
  }
  printf("\nTotal Amount : %f",amt+(0.2*amt));
 printf("\n---------------------------\n");
}
int main()
{
 printf("\n-----Bus Reservation System-----");int ch;
 while(1)
 {
 printf("\n\nEnter : \n1.Book Ticket\n2.Cancel Ticket\n3.View Details\n4.Exit");
 printf("\nEnter Your Choice : ");
 scanf("%d",&ch);
 switch(ch)
 {
    case 1 : book();break;
    case 2 : cancel();break;
    case 3 : details();break;
    case 4 : exit(0);break;
    default : printf("\nInvalid Choice");
 }
 }
}
