#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct dictionary
{
	char word[20];
	char partOfSpeech[20];
	char meaning[200];
	char example[200];
} dictionary;
int word_search(void);
void display(void);
void add(void);
void edit_or_delete(int deleteFlag);
void sort(void);

int main()
{
	int playerInput = 0;
	while (1)
	{

		printf("\n\t\t============= WORD DICTIONARY ===============\n");
		printf("\n\t\t  1. Display all the words in dictionary."); //done
		printf("\n\t\t  2. Search a word in dictionary.");		   //done
		printf("\n\t\t  3. Add a word in dictionary.");			   //done
		printf("\n\t\t  4. Sort words in dictionary.");			   //not
		printf("\n\t\t  5. Edit a word in dictionary.");		   //done
		printf("\n\t\t  6. Delete a word");						   //done
		printf("\n\t\t  7. exit");								   //done
		printf("\n\n\t\t=============================================\n");

		//-------------------------------------------------------------------------------------
		printf("\n\t\tPlease enter your choice : ");
		scanf("%d", &playerInput);
		fflush(stdin);
		//-------------------------------------------------------------------------------------
		switch (playerInput)
		{
		case 1:
			display();
			printf("\n\n\t\tPress \"ENTER\" : ");
			getchar();
			system("cls");
			break;

		case 2:
			//-------------------------------word search-------------------------------------------

			word_search();
			printf("\n\n\t\tPress \"ENTER\" : ");
			getchar();
			system("cls");
			break;

		case 3:
			add();
			printf("\n\n\t\tThe word has been added successfully !\n");
			printf("\n\n\t\tPress \"ENTER\" : ");
			getchar();
			system("cls");
			break;

		case 4:

			break;

		case 5:
			edit_or_delete(0); //edit
			printf("\n\n\t\tThe word has been updated successfully !\n");
			printf("\n\n\t\tPress \"ENTER\" : ");
			getchar();
			system("cls");
			break;
		case 6:
			edit_or_delete(1); //delete
			printf("\n\n\t\tThe word has been deleted successfully !\n");
			printf("\n\n\t\tPress \"ENTER\" : ");
			getchar();
			system("cls");
			break;
		case 7:
			exit(EXIT_SUCCESS);
			break;

		default:
			printf("\n\t\tPlease enter valid key !");
			printf("\n\n\t\tPress \"ENTER\" : ");
			getchar();
			system("cls");

			break;
		}
	}

	return 0;
}

int word_search(void)
{
	dictionary words;
	FILE *original;
	char search[20];
	char newline[2];
	int wordCount = 0;
	original = fopen("datafile.txt", "r");

	printf("\n\t\tPlease enter the word you want to search : ");
	gets(search);
	while (feof(original) == 0)
	{
		wordCount++;
		if (wordCount == 1)
		{

			fgets(newline, 2, original);
		}
		fgets(newline, 2, original);

		fgets(words.word, 20, original);
		words.word[strlen(words.word) - 1] = 0;

		fgets(words.partOfSpeech, 20, original);
		words.partOfSpeech[strlen(words.partOfSpeech) - 1] = 0;

		fgets(words.meaning, 200, original);
		words.meaning[strlen(words.meaning) - 1] = 0;

		fgets(words.example, 200, original);
		if (words.example[strlen(words.example) - 1] == 10)
		{
			words.example[strlen(words.example) - 1] = 0;
		}

		if (strcmp(words.word, search) == 0)
		{
			printf("\n\t word found !\n");
			printf("\n\t<----------------------------------------------------------------------------------->\n");
			printf("\n\t word : %s\n\t Part of speech : %s\n\t Meaning : %s\n\t Example sentence : %s\n", words.word, words.partOfSpeech, words.meaning, words.example);
			printf("\n\t<----------------------------------------------------------------------------------->");
			fclose(original);
			return 0;
		}
	}

	printf("\n\tword not found !\n");
	fclose(original);
	return 0;
}

