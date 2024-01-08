#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include"header.h"

int overs;
int bowl_index;

typedef struct bat
 {
   char name[25];
   int runs,balls,ones,twos,threes,fours,sixes;
   int max_six,max_run,max_four;
   float str;
   int used;
 }batsman;


typedef struct bowl
 {
   char name[25];
   int runsgv,wkttkn,overs;
   int max_w;
   int total_ball;
   float econ;
   int used;
 }bowlers;

batsman bats_man_a[11];                           ///// ******
batsman bats_man_b[11];
bowlers bowler_a[11];
bowlers bowler_b[11];
int total_balls_a,total_runs_a,wicket_a;          ///// ******
int total_balls_b,total_runs_b,wicket_b;

void fetch_bat_details(batsman* bat){
    printf("\nName : ");
    scanf("%s",bat->name);
    bat->runs = 0;
    bat->balls = 0;
    bat->fours = 0;
    bat->sixes = 0;
    bat->used = 1;
}

void fetch_bowl_details(bowlers* bowl,char* name){
    // printf("Name :\n");
    // scanf("%s",bowl->name);
    // for(int i=0;i<11;i++){
    //     if(!strcmp(bowler[i].name,bowl->name)) return;
    // }

    strcpy(bowl->name,name);
    bowl->runsgv = 0;
    bowl->wkttkn = 0;
    bowl->overs = 0;
    bowl->total_ball = 0;
    bowl->used = 1;
}

void scoreline(int curr1,int curr2,bowlers bowl,char* team1,char* team2,int curr,int bowl_i,int team_num){

    batsman* bats_man;
    bowlers* bowler;
    char* team;
    int total_balls,wicket,total_runs;

    if(!team_num){
        bats_man = bats_man_a;
        bowler = bowler_a;
        total_balls = total_balls_a;
        wicket = wicket_a;
        total_runs = total_runs_a;
        team = team1;
    }
    else{
        bats_man = bats_man_b;
        bowler = bowler_b;
        total_balls = total_balls_b;
        wicket = wicket_b;
        total_runs = total_runs_b;     
        team = team2;
    }

    int curr_over = total_balls / 6;
    int curr_over_ball = total_balls % 6;

    printf("\n %d.%d / %d.0                               \033[0;34m%s\033[0m : %d / \033[0;31m%d\033[0m                             %s : %d / %d \n",curr_over,curr_over_ball,overs,team,total_runs,wicket,bowler[bowl_i].name,bowler[bowl_i].runsgv,bowler[bowl_i].wkttkn);    
    printf("===================================================================================================\n");
    printf("   Batsman              runs                balls            fours           sixes            sr   \n");
    printf("===================================================================================================\n");
    if(curr==1){
        printf("\033[0;36m");
    }
    printf("%10s            %5d               %5d            %5d          %5d              %2.2f\n",bats_man[curr1].name,bats_man[curr1].runs,bats_man[curr1].balls,bats_man[curr1].fours,bats_man[curr1].sixes,(bats_man[curr1].runs/(float)bats_man[curr1].balls)*100);
    printf("\033[0m");
    if(curr!=1){
        printf("\033[0;36m");   
    }
    printf("%10s            %5d               %5d            %5d          %5d              %2.2f\n",bats_man[curr2].name,bats_man[curr2].runs,bats_man[curr2].balls,bats_man[curr2].fours,bats_man[curr2].sixes,(bats_man[curr2].runs/(float)bats_man[curr2].balls)*100);
    printf("\033[0m");
}

int check(char *name,int team_num){

    bowlers* bowler;

    if(!team_num){
        bowler = bowler_a;
    }else{
        bowler = bowler_b;
    }

    for(int i=0;i<11;i++){
        if(!strcmp(name,bowler[i].name)){
            return i+1;
        }
    }
    return 0;
}


