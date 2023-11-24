#include <iostream>
#include <map>

void print_placement(const std::map<size_t, std::string> &race)
{
    std::cout << "Race placement:" << '\n';
    for (const auto &[rank, name] : race)
    {
        std::cout << rank << " : " << name << std::endl;
    }
}


int main()
{
    std::map<size_t, std::string> race_placement{{1, "skyler"},
                                                 {2, "Randall"},
                                                 {3, "Rebecca"},
                                                 {4, "Django"},
                                                 {5, "Dr. King Schultz"},
                                                 {6, "Mahdi"}};
    print_placement(race_placement);
    {
        auto a = race_placement.extract(2);
        auto b = race_placement.extract(6);
        if (!a.empty() && !b.empty())
        {
            std::swap(a.key(), b.key());
        }
        race_placement.insert(std::move(a));
        race_placement.insert(std::move(b));
    }
    print_placement(race_placement);
    return 0;
}