void display(void)
{
	dictionary words;
	FILE *original;
	char newline[2];
	int wordCount = 0;
	original = fopen("datafile.txt", "r");
	printf("\n\t<========================== ALL WORDS ===========================>\n");
	while (feof(original) == 0)
	{
		wordCount++;
		if (wordCount == 1)
		{

			fgets(newline, 2, original);
		}
		fgets(newline, 2, original);

		fgets(words.word, 20, original);
		words.word[strlen(words.word) - 1] = 0;

		fgets(words.partOfSpeech, 20, original);
		words.partOfSpeech[strlen(words.partOfSpeech) - 1] = 0;

		fgets(words.meaning, 200, original);
		words.meaning[strlen(words.meaning) - 1] = 0;

		fgets(words.example, 200, original);
		if (words.example[strlen(words.example) - 1] == 10)
		{
			words.example[strlen(words.example) - 1] = 0;
		}

		printf("\n\t %s\n\t\t Part of speech : %s\n\t\t meaning : %s\n\t\t Example sentence : %s\n", words.word, words.partOfSpeech, words.meaning, words.example);
	}
	printf("\n\t<================================================================>\n");
	fclose(original);
}

void add(void)
{
	dictionary words;
	FILE *original;
	original = fopen("datafile.txt", "a");

	printf("\n\t\tPlease enter the new word : ");
	gets(words.word);
	printf("\n\t\tEnter part of speech : ");
	gets(words.partOfSpeech);
	printf("\n\t\tEnter meaning : ");
	gets(words.meaning);
	printf("\n\t\tEnter examaple sentence : ");
	gets(words.example);

	fprintf(original, "\n\n%s\n%s\n%s\n%s", words.word, words.partOfSpeech, words.meaning, words.example);
	fclose(original);
}
void edit_or_delete(int deleteFlag)
{
	char newline[2];
	dictionary words;
	FILE *original;
	FILE *temp;
	int searchSuccess = 0;
	int wordCount = 0;
	char editOrDelete[20];
	original = fopen("datafile.txt", "r");
	temp = fopen("temp.txt", "w");
	fflush(stdin);
	if (deleteFlag == 0)
	{
		printf("\nenter the word that you want to edit : ");
		gets(editOrDelete);
	}
	else
	{
		printf("\nenter the word that you want to delete : ");
		gets(editOrDelete);
	}
	while (feof(original) == 0)
	{
		wordCount++;
		if (wordCount == 1)
		{

			fgets(newline, 2, original);
		}
		fgets(newline, 2, original);
		fgets(words.word, 20, original);
		words.word[strlen(words.word) - 1] = 0;

		fgets(words.partOfSpeech, 20, original);
		words.partOfSpeech[strlen(words.partOfSpeech) - 1] = 0;

		fgets(words.meaning, 200, original);
		words.meaning[strlen(words.meaning) - 1] = 0;

		fgets(words.example, 200, original);
		if (words.example[strlen(words.example) - 1] == 10)
		{
			words.example[strlen(words.example) - 1] = 0;
		}

		if (strcmp(words.word, editOrDelete) == 0)
		{
			searchSuccess = 1;
			printf("\n\t word found !\n");
			printf("\n\t<----------------------------------------------------------------------------------->\n");
			printf("\n\t word : %s\n\t Part of speech : %s\n\t Meaning : %s\n\t Example sentence : %s\n", words.word, words.partOfSpeech, words.meaning, words.example);
			printf("\n\t<----------------------------------------------------------------------------------->");

			if (deleteFlag == 0)
			{
				printf("\n\t\tPlease enter the new word : ");
				gets(words.word);
				printf("\n\t\tenter part of speech :");
				gets(words.partOfSpeech);
				printf("\n\t\tenter meaning : ");
				gets(words.meaning);
				printf("\n\t\tenter example sentence : ");
				gets(words.example);
			}
		}
		if (deleteFlag == 0)
		{
			fprintf(temp, "\n\n%s\n%s\n%s\n%s", words.word, words.partOfSpeech, words.meaning, words.example);
		}
		else if ((deleteFlag == 1) && (strcmp(words.word, editOrDelete) != 0))
		{
			fprintf(temp, "\n\n%s\n%s\n%s\n%s", words.word, words.partOfSpeech, words.meaning, words.example);
		}
	}

	if (searchSuccess == 0)
		printf("\n\t\tWord not found !");
	fclose(temp);
	fclose(original);

	remove("datafile.txt");
	rename("temp.txt", "datafile.txt");
}

void sort(void)
{
}
