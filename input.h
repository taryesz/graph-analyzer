// this function returns the user input
int get_user_input() {

    // this variable stores a value of an input
    int user_input = 0;

    // proceed to checking the input
    while (true) {

        // get the input from a user
        int input = getchar();

        // convert an ascii to its respective value
        if (input >= first_digit_ascii && input <= last_digit_ascii) {
            user_input = user_input * factor + (input - first_digit_ascii);
        }

        // if pressed 'Enter' or a space symbol is found, stop the loop
        if (input == enter || input == space) break;

    }

    return user_input; // return the provided input

}