void summary(char* team1,char* team2,int team_num){

    batsman* bats_man;
    bowlers* bowler;
    int total_balls,wicket,total_runs;
    char* team;

    if(!team_num){
        bats_man = bats_man_a;
        bowler = bowler_a;
        total_balls = total_balls_a;
        wicket = wicket_a;
        total_runs = total_runs_a;
        team = team1;
    }
    else{
        bats_man = bats_man_b;
        bowler = bowler_b;
        total_balls = total_balls_b;
        wicket = wicket_b;
        total_runs = total_runs_b;     
        team = team2;
    }

    int curr_over = total_balls / 6;
    int curr_over_ball = total_balls % 6;

    system("clear");
    printf("\n\n      <-----------------------------  MATCH SUMMARY -------------------------->                           \n\n");

    printf("                                     \033[0;34m%s\033[0m : %d / \033[0;31m%d\033[0m                         %d.%d / %d.0  \n\n",team,total_runs,wicket,curr_over,curr_over_ball,overs);

    printf("===================================================================================================\n");
    printf("\033[0;33m   Batsman              runs                balls            fours           sixes            sr   \033[0m\n");
    printf("===================================================================================================\n");


    for(int i=0;i<11;i++){
        if(bats_man[i].used){
           printf("%10s            %5d               %5d            %5d          %5d              %2.2f\n",bats_man[i].name,bats_man[i].runs,bats_man[i].balls,bats_man[i].fours,bats_man[i].sixes,(bats_man[i].runs/(float)bats_man[i].balls)*100);
        }
    }

    printf("\n\n\n");

    printf("===================================================================================================\n");
    printf("\033[0;33m   Bowler              overs                runs            balls           wickets            econ   \033[0m\n");
    printf("===================================================================================================\n");

    for(int i=0;i<11;i++){
        if(bowler[i].used){
           printf("%10s            %5d               %5d            %5d          %5d              %2.2f\n",bowler[i].name,bowler[i].overs,bowler[i].runsgv,bowler[i].total_ball,bowler[i].wkttkn,(bowler[i].runsgv/(float)bowler[i].overs));
        }
    }

    printf("\n\n\n");


}

void bat_swap(batsman*a,batsman* b){
    batsman* tamp = a;
    a = b;
    b = tamp;
}

void bat_sort(batsman* a){
    batsman temp;
    for(int i=0;i<11;i++){
        if(a[i].used){
            for(int j=i+1;j<11;j++){
                    if(a[j].used && (a[j].runs > a[i].runs)){
                        // bat_swap(&a[i],&a[j]);
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                }      
            }
        }
    }
}

void bowl_swap(bowlers*a,bowlers* b){
    bowlers* tamp = a;
    a = b;
    b = tamp;
}

void bowl_sort(bowlers* a){
    bowlers temp;
    for(int i=0;i<11;i++){
        if(a[i].used){
            for(int j=i+1;j<11;j++){
                    if(a[j].used && (a[j].wkttkn > a[i].wkttkn)){
                        // bowl_swap(&a[i],&a[j]);
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                }      
            }
        }
    }
}

