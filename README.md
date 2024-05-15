### Premise
A coin is flipped 100 times, resulting in an H (heads) or T (tails) each time. For every HH in the sequence (two heads in a row), Alice gets a point. For every HT in the sequence (a heads followed by a tails), Bob gets a point. What is the probability of Bob winning the game, Alice winning the game, and a tie?
### This Program
By seeding the random() function with a seed taken from /dev/urandom and running consecutive simulations of the 100 coin toss game, the win and tie percentage for Bob and Alice can be approximated.