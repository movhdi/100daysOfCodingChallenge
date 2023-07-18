#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <chrono>
#include <cmath>
#include <bits/stdc++.h>
#include <random>

double calculate_PI_using_monte_carlo(std::uniform_real_distribution<>& dis,std::mt19937& gen, int64_t limit)
{
    int64_t point_in_circle{0};
    double pi;
    double x{0.0},y{0.0};
    
    for(int64_t i{0}; i <= limit; i++)
    {
        x = dis(gen);
        y = dis(gen);
        if(y*y + x*x <= 1)
        {
            point_in_circle++;
        }
    }
    pi = 4.0*(double)point_in_circle/(double)limit;
    return pi;
}

double calculate_PI(double n)
{
    double calculated_pi{1.0f};
    for(double i = 1 ; i <= n; i++)
    {
        calculated_pi = calculated_pi + pow(-1.0,i)/(2.0f*i+1);
    }
    return 4.0f*calculated_pi;
}

int main(int argc, char * argv[])
{
    std::cout<< std::fixed << std::setprecision(20) << calculate_PI(1000000000.0) << std::endl;
    // 3.141592653589793238462643383279502884197 -> result from internet
    // 3.14159265458805059268 result from the program
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0,1.0);

    std::cout << calculate_PI_using_monte_carlo(dis,gen, 1000000) << std::endl;
    
    (void) argc;
    (void) argv;
    return 0;
}