#ifndef U_GRAPH_HPP
#define U_GRAPH_HPP

#include <cstddef>
#include <vector>
#include <set>

#include "../core/core.hpp"
#include "./spanning_tree.hpp"
#include "./digraph.hpp"

/*
 * TODO:
 * - rename namespace to flow graph
 * - use smart pointers
 */

// undirected graph
namespace u_graph {

/**
 * An edge in an undirected graph where (l , r) == (r, l)
 */
class Edge {
  std::size_t l;
  std::size_t r;
  core::color c;

public:
  Edge(std::size_t l, std::size_t r , core::color c=core::color::black):
    l(std::min(l,r)), r(std::max(l,r)){
    this->c = c;
  }

// spaceship operator
friend constexpr auto operator<=>(Edge, Edge) = default;

  core::color get_color() const { return this->c; }
  bool is_black() const { return this->c == core::color::black; }
  std::size_t left() const { return this->l; }
  std::size_t right() const { return this->r; }

  void set_left(std::size_t l) { this->l = l; }
  void set_right(std::size_t r) { this->r = r; }
};

class Vertex {
  // the indexes of edges in CFG
  // TODO: make this a vector
  std::set<std::size_t> edge_idxs;

public:
  Vertex();

  // takes an edge index in the flow graph
  // TODO rename to add_edge_idx
  void add_edge_idx(std::size_t e_idx);
  void del_edge_idx(std::size_t e_idx);

  std::set<std::size_t>const& get_adjacent_vertices() const;
};

/*
 * Flow Graph
 * ==========
 */
  
/**
 * this undirected graph is actually a flow graph
 * undirected
 * edge from end to start will always be a back-edge
 */
class FlowGraph {
  std::vector<Vertex> adj_list;

  // edges in a list
  std::vector<Edge> edges;
  
  // start node is always zero
  // stop node is always N+1
  // std::set<std::size_t> start_nodes;
  // std::set<std::size_t> end_nodes;
  std::size_t start_node_id{}; // static data member

  /*
    private methods
   */
  std::size_t stop_node_internal_idx();
  std::size_t size_internal();

  Vertex& start_node_internal();
  Vertex& stop_node_internal();
  Vertex const& get_vertex_internal(std::size_t vertex) const;
  std::set<std::size_t> const& get_adjacent_vertices_internal(std::size_t vertex) const;

public:
  // constructor(s)
  // --------------


  // CFG();
  // TODO: from gfa
  // CFG(std::size_t initial_len=2); // from di graph or from gfa
  FlowGraph(std::size_t initial_len=2);
  FlowGraph(digraph::DiGraph const& di_graph);

  // getters
  // -------
  
  std::size_t size();
  // get an immutable reference to a vertex
  Vertex const& get_vertex(std::size_t vertex) const;
  std::set<std::size_t> const& get_adjacent_vertices(std::size_t vertex) const;
  std::set<std::size_t> get_adjacent_vertices_n(std::size_t vertex) const;

  
  // setters
  // -------

  void add_edge(std::size_t n1, std::size_t n2, core::color c=core::color::black);

  // get a mutable reference to a vertex
  Vertex& get_vertex_mut(std::size_t vertex);

  // mark/set a vertex as a start node
  void set_start_node(std::size_t vertex);
  void set_stop_node(std::size_t vertex);

  spanning_tree::Tree compute_spanning_tree();

  // split any node with > 1 incoming and >1 outgoing edges
  // into two nodes connected by a single (gray) edge
  void make_bi_edged();

  void print_dot();
};

}; // namespace u_graph
#endif