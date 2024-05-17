// this function returns the user input
int get_user_input() {

    // this variable stores a value of an input
    int user_input = 0;

    // flag to check if any digit has been entered
    bool digit_entered = false;

    // proceed to checking the input
    while (true) {

        // get the input from a user
        int input = getchar();

        // convert an ascii to its respective value and set the flag
        if (input >= first_digit_ascii && input <= last_digit_ascii) {
            user_input = user_input * factor + (input - first_digit_ascii);
            digit_entered = true;
        }

        // if pressed 'enter' or a space symbol is found, stop the loop
        if (input == enter || input == space || input == EOF) {

            // if a "bare" 0 is found (as a separate number) ...
            if (digit_entered && !user_input) {

                // "consume" the rest of the line
                while (input != enter) input = getchar();
                break; // return the zero
            }

            // if the number is fully processed, stop the input
            if (digit_entered) break;

        }
    }

    return user_input; // return the provided input

}