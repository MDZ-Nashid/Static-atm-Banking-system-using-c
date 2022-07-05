#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>
char number[][15]= {"0195","0182","0171","0162"};///user number database
char pin[][7]= {"1009","1008","1007","1006"};///user password database
int cash[]= {12000,50000,80000,26000};///user amount
char phone[15],password[7];///users input
int amount,i,c=0,size,t=3,holder,choice;///amount is for withdrawal data,i is for loop,c is for number checking,size is for determining database size of phone number,
///t is for wrong pass trial,holder is for specific users cash detail storage,choice is for yes no determination.
int exitfn()
{
    printf("\t\t\t\t\tExit?\n");
    printf("\t\t\t\t\t1.Yes 2.No\n");
    printf("\t\t\t\t\t");
    scanf("%d",&choice);
}
int end()
{
    system("cls");
    printf("\t\t\t\t\tThank you for banking");
}
int withdraw()
{
    system("cls");
    printf("\t\t\t\t\tHow much do you want to withdraw? :\n");///money withdrawing
}
int main()
{
    system("color 4E");
    size=sizeof(number)/sizeof(number[0]);///determining the length of number array
phn:
    printf("\t\t\t\t\tEnter your phone number :\n");
    printf("\t\t\t\t\t");
    gets(phone);
    for(i=0; i<size; i++)///loop for checking phone number
    {
        if(strcmp(phone, number[i]) == 0)
        {
            c++;
            system("cls");
            while(t)///loop of wrong pass trial
            {

                printf("\t\t\t\t\tEnter your pass:\n");
                printf("\t\t\t\t\t");
                gets(password);
                if(strcmp(password, pin[i]) == 0)
                {
                    t=0;
                    withdraw();
                    holder=i;
                    goto amnt;
                }
                else
                {
                    t--;
                    system("cls");
                    printf("\t\t\t\t\tWrong pin.Try again\n");
                    if(t==0)
                    {
                        system("cls");
                        printf("\t\tToo many attempts.You have been blocked to access in your account temporarily.");
                        Sleep(2000);
                        end();
                    }
                }
            }
        }
    }
    if(c==0)
    {
        system("cls");
        printf("\t\t\t\t\tCouldn't find your account in database\n");
        Sleep(2000);
        end();
    }
amnt:
    printf("\t\t\t\t\t");
    scanf("%d",&amount);///withdrawal amount
    if(amount<=20000 && amount>=500)
    {
        if(amount>cash[holder])///when withdrawal amount is greater than cash amount
        {
            system("cls");
            printf("\t\tYou don't have enough money in your account.Do you want to see your balance?\n");
            printf("\t\t\t\t\t\t1.Yes 2.No\n");
            printf("\t\t\t\t\t");
wrong:
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
            {
                system("cls");
                printf("\t\t\t\t\tYou have %d taka in your account\n\n",cash[holder]);
                exitfn();
                switch(choice)
                {
                case 1:
                {
                    end();
                    break;
                }
                case 2:
                {
                    withdraw();
                    goto amnt;
                    break;
                }
                }
            }
            break;
            case 2:
            {
                system("cls");
                exitfn();
                switch(choice)
                {
                case 1:
                {
                    end();
                    break;
                }
                case 2:
                {
                    withdraw();
                    goto amnt;
                    break;
                }
                }
            }
            default:
                printf("\t\t\t\t\twrong input.enter again");
                goto wrong;
            }
        }
        else
        {
            cash[holder]= cash[holder]-amount;///for decreasing money from the cash database.
            system("cls");
            printf("\t\t\t\t\tDo you want to proceed?..\n");
            printf("\t\t\t\t\t1.Yes 2.No\n");
            printf("\t\t\t\t\t");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                system("cls");
                printf("\t\t\t\t\tplease wait...\n");
                Sleep(2000);
                printf("\t\t\t\t\tCollect your money please...\n");
                Sleep(2000);
                printf("\t\t\t\t\tDo you want to withdraw again?\n");
                printf("\t\t\t\t\t1.Yes 2.No\n");
                printf("\t\t\t\t\t");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                {
                    withdraw();
                    goto amnt;
                    break;
                }
                case 2:
                {
                    end();
                    break;
                }
                }
            case 2:
            {
                system("cls");
                exitfn();
                switch(choice)
                {
                case 1:
                    end();
                    break;
                case 2:
                {
                    withdraw();
                    goto amnt;
                    break;
                }
                }
            }
            }
        }
    }
    else
    {
        system("cls");
        printf("\t\t\t\t\tYou cannot withdraw over 20000 or less than 500 at a time.Try again..\n");
        goto amnt;
    }
    getch();
}
