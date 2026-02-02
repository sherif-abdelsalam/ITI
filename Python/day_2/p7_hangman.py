import random
from p4_user_info import is_valid_name
from i_locations import find_char_indexes

word_list = ["sherif", "ahmed", "mohammed", "ali", "mahmoud"]

chosen_word = random.choice(word_list)
placeholders = "_" * len(chosen_word)

attempts = 7
used_letters = ""

user_name = input("Enter your name: ")

while not is_valid_name(user_name):
    print("Invalid Name. Name must be only letters.")
    user_name = input("Enter your name: ")

print("\nYou have 7 attempts to guess the word. Let's Play!")
print(placeholders)

while attempts > 0:

    try:

        guess = input("\nGuess a letter: ")

        if len(guess) != 1 or not guess.isalpha():
            print("Please enter a single letter.")
            continue

        if guess in used_letters:
            print("You already guessed this letter.")
            continue

        used_letters+=guess

        if guess in chosen_word:
            indexes = find_char_indexes(chosen_word, guess)
            new_placeholders = ""

            for i in range(len(chosen_word)):
                if i in indexes:
                    new_placeholders += guess
                else:
                    new_placeholders += placeholders[i]

            placeholders = new_placeholders
            print(placeholders)

            if "_" not in placeholders:
                print(f"\nCongratulations {user_name}! You guessed: {chosen_word}")
                break
        else:
            attempts -= 1
            print(f"Wrong guess. Attempts left: {attempts}")
            
    except Exception as e:
        print(f"Something Wrong!  {e}")

else:
    print(f"\n Game over! The word was: {chosen_word}")
