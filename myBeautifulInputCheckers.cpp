//input error checking functions
int IntInput(string inMsg,    //menu prompt
	const int MIN, //minimum value allowed
	const int MAX) //maximum value allowed
{
	int  integer; //input by user to be checked
	bool valid;   //LCV for validated input
	do
	{
		valid = true;
		cout << inMsg;
		cin  >> integer;
		cin.ignore(10000, '\n');

		if (cin.fail() || integer < MIN || integer > MAX)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			valid = false;
			cout << "Invalid input, please try " << MIN << '-' << MAX << endl;
		}
	} while (!valid);
	return integer;
}

float FloatInput(string inMsg,  //menu prompt
	const int MIN, //minimum value allowed
	const int MAX) //maximum value allowed
{
	float floater; //input by user to be checked
	bool valid;    //LCV for validated input
	do
	{
		valid = true;
		cout << inMsg;
		cin >> floater;
		cin.ignore(10000000, '\n');


		if (cin.fail() || floater < MIN || floater > MAX)
		{
			cin.clear();
			cin.ignore(10000000, '\n');
			valid = false;
			cout << "Invalid input, please try " << MIN << '-' << MAX << endl;
			//system("pause");
			//system("cls");
		}
	} while (!valid);
	return floater;
}
double DoubleInput(string inMsg,  //menu prompt
	const int MIN, //minimum value allowed
	const int MAX) //maximum value allowed
{
	double dbl; //input by user to be checked
	bool valid;    //LCV for validated input
	do
	{
		valid = true;
		cout << inMsg;
		cin >> dbl;
		cin.ignore(10000000, '\n');


		if (cin.fail() || dbl < MIN || dbl > MAX)
		{
			cin.clear();
			cin.ignore(10000000, '\n');
			valid = false;
			cout << "Invalid input, please try " << MIN << '-' << MAX << endl;
			//system("pause");
			//system("cls");
		}
	} while (!valid);
	return dbl;
}
char YNCharInput(string inMsg) //input message
{
	char  character; //input by user to be checked
	bool valid;   //LCV for validated input
	do
	{
		valid = true;
		cout << inMsg;
		character = getch();
		character = tolower(character);

		if (character != 'y' && character != 'n')
		{
			cin.clear();
			cin.ignore(10000, '\n');
			valid = false;
			cout << "Invalid input, please try y/n." << endl;
		}
	} while (!valid);
	return character;
}
