#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int a = 0;

int DFA(string key[], int a)
{
	string keyword1 = "as";
	string fkey = key[0];

	if (keyword1[a] == fkey[a])
	{

		a++;
		if (fkey[a + 1] == keyword1[a + 1])
		{
			return 1;

		}
		else
		{

			return 0;

		}
	}
}

int DFA1(string key[], int a)
{
	string keyword1 = "althought";
	string fkey = key[1];

	if (keyword1[a] == fkey[a])
	{

		a++;
		if (fkey[a + 1] == keyword1[a + 1])
		{
			return 1;

		}
		else
		{
			return 0;

		}
	}
}

int DFA2(string key[], int a)
{
	string keyword1 = "if";
	string fkey = key[1];

	if (keyword1[a] == fkey[a])
	{

		a++;
		if (fkey[a + 1] == keyword1[a + 1])
		{
			return 1;

		}
		else
		{
			return 0;

		}
	}
}


int main()
{
	string c[50];
	string t[50];
	string f[50];

	string key[50];
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;


	string ident[50];
	string sym[50];
	string con[50];

	int i = 0;
	int a = 0;
	ifstream read;

	read.open("token.txt");      ///////////////////                   Read file

	if (read.is_open())
	{
		while (!read.eof())
		{
			c[a] = read.get();



			if (c[a] == "(" || c[a] == ")" || c[a] == "{" || c[a] == "}" || c[a] == "=" || c[a] == "<<" || c[a] == ">>" || c[a] == "," || c[a] == ";" || c[a] == "<")
			{

				i++;
				t[i] = t[i] + c[a];
				i++;
			}
			else if (c[a] == " " || c[a] == "\n" || c[a] == "\0")
			{

				i++;

			}
			else
			{
				t[i] = t[i] + c[a];
			}

		}
	}

	/////////////////////////////////////                   Remove white spaces if spaces is remaining

	int k = 0;
	for (int j = 0; j <= i; j++)
	{

		if (t[j] == " " || t[j] == "\n" || t[j] == "\0")
		{
			t[j];
		}
		else
		{
			f[k] = f[k] + t[j];
			k++;
		}
	}
	/////////////////////////////////////////////                  Token

	cout << "1. Token" << endl;
	for (int k1 = 0; k1 < k; k1++)
	{
		cout << f[k1] << endl;
	}

	////////////////////////////////////////////                  Keyword

	cout << "2. Keywords" << endl;
	for (int j1 = 0; j1 < k; j1++)
	{
		if (f[j1] == "as" || f[j1] == "althought" || f[j1] == "mydata" || f[j1] == "act" || f[j1] == "if" || f[j1] == "otherwise" || f[j1] == "sround" || f[j1] == "terminates" || f[j1] == "case" || f[j1] == "fourbyte")
		{
			key[p1] = f[j1];
			cout << "Keyword" << " = " << f[j1] << endl;
			p1++;
		}
	}

	cout << " " << endl;

	///////////////////////////////////////////                  Symbols

	cout << "3. Symbols" << endl;
	for (int j2 = 0; j2 < k; j2++)
	{
		if (f[j2] == "(" || f[j2] == ")" || f[j2] == "{" || f[j2] == "}" || f[j2] == ";" || f[j2] == "," || f[j2] == "<<" || f[j2] == "=" || f[j2] == "<" || f[j2] == ">")
		{
			sym[p2] = f[j2];
			cout << "Symbol" << " = " << f[j2] << endl;
			p2++;
		}
	}

	cout << " " << endl;

	//////////////////////////////////////////                  Constants

	cout << "4. constants" << endl;
	for (int j3 = 0; j3 < k; j3++)
	{
		if (f[j3] >= "0" && f[j3] <= "9")
		{
			con[p3] = f[j3];
			cout << "Constant" << " = " << f[j3] << endl;
			p3++;
		}
	}

	cout << " " << endl;

	///////////////////////////////////////////                  Identifier

	string a2;
	cout << "5. Identifier" << endl;
	for (int j4 = 0; j4 < k; j4++)
	{
		a2 = f[j4];
		if (a2[0] >= 'a' && a2[0] <= 'z')
		{
			if (a2 == "as" || a2 == "althought" || a2 == "act" || a2 == "if" || a2 == "atherwise" || a2 == "sround" || a2 == "terminates" || a2 == "case" || a2 == "fourbyte")
			{

			}
			else
			{
				ident[p4] = f[j4];
				cout << "Identifier" << " = " << a2 << endl;
				p4++;
			}

		}

	}

	cout << " " << endl;

	/////////////////////////////////////////                  valid keyword 




	if (f[0] == "as")                                           //For loop check whether keyword is valid or not 
	{
		cout << "Check whether keyword is valid or not " << endl;

		int d, d1, d2, d3, d4, d5, d6, d7;

		d = DFA(key, a);

		if (d == 1)
		{

			d1 = DFA(key, a);

			if (d1 == 1)
			{

				d2 = DFA(key, a);

				if (d2 == 1)
				{
					cout << "keyword Valid" << " = " << key[0] << endl;

				}
			}

		}
	}

	///////////////////////////////////////////

	else if (f[0] == "althought")                                 //while loop check whether keyword is valid or not 
	{
		cout << "Check whether keyword is valid or not " << endl;

		int d, d1, d2, d3, d4, d5, d6, d7, d8;

		d = DFA1(key, a);

		if (d == 1)
		{

			d1 = DFA1(key, a);

			if (d1 == 1)
			{

				d2 = DFA1(key, a);

				if (d2 == 1)
				{
					d3 = DFA1(key, a);

					if (d3 == 1)
					{
						d4 = DFA1(key, a);
						if (d4 == 1)
						{
							d5 = DFA1(key, a);
							if (d5 == 1)
							{
								d6 = DFA1(key, a);
								if (d6 == 1)
								{
									d7 = DFA1(key, a);
									if (d7 == 1)
									{
										d8 = DFA1(key, a);
										if (d8 == 1)
										{
											cout << "keyword Valid" << " = " << key[0] << endl;
										}
									}
								}
							}

						}
					}
				}

			}

		}
	}


	////////////////////////////////////////////





	else if (f[0] == "if")                                           //if statement check whether keyword is valid or not 
	{
		cout << "Check whether keyword is valid or not " << endl;

		int d, d1, d2, d3, d4, d5, d6, d7;

		d = DFA2(key, a);

		if (d == 1)
		{

			d1 = DFA2(key, a);

			if (d1 == 1)
			{

				d2 = DFA2(key, a);

				if (d2 == 1)
				{
					cout << "keyword Valid" << " = " << key[0] << endl;

				}
			}

		}
	}





	/////////////////////////////////////////////////                 valid Identifier

	cout << " " << endl;
	cout << "Check whether Identifier is valid or not " << endl;


	for (int j4 = 0; j4 < k; j4++)
	{
		a2 = f[j4];
		if (a2[0] >= 'a' && a2[0] <= 'z')
		{
			if (a2 == "as" || a2 == "althought" || a2 == "act" || a2 == "if" || a2 == "otherwise" || a2 == "sround" || a2 == "terminates" || a2 == "case" || a2 == "fourbyte")
			{

			}
			else
			{
				ident[p4] = f[j4];
				cout << "valid Identifier" << " = " << a2 << endl;
				p4++;
			}

		}

	}

	cout << " " << endl;


	/////////////////////////////////////////////////                 CFG



	//////////////////////////////////////////////////                 Three address code 

	cout << " " << endl;
	cout << "Three address code" << endl;                      /////// for loop

	if (f[0] == "as")
	{
		cout << "1. " << "if(" << f[3] << ">" << f[9] << ")" << "goto(7)" << endl;
		cout << "2. " << f[14] << " " << "=" << " " << f[16] << endl;
		cout << "3. " << "T1" << " " << "=" << " " << f[3] << endl;
		cout << "4. " << f[3] << " " << "=" << " " << "T1" << endl;
		cout << "5. " << f[3] << " " << "=" << " " << f[3] << " " << "+" << " " << "1" << endl;
		cout << "6. " << "goto(1)" << endl;
		cout << "7. " << "Exit" << endl;

	}
	else if (f[0] == "althought")                             /////// while loop
	{
		cout << "1. " << "if(" << f[2] << ">" << f[4] << ")" << "goto(7)" << endl;
		cout << "2. " << f[7] << " " << "=" << " " << f[9] << endl;
		cout << "3. " << "T1" << " " << "=" << " " << f[2] << endl;
		cout << "4. " << f[2] << " " << "=" << " " << "T1" << endl;
		cout << "5. " << f[2] << " " << "=" << " " << f[2] << " " << "+" << " " << "1" << endl;
		cout << "6. " << "goto(1)" << endl;
		cout << "7. " << "Exit" << endl;
	}
	else if (f[0] == "if")                             /////// while loop
	{
		cout << "1. " << "if(" << f[2] << ">" << f[4] << ")" << "goto(7)" << endl;
		cout << "2. " << f[7] << " " << "=" << " " << f[9] << endl;
		cout << "3. " << "T1" << " " << "=" << " " << f[2] << endl;
		cout << "4. " << f[2] << " " << "=" << " " << "T1" << endl;
		cout << "5. " << f[2] << " " << "=" << " " << f[2] << " " << "+" << " " << "1" << endl;
		cout << "6. " << "goto(1)" << endl;
		cout << "7. " << "Exit" << endl;
	}




	cout << " " << endl;

	system("pause");
	return 0;

}