void match_summary(char* team1,char* team2,int win_team){
    system("clear");


    printf("\n\n\n");

    printf("                   *+*+*+*+*+*+*+*+*+*+*+*+* RESULTS *+*+*+*+*+*+*+*+*+*+*+*+*  \n\n\n");
    if(!win_team){
        printf("                                         %s won by %d runs.\n\n",team1,total_runs_a - total_runs_b);
    }
    else{
        printf("                                         %s won by %d wickets.\n\n",team2, 10 - wicket_b);        
    }

    bat_sort(bats_man_a);
    bat_sort(bats_man_b);
    bowl_sort(bowler_a);
    bowl_sort(bowler_b);


    int curr_over_a = total_balls_a / 6;
    int curr_over_ball_a = total_balls_a % 6;

    int curr_over_b = total_balls_b / 6;
    int curr_over_ball_b = total_balls_b % 6;

    printf("  \033[0;34m%s\033[0m : %d / \033[0;31m%d\033[0m                                                               %d.%d / %d.0 \n",team1,total_runs_a,wicket_a,curr_over_a,curr_over_ball_a,overs);
    printf("===================================================================================================\n");
    printf("\033[0;33m          Batting info                                                Bowling info             \033[0m \n\n");

    for(int i=0;i<3;i++){
        printf("%10s : %3d (%3d)                     |                     %10s : %3d / %d \n",bats_man_a[i].name,bats_man_a[i].runs,bats_man_a[i].balls,bowler_a[i].name,bowler_a[i].runsgv,bowler_a[i].wkttkn);
    }

    printf("\n\n");

    printf("  \033[0;34m%s\033[0m : %d / \033[0;31m%d\033[0m                                                               %d.%d / %d.0 \n",team2,total_runs_b,wicket_b,curr_over_b,curr_over_ball_b,overs);
    printf("===================================================================================================\n");
    printf("\033[0;33m          Batting info                                                    Bowling info          \033[0m \n\n");

    for(int i=0;i<3;i++){
        printf("%10s : %3d (%3d)                     |                     %10s : %3d / %d \n",bats_man_b[i].name,bats_man_b[i].runs,bats_man_b[i].balls,bowler_b[i].name,bowler_b[i].runsgv,bowler_b[i].wkttkn);
    }

    exit(0);

}

void run(int curr1,int curr2,bowlers bowl,char* team1,char* team2,int team_num){
    int ch,op = 0;
    int curr = 1;
    int bowl_curr_index = 0;
    batsman* bats_man;
    bowlers* bowler;
    int *total_balls,*total_runs,*wicket;

    if(!team_num){
        bats_man = bats_man_a;
        bowler = bowler_a;
        total_balls = &total_balls_a;
        wicket = &wicket_a;
        total_runs = &total_runs_a;
    }
    else{
        bats_man = bats_man_b;
        bowler = bowler_b;
        total_balls = &total_balls_b;
        wicket = &wicket_b;
        total_runs = &total_runs_b;     
    }

    while(1){

        if(total_runs_b > total_runs_a){
               summary(team1,team2,1);

                sleep(15);

                match_summary(team1,team2,1);

                exit(0);
        }

        if((*wicket) == 10 || (*total_balls) == overs * 6){
            if(!team_num){
                summary(team1,team2,0);

                printf("\n\n                                    %s scored %d with %d wickets down\n",team1,total_runs_a,wicket_a);
                printf("                                    next innings will satrt in 5 seconds. \n\n\n\n");
    
                sleep(15);
    
                system("clear");
    
                printf("\n\n\n\n                              %s need to score %d runs in %d overs.\n",team2,total_runs_a+1,overs);
                printf("                            Every one are very eager to watch the second innning\n\n\n\n");
    
                sleep(5);
    
                system("clear");
    
                scoreboard(team1,team2,1);
    
                break;
            }
            else{
                summary(team1,team2,1);

                sleep(15);

                match_summary(team1,team2,0);

                exit(0);
            }
        }

        system("clear");

        ch = rand() % 10;
        if(ch==5 || ch==7 || ch==8 ){
            ch = 0;
        }


        // printf("Ball : (Enter 0,1,2,3,4,6,w for wicket) = ");
        // scanf("%d",&ch);

        if(ch==1 || ch==2 || ch==3){
            printf("\n\n                                        it's %d runs for the team\n\n",ch);
        }
        else if(ch==4 || ch==6){
            printf("\n\n                                     It's a fabulous %d by the player\n\n",ch);
        }
        else if(ch==0){
            printf("\n\n                                    It's a nice defensive shot by the player\n\n");
        }
        else if(ch==9){
            printf("\n\n                                   Awesome bowl by the bowler and there goes a wicket\n\n");
        }

    switch(ch){
        case 9 :
            (*total_balls)++;
            bowler[bowl_curr_index].total_ball++;
            bowler[bowl_curr_index].wkttkn++;
            (*wicket)++;
            // printf("sad, which player got out : (player 1 or 2) :");
            // scanf("%d",&op);
            curr++;
            if(op==0){
                curr1 = curr;
            }
            else{
                curr2 = curr;
            }

            if((*wicket) != 10){
                printf("Now enter the new batsman details : \n");
                fetch_bat_details(&bats_man[curr]); 

            }

            break;
        default :
            (*total_balls)++;
            bowler[bowl_curr_index].total_ball++;
            (*total_runs) += ch;
            // printf("Which player scored : (1 or 2) :");
            // scanf("%d",&op);
            if(op==0){
                bats_man[curr1].runs += ch;
                bats_man[curr1].balls++;
                if(ch==4){
                    bats_man[curr1].fours++;
                }
                else if(ch==6){
                    bats_man[curr1].sixes++;
                }
            }
            else{
                bats_man[curr2].runs += ch;
                bats_man[curr2].balls++;
                if(ch==4){
                    bats_man[curr2].fours++;
                }
                else if(ch==6){
                    bats_man[curr2].sixes++;
                }
            }
            bowler[bowl_curr_index].runsgv += ch;

            break;

        }

        scoreline(curr1,curr2,bowl,team1,team2,op+1,bowl_curr_index,team_num);




        if(ch==1 || ch==3){
            op = !op;
        }

        if((*total_balls % 6 == 0) && (*total_balls != overs * 6)){
            bowler[bowl_curr_index].overs++;
            printf("\nOk so we have to now change the bowler\n");
            char name[50];
            printf("Name : ");
            scanf("%s",name);
            if(check(name,team_num)){
                int index = check(name,team_num);
                index--;
                bowl_curr_index = index;
            }
            else{
                fetch_bowl_details(&bowler[++bowl_index],name);
                bowl_curr_index = bowl_index;
            }
            op = !op;
        }


        sleep(3);

    }


}


