#include <iostream>
#include <string>

int main()
{
    graph<char, double> g;
    g.add_edge('A', 'B', 7);
    g.add_edge('A', 'C', 9);
    g.add_edge('A', 'F', 14);
    g.add_edge('B', 'C', 10);
    g.add_edge('B', 'D', 15);
    g.add_edge('C', 'D', 11);
    g.add_edge('C', 'F', 2);
    g.add_edge('D', 'E', 6);
    g.add_edge('E', 'F', 9);
    char source = 'A';
    std::map<char, double> min_distance;
    std::map<char, char> previous;
    shortest_path(g, source, min_distance, previous);
    for (auto const &kvp : min_distance)
    {
        std::cout << source << " -> " << kvp.first << " : "
                  << kvp.second << '\t';
        print_path(build_path(previous, kvp.first));
        std::cout << std::endl;
    }
}