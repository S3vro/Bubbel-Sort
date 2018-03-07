#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*Array with all Names to be sorted*/
vector<string> names{ "Paul", "Thomas","Markus","Gerd","Lizzy","Jakob","Ben","Kilian","Leonie","Regine","Ulla","Lara","Denise","Lena","Leni","Leni","Leo","Penny","Maja","Melina","Feuer","Feuerwehr"};

bool finished_all = false; /*Finished? => Yes stop looping*/
int runs; /*Counts the times the proramm runs through*/



void sort()
{
	while (!finished_all) /*Looping until finished_all = true*/
	{
		int timesChanged = 0; /*Times checked each run | If this is 0 after a full run the programm stops*/
		runs++; /*Counting Runs*/

		for (int i = 0; i != names.size() - 1; i++) /*Loop through names list*/
		{

				for (int f = 0; (f <= names[i].length()) && (f <= names[i + 1].length()); f++) /*loop through the two words*/
				{
					int Char1_2 = names[i][f]; /*Other chars of first word*/
					int Char2_2 = names[i + 1][f]; /*Other chars of second word*/

					if (Char1_2 > Char2_2) /*Check if 'Char1_2' ist already at the right place*/
					{
						string RAM;
						RAM = names[i + 1]; /*Save the second name in RAM*/
						names[i + 1] = names[i]; /*Swap names*/
						names[i] = RAM;

						timesChanged++; /*Something was changed*/
						break; /*return*/
					}
					else if (Char1_2 != Char2_2) break; 					
					else if ((Char1_2 == Char2_2) && (f == names[i].length() || f == names[i + 1].length())) /*If 'Char1' is in 'Char2' like 'Leo' and 'Leonie' Leo will be before Leonie*/
					{
						if (names[i].length() > names[i + 1].length())
						{
							string RAM;
							RAM = names[i + 1]; /*Save the second name in RAM*/
							names[i + 1] = names[i]; /*Swap names*/
							names[i] = RAM;

							timesChanged++; /*Something was changed*/
							break; /*return*/
						}
					}
				}
			
		}
		if (timesChanged == 0) finished_all = true; /*If 'timesChanged' is 0 after a full run the programm stops*/

	}
}


int main(void)
{
	sort();

	cout << "Finished after " << runs << " times | " << names.size() << " items were sorted." << endl;
	
	for (int i = 0; i != names.size(); i++)
	{
		cout << names[i] << endl;
	}

	system("pause");

	return 0;
}