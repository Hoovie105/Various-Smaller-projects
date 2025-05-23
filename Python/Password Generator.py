#Simple CL Password Generator
import random
import string
# Define the characters that can be used in the password
def GeneratePassword (length = 12):
    char_set = string.ascii_letters + string.digits + string.punctuation
    # Generate a password of the specified length
    return "".join(random.choice(char_set) for i in range(length))

def main():
    try:
        length = int(input("Enter the length of the password: "))
        if length < 1:
            print("Password length must be at least 1")
            return
        password = GeneratePassword(length)
        print(f"Generated Password: {password}")
    except ValueError:
        print("Invalid input. Please enter a number.")

if __name__ == "__main__":
    main()
