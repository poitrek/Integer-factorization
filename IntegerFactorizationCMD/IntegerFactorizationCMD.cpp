// IntegerFactorizationCMD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include <conio.h>

using namespace std;

typedef unsigned long long ulong;

void printFactor(ulong prime, int exponent)
{
	cout << " " << prime << " ^ " << exponent << endl;
}

vector<pair<ulong, int>> factorize(ulong N)
{
	vector<pair<ulong, int>> factors;
	ulong sqrtN = (ulong)sqrt(N);
	
	if (N < 1)
		return factors;

	// Check divisibility by 2
	int exp_2{ 0 };
	while (N % 2 == 0)
	{
		N /= 2;
		exp_2++;
	}
	if (exp_2 > 0)
	{
		factors.push_back(pair<ulong, int>(2, exp_2));
		printFactor(2, exp_2);
	}
	// For every k that is prime, count the number of times N is divisible by k
	for (ulong k = 3; k <= sqrtN && N > 1; k += 2)
	{
		bool is_prime{ true };
		for (ulong i = 3; i <= sqrt(k); i += 2)
			if (k % i == 0)
				is_prime = false;
		if (is_prime)
		{
			int exp_k{ 0 };
			while (N % k == 0)
			{
				N /= k;
				exp_k++;
			}
			if (exp_k > 0) {
				factors.push_back(pair<ulong, int>(k, exp_k));
				printFactor(k, exp_k);
			}
		}
	}
	// If N is still greater than 1, it is the remaining prime factor
	if (N > 1) {
		factors.push_back(pair<ulong, int>(N, 1));
		printFactor(N, 1);
	}
	return factors;
}


//void printFactors(vector<pair<ulong, int>> factors)
//{
//	for (pair<ulong, int> fact : factors)
//	{
//	}
//}


int main()
{
	ulong N;
	clock_t start, stop;
	double duration;
	char key = 0;
	while (key != 27)
	{
		cout << "Type a natural number to factorize: ";
		cin >> N;
		start = clock();
		factorize(N);
		stop = clock();
		duration = (double)(stop - start) / CLOCKS_PER_SEC;
		cout << "---------------" << endl;
		cout << " TIME: " << duration << " s" << endl;
		cout << "---------------" << endl;
		cout << "Press anything to try another number" << endl;
		cout << "Press space to clear screen" << endl;
		cout << "Press 'Esc' to exit" << endl << endl;
		key = _getch();
		if (key == 32)
			system("cls");
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
