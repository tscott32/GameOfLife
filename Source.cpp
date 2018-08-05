//**********************************************
//
//		Description:	Game of Life
//		Class:			COSC 1436.S01
//		Author:			Taylor Benavides
//		Date:			Oct 2017
//
//***********************************************

#include<iostream>

using namespace std;

#include<stdlib.h>
#include<memory.h>

void main()
{
	int			Col = 0;
	int			Row = 0;
	int			Generation = 0;
	int			Neighbors;
	int			Quit = 0;

	const int	MaxRows(60);
	const int	MaxCols(60);
	bool		Board[MaxRows + 2][MaxCols + 2];
	bool		NewBoard[MaxRows + 2][MaxCols + 2];


	memset(Board, false, ((MaxRows + 2) * (MaxCols + 2) * sizeof(bool)));		// Sets entire array to false
	memset(NewBoard, false, ((MaxRows + 2) * (MaxCols + 2) * sizeof(bool)));	// Sets entire array to false

	for (; Row != -1 && Col != -1;)
	{
		cout << "Enter 1-60 for rows and columns to set living cells. " << endl;
		cout << "Enter -1 for both row and column when you are ready to start the game" << endl;
		Board[Row][Col] = true;
		cin >> Row;
		if ((0 >= Row && Row != -1) || Row > MaxRows)
		{
			cout << "You entered an invalid row.\n " << endl;
			Row = 0;
			continue;
		}
		else
			cin >> Col;
		if ((0 >= Col && Col != -1) || Col > MaxCols)
		{
			cout << "You entered an invalid column.\n " << endl;
			Col = 0;
			continue;
		}
		else;
	}

	for (Row = 1; Row <= MaxRows; Row++)
	{
		for (Col = 1; Col <= MaxCols; Col++)
			cout << (Board[Row][Col] ? '*' : ' ');
		cout << endl;

	}

	while (true)
	{
		Quit = 1;
		while (Quit != 0)
		{
			cout << "Would you like to continue to next generation? if so, enter 0." << endl;
			cout << "If you would like to quit now, enter 61." << endl;


			cout << "Generation: " << Generation << endl;
			Generation++;
			cin >> Quit;
			switch (Quit)
			{
			case (0) :
				break;
				break;

			case (61) :
				exit(0);
				break;

			}
		}

		for (Row = 1; Row <= MaxRows; Row++)
		{
			for (Col = 1; Col <= MaxCols; Col++)
			{
				Neighbors = 0;
					if (Board[Row][Col] == false)
					{
						if (Board[Row - 1][Col - 1])
							Neighbors++;
						else;

						if (Board[Row][Col - 1])
							Neighbors++;
						else;

						if (Board[Row + 1][Col - 1])
							Neighbors++;
						else;

						if (Board[Row + 1][Col])
							Neighbors++;
						else;

						if (Board[Row + 1][Col + 1])
							Neighbors++;
						else;

						if (Board[Row][Col + 1])
							Neighbors++;
						else;

						if (Board[Row - 1][Col + 1])
							Neighbors++;
						else;

						if (Board[Row - 1][Col])
							Neighbors++;
						else;

						if (Neighbors <= 1)
						{
							NewBoard[Row][Col] = false;
						}
						else if (Neighbors == 3)
						{
							NewBoard[Row][Col] = true;
						}
					}
					else;
			}

		}

		Board[0][0] = false;
		NewBoard[0][0] = false;

		for (Row = 1; Row <= MaxRows; Row++)
		{
			for (Col = 1; Col <= MaxCols; Col++)
			{
				Neighbors = 0;
				if (Board[Row][Col])
				{
					if (Board[Row - 1][Col - 1])
						Neighbors++;
					else;

					if (Board[Row][Col - 1])
						Neighbors++;
					else;

					if (Board[Row + 1][Col - 1])
						Neighbors++;
					else;

					if (Board[Row + 1][Col])
						Neighbors++;
					else;

					if (Board[Row + 1][Col + 1])
						Neighbors++;
					else;

					if (Board[Row][Col + 1])
						Neighbors++;
					else;

					if (Board[Row - 1][Col + 1])
						Neighbors++;
					else;

					if (Board[Row - 1][Col])
						Neighbors++;
					else;


					if (Neighbors <= 1)
					{
						NewBoard[Row][Col] = false;
					}
					else;
					
					if (Neighbors > 3)
					{
						NewBoard[Row][Col] = false;
					}
					else;

					if (Neighbors == 2)
					{
						NewBoard[Row][Col] = true;
					}

					if (Neighbors == 3)
					{
						NewBoard[Row][Col] = true;
					}
					else;
				}
				else;
			}
		}
		for (Row = 1; Row <= MaxRows; Row++)
		{
			for (Col = 1; Col <= MaxCols; Col++)
			{
				Board[Row][Col] = NewBoard[Row][Col];
			}
		}

		system("cls");
		for (Row = 1; Row <= MaxRows; Row++)
		{
			for (Col = 1; Col <= MaxCols; Col++)
				cout << (Board[Row][Col] ? '*' : ' ');
			cout << endl;
		}


	}
}