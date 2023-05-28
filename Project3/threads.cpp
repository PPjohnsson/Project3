#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
using namespace std;
using namespace std::chrono;




atomic <int> raknare = 0 ;


bool isPrime(int num)
{
    if (num <= 1)
        return false; 
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0)
            return false;  
    }
    return true;  
}



void seriellt(int st, int ed)
{
    int local_count = 0;
    for (int i = st; i <= ed; i++) {

        if (isPrime(i)) 
            local_count++;
            
    }
    raknare += local_count;
   
}

int main()
{


    auto t0 = steady_clock::now();

    thread my_thread(seriellt, 0, 62500); 
    thread my_thread_2(seriellt, 62500, 125000); 
    thread my_thread_3(seriellt, 125000, 187500); 
    thread my_thread_4(seriellt, 187500, 250000); 
    thread my_thread_5(seriellt, 250000, 312500);
    thread my_thread_6(seriellt, 312500, 375000); 
    thread my_thread_7(seriellt, 375000, 437500); 
    thread my_thread_8(seriellt, 437500, 500000); 
    thread my_thread_9(seriellt, 500000, 562500); 
    thread my_thread_10(seriellt, 562500, 625000); 
    thread my_thread_11(seriellt, 562500, 625000); 
    thread my_thread_12(seriellt, 687500, 750000); 
    thread my_thread_13(seriellt, 750000, 812500); 
    thread my_thread_14(seriellt, 812500, 875000); 
    thread my_thread_15(seriellt, 875000, 937500); 
    thread my_thread_16(seriellt, 937500, 1000000); 


    my_thread.join();
    my_thread_2.join();
    my_thread_3.join();
    my_thread_4.join();
    my_thread_5.join();
    my_thread_6.join();
    my_thread_7.join();
    my_thread_8.join();
    my_thread_9.join();
    my_thread_10.join();
    my_thread_11.join();
    my_thread_12.join();
    my_thread_13.join();
    my_thread_14.join();
    my_thread_15.join();
    my_thread_16.join();


    duration<double> duration_sec = steady_clock::now() - t0;
    cout << "Number of primes found: "<< raknare << endl;
    cout << "Time: " << duration_sec.count() << " sec" << endl;
    cout << endl;
}