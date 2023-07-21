//17-06-2021_yogesh_kumbhar
// int number = (rand()%(upper - lower + 1) + lower)
void display_reward(char reward[][10][45], int number);
void display_word_guessing_game(void);
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    int upper = 0;       //no of word -1
    int lives = 6;       //total lives
    int deduct;          //flag
    char guess;          //save guessed letter
    int end_of_game = 0; //flag
    int i;
    char easy_words[][15] = {
        "cat", "sun", "cup", "cow", "banana", "dog", "coat", "ocean"};
    char easy_word_meaning[][150] = {
        "a small animal with soft fur that people often keep as a pet.",
        "The star that shines in the sky during the day and that gives the earth heat and light.",
        "a small container usually with a handle, used for drinking liquids.",
        "a large female animal that is kept on farms to produce milk.",
        "a curved fruit with yellow skin that grows in hot countries.",
        "an animal that many people keep as a pet, or for working on farms, hunting.",
        "a piece of clothing that you wear over your other clothes to keep warm when you are outside.",
        "The mass of salt water that covers most of the surface of the earth."};

    char medium_words[][15] = {
        "horse", "backbone", "cowboy", "electricity", "thief", "spare", "shallow", "music", "whisk"};
    char medium_word_meaning[][150] = {
        "a large animal that is used for riding on or for pulling or carrying heavy loads",
        "the most important part of something",
        "a man whose job is to look after cows (usually on a horse) in certain parts of the US.",
        "a type of energy that we use to make heat, light and power to work machines,etc.",
        "a person who steals things from another person.",
        "not needed now but kept because it may be needed in the future.",
        "not deep; with not much distance between top and bottom",
        "an arrangement of sounds in patterns to be sung or played on instruments.",
        "a tool that you use for beating eggs, cream, etc. very fast."};

    char hard_words[][15] = {
        "retail", "fabric", "jazz", "download", "dashboard", "migrate", "clog", "yolk"};
    char hard_word_meaning[][150] = {
        "the selling of goods to the public in shops, etc.",
        "a type of cloth or soft material that is used for making clothes, curtains, etc.",
        "a style of music with a strong rhythm, originally of African American origin.",
        "to copy a computer file, etc. from a large computer system to a smaller one.",
        "the part in a car in front of the driver where most of the switches, etc. are",
        "to travel from one part of the world to another at the same time every year(used about animals and birds).",
        "a type of shoe made completely of wood or with a thick wooden base.",
        "the yellow part in the middle of an egg."};

    char reward[7][10][45] = {{"\t___________________________________________",
                               "\t|                                 ,-.     |",
                               "\t|                               .-|-|-.   |",
                               "\t|   .----.    .----.    .----.  | | |_|   |",
                               "\t|  /  ..  \\  /  ..  \\  /  ..  \\ `-|.| '.  |",
                               "\t| |  /  \\  .|  /  \\  .|  /  \\  ..-| |  |  |",
                               "\t| '  \\  /  ''  \\  /  ''  \\  /  '| |-|  /  |",
                               "\t|  \\  `'  /  \\  `'  /  \\  `'  /  `|-|''   |",
                               "\t|   `---''    `---''    `---''    `-'     |",
                               "\t|_________________________________________|"},
                              {"\t___________________________________________",
                               "\t|                             ,-.         |",
                               "\t|                           .-|-|-.       |",
                               "\t|   .--.  .----.    .----.  | | |_|       |",
                               "\t|  /_  | /  ..  \\  /  ..  \\ `-|.| '.      |",
                               "\t|   |  ||  /  \\  .|  /  \\  ..-| |  |      |",
                               "\t|   |  |'  \\  /  ''  \\  /  '| |-|  /      |",
                               "\t|   |  | \\  `'  /  \\  `'  /  `|-|''       |",
                               "\t|   `--'  `---''    `---''    `-'         |",
                               "\t|_________________________________________|"},
                              {"\t___________________________________________",
                               "\t|                                ,-.      |",
                               "\t|                              .-|-|-.    |",
                               "\t|   .----.   .----.    .----.  | | |_|    |",
                               "\t|  \\_,-.  | /  ..  \\  /  ..  \\ `-|.| '.   |",
                               "\t|     .' .'|  /  \\  .|  /  \\  ..-| |  |   |",
                               "\t|   .'  /_ '  \\  /  ''  \\  /  '| |-|  /   |",
                               "\t|  |      | \\  `'  /  \\  `'  /  `|-|''    |",
                               "\t|  `------'  `---''    `---''    `-'      |",
                               "\t|_________________________________________|"},
                              {"\t___________________________________________",
                               "\t|                                ,-.      |",
                               "\t|                              .-|-|-.    |",
                               "\t|   .----.   .----.    .----.  | | |_|    |",
                               "\t|  \\_.-,  | /  ..  \\  /  ..  \\ `-|.| '.   |",
                               "\t|    |_  < |  /  \\  .|  /  \\  ..-| |  |   |",
                               "\t|  .-. \\  |'  \\  /  ''  \\  /  '| |-|  /   |",
                               "\t|  \\ `-'  / \\  `'  /  \\  `'  /  `|-|''    |",
                               "\t|   `---''   `---''    `---''    `-'      |",
                               "\t|_________________________________________|"},
                              {"\t___________________________________________",
                               "\t|                                 ,-.     |",
                               "\t|                               .-|-|-.   |",
                               "\t|     .---.   .----.    .----.  | | |_|   |",
                               "\t|    / .  |  /  ..  \\  /  ..  \\ `-|.| '.  |",
                               "\t|   / /|  | |  /  \\  .|  /  \\  ..-| |  |  |",
                               "\t|  / '-'  ||'  \\  /  ''  \\  /  '| |-|  /  |",
                               "\t|  `---|  |' \\  `'  /  \\  `'  /  `|-|''   |",
                               "\t|      `--'   `---''    `---''    `-'     |",
                               "\t|_________________________________________|"},
                              {"\t___________________________________________",
                               "\t|                                ,-.      |",
                               "\t|                              .-|-|-.    |",
                               "\t|  .-----.   .----.    .----.  | | |_|    |",
                               "\t|  |   __|  /  ..  \\  /  ..  \\ `-|.| '.   |",
                               "\t|  `--.  '.|  /  \\  .|  /  \\  ..-| |  |   |",
                               "\t|  .-  |  |'  \\  /  ''  \\  /  '| |-|  /   |",
                               "\t|  | `-'  / \\  `'  /  \\  `'  /  `|-|''    |",
                               "\t|   `---''   `---''    `---''    `-'      |",
                               "\t|_________________________________________|"},
                              {"\t___________________________________________",
                               "\t|                                ,-.      |",
                               "\t|                              .-|-|-.    |",
                               "\t|    ,--.    .----.    .----.  | | |_|    |",
                               "\t|   /  .'   /  ..  \\  /  ..  \\ `-|.| '.   |",
                               "\t|  .  / -. |  /  \\  .|  /  \\  ..-| |  |   |",
                               "\t|  '  .-. \\'  \\  /  ''  \\  /  '| |-|  /   |",
                               "\t|  \\  `-' / \\  `'  /  \\  `'  /  `|-|''    |",
                               "\t|   `----'   `---''    `---''    `-'      |",
                               "\t|_________________________________________|"}};

    char(*word_list)[15];
    char(*word_meaning_list)[150];
    //========================menu========================
    int input = 0;
    do
    {
        display_word_guessing_game();
        printf("\n     =================");
        printf("\n\t1.easy\n\t2.medium\n\t3.hard\n\t4.exit game");
        printf("\n     =================");
        printf("\n\n    Please select difficulty level: ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            word_list = easy_words;
            word_meaning_list = easy_word_meaning;
            upper = 7;
            break;
        case 2:
            word_list = medium_words;
            word_meaning_list = medium_word_meaning;
            upper = 8;

            break;
        case 3:
            word_list = hard_words;
            word_meaning_list = hard_word_meaning;
            upper = 7;

            break;
        case 4:
            exit(EXIT_SUCCESS);

            break;
        default:
            input = 99;
            printf("\n\tPlease enter valid choice!");
            printf("\n\tPress ENTER to return to menu: ");
            fflush(stdin);
            getchar();
            break;
        }
        system("cls");
    } while (input == 99);

    //====================================================
    char *chosen_word;
    char *display;

    srand(time(0)); //seed as time
    //int lower = 0;
    int rand_number = rand() % (upper + 1); //random number genrator
    chosen_word = word_list[rand_number];   //pick random word
    int wordlength = strlen(chosen_word);

    //printf("\nthe random word is : %s\n", chosen_word);

    display = (char *)malloc(sizeof(char) * wordlength); //display[wordlength];
    for (i = 0; i < wordlength; i++)
        display[i] = '_';

    printf("\n\tGood luck, the highest reward will be: \n");
    display_reward(reward, lives);
    while (!end_of_game)
    {
        printf("\n\tHINT: %s\n", word_meaning_list[rand_number]);
        printf("\n");
        printf("\t");
        for (i = 0; i < wordlength; i++) //display blanks
        {
            printf("%c ", display[i]);
        }

        printf("\n\n\tGuess a letter : "); //user input
        fflush(stdin);
        guess = tolower(getc(stdin));
        system("cls");

        int skip = 0;
        for (i = 0; i < wordlength; ++i) //check for already guessed letter
        {
            if (guess == display[i])
            {
                system("cls");
                printf("\tYou've already guessed %c\n\n", guess);
                display_reward(reward, lives);
                skip = 1;
                break;
            }
        }
        if (skip)
        {
            continue;
        }

        deduct = 1;
        for (i = 0; i < wordlength; i++) //replace blanks with guessed leter
        {
            if (chosen_word[i] == guess)
            {
                display[i] = guess;
                deduct = 0;
            }
        }
        if (deduct == 0)
            printf("\tYou guessed %c, that's in the word.", guess);

        if (deduct) //for reducing the lives and for ending game when zero lives are left
        {
            lives--;
            if (lives == 0)
            {
                printf("\n");
                printf("\tYou guessed %c, that's not in the word.", guess);
                puts("\n\tYou have lost all of your reward!");
                display_reward(reward, 0);
                printf("\n\tThe correct word is : %s", chosen_word);
                exit(EXIT_SUCCESS);
            }
            else
            {
                printf("\n\tYou guessed %c, that's not in the word. You lose some reward.", guess);
            }
        }

        //===========================================
        end_of_game = 1;
        for (i = 0; i < wordlength; i++) //wining condition and exit game
        {
            if (display[i] == '_')
            {
                end_of_game = 0;
            }
        }
        putchar('\n');
        printf("\tYour reward will be : \n");
        display_reward(reward, lives);
        if (end_of_game) //wining message display
        {
            system("cls");
            printf("\n\tcongratulations you have guessd \"%s\" correctly !\n\tyou won and your reward is : \n", chosen_word);
            display_reward(reward, lives);
        }
        //============================================
    }
    return 0;
}
void display_reward(char reward[][10][45], int number)
{

    puts(reward[number][0]);
    puts(reward[number][1]);
    puts(reward[number][2]);
    puts(reward[number][3]);
    puts(reward[number][4]);
    puts(reward[number][5]);
    puts(reward[number][6]);
    puts(reward[number][7]);
    puts(reward[number][8]);
    puts(reward[number][9]);
}
void display_word_guessing_game(void)
{

    printf("                       _                             _  \n");
    printf("                      | |                           (_)\n");
    printf("__      _____  _ __ __| |   __ _ _   _  ___  ___ ___ _ _ __   __ _    __ _  __ _ _ __ ___   ___ \n");
    printf("\\ \\ /\\ / / _ \\| '__/ _` |  / _` | | | |/ _ \\/ __/ __| | '_ \\ / _` |  / _` |/ _` | '_ ` _ \\ / _ \\\n");
    printf(" \\ V  V / (_) | | | (_| | | (_| | |_| |  __/\\__ \\__ \\ | | | | (_| | | (_| | (_| | | | | | |  __/\n");
    printf("  \\_/\\_/ \\___/|_|  \\__,_|  \\__, |\\__,_|\\___||___/___/_|_| |_|\\__, |  \\__, |\\__,_|_| |_| |_|\\___|\n");
    printf("                            __/ |                             __/ |   __/ | \n");
    printf("                           |___/                             |___/   |___/   \n");
}
