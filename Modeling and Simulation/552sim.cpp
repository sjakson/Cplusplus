#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

/* Period parameters */  
#define N 624
#define M 397
#define MATRIX_A 0x9908b0df   /* constant vector a */
#define UPPER_MASK 0x80000000 /* most significant w-r bits */
#define LOWER_MASK 0x7fffffff /* least significant r bits */

/* Tempering parameters */   
#define TEMPERING_MASK_B 0x9d2c5680
#define TEMPERING_MASK_C 0xefc60000
#define TEMPERING_SHIFT_U(y)  (y >> 11)
#define TEMPERING_SHIFT_S(y)  (y << 7)
#define TEMPERING_SHIFT_T(y)  (y << 15)
#define TEMPERING_SHIFT_L(y)  (y >> 18)

static unsigned long mt[N]; /* the array for the state vector  */
static int mti=N+1; /* mti==N+1 means mt[N] is not initialized */

using namespace std;

int main (){

	//srand((unsigned)time(0));

	double MAX_INVEST = 200000.0, MIN_INVEST = 0.0;
	int gen_poisson(double lambda);
	double genrand();
	int gen_binomial(int n, double p);
	double gen_expo(double lambda);
	double genrand_open();

	bool again;
	int n,j;
	double Cinitial;
	//double Ctotal=0,Dtotal=0,Vtot=0,p=0.01,lamba=5000,C;

	cout << "Enter the number of samples: ";

	cin >> n;

	cout << "Enter the intial amount in the reserve account: $";

	cin >> Cinitial;

do{

	double Ctotal=0,Dtotal=0,Vtot=0,p=0.01,lamba=5000,C;

	for(j=0; j<n; j++){//for loop for number of samples

	int D=50,Vtotal=0,S=0,Ttotal=0,Si,T[21],V[21],Ttemp=0,Vtemp=0,i;
	
	C = Cinitial; //set the intial amount for each sample

	double r=0.05;//the fixed interest rate for the reserve account
		
	for(i=1; i<=20; i++){//for loop for 20-year sample

	Si = gen_poisson(lamba); //number of refrigerators sold in year i
		
	S+=Si; //add number of refigerators sold in year i to the total

	T[i]=Si; //no. of new refrigerators under warranty for year i

	Ttotal+=T[i]; //add no. of refrigerators under warranty to the total

	if(i>5){ //After year 5, subtract out warranties for refrigerators older than 5 years
		Ttotal-=T[i-5];
	}

	
		V[i]=gen_binomial(Ttotal,p);

	
	Vtotal+=V[i]; //add no. of refrigerators that needs repairs to the total

	if(C>D*V[i])
		C = (C-D*V[i])*(1+r);//subtract out cost of repairs multiplied by the fixed interest rate
	else
		C-=D*V[i];
	}
	
	/*cout << "Sample: " << j+1 << endl;
	
	cout << "At the end of year "<< i-1 << endl;

	cout << "The number of refrigerators sold in this year is: " << Si << endl;

	cout << "The total number of refrigerators sold is: " << S << endl;

	cout << "The total number of refrigerators currently under warranty is: " << Ttotal << endl;

	cout << "The number of new refrigerators that need repairs in this year is: " << V[i-1] <<endl;

	cout << "The total number of refrigerators that need repairs is: " << Vtotal << endl;

	cout << "The total cost of repairs is: $" << D*Vtotal <<endl;

	cout << "The amount left in the reserve account is: $" << C <<endl;
	
	cout <<endl;*/

	Vtot+=Vtotal;//add up the total number of refrigerators that need repairs for all samples
	Dtotal+=D*Vtotal;//add up the total cost of repairs for all samples
	Ctotal+=C;//add up the total amount left in the reserve account for all samples

	}

	cout << "With an initial value in the reserve account of: $" << Cinitial <<endl;
	cout << "The average total number of refrigerators that need repairs is: " << Vtot/n <<endl;
	cout << "The average total cost of repairs is: $" << Dtotal/n <<endl;
	cout << "The average amount left in the reserve account is: $" << Ctotal/n <<endl;
	cout <<endl;

	if((Ctotal/n) > 100)
	{
		MAX_INVEST = Cinitial;
	    Cinitial = (MIN_INVEST + Cinitial)/2;
		//Cinitial = Cinitial - 1;
		again = true;
	}
	else if((Ctotal/n) < -100)
	{
		MIN_INVEST = Cinitial;
	    Cinitial = (MAX_INVEST + Cinitial)/2;
		//Cinitial = Cinitial + 1;	
		again = true;
	}
	else{
		again = false;
	/*cout << "With an initial value in the reserve account of: $" << Cinitial <<endl;
	cout << "The average total number of refrigerators that need repairs is: " << Vtot/n <<endl;
	cout << "The average total cost of repairs is: $" << Dtotal/n <<endl;
	cout << "The average amount left in the reserve account is: $" << Ctotal/n <<endl;
	cout <<endl;*/

	}
	//cin >> again;
  }while(again==true);


	exit(0);

}

void sgenrand(unsigned long seed)
{
    /* setting initial seeds to mt[N] using         */
    /* the generator Line 25 of Table 1 in          */
    /* [KNUTH 1981, The Art of Computer Programming */
    /*    Vol. 2 (2nd Ed.), pp102]                  */
    mt[0]= seed & 0xffffffff;
    for (mti=1; mti<N; mti++)
        mt[mti] = (69069 * mt[mti-1]) & 0xffffffff;
}

double genrand()
{
    unsigned long y;
    static unsigned long mag01[2]={0x0, MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (mti >= N) { /* generate N words at one time */
        int kk;

        if (mti == N+1)   /* if sgenrand() has not been called, */
            sgenrand((unsigned)time(0)); /* seed with the system time  */

        for (kk=0;kk<N-M;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        for (;kk<N-1;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        y = (mt[N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
        mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1];

        mti = 0;
    }
  
    y = mt[mti++];
    y ^= TEMPERING_SHIFT_U(y);
    y ^= TEMPERING_SHIFT_S(y) & TEMPERING_MASK_B;
    y ^= TEMPERING_SHIFT_T(y) & TEMPERING_MASK_C;
    y ^= TEMPERING_SHIFT_L(y);

    return ( (double)y / (unsigned long)0xffffffff ); /* reals */
    /* return y; */ /* for integer generation */
}

double genrand_open(){
	double x;
	while((x=genrand()) <= 0 || x >= 1);
	return x;
}

double gen_expo(double lambda)
{
	return -1*(log(genrand_open())/lambda);
}

int gen_poisson(double lamda)
{
	if(lamda == 0) return 0;

	int count;
	double timer = 0;
	for (count=0; timer < 1.0; count++)
	{
		timer = timer + gen_expo(lamda);
		              
    }
	return count-1;
}


int gen_bernoulli(double p)
{
	return genrand() <= p;
}

int gen_binomial(int n, double p)
{
	int i;
	int count = 0;
	for(i=0; i < n; i++)
		count += gen_bernoulli(p);
	return count;
}
