#include <iostream>
#include <ctime>
using namespace std;

///global variables declaration - used by most of the functions
int balance = 1000, bet, num;
int winning_amount;
int current_win;

//functions declaratuin in order to call them, they must be declared over the functions, they are getting called from.
void Betting_Color();
void Betting_Num();

void Play_Game()
{
	cout << "\n\n\nYOUR BALANCE IS " << balance << " SEK, START THE BETTING" << endl;
	cout << "\nCHOOSE YOUR BET (PLEASE ENTER THE CORRECT AMOUNT eg; 100)" << endl;

	// Show available betting options based on the current balance.
	if (balance >= 500)
	{
		cout << "\n    100 SEK\n    300 SEK\n    500 SEK\n\n  BETTING AMOUNT: ";
	}
	else if (balance >= 300) 
	{
		cout << "\n    100 SEK\n    300 SEK\n\n  BETTING AMOUNT: ";
	}
	else 
	{
		cout << "\n    100 SEK\n\n  BETTING AMOUNT: ";
	}

	cin >> bet;

	// Check if the bet is one of the allowed amounts and bet is lower than the balance
	if ((bet == 100 || bet == 300 || bet == 500) && bet <= balance) 
	{
		balance = balance - bet;
		cout << "\nYOU HAVE CHOSEN " << bet << " SEK AS YOUR BETTING AMOUNT." << endl;		
	}
	else 
	{
		cout << "\nINVALID BET OR INSUFFICIENT BALANCE. PLEASE CHOOSE A VALID BET AMOUNT." << endl;
		Play_Game();
	}
	

	// Continue with the game after valid bet selection
	cout << "\nNOW CHOOSE A COLOR OR A NUMBER TO BET ON.\n\n    1.COLOR\n    2.NUMBER" << endl;
	cout << "\nPRESS NUMBER (1 FOR COLOR /2 FOR NUMBER): ";
	cin >> num;

	if (num == 1) 
	{
		Betting_Color();
	}
	else if (num == 2) 
	{
		Betting_Num();
	}
	else 
	{
		cout << "ERROR: INVALID CHOICE, TRY AGAIN." << endl; //input validation
		Play_Game();
	}
}


void Check_Balance()
{
	if (balance >= 100) //cheking the balance before user got asked to play again. To make sure he/she has suficient funds.
	{
		string answer;
		cout << "\nDO YOU WISH TO PLAY AGAIN?(YES/NO): ";
		cin >> answer;
		if (answer == "YES" || answer == "yes")
		{
			Play_Game();
		}
		else
		{
			cout << "\n\n\nUNTIL NEXT TIME, GOODBYE\n\n" << endl;
			exit(0);
		}
	}
	else
	{
		cout << "\n\nYOU DO NOT HAVE ENOUGH BALANCE TO PLACE A BET. GAME OVER!\n\n" << endl;
		exit(0);
	}
}

void Betting_Num()
{
	int choosen_num;
	cout << "YOU ARE BETTING ON A NUMBER...\n\nPLEASE CHOOSE A NUMBER BETWEEN 1 AND 36" << endl;
	cout << "\nBETTING NUMBER (e.g; 27): ";
	cin >> choosen_num;

	if (choosen_num < 1 || choosen_num > 36)
	{
		cout << "\nINPUT VALUE IS WRONG\n\n"<<endl;
		Betting_Num();
	}
	else
	{
		srand(time(0)); //spinning the wheel
		int generated_num = rand() % 36 + 1;

		// Display both numbers
		cout << "\n   YOU CHOOSED " << choosen_num << endl;
		cout << "\n   GENERATED NUMBER: " << generated_num<< endl;

		// Check if the user won
		if (choosen_num == generated_num)
		{
			cout << "\nCONGRATULATIONS! YOU WON!" << endl;
			current_win = bet * 10;
			cout << "\nYOU WON " << current_win << " SEK ." << endl;
			winning_amount = winning_amount + current_win;
			balance = balance + winning_amount + bet;
			cout << "\nTOTAL WINING AMOUNT IS " << winning_amount <<" SEK" << endl;
			Check_Balance();		
		}
		else
		{
			cout << "\nSORRY YOU LOST, BETTER LUCK NEXT TIME!" << endl;
			Check_Balance();
		}
	}
	
}

