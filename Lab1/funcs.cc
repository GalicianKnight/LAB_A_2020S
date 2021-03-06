/*
	Lab1 Team Programming 
	Author: Dov Kruger

	For a description of each function, see:
	https://docs.google.com/document/d/1eTLecRiJJdQkS6OWDgNIhECLfIvyYP_-EdfwistiT8U/edit?usp=sharing
*/
#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;
uint32_t sum(uint32_t a, uint32_t b); //Nathan Renner
uint64_t prod(uint32_t a, uint32_t b); //Edgar Castaneda-Vargas
uint32_t sumsq(uint32_t a, uint32_t b); //Joshua Hornilla
uint64_t prod(uint32_t a, uint32_t b); //Matt Ross
uint32_t countPrimes(uint32_t a, uint32_t b){ //James Parisi
void swap(uint32_t& a, uint32_t& b); //Chloe Sharpe
bool isPrime(uint32_t p); // Sean Melone
uint32_t gcd(uint32_t a, uint32_t b); //Sylvia Boamah
uint32_t lcm(uint32_t a, uint32_t b); //Anisha Shin
double fact(uint32_t n); //Logan Smith
double hypot(double a, double b); //Kalani Pigao
double diffsq(double a, double b);
double mean(int a, int b); //Serafin Fernandez
double mean(int a, int b, int c); //Andrew DeSanti
uint64_t sum(uint32_t n); //Andrew DeSanti
double hypot(double a, double b); //Kalani Pigao
double mean(int a, int b); //Serafin Fernandez
double mean(int a, int b, int c);//Qingyao Fan
bool pythagoreantriple(double a, double b); //Matt Ross
double trigIdentity(double x);
/*
	note: this function uses pass by reference. Compute the answer and assign
	to x1 and x2 and the roots will be sent back to main and printed
*/
void quadraticEquation(double a, double b, double c, double& x1, double& x2);

double area(double x1, double y1, double x2, double y2, double x3, double y3);
double area(double x1, double y1,
						double x2, double y2,
						double x3, double y3,
						double x4, double y4);
double perimeter(double x1, double y1, double x2, double y2, double x3, double y3);

double perimeter(double x1, double y1,
								 double x2, double y2,
								 double x3, double y3,
								 double x4, double y4);

double dot(double v1x, double v1y, double v1z,
					 double v2x, double v2y, double v2z);
void rect2polar(double x, double y, double &r, double &theta);
void polar2rect(double r, double theta, double &x, double &y);

class Vec3d {
public:
	double x,y,z;
	Vec3d(double x, double y, double z) : x(x), y(y), z(z) {}
	friend ostream &operator<<(ostream& s, const Vec3d& v) {
		return s << v.x << "," << v.y << "," << v.z;
	}
};

double dot(Vec3d v1, Vec3d v2);

Vec3d cross(Vec3d v1, Vec3d v2);

double grav(double m1, Vec3d v1, double m2, Vec3d v2);

// array problems
double mean(int x[], int n); // Nathan Renner
int max(int x[], int n); // Edgar Castaneda-Vargas
int min(int x[], int n); //Joshua Hornilla 
double prod(int x[], int n); //James Parisi
int sum(int x[], int n); //Sean Melone
void demean(double x[], int n); //Chloe Sharpe
void square(double x[], int n);//Kalani Pigao
void normalize(double x[], int n); //Sylvia Boamah
void round(double x[], int n); //Anisha Shin
void squareRoot(double x[], int n);//Andrew DeSanti
uint32_t strip(double x[], uint32_t n, double a, double b);
void reverse(int x[], int n); //Logan Smith
uint32_t randomElement(const int x[], int n);
uint32_t countEvens(const int x[], int n); //Serafin Fernandez
void addToEach(int x[], int n, int delta);

void removeVowels(char s[]);
void reverse(char s[]);
bool isPalindrome(const char s[]);
uint32_t checksum(const char s[]); 
uint32_t myhash(const char s[]);
void lowercase(char s[]); //Matt Ross

double taylorSeriesSine(double x);//Qingyao Fan
double taylorSeriesCosine(double x);
double taylorSeriesE(double x);


void print(const double x[], int n) {
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';
	cout << '\n';
}

void print(const int x[], int n) {
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';
	cout << '\n';
}

int main() {
	cout << sum(1, 3) << ' ' << sum(1, 100) << '\n'; // should work no problem, right?
	cout << sum(1, 1000000) << '\n'; // what should this be? Don't assume it's right, check!
					 // this will overflow for the 1-1000000 input.

	cout << prod(2, 5) << '\n'; // 2*3*4*5 = 120
	cout << prod(3, 10) << '\n';
	cout << prod(3, 20) << '\n'; // just note whether you think these are right
	cout << prod(3, 30) << '\n'; // if it overflows, you don't have to fix it
	cout << prod(3, 100) << '\n'; 
	
	cout << sumsq(1, 5) << '\n';
	cout << "countPrimes(1,100): " << countPrimes(1, 100) << '\n';
	cout << "countPrimes(1,1000000): " << countPrimes(1, 1000000) << '\n';
	cout << "isPrime(1001)=" << isPrime(1001) << '\n';
	int a = 2, b = 3;
	swap(a, b);
	cout << "after swap a=" << a << " b=" << b << '\n';
	cout << "gcd(12, 18)=" << gcd(12, 18) << '\n';
	cout << "gcd(1025, 3025)=" << gcd(1025, 3025) << '\n';
	cout << "lcm(12, 18)=" << lcm(12, 18) << '\n';
	cout << "fact(10)=" << fact(10) << '\n';
	cout << "sum(1..100) = " << sum(100) << '\n';
	cout << "hypot(3,4)=" << hypot(3,4) << '\n';
	cout << "hypot(4,5)=" << hypot(4,5) << '\n';
	cout << "diffsq(3,4)=" << diffsq(3,4) << '\n';
	cout << "mean(1,4)=" << mean(1,4) << '\n';
	cout << "mean(1,4,5)=" << mean(1,4,5) << '\n';
	cout << "pythagoreantriple(3,4)=" << pythagoreantriple(3,4) << '\n';
	cout << "trig identity sin^2+cos^2 =" << trigIdentity(0.0);
	cout << "trig identity sin^2+cos^2 =" << trigIdentity(1.0); // for 1 radian
	double root1, root2; // these will contain the answers after calling
	quadraticEquation(1.0, 3.0, 2.0, root1, root2);
	cout << "roots=" << root1 << ", " << root2 << '\n';

	cout << "area of tri=" << area(0,0, 3,0, 3,3) << '\n';
	cout << "area of tri=" << area(0,0, -4,3, 3,5) << '\n';

	cout << "area of quad=" << area(0,0, 3,0, 4,3, -1,3);
	cout << "perimeter of tri=" << perimeter(0,0, 3,0, 3,3) << '\n';

	cout << "perimeter of quad=" << perimeter(0,0, 3,0, 3,4, 0,4) << '\n';

	cout << "dot product=" << dot(3.0, 2.0, 1.5,  2.0, 1.5, -3.0) << '\n';
	cout << "dot product=" << dot(2.0, 1.0, 1.0,  -3.0, 2.0, 4.0) << '\n';
	Vec3d v1(1.0, 2.0, 0.0), v2(1.0, 5.0, 0.0);
	cout << dot(v1, v2) << '\n';
	Vec3d c = cross(v1, v2);
	cout << c << '\n';

	double x = 3, y = 4;
	double r, theta;
	rect2polar(x, y, r, theta);
	cout << "r=" << r << " theta=" << theta << '\n';
	polar2rect(r, theta, x, y); // should get back the original values!
	cout << "x=" << x << " y=" << y << '\n';

	double earthMass=5.92e+24, moonMass = 7.348e23;
	Vec3d earthPos(0,0,0), moonPos(384400000, 0,0);
	double F = grav(earthMass, earthPos, moonMass, moonPos);
	cout << "Force between earth and moon=" << F << '\n';

  // array problems
	int arr[] = {1, 4, 3, 2};
	cout << "arr avg=" << mean(arr, 4) << '\n'; // should be 2.5
	cout << "arr max=" << max(arr, 4) << '\n'; // should be 4
	cout << "arr max=" << min(arr, 4) << '\n'; // should be 1
	cout << "arr prod=" << prod(arr, 4) << '\n'; // should be 24
	cout << "arr sum=" << sum(arr, 4) << '\n'; // should be 10

	int arr2[] = {5, 6, 7, 8, 9, 10, 2, 1};
	cout << "arr avg=" << mean(arr2, 8) << '\n';
	cout << "arr max=" << max(arr2, 8) << '\n';
	cout << "arr max=" << min(arr2, 8) << '\n';
	cout << "arr prod=" << prod(arr2, 8) << '\n';
	cout << "arr sum=" << sum(arr2, 8) << '\n';

	double arr3[6] = {1, 2, 3, 4, 5, 6};
	demean(arr3, sizeof(arr3)/sizeof(double));
	print(arr3, 6);

	double arr4[6] = {1, 2, 3, 4, 5, 6};
	normalize(arr4, 6);
	print(arr4, 6);

	double arr5[] = { 1.5, 3, 9, 4, 16, 8.2, 5.9, 15.2};
	int size = strip(arr5, 8, 3.0, 8.5);
	print(arr5, size);

	int arr6[] = {6, 1, 9, 2, 5, 3, 7};
	for (int i = 0; i < 4; i++) {
		uint32_t pos = randomElement(arr6, 7);
		cout << arr6[pos] << ' ' ;
	}

	double arr7[] = { 2.5, 2.8, 3.1, 4.2, 9.6, 7.1, -7.3, -7.6};
	round(arr7, sizeof(arr7)/sizeof(double));
	print(arr7, sizeof(arr7)/sizeof(double));
	
	cout << "countevens=" << countEvens(arr6, 7) << '\n';
	addToEach(arr6, 7, 3);
	print(arr6, sizeof(arr6)/sizeof(double));

	double arr8[] = {1.0, 2.5, 3.0, 3.5};
	square(arr8, sizeof(arr8)/sizeof(double));
	print(arr8, sizeof(arr8)/sizeof(double));
	squareRoot(arr8, sizeof(arr8)/sizeof(double));
	print(arr8, sizeof(arr8)/sizeof(double)); // should be back to orinal values
	
	int r1[] = {1, 2, 3, 4, 5, 6, 7};
	reverse(r1, 7);
	print(r1, 7);

	int r2[] = {1, 2, 3, 4, 5, 6, 7, 8};
	reverse(r2, 8);
	print(r2, 8);

	char s1[] = "this is a test";
	removeVowels(s1);
	cout << s1 << '\n';

	char s2[] = "testing testing 123";
	reverse(s2);
	cout << s2 << '\n';

	char s3[] = "a toyota. able was i ere i saw elba";
	reverse(s3);
	cout << s3 << '\n';
	
	cout << "isPalindrome(atoyota)=" << isPalindrome("atoyota") << '\n';
	cout << "isPalindrome(testing)=" << isPalindrome("testing") << '\n';
	cout << "checksum=" << checksum("ABC") << '\n'; // should be 65 + 66 + 67
	cout << "checksum=" << checksum("abcdefghijklmnopqrstuvwxyz") << '\n';

	cout << myhash("ABC") << '\n'; // (65 * 26 + 66) * 26 + 67
	cout << myhash("hash this!") << '\n';
	cout << myhash("hash a longer string") << '\n';
*/
}

// NON-ARRAY PROBLEMS

uint32_t sum(uint32_t a, uint32_t b) { //Nathan Renner 
	uint32_t sum = 0;	       // This function will overflow for the 1-1000000 input.
	for (int i = a; i <= b; i++)
		sum += i;
	return sum;
}

double mean(int a, int b, int c) { //Andrew DeSanti
	return (a + b + c)/3;

uint64_t prod(uint32_t a, uint32_t b)
{ // Edgar Castaneda-Vargas
	uint64_t product = 1;
	for (uint32_t i = a; i <= b; i++)
	{
		product *= i;
	}
	return product;
}

double mean(double a, double b){// Serafin Fernandez
	double m = (a+b)*0.5;
	return m;
}

void swap(uint32_t& a, uint32_t& b) { //Chloe Sharpe
	int c = a;
	a = b;
	b = c;
};

bool isPrime(uint32_t p); { //Sean Melone
	for (int i = 2; i <= p; i++){
		if(p % i == 0){
			return false;
			break;
		}
	}
	return true;

}
i
uint32_t sumsq(uint32_t a, uint32_t b){ //Joshua Hornilla
	return (a*a)+(b*b);
	}


uint32_t countPrimes(uint32_t a, uint32_t b) { // James Parisi
	uint32_t count = 0;
	for (uint32_t i = a; a <= b; a++) {
		if(isPrime(i)) {
			count++;
		}
	}
	return count;
}

uint32_t lcm(uint32_t a, uint32_t b) { //Anisha Shin
	uint32_t counter = 0;
	bool lcmFound = false;
	while (lcmFound == false) {
		counter++;
		if (counter % a == 0 && counter % b == 0) {
			lcmFound = true;
			return counter;
		}
	}

}

double hypot(double a, double b) { //Kalani Pigao
	return sqrt(a * a + b * b)
}

double mean(int a, int b, int c) //Andrew DeSanti
{

	return(a + b + c)/3.0;

}

bool pythagoreantriple(double a, double b){ //Matt Ross
    double c = sqrt( a*a + b*b );
    if (fmod(c,0) == 0){
        return true;
    }
    else return false;
}
double fact(uint32_t n) //Logan Smith
{
	int product = 1;
	for(int i = 1; i <= n; i++)
	{
		product *= i;
	}
	return product;
}

// ARRAY PROBLEMS

double mean(int x[], int n){ // Nathan Renner
	double sum = 0;	
	for (int i = 0; i < n; i++)
		sum += x[i];
	return sum/4.0;	
}

void demean(double x[], int n){ //Chloe Sharpe

	double sum = 0;
	for(int i = 0; i < n; i++){
		sum += x[i];
	}	
	
	double mean = sum/n;

	for(int i = 0; i < n; i++){
		x[i] -= mean;
	}	
};	

int max(int x[], int n) // Edgar Castaneda-Vargas
{
	int max_value = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		if (x[i] > max_value)
		{
			max_value = x[i];
		}
	}
	return max_value;
}


double mean(int a, int b, int c){
int d;
d=a+b+c;
d=d/3;
return d;
}//Qingyao Fan
	

double taylorSeriesSine(double x){
double a;
a += pow (-1.0, x) * pow (a, 2*x+1) / factorial(2*x+1);
return a;
}//Qingyao Fan




int min(int x[];int n){ //Joshua Hornilla
	int small = x[0];
	for (int i=0; i<n; i++){
		if (small > x[i]){
			small = x[i];
		}
	}
	return small;
};

double prod(int x[], int n){ //James Parisi
	double product = 1
	for(int i = 0; i < n; i++) {
		product *= x[i];
	}
	return product;
};


int sum(int x[], int n){ // Sean Melone
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += x[i];
	}
	return sum;
}

