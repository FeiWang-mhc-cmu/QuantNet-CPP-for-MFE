//Fei - Exe 5.1.4
//Boost libraries - Random number generator

#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include <ctime>			// std::time
#include <map>
using namespace std;
#include<iomanip>			//set precision

int main()
{
	// Throwing dice.
	// Mersenne Twister.
	boost::random::mt19937 myRng;

	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1,6);

	// Structure to hold outcome + frequencies
	map<int, long> statistics; 
		
	//Generate a large number of trials and place their frequencies in map
	int n = 1000000;		// Number of trials
	int outcome;			// Current outcome

	//Initialize frequencies for each outcome
	//double count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;

	//Loop over to count the frequency of each outcome
	for (int i = 0; i < n; i++)
	{
		outcome = six(myRng);
		
		statistics[outcome]++;

		/*
		if(outcome==1)
			count1 +=1;
		else if (outcome==2)
			count2 += 1;
		else if (outcome==3)
			count3 += 1;
		else if (outcome==4)
			count4 += 1;
		else if (outcome==5)
			count5 += 1;
		else if (outcome==6)
			count6 += 1;
		*/
	}
	
	/*
	//Mapping outcomes to their frequencies
	statistics[1] = count1;
	statistics[2] = count2;
	statistics[3] = count3;
	statistics[4] = count4;
	statistics[5] = count5;
	statistics[6] = count6;
	*/


	//Produce the required outcome
	cout << "How many trials? " << n << endl;

	for (int i=1; i<=6; i++)
	{
		double freq;
		double count = statistics[i];
		freq = count/n*100;

		cout << "Trial " << i << " has " << std::setprecision(6) << freq << " % outcomes" << endl;
	}


	return 0;
}