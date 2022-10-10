#pragma once

#include <string>
#include "graph.hpp"

namespace printing {
namespace json {
std::string print_vertex(const Graph::Vertex& vertex, const Graph& graph);
std::string print_edge(const Graph::Edge& edge, const Graph& graph);
std::string print_graph(const Graph& graph);
}  // namespace json

void write_to_file(const std::string graph_repr, const std::string file_name);
}  // namespace printing