void square(double x[], int n){ //Kalani Pigao
	for (int i = 0; i < n; i++){
		x[i] = x[i] *x[i];
	}
}

uint32_t countEvens(const int x[], int n){// Serafin Fernandez
	uint32_t evens =0;
	for (int i =0; i<n;){
		if (x[i] % 2== 0){
			evens ++;
		}
		i++;
	}
	return evens;
}

void squareRoot(double x[], int n) //Andrew DeSanti
{

	for(int i=0;i< n; i++)
	{
		x[i]=sqrt(x[i]);
	}
}

void reverse(int x[]; int n) //Logan Smith
{
	for(int i = 0; i < n/2; i++)
	{
		int a = x[i];
		x[i] = x[(n-1) - i];
		x[(n-1) - i] = a;
	}
}	

void round(double x[], int n) { //Anisha Shin
 	for (int i = 0; i < n; i++) {
		int integer = (int) x[i];
		if (abs(x[i] - integer) < 0.5) {
			x[i] = integer;
		}
		else {
			if (x[i] > 0) {
				x[i] = integer + 1;
			}
			else {
				x[i] = integer - 1;
			}
		}
	}
}

void lowercase(char s[]){ //Matt Ross
	int n = sizeof(s);
	for(int i=0; i<n; i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] +=32;
		}
		cout << s[i] << "\n";
	}
}
