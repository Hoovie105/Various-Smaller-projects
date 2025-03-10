#Guessing Higher Lower Game:::
#The computer will think of a number between 1 and 100.
#The player will try to guess the number.
#After each guess, the computer will tell the player if their guess was higher or lower
#than the number it is thinking of.
#The game will continue until the player guesses the number correctly.
#The computer will keep track of the number of guesses the player makes.
#The game will end when the player guesses the number correctly, and the computer will tell the
#player the number of guesses it took to win.

import random

computer = random.randint(1, 100)
GameState = True
guesses = 0
while GameState:
    guesses +=1
    try:
        Playerguess = int(input("Choose a number between 1 and 100: "))
    except ValueError:
        print("Invalid input. Please enter a number.")
        continue
    if Playerguess > computer:
        print("Guess is too High")
    elif Playerguess < computer:
        print("Guess is too Low")
    else: 
        print("You guessed the number in", guesses, "guesses")
        GameState = False
