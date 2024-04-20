#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <array>
#include <algorithm>
#include <thread>

class universe
{
public:
    enum class seed
    {
        random,
        ten_cell_row
    };

public:
    universe(size_t coloumn, size_t row) : coloumns{coloumn}, rows{row}, grid(coloumns*rows), dist(0, 4)
    {
        std::random_device rd;
        auto seedData = std::array<int, std::mt19937::state_size>{};
        std::generate(std::begin(seedData), std::end(seedData), std::ref(rd));
        std::seed_seq seq(seedData.begin(), seedData.end());
        mt.seed(seq);
    }

    void run(seed const mode, size_t const iterations, std::chrono::milliseconds const dur = std::chrono::milliseconds(100))
    {
        reset();
        initialize();
        display();
        size_t i{};
        do
        {
            next_generation();
            display();
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(dur);
        } while (iterations == 0 || i++ < iterations);
    }

    void reset()
    {
        for (size_t r = 0; r < rows; ++r)
        {
            for (size_t c = 0; c < coloumns; ++c)
            {
                cell(c,r) = dead;
            }
        }
    }
    ~universe()
    { 
    }

private:
    void initialize(void)
    {
        for (size_t i = 0; i < grid.size(); i++)
        {
            grid[i] = (dist(mt) == 0 ? alive : dead);
        }
    }

    size_t count_neighbors(size_t const c, size_t const r)
    {
        //1
        if (r == 0 && c == 0)
        {
            return count_alive(cell(1,0), cell(1,1), cell(0,1));
        }
        //2
        if (r == 0 && c == (coloumns - 1))
        {
            return count_alive(cell(coloumns - 2, 0), cell(coloumns - 2, 1), cell(coloumns - 1, 1));
        }
        //3
        if (r == (rows - 1) && c == (coloumns -1))
        {
            return count_alive(cell(coloumns - 2, rows - 1), cell(coloumns -2, rows -2), cell(coloumns -1, rows -2));
        }
        //4
        if (r == (rows - 1) && c == 0)
        {
            return count_alive(cell(0, rows -2), cell(1, rows -2), cell(1, rows -1));
        }
        //5
        if (r == 0 &&  c > 0 && c < (coloumns - 1))
        {
            return count_alive(cell(c-1, 0),cell(c-1,1),cell(c,1),cell(c+1,1),cell(c+1,0));
        }
        //6
        if (r > 0 && r < (rows - 1) && c == 0)
        {
            return count_alive(cell(0,r-1),cell(1,r-1),cell(1,r),cell(1,r+1),cell(0,r+1));
        }
        //7
        if (r == (rows - 1) && c > 0 && c < (coloumns - 1))
        {
            return count_alive(cell(c-1,r),cell(c-1,r-1),cell(c,r-1),cell(c+1,r-1),cell(c+1,r));
        }
        //8
        if (r > 0 && r < (rows - 1) && c == (coloumns - 1))
        {
            return count_alive(cell(c,r-1),cell(c-1,r-1),cell(c-1,r),cell(c-1,r+1),cell(c,r+1));
        }
        //9
        return count_alive(cell(c-1,r-1),cell(c,r-1),cell(c+1,r-1),cell(c+1,r),cell(c+1,r+1),cell(c,r+1),cell(c-1,r+1),cell(c-1,r));
    }

    void next_generation()
    {
        std::vector<unsigned char> newgrid(grid.size());

        for (size_t r = 0; r < rows; ++r)
        {
            for (size_t c = 0; c < coloumns; ++c)
            {
                auto count = count_neighbors(c,r);
                if (count == 2 || count == 3)
                {
                    if (cell(c,r) == alive)
                    {
                        newgrid[r*coloumns + c] = alive;
                    }
                    else
                    {
                        newgrid[r*coloumns + c] = dead;
                    }
                }else
                {
                    newgrid[r*coloumns + c] = dead;
                }  
            }
        }
        grid.swap(newgrid);
    }

    void display()
    {
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < coloumns; j++)
            {
                std::cout << ((cell(j, i) == 1) ? '*' : ' ');
            }
            std::cout << std::endl;
        }
    }

    size_t count_alive()
    {
        return 0;
    }

    template<typename T1, typename... T>
    size_t count_alive(T1 s, T... ts)
    {
        return s + count_alive(ts...);
    }

    unsigned char &cell(size_t const c, size_t const r)
    {
        return grid[r * coloumns + c];
    }

private:
    size_t rows;
    size_t coloumns;

    std::vector<unsigned char> grid;
    const unsigned char alive = 1;
    const unsigned char dead = 0;

    std::uniform_int_distribution<> dist;
    std::mt19937 mt;
};

int main()
{
    using namespace std::chrono_literals;
    universe u(50, 20);
    u.run(universe::seed::random, 100, 100ms);
    return 0;
}