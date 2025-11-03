// 7. Write a program that uses an array of structures to represent a cricket team (player name, runs, wickets). Print the player with the highest runs.

#include <stdio.h>

struct Player {
    char name[50];
    int runs;
    int wickets;
};

int main() {
    int n;
    printf("Enter number of players: ");
    scanf("%d", &n);

    struct Player team[n];
    for(int i = 0; i < n; i++) {
        printf("Enter name, runs, wickets for player %d: ", i+1);
        scanf("%s %d %d", team[i].name, &team[i].runs, &team[i].wickets);
    }

    struct Player top = team[0];
    for(int i = 1; i < n; i++) {
        if(team[i].runs > top.runs) top = team[i];
    }

    printf("\nTop Scorer: %s with %d runs\n", top.name, top.runs);

    return 0;
}
