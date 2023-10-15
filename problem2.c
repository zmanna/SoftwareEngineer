/*
Creator: Aryamann Zutshi
Id Number: 3023609
Lab: Software Engineering Lab 5
Date: October 14, 2023
Sources Used:
    - https://www.geeksforgeeks.org/nested-loops-in-c-with-examples-2/
*/

/*
The programming lab assignment requires reading an NFL game score by a team and determining 
the scoring possibilities. A score is expected to be 2 or higher. Thus, the program should stop 
if a score less than 2 is entered.
*/

// A scoring plays in an NFL game can be the following:
// • Touchdown (TD) worth 6 points
// • Field goal (FG) worth 3 points
// • Safety worth 2 points
// • Touchdown (TD) + 2-point conversion worth 8 points
// • Touchdown (TD) + 1-point field goal worth 7 points

//I'm thinking we use nested loops, need to check largest first then move down to smallest?
//turns out it is smallest then up to largest

#include <stdio.h>

void print_combination(int td_2pt, int td_fg, int td, int fg, int safety);


//This is our main function other than main
//we want to start with greatest score, find out if that can be broken down and how, then for each possibility of that, run the next loop
//this is the overarching logic for the whole function actually
void calculate_combinations(int score) {
    printf("Possible combinations of scoring plays:\n");
    //touchdown with 2-point conversion
    for (int td_2pt = 0; td_2pt * 8 <= score; td_2pt++) { 
        /*
        going to explain the logic for one line of the loop, same logic follows to the rest
        int td_2pt = 0; loop starts here, initialize to zero
        td_2pt * 8 <= score; 8 point total for this, loop wants to figure out if 8 is even possible
        in second iteration, tf_2pt++, this will consider one more touchdown so 16 points
        keeps doing this until it can't
        these will become all the iterations possible for the next loop to nest over
        logic will trickle down
        */
        //touchdown with 1-point field goal
        for (int td_fg = 0; td_fg * 7 + td_2pt * 8 <= score; td_fg++) {
            //only touchdown
            for (int td = 0; td * 6 + td_fg * 7 + td_2pt * 8 <= score; td++) {
                //field goals
                for (int fg = 0; fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= score; fg++) {
                    //safeties from whatever is left
                    //do this last bc it is the elast likely
                    int remaining = score - (fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8);
                    if (remaining % 2 == 0) {
                        int safety = remaining / 2;
                        print_combination(td_2pt, td_fg, td, fg, safety);
                    }
                }
            }
        }
    }
}

// made a function for print to organize neater
void print_combination(int td_2pt, int td_fg, int td, int fg, int safety) {
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td_fg, td, fg, safety);
}

int main() {
    while (1) { //always true, infinite until false
        int score;
        printf("Enter 0 or 1 to STOP\n"); //0 false
        printf("Enter the NFL score: "); //asking for user input
        scanf("%d", &score); //using scan functionality to locate

        if (score <= 1) {
            break;
        }

        // run the code
        calculate_combinations(score);
    }
    return 0;
}