void Betting_Color()
{
	string choosen_color;
	cout << "YOU ARE BETTING ON A COLOR...\n\nPLEASE CHOOSE A COLOR BETWEEN RED AND BLACK\n" << endl;
	
	cout << "   1.ODD NUMBERS HAVE THE COLOR RED" << endl;
	cout << "   2.EVEN NUMBERS HAVE THE COLOR BLACK\n" << endl;
	cout << "   BETTING COLOR (PLEASE TYPE THE COLOR e.g; red/RED): ";
	cin >> choosen_color;

	if (choosen_color =="red" || choosen_color =="RED" || choosen_color == "black" || choosen_color == "BLACK")
	{
		int selection=0;

		if (choosen_color == "red" || choosen_color == "RED")
		{
			cout << "\n    YOU CHOOSED RED" << endl;
			selection = 1;
		}
		else
		{
			cout << "\n    YOU CHOOSED BLACK" << endl;
		}

		srand(time(0));//spinning the wheel
		int generated_num = rand() % 36 + 1;
		cout << "\n    GENERATED NUMBER: " << generated_num << endl;

		if (generated_num % 2 != 0) //check whether the generated number is even or odd.
		{
			cout << "\n    AN ODD NUMBER IS GENERATED,WHICH HAVE THE COLOR RED." << endl;
		}
		else
		{
			cout << "\n    AN EVEN NUMBER IS GENERATED,WHICH HAVE THE COLOR BLACK." << endl;
		}

		// Check if the user won.
		if (selection = (generated_num % 2))
		{
			cout << "\nCONGRATULATIONS! YOU WON!" << endl;
			current_win = bet * 2;
			cout << "\nYOU WON " << current_win << " SEK ." << endl;
			winning_amount = winning_amount + current_win;
			balance = balance + winning_amount + bet;
			cout << "\nTOTAL WINING AMOUNT IS " << winning_amount << " SEK" << endl;
			Check_Balance();

		}
		else
		{
			cout << "\nSORRY YOU LOST, BETTER LUCK NEXT TIME!" << endl;
			Check_Balance();

		}
	}
	else
	{
		cout << "\nINPUT VALUE IS WRONG\n\n" << endl;
		Betting_Color();
	}
}


int main()
{
	string name;
	int date, month, year, age;
	

	// Get the current year from the system
	time_t t = time(0);   // Get current time
	tm now;
	localtime_s(&now, &t);  // Use localtime_s to safely get the local time
	int currentYear = now.tm_year + 1900;  // tm_year gives years since 1900

	cout << "WELCOME TO THE LUCKY SUCKER ROULETTE\n\n" << endl;
	cout << "*********************************************************************************************************\n\n" << endl;

	cout << "PLEASE ENTER YOUR FIRST NAME\n\n    NAME: ";
	cin >> name;

	cout << "\nPLEASE ENTER YOUR BIRTHDAY (DD-MM-YYYY) DAY-MONTH-YEAR FORMAT.\n\n";
	cout << "ENTER YOUR BIRTH DATE (DD): ";
	cin >> date;
	cout << "\nENTER YOUR BIRTH MONTH (MM): ";
	cin >> month;
	cout << "\nENTER YOUR BIRTH YEAR (YYYY): ";
	cin >> year;

	if (date <=31 && date >= 1 && month <=12 && month >= 1 && year < currentYear && year > 1900) 
	{
		age = currentYear - year;

		if (age < 18)
		{
			cout << "\nHELLO, " << name << "." << endl;
			cout << "AT " << age << " YEARS OLD, YOU ARE UNDER 18 AND THEREFORE NOT ELIGIBLE TO PARTICIPATE IN THIS GAME." << endl;
			cout << "THANK YOU FOR YOUR INTEREST, AND WE HOPE TO SEE YOU AGAIN IN THE FUTURE. GOODBYE.\n" << endl;
		}

		else
		{
			cout << "\nHELLO, " << name << ". OUR NEWEST LUCKY SUCKER. WELCOME TO THE ROULETTE. " << endl;
			cout << "\n\n*********************************************************************************************************\n\n" << endl;

			cout << "LUCKY SUCKER ROULETTE GAME RULES.\n\n";
			cout << "1) AT THE BEGINNING OF THE GAME, YOU HAVE 1000 SEK.\n\n";
			cout << "2) THERE ARE THREE BETTING OPTIONS: 100 SEK, 300 SEK, AND 500 SEK.\n";
			cout << "   YOU CAN PLACE YOUR BET ON EITHER A NUMBER (1-36) OR A COLOR (RED OR BLACK) ON THE ROULETTE BOARD.\n\n";
			cout << "3) THE ROULETTE WILL SPIN AND GENERATE A RESULT. IF YOU WIN, YOUR BETTING AMOUNT WILL BE RETURNED ALONG WITH THE WINNING AMOUNT.\n";
			cout << "   HOWEVER, IF YOU LOSE, YOU WILL FORFEIT THE BET AMOUNT.\n\n";
			cout << "   3.1) IF YOU BET ON A NUMBER AND WIN, YOU WILL RECEIVE TEN TIMES YOUR BET AMOUNT.\n";
			cout << "   3.2) IF YOU BET ON A COLOR AND WIN, YOU WILL RECEIVE TWICE YOUR BET AMOUNT.\n\n";
			cout << "4) AFTER EACH ROUND, YOU WILL BE ASKED IF YOU WANT TO CONTINUE.\n";
			cout << "   PLEASE TYPE \"YES\" IF YOU WANT TO CONTINUE OR \"NO\" IF YOU DO NOT.\n\n";
			cout << "5) PLAY THE GAME ACCORDING TO THE GIVEN INSTRUCTIONS.\n\n\n";

			cout << "\n\n*********************************************************************************************************\n\n" << endl;
			Play_Game();
		}
	}
	else 
	{
		cout << "\n\nINVALID INPUTS. PLEASE ENTER VALID DATA.\n\n\n" << endl;
		main();
	}

	return 0;
}

