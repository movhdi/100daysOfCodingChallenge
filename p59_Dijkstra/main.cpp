#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <utility>
#include <limits>
#include <queue>
#include <set>
#include <algorithm>

template <typename vertex, typename weight>
class graph
{
private:
    std::map<vertex, std::vector<std::pair<vertex, weight>>> graph_vertices;

public:
    graph()
    {
    }
    ~graph()
    {
    }
    void add_edge(vertex src, vertex dest, weight cost)
    {
        graph_vertices[src].emplace_back(std::make_pair(dest, cost));
        graph_vertices[dest].emplace_back(std::make_pair(src, cost));
    }
    
    std::vector<vertex> vertices() const
    {
        std::vector<vertex> result;
        for (const auto &kvp : graph_vertices)
        {
            result.push_back(kvp.first);
        }
        return result;
    }
    
    std::vector<std::pair<vertex, weight>> neighbors(vertex const & v) const
    {
        auto pos = graph_vertices.find(v);
        if (pos == graph_vertices.end())
        {
            throw std::runtime_error("vertex not found");
        }
        return pos->second;
    }

    size_t graph_size() const
    {
        return this->graph_vertices.size();
    }
};

template <typename vertex, typename weight>
void shortest_path(graph<vertex, weight> const &g, vertex const src, std::map<vertex, weight> &min_distance, std::map<vertex, vertex> &previous)
{
    auto const n = g.graph_size();
    auto const vertices = g.vertices();

    min_distance.clear();
    previous.clear();

    min_distance[src] = 0;
    auto const Infinity = std::numeric_limits<weight>::infinity();
    for (auto & node : min_distance)
    {
        node.second = Infinity;
    }

    std::set<std::pair<weight, vertex>> vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[src], src));
    
    while(!vertex_queue.empty())
    {
        auto dist = vertex_queue.begin()->first;
        auto u = vertex_queue.begin()->second;

        vertex_queue.erase(std::begin(vertex_queue));

        auto const & neighbors = g.neighbors(u);
        for (auto const & neighbor : neighbors)
        {
            auto v = neighbor.first;
            auto w = neighbor.second;
            auto dist_via_u = dist + w;
            if (dist_via_u < min_distance[v])
            {
                vertex_queue.erase(std::make_pair(min_distance[v], v));
                min_distance[v] = dist_via_u;
                previous[v] = u;
                vertex_queue.insert(std::make_pair(min_distance[v], v));
            }
        }
    }
}

template <typename vertex>
void build_path(std::map<vertex, vertex> const & previous, vertex const v, std::vector<vertex> & result)
{
    result.push_back(v);
    auto pos = previous.find(v);
    if (pos == std::end(previous))
    {
        return;
    }
    build_path(previous, pos->second, result);
}

template<typename vertex>
std::vector<vertex> build_path(std::map<vertex, vertex> const & previous, vertex const v)
{
    std::vector<vertex> result;
    build_path(previous, v, result);
    std::reverse(std::begin(result), std::end(result));
    return result;
}

template <typename Vertex>
void print_path(std::vector<Vertex> const &path)
{
    for (size_t i = 0; i < path.size(); ++i)
    {
        std::cout << path[i];
        if (i < path.size() - 1)
            std::cout << " -> ";
    }
}
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