void scoreboard(char* team1,char* team2,int team_num){
    printf("\n\n");

    batsman* bats_man;
    bowlers* bowler;
    int *total_balls,*total_runs,*wicket;

    if(!team_num){
        bats_man = bats_man_a;
        bowler = bowler_a;
        total_balls = &total_balls_a;
        wicket = &wicket_a;
        total_runs = &total_runs_a;
    }
    else{
        bats_man = bats_man_b;
        bowler = bowler_b;
        total_balls = &total_balls_b;
        wicket = &wicket_b;
        total_runs = &total_runs_b;    
    }

    for(int i=0;i<11;i++){
        bats_man[i].used = 0;
        bowler[i].used = 0;
    }

    int curr1,curr2;
    float curr_over;
    bowlers bowl;
    time_t t;
    srand((unsigned)time(&t));

    printf("Enter the opening batsman details : \n");
    printf("Player 01 :");
    fetch_bat_details(&bats_man[0]);
    curr1 = 0;
    printf("Player 02 :");
    fetch_bat_details(&bats_man[1]);
    curr2 = 1;

    printf("\n\n");
    printf("Bowler details : \n");
    printf("Name : ");
    char bowler_name[50];
    scanf("%s",bowler_name);

    fetch_bowl_details(&bowler[0],bowler_name);
    bowl_index = 0;

    system("clear");



    printf("                                       Match Bill-Board                                            \n");
    // printf("===================================================================================================\n");
    // printf("   Batsman              runs                balls            fours           sixes            sr   \n");
    // printf("===================================================================================================\n");
    
    
    scoreline(curr1,curr2,bowl,team1,team2,1,0,team_num);

    printf("\n\n                        ..........And the match begins.........                            \n\n ");


    sleep(5);
    system("clear");


    run(curr1,curr2,bowl,team1,team2,team_num);
}