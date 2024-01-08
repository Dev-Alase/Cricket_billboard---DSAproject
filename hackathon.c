#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"header.h"
// #include<climits.h>
// #include<algorithms.h>

extern int overs;

int main(){
    printf("******************  WELCOME TO INTERNATIONAL CRICKET COUNCIL **************************\n\n\n");
    char format[10];
    init :
    printf("Enter the format : ");
    scanf("%s",format);
    
    for(int i=0;format[i]!='\0';i++){
        format[i] = tolower(format[i]);
    }

    if(!strcmp("odi",format)){
        overs = 50;
    }
    else if(!strcmp("t20",format)){
        overs = 20;
    }
    else if(!strcmp("test",format)){
        overs = 1000;
    }
    else{
        printf("Incorrect input format\n");
        goto init;
    }

    char team1[50],team2[50],team[50],toss_op[20];
    printf("Enter the name of a first team : ");
    scanf("%s",team1);

    printf("Enter the name of a second team : ");
    scanf("%s",team2);

    printf("\n         We are witnessing a %d overs match between %s and %s\n",overs,team1,team2);

    printf("\nEnter the team name which won the toss : ");
    scanf("%s",team);

    printf("%s won the toss and decided to : ",team);
    scanf("%s",toss_op);


    if((!strcmp(team,team2) && !strcmp(toss_op,"bat")) || (!strcmp(team,team1) && !strcmp(toss_op,"bowl"))){
        char temp[50];
        strcpy(temp,team1);
        strcpy(team1,team2);
        strcpy(team2,temp);
    }


    printf("\n%s is going bat",team1);

    scoreboard(team1,team2,0);

}