#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <string_view>
#include <vector>


class weasel
{
    std::string target;
    size_t numOffspring{100};
    double mutateProb{5.0};
    std::string_view src{"ABCDEFGHIJKLMNOPQRSTUVWXYZ "};
    std::uniform_int_distribution<int> chardist;
    std::uniform_real_distribution<double> ratedist;
    std::mt19937 rndeng;

public:
    weasel() = delete;
    weasel(std::string t) : target(t), chardist(0, 26), ratedist(0, 100)
    {
        // a std::random_device could be used to generate seed data(seq)
        std::random_device rd;
        std::array<int, std::mt19937::state_size> seq;
        std::generate(std::begin(seq), std::end(seq), std::ref(rd));
        std::seed_seq seeds(std::begin(seq), std::end(seq));
        rndeng.seed(seeds);
    }
    ~weasel()
    {
    }

    void run(size_t runtimes)
    {
        std::string current = make_random();
        size_t gen{};
        std::cout << "Hello from run method" << std::endl;
        std::cout << std::boolalpha << (current != target) << std::endl;
        while (current != target)
        {
            auto offspring = mutate(current);
            current = fittest(offspring);
            ++gen;
            std::cout << std::setw(4) << std::left << gen << std::setw(target.size()) << current << std::endl;
        }
        (void)runtimes;
    }

private:
    std::string fittest(std::vector<std::string> population) const
    {
        std::string result;
        size_t max_compatibility{};
        for (auto const offspring : population)
        {
            size_t m{};
            for (size_t i = 0; i < target.size(); i++)
            {
                if (offspring[i] == target[i])
                {
                    ++m;
                }
            }
            if (m > max_compatibility)
            {
                max_compatibility = m;
                result = offspring;
            }
        }
        return result;
    }

    std::vector<std::string> mutate(std::string state)
    {
        // std::cout << "Hello from mutate method" << std::endl;
        std::vector<std::string> generation(numOffspring);
        for (size_t i = 0; i < numOffspring; ++i)
        {
            // std::cout << "Hello from outer loop of mutate i = " << i << std::endl;
            std::string offspring;
            offspring.resize(target.size());
            for (size_t j = 0; j < target.size(); j++)
            {
                // std::cout << "Hello from inner loop of mutate j = " << j << std::endl;
                auto prob = ratedist(rndeng);
                if (prob <= mutateProb)
                {
                    offspring[j] = src[chardist(rndeng)];
                }
                else
                {
                    offspring[j] = state[j];
                }
            }
            generation.emplace_back(offspring);
        }
        return generation;
    }

    std::string make_random()
    {
        std::string result;
        for (size_t j = 0; j < target.size(); ++j)
        {
            result += src[chardist(rndeng)];
        }
        return result;
    }
};

int main()
{
    weasel w("METHINKS IT IS LIKE A WEASEL");
    w.run(100);
}
