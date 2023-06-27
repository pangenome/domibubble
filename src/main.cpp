#include <iostream>

#include "./graph/graph.hpp"
#include "./graph/spanning_tree.hpp"
#include "./vst/vst.hpp"


u_graph::CFG g1() {
  u_graph::CFG g;

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.add_edge(3, 1);

  g.set_start_node(0);
  g.set_stop_node(3);

  return g;
};

// overlapping
u_graph::CFG g6() {
  u_graph::CFG g;

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.add_edge(3, 4);
  g.add_edge(4, 2);
  g.add_edge(4, 5);
  g.add_edge(1, 5);
  g.add_edge(5, 6);

  g.set_start_node(0);
  g.set_stop_node(6);

  return g;
};

// big
u_graph::CFG g2() {
  u_graph::CFG g;
  g = u_graph::CFG();

  g.add_edge(0, 3);
  g.add_edge(0, 1);
  g.add_edge(3, 2);
  g.add_edge(1, 2);

  g.add_edge(2, 9);
  g.add_edge(2, 8);

  g.add_edge(1, 4);
  g.add_edge(1, 6);
  g.add_edge(1, 7);

  g.add_edge(5, 4);
  g.add_edge(7, 4);

  g.add_edge(4, 6);
  g.add_edge(7, 6);

  g.set_start_node(0);
  g.set_stop_node(5);
  g.set_stop_node(8);
  g.set_stop_node(9);

  return g;
};

// diamond
u_graph::CFG g3() {
  u_graph::CFG g;
  g = u_graph::CFG();

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(1, 3);
  g.add_edge(2, 4);
  g.add_edge(3, 4);
  g.add_edge(4, 5);

  g.set_start_node(0);
  g.set_stop_node(5);

  return g;
}

// overleaf fig 1
// missed by bubble finder
u_graph::CFG g4() {
  u_graph::CFG g;
  g = u_graph::CFG();

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(1, 3);
  g.add_edge(2, 4);
  g.add_edge(3, 4);
  g.add_edge(1, 5);
  g.add_edge(4, 5);


  g.set_start_node(0);
  g.set_stop_node(5);

  return g;
}

const bool DEBUG = true;

int main() {
    
  u_graph::CFG g = g6();
  if (DEBUG) { 
    std::cout << "Input Graph" << "\n\n";
    g.print_dot();
  }

  spanning_tree::Tree t = g.compute_spanning_tree();
  if (DEBUG) { 
    std::cout << "\n\n" << "Spanning tree" << "\n\n";
    t.print_dot();
  }
  
  vst::cycle_equiv(t);
  if (DEBUG) { 
    std::cout << "\n\n" << "Updated Spanning tree" << "\n\n";
    t.print_dot();
  }
  
  vst::VST tv = vst::VST(t);
  if (DEBUG) { 
    std::cout << "\n\n" << "VST" << "\n\n";
    tv.print_dot();
  }
  return  0;
}