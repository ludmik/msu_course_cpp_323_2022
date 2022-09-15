#include <iostream>
#include <vector>

int kVerticesCount = 14;

class Graph {
  using VertexId = int;
  using EdgeId = int;
  struct Vertex {
   public:
    explicit Vertex(VertexId id) : id_(id) {}
    VertexId id() const { return id_; }

   private:
    VertexId id_ = 0;
  };
  struct Edge {
   public:
    Edge(EdgeId id, VertexId from_vertex_id, VertexId to_vertex_id)
        : id_(id),
          from_vertex_id_(from_vertex_id),
          to_vertex_id_(to_vertex_id) {}
    EdgeId id() const { return id_; }
    VertexId from_vertex_id() const { return from_vertex_id_; }
    VertexId to_vertex_id() const { return to_vertex_id_; }

   private:
    EdgeId id_ = 0;
    VertexId from_vertex_id_ = 0;
    VertexId to_vertex_id_ = 0;
  };
  std::vector<Vertex> vertexes;
  std::vector<Edge> edges;

 public:
  void add_vertex();
  void add_edge(VertexId from_vertex_id, VertexId to_vertex_id);
  void print_vertexes() {
    std::cout << "Vertexes:";
    for (int i = 0; i < vertexes.size(); ++i) {
      std::cout << vertexes[i].id() << " ";
    }
    std::cout << std::endl;
  }
  void print_edges() {
    std::cout << "Edges:" << std::endl;
    for (int i = 0; i < edges.size(); ++i) {
      std::cout << "edge " << edges[i].id() << " : ";
      std::cout << "(" << edges[i].from_vertex_id() << ", "
                << edges[i].to_vertex_id() << ")" << std::endl;
    }
  }
};

void Graph::add_vertex() {
  struct Vertex vertex(vertexes.size());
  vertexes.push_back(vertex);
}

void Graph::add_edge(VertexId from_vertex_id, VertexId to_vertex_id) {
  struct Edge edge(edges.size(), from_vertex_id, to_vertex_id);
  edges.push_back(edge);
}

int main() {
  auto graph = Graph();

  for (int i = 0; i < kVerticesCount; i++) {
    graph.add_vertex();
  }

  graph.add_edge(0, 1);
  graph.add_edge(0, 2);
  graph.add_edge(0, 3);
  graph.add_edge(1, 4);
  graph.add_edge(1, 5);
  graph.add_edge(1, 6);
  graph.add_edge(2, 7);
  graph.add_edge(2, 8);
  graph.add_edge(3, 9);
  graph.add_edge(4, 10);
  graph.add_edge(5, 10);
  graph.add_edge(6, 10);
  graph.add_edge(7, 11);
  graph.add_edge(8, 11);
  graph.add_edge(9, 12);
  graph.add_edge(10, 13);
  graph.add_edge(11, 13);
  graph.add_edge(12, 13);

  return 0;
}
