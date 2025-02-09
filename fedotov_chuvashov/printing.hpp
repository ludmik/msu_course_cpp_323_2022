#pragma once
#include <string>
#include "graph.hpp"

namespace printing {
std::string print_edge_color(Graph::Edge::Color color);

namespace json {
std::string print_vertex(const Graph::Vertex& vertex, const Graph& graph);

std::string print_edge(const Graph::Edge& edge);

std::string print_graph(const Graph& graph);
}  // namespace json
}  // namespace printing
