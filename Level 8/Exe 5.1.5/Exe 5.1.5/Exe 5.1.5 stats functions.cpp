//Fei - Exe 5.1.5
//Boost libraries - Statistical Functions

#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions

#include <vector>
#include <iostream>
using namespace std;


int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;

	//Create an exponential distribution
	double scaleParameter = 0.5;

	exponential_distribution<>   myExpo(scaleParameter); // Default type is 'double'
	cout << "Mean: " << mean(myExpo) << ", standard deviation: " << standard_deviation(myExpo) << endl;

	// Distributional properties
	double x = 10.25;

	cout << "pdf: " << pdf(myExpo, x) << endl;		//pdf=scaleParameter*exp(-scaleParameter*x)
	cout << "cdf: " << cdf(myExpo, x) << endl;		//cdf=1-exp(-x*scaleParameter)

	// Choose another data type and now with a new scaleParameter
	double scaleParameter1 = 1;
	exponential_distribution<float> myExpo2(scaleParameter1); 
	cout << "Mean: " << mean(myExpo2) << ", standard deviation: " << standard_deviation(myExpo2) << endl;
	
	cout << "pdf: " << pdf(myExpo2, x) << endl;
	cout << "cdf: " << cdf(myExpo2, x) << endl;

	// Choose precision
	cout.precision(10); // Number of values behind the comma

	// Other properties
	//https://www.boost.org/doc/libs/1_54_0/libs/math/doc/html/math_toolkit/dist_ref/dists/exp_dist.html
	cout << "\n***Exponential distribution: \n";
	cout << "mean: " << mean(myExpo) << endl;							//mean=1/scaleParameter=1/0.5=2
	cout << "variance: " << variance(myExpo) << endl;					//variance=std^2=mean^2=4
	cout << "median: " << median(myExpo) << endl;						//median=scaleParamenter^(-1)ln(2)
	cout << "mode: " << mode(myExpo) << endl;							//mode=0
	cout << "kurtosis excess: " << kurtosis_excess(myExpo) << endl;		//kurtosis excess=6
	cout << "kurtosis: " << kurtosis(myExpo) << endl;					//kurtosis=9
	cout << "characteristic function: " << chf(myExpo, x) << endl;		
	cout << "hazard: " << hazard(myExpo, x) << endl;

	cout << endl << endl;




	// Poisson distribution
	double mean = 3.0;
	poisson_distribution<double> myPoisson(mean);

	double val = 13.0;
	cout << endl <<  "pdf: " << pdf(myPoisson, val) << endl;			//pdf=e^(-mean)*(mean^k)/k!
	cout << "cdf: " << cdf(myPoisson, val) << endl;						

	// Other properties
	//https://www.boost.org/doc/libs/1_47_0/libs/math/doc/sf_and_dist/html/math_toolkit/dist/dist_ref/dists/poisson_dist.html
	cout << "\n***Poisson distribution: \n";
	cout << "variance: " << variance(myPoisson) << endl;					//variance=mean=3					
	cout << "mode: " << mode(myPoisson) << endl;							
	cout << "kurtosis excess: " << kurtosis_excess(myPoisson) << endl;		//kurtosis excess=1/mean=1/3
	cout << "kurtosis: " << kurtosis(myPoisson) << endl;					//kurtosis=3+1/mean
	cout << "characteristic function: " << chf(myPoisson, x) << endl;
	cout << "hazard: " << hazard(myPoisson, x) << endl;

	cout << endl;

	vector<double> pdfList;
	vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myPoisson, val));
		cdfList.push_back(cdf(myPoisson, val));

		val += h;
	}

	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", ";

	}

	cout << endl << "***" << endl;

	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", ";

	}

	cout << endl;
	
	return 0;
}