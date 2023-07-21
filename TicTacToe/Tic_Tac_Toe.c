//25 ‎November ‎2020.
//Kumbhar Yogesh Balasaheb.
#include <stdio.h>

void playbox(char box[][7]);
char marker(char playerInput, char player, char box[][7]);
void dommybox(void);
char wincondition(char box[][7], char player);
int main(void)
{
    char player = 0;
    char playerInput = 0;
    char inputError;

    char box[3][7] = {
        {'|', '-', '|', '-', '|', '-', '|'},
        {'|', '-', '|', '-', '|', '-', '|'},
        {'|', '-', '|', '-', '|', '-', '|'},
    };
    dommybox();
    playbox(box);
    int i;
    for (i = 1; i <= 9; i++)
    {
    retry:
        inputError = 'S';
        if (i % 2 == 0)
        {
            printf("\n Current turn : Plyer 2");
            player = 'O';
        }
        else
        {
            printf("\n Current turn : Plyer 1");
            player = 'X';
        }
        printf("\n Pleas enter position : ");
        scanf(" %c", &playerInput);
        inputError = marker(playerInput, player, box);
        if (inputError == 'n' || inputError == 'F')
        {

            printf("\n \t Pleas enter valid key! \n");
            goto retry;
        }
        playbox(box);
        player = wincondition(box, player);
        if (player != 'N')
        {
            if (player == 'X')
            {
                printf("\n\nPlayer1 won this game!!");
                return 0;
            }
            else
            {
                printf("\n\nPlayer2 won this game!!");
                return 0;
            }
        }
    }
    printf("\nThis match is Draw!");
    return 0;
}
void playbox(char box[][7])
{	
	int i,j;
    printf("\tPlaybox: \n");
    for (i = 0; i < 3; i++)
    {
        printf("\n\t\t");
        for ( j = 0; j < 7; j++)
        {
            printf("%c", box[i][j]);
        }
    }
}
char marker(char playerInput, char player, char box[][7])
{
    if (player == 'X')
    {
        switch (playerInput)
        {
        case '1':
            if (box[0][1] == '-')
            {
                box[0][1] = 'X';
            }
            else
            {
                return 'F';
            }
            break;
        case '2':
            if (box[0][3] == '-')
            {
                box[0][3] = 'X';
            }
            else
            {
                return 'F';
            }
            break;
        case '3':
            if (box[0][5] == '-')
            {
                box[0][5] = 'X';
            }
            else
            {
                return 'F';
            }
            break;
        case '4':
            if (box[1][1] == '-')
            {
                box[1][1] = 'X';
            }
            else
            {
                return 'F';
            }
            break;
        case '5':
            if (box[1][3] == '-')
            {
                box[1][3] = 'X';
            }
            else
            {
                return 'F';
            }
            break;
        case '6':
            if (box[1][5] == '-')
            {
                box[1][5] = 'X';
            }
            else
            {
                return 'F';
            }
            break;
        case '7':
            if (box[2][1] == '-')
            {
                box[2][1] = 'X';
            }
            else
            {
                return 'F';
            }
            break;
        case '8':
            if (box[2][3] == '-')
            {
                box[2][3] = 'X';
            }
            else
            {
                return 'F';
            }
            break;
        case '9':
            if (box[2][5] == '-')
            {
                box[2][5] = 'X';
            }
            else
            {
                return 'F';
            }
            break;
        default:
            return 'n';
            break;
        }
    }
    else
    {
        switch (playerInput)
        {
        case '1':
            if (box[0][1] == '-')
            {
                box[0][1] = 'O';
            }
            else
            {
                return 'F';
            }
            break;
        case '2':
            if (box[0][3] == '-')
            {
                box[0][3] = 'O';
            }
            else
            {
                return 'F';
            }
            break;
        case '3':
            if (box[0][5] == '-')
            {
                box[0][5] = 'O';
            }
            else
            {
                return 'F';
            }
            break;
        case '4':
            if (box[1][1] == '-')
            {
                box[1][1] = 'O';
            }
            else
            {
                return 'F';
            }
            break;
        case '5':
            if (box[1][3] == '-')
            {
                box[1][3] = 'O';
            }
            else
            {
                return 'F';
            }
            break;
        case '6':
            if (box[1][5] == '-')
            {
                box[1][5] = 'O';
            }
            else
            {
                return 'F';
            }
            break;
        case '7':
            if (box[2][1] == '-')
            {
                box[2][1] = 'O';
            }
            else
            {
                return 'F';
            }
            break;
        case '8':
            if (box[2][3] == '-')
            {
                box[2][3] = 'O';
            }
            else
            {
                return 'F';
            }
            break;
        case '9':
            if (box[2][5] == '-')
            {
                box[2][5] = 'O';
            }
            else
            {
                return 'F';
            }
            break;
        default:
            return 'n';
            break;
        }
    }
}
void dommybox(void)
{
    printf("Instructions:\n\t 1.Use Numpad to play this game.\n\t 2.You can use 1 to 9 kyes.\n\t 3.The box below shows the positions. \n");
    printf("\t POSITIONS: \n\t\t\t|1|2|3|\n\t\t\t|4|5|6|\n\t\t\t|7|8|9|\n");
}
char wincondition(char box[][7], char player)
{
    if ((box[0][1] == box[0][3] && box[0][1] == box[0][5] && box[0][1] != '-') || (box[1][1] == box[1][3] && box[1][1] == box[1][5] && box[1][1] != '-') || (box[2][1] == box[2][3] && box[2][1] == box[2][5] && box[2][1] != '-'))
    {
        if (player == 'X')
        {
            return 'X';
        }
        else
        {
            return 'O';
        }
    }
    else if ((box[0][1] == box[1][1] && box[0][1] == box[2][1] && box[0][1] != '-') || (box[0][3] == box[1][3] && box[0][3] == box[2][3] && box[0][3] != '-') || (box[0][5] == box[1][5] && box[0][5] == box[2][5] && box[0][5] != '-'))
    {
        if (player == 'X')
        {
            return 'X';
        }
        else
        {
            return 'O';
        }
    }
    else if ((box[0][1] == box[1][3] && box[0][1] == box[2][5] && box[0][1] != '-') || (box[2][1] == box[1][3] && box[2][1] == box[0][5] && box[2][1] != '-'))
    {
        if (player == 'X')
        {
            return 'X';
        }
        else
        {
            return 'O';
        }
    }
    else
    {
        return 'N';
    }
}
