#include <iostream>
#include <map>
#include <mutex>
#include <set>
#include <vector>
#include <chrono>


unsigned long long int collatz_length(long unsigned int& collatz_input)
{
    unsigned long long int length{0};
    unsigned long long int n{collatz_input};
    while(n != 1)
    {
        if(n % 2 == 0)
        {
            n = n/2;
        }else if(n % 2 != 0)
        {
            n = 3*n +1;
        }
        length++;
    }
    return length;
}

std::pair<unsigned long long, long> collatz_length1(long unsigned int limit)
{
    long length = 0;
    unsigned long long number = 0;
    std::vector<int> cache(limit + 1, 0);
    for (unsigned long long i = 2; i <= limit; i++)
    {
        auto n = i;
        long steps = 0;
        while (n != 1 && n >= i)
        {
            if ((n % 2) == 0) n = n / 2;
            else n = n * 3 + 1;
            steps++;
        }
        cache[i] = steps + cache[n];
        if (cache[i] > length)
        {
            length = cache[i];
            number = i;
        }
    }
    return std::make_pair(number, length);
}

int main(int argc , char * argv[])
{
    unsigned long long int temp_length{0};
    std::pair<unsigned long long, long> temp_length_pair;
    unsigned long long int max_length{0};
    auto start = std::chrono::high_resolution_clock::now();
    for(long unsigned int i = 4; i <= 1000000; i++)
    {
        temp_length = collatz_length(i);
        if(max_length < temp_length)
        {
            max_length = temp_length;
        }


    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "(1st algorithm) maximum length of collatz sequence between numbers up to 1000,000.00 is: " << max_length << std::endl;
    std::cout << "Run time duration of the 1st algorithm: " << duration.count() << "\n\n";

    start = std::chrono::high_resolution_clock::now();
    temp_length_pair = collatz_length1(1000000);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    
    std::cout << "(2nd algorithm) maximum length of collatz sequence between numbers up to 1000,000.00 is: " << temp_length_pair.second << std::endl;
    std::cout << "Run time duration of the 1st algorithm: " << duration.count() << std::endl;

    (void) argc;
    (void) argv;
    return 0;
}