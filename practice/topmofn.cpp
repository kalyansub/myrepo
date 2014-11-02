/* 1) Generate a random list/array of N integers and save it to a text file, one integer per line.
 * N will be a non-negative integer value.
 * 2) Select the M largest integers out of the N integer values that were generated in step 1.  
 * 0 <= M <= N.  
 * This step should be parallelized and use T concurrent threads.
 * 3) Output the list/array of the M largest integers to a text file 
 * (not the same file as the one created in step 1). 
 *  The arguments will be specified in the following order:
 * MyApp N M T
 * There is no need to validate the arguments, only valid input will be used in the following ranges:
 * N: [0, Integer.MAX_VALUE]
 * M: [0, N]
 * T: [0, Integer.MAX_VALUE]
 *
 * $Author$: Kalyan Subramanian
 * $Date$:   Oct 20th, 2014
 * $email$:  kalyan dot sub at gmail dot com
*/ 

#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <pthread.h>
#include <cassert>

using namespace std;

// Global vector for merged results
vector<int> result;

bool mycomparefn(int i,int j) { return (i>j); }
 
// Setup predicate object required by patrition algorithm ...
struct Pred 
{
    Pred(int nth) : m_nth(nth) {};
    bool operator()(int k) { return k >= m_nth; }
    int m_nth;
};

// struct to enable passing parameters to thread function...
struct ThreadParams
{
    vector<int> v_sub;
    int m; 
};

// A helper class to implement pthread_mutex lock and automatically unlock...
class Lock
{
    public:
        Lock()
        {   
            pthread_mutex_init(&m_lock, NULL);
            int rval = pthread_mutex_lock(&m_lock);
            assert(rval == 0);
        }
        ~Lock()
        {  
            int rval = pthread_mutex_unlock(&m_lock); 
            assert(rval == 0);
        }

    private:
        // Disallow copy ctor and = operator:
        Lock( const Lock& from );
        Lock& operator=( const Lock &rhs );

        pthread_mutex_t m_lock;
};

// Function top_m() is the thread function executed by every thread spawned, it takes a thread context
// as an input parameter and de-references it to get the sub-vector and integer m as inputs; it then
// performs a 'top m' operation and writes it's result to a global 'result' vector with a mutex.
void* top_m(void* threadContext)
{
    ThreadParams* tpar = (ThreadParams* )threadContext;
    vector<int> v_sub = tpar->v_sub;
    int         m     = tpar->m;
 
    int len = 0;
   
    // Shuffle the nth integer to be nth from the end of the vector...
    std::nth_element(v_sub.begin(), v_sub.end() - m, v_sub.end());

    // Modify the range, such that the first n integers are  >=  the mth. integer...
    std::partition(v_sub.begin(), v_sub.end(), Pred(*(v_sub.end() - m)));
    
    int c = 0, id = pthread_self();
    {
        Lock();
        for (auto it = v_sub.begin(); it != v_sub.end(); ++it, ++c)
        {
            if (c == m) break;
            result.push_back(*it); 
        }
        std::sort(result.begin(), result.end(), mycomparefn);
    }
}

// main() driver porgam for the top_m() function: handles command line arguments, 
// generates 'n' random numbers into a file 'randint.txt', spawns 't' threads and waits for 
// them to complete delivering the top 'm' integers before merging the sub vector results into 
// a final result which is written to a file, 'results.txt'.
int main(int argc, char* argv[])
{
    int n, m, t;
    
    if (argc < 4)
    {
        cout << "usage: " << argv[0] << " N (number of rand. integers)," 
                          << " M (find largest M of these integers)," 
                          << " T (number of threads to use)" << endl;

        return -1;
    }

    n = atoi(argv[1]); // these many random integers
    m = atoi(argv[2]); // find the largest m of these
    t = atoi(argv[3]); // use t threads 

    //cout << "Read: n = " << n << ", m = " << m << ", t = " << t << endl;

    // Generate a uniform random distribution of integers in [0,n]:
    uniform_int_distribution<int> dist(0,n);

    default_random_engine eng;
    ofstream ofs;

    //Write the uniform distribution of n integers to a file:
    ofs.open("randints.txt");
    for(int i = 0; i < n; ++i)
    {
        ofs << dist(eng) << endl;
    }

    // read from file, populate vector with random integers read: 
    ifstream ifs("randints.txt");
    if (!ifs)
    {
        cout << "Unable to open input file.."<< endl;
        return -1;
    }
    vector<int> v;
    copy(istream_iterator<int>(ifs), istream_iterator<int>(), back_inserter(v));

    int subVecLength = (n/t); 
    int nsubVecs = (n%t == 0)? t: (t + 1);

    vector<int> v_sub[nsubVecs];
    // Split the vector of ints into suitable # of sub vectors, to be farmed off to 1 thread each...
    for(int i = 0; i < nsubVecs; ++i)
    {
        int counter = 0; 
        for (auto it = v.begin() + i*subVecLength ; it != v.end(); ++it, ++counter)
        {
            if (counter == subVecLength) break;
            v_sub[i].push_back(*it);
        }
    }   

    ThreadParams tpar[nsubVecs];
    for(int i = 0; i < nsubVecs; ++i)
    {
        tpar[i].v_sub = v_sub[i];
        if( m <= subVecLength)
            tpar[i].m     = m;
        else
            tpar[i].m    = subVecLength;
    }

    pthread_t threads[nsubVecs];
    int rv;
    for(int i = 0; i < nsubVecs; ++i)
    {
        rv = pthread_create(&threads[i], NULL, top_m, &tpar[i]); 
        if (rv != 0)
        {
            cout << "Error creating pthread!" << endl;
        }
    }
    
    // Resize the output result vector based on input parameters...
    result.resize(m*nsubVecs);

    for(int i = 0; i < t; ++i)
    {
        pthread_join(threads[i], NULL);
    }
#if 0
    // Find the top m elements of the merged result to get the final answer...
    std::nth_element(result.begin(), result.end() - m, result.end());
    std::partition(result.begin(), result.end(), Pred(*(result.end() - m)));
    int c1 = 0;
    for (auto it = result.begin(); it != result.end(); ++it, ++c1)
    {
        if (c1 == m) break;
    }
#endif
    ofstream rfs("results.txt");
    for(int i = 0; i < m; ++i)
    {
        rfs << result[i] << endl;
    }
    
    ofs.close();
    ifs.close();
    rfs.close();

    cout << "Done: see file results.txt for output\n";
    return 0;
}
