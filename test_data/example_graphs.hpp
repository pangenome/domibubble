#include "./graph/digraph.hpp"
#include "./graph/u_graph.hpp"

u_graph::FlowGraph g1() {
  u_graph::FlowGraph g;

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.add_edge(3, 1);

  g.set_start_node(0);
  g.set_stop_node(3);

  return g;
};

// big
u_graph::FlowGraph g2() {
  u_graph::FlowGraph g;
  g = u_graph::FlowGraph();

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
u_graph::FlowGraph g3() {
  u_graph::FlowGraph g;
  g = u_graph::FlowGraph();

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
u_graph::FlowGraph g4() {
  u_graph::FlowGraph g;
  g = u_graph::FlowGraph();

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

// fig 1 a paper
// diamond
u_graph::FlowGraph g5() {
  u_graph::FlowGraph g;
  g = u_graph::FlowGraph();

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(1, 3);
  g.add_edge(2, 4);
  g.add_edge(3, 4);
  g.add_edge(4, 5);
  g.add_edge(3, 5);
  g.add_edge(6, 5);

  g.set_start_node(0);
  g.set_stop_node(6);

  return g;
}

// overlapping
u_graph::FlowGraph g6() {
  u_graph::FlowGraph g;

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

digraph::DiGraph g7() {
  digraph::DiGraph g(7);

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.add_edge(3, 4);
  g.add_edge(4, 2);
  g.add_edge(4, 5);
  g.add_edge(1, 5);
  g.add_edge(5, 6);

  g.add_edge(5, 7);
  g.add_edge(6, 7);

  g.add_edge(7, 8);

  g.add_start_node(0);
  g.add_stop_node(6);

  return g;

}

digraph::DiGraph g8() {
  digraph::DiGraph g(5);

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(0, 2);
  g.add_edge(2, 3);
  g.add_edge(2, 4);

  g.add_start_node(0);
  g.add_stop_node(3);
  g.add_stop_node(4);

  return g;
}

// from ekg
digraph::DiGraph g9() {
  digraph::DiGraph g(16);

  g.add_edge(0, 1);

  g.add_edge(1, 3);
  g.add_edge(3, 5);

  g.add_edge(5, 7);
  g.add_edge(5, 9);
  g.add_edge(7, 11);
  g.add_edge(9, 11);
  g.add_edge(11, 13);
  g.add_edge(13, 1);

  g.add_edge(0, 2);
  g.add_edge(2, 4);
  g.add_edge(4, 6);
  g.add_edge(4, 8);
  g.add_edge(6, 10);
  g.add_edge(10, 8);
  g.add_edge(10, 12);
  g.add_edge(8, 12);
  g.add_edge(12, 14);
  g.add_edge(14, 15);
  g.add_edge(15, 0);
  g.add_edge(13, 15);

  g.add_start_node(0);
  g.add_stop_node(15);

  return g;
}

// non planar 1
digraph::DiGraph g10() {
  digraph::DiGraph g(5);

  g.add_edge(0, 1);

  g.add_edge(1, 3);
  g.add_edge(1, 2);

  g.add_edge(3, 4);
  g.add_edge(2, 4);
  g.add_edge(0, 4);
  g.add_edge(3, 5);
  g.add_edge(2, 5);

  g.add_start_node(0);
  g.add_stop_node(5);

  return g;
}

// non planar 2
digraph::DiGraph g11() {
  digraph::DiGraph g(5);

  g.add_edge(0, 1);
  g.add_edge(0, 3);
  g.add_edge(1, 3);
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.add_edge(2, 4);

  g.add_start_node(0);
  g.add_stop_node(4);

  return g;
}

digraph::DiGraph g12() {
  digraph::DiGraph g;

  g.add_edge(0, 1);
    g.add_edge(0, 4);
  g.add_edge(1, 2);
  g.add_edge(1, 3);

  g.add_edge(2, 3);
  g.add_edge(2, 4);

  g.add_start_node(0);
  g.add_stop_node(4);

  return g;
};

digraph::DiGraph g13() {
  digraph::DiGraph g;

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.add_edge(3, 1);
  g.add_edge(3, 4);

  g.add_start_node(0);
  g.add_stop_node(4);

  return g;
};

digraph::DiGraph g14() {
  digraph::DiGraph g;

  g.add_edge(0, 1);

  g.add_edge(1, 2);
  g.add_edge(1, 3);

  g.add_edge(2, 4);
  g.add_edge(3, 4);

  g.add_edge(4, 5);

  g.add_start_node(0);
  g.add_stop_node(5);

  return g;
};

digraph::DiGraph g15() {
  digraph::DiGraph g;

  g.add_edge(0, 1);

  g.add_edge(1, 2);
  g.add_edge(1, 3);

  g.add_edge(2, 4);
  g.add_edge(3, 4);

  g.add_edge(4, 5);
    g.add_edge(1, 5);
    g.add_edge(5, 6);


  g.add_start_node(0);
  g.add_stop_node(6);

  return g;
};

// figure 1 Johnson et al
digraph::DiGraph g16() {
  digraph::DiGraph g;

  g.add_edge(0, 1);

  //g.add_edge(0, 1);
  g.add_edge(1, 3);
  g.add_edge(3, 5);
  g.add_edge(5, 8);
  g.add_edge(5, 9);
  g.add_edge(8, 10);
  g.add_edge(9, 10);
  g.add_edge(10, 11);
  g.add_edge(11, 1);
  g.add_edge(11, 15);
  g.add_edge(15, 16);

  g.add_edge(0, 2);
  g.add_edge(2, 4);
  g.add_edge(4, 6);
  g.add_edge(4, 7);
  g.add_edge(6, 12);
  g.add_edge(7, 12);
  g.add_edge(12, 13);
  g.add_edge(13, 7);
  g.add_edge(13, 14);
  g.add_edge(14, 15);
  g.add_edge(15, 16);

  g.add_start_node(0);
  g.add_stop_node(16);

  return g;
};

// diamond
digraph::DiGraph g17() {
  digraph::DiGraph g;
  //g = u_graph::FlowGraph();

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(1, 3);
  g.add_edge(2, 4);
  g.add_edge(3, 4);
  g.add_edge(4, 5);

  g.add_start_node(0);
  g.add_stop_node(5);

  return g;
}

// with overlapping
digraph::DiGraph g18() {
  digraph::DiGraph g;

  g.add_edge(0, 1);
  g.add_edge(1, 3);
  g.add_edge(1, 2);
  g.add_edge(2, 4);

  g.add_edge(3, 4);
  g.add_edge(5, 3);

  g.add_edge(4, 5);
  g.add_edge(5, 6);

  g.add_start_node(0);
  g.add_stop_node(6);

  return g;
};

// with capping
digraph::DiGraph g19() {
  digraph::DiGraph g;

  // TODO: flip 2 3 for capping
  g.add_edge(0, 1);
  g.add_edge(1, 3);
  g.add_edge(1, 2);
  g.add_edge(2, 4);

  g.add_edge(3, 4);
  g.add_edge(5, 2);

  g.add_edge(4, 5);
  //g.add_edge(5, 2);

  g.add_edge(5, 6);

  g.add_start_node(0);
  g.add_stop_node(6);

  return g;
};

// figure 1 Johnson et al
digraph::DiGraph g20() {
  digraph::DiGraph g;

  g.add_edge(0, 1);

  //g.add_edge(0, 1);
  g.add_edge(1, 3);
  g.add_edge(3, 5);
  g.add_edge(5, 8);
  g.add_edge(5, 9);
  g.add_edge(8, 10);
  g.add_edge(9, 10);
  g.add_edge(10, 11);
  g.add_edge(11, 1);
  g.add_edge(11, 15);
  g.add_edge(15, 16);

  g.add_edge(0, 2);
  g.add_edge(2, 4);
  g.add_edge(4, 6);
  g.add_edge(4, 7);
  g.add_edge(6, 12);
  g.add_edge(7, 12);
  g.add_edge(12, 13);
  g.add_edge(13, 7);
  g.add_edge(13, 14);
  g.add_edge(14, 15);
  g.add_edge(15, 16);

  g.add_start_node(0);
  g.add_stop_node(16);

  return g;
};
