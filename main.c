#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, int* argv[])
{
    long int number_games = 1e7;
    long int number_flips = 1e2;
    long int ties = 0;
    long int bob_wins = 0;
    long int alice_wins = 0;
    int seed;
    FILE *f = fopen("/dev/urandom", "r");
    fread(&seed, sizeof(int), 1, f);
    srandom(seed);
    fclose(f);
    for(int i = 0; i<number_games; i++)
    {
        // srand(time(NULL));
        int this_num = -1;
        int last_num = -1;
        long int bob_score = 0;
        long int alice_score = 0;
        for(int k = 0; k<number_flips; k++)
        {
            last_num = this_num;
            this_num = random()%2;
            if(last_num == 1 && this_num == 1)
            {
                alice_score++;
            }
            else if(last_num == 1 && this_num == 0)
            {
                bob_score++;
            }
        }
        if(bob_score == alice_score)
        {
            ties++;
        }
        else if(bob_score > alice_score)
        {
            bob_wins++;
        }
        else
        {
            alice_wins++;
        }
    }
    
    printf("\n%d games played, with %d coin flips per game.\n", number_games, number_flips);
    printf("Bob won %d times, with a winrate of %f%%.\n", bob_wins, ((double)bob_wins/(double)number_games)*100);
    printf("Alice won %d times, with a winrate of %f%%.\n", alice_wins, ((double)alice_wins/(double)number_games)*100);
    printf("There was a tie %f%% of the time.\n", ((double)ties/(double)number_games)*100);
    return 0;
}