#include <iostream>
#include <stack>

#include "./pst.hpp"
#include "../graph/spanning_tree.hpp"
#include "../graph/u_graph.hpp"

namespace pst {
/*
 * PST
 * ---
 *
 * The PST is a tree of cycle equivalent regions of the spanning tree of the
 * undirected flow graph U_f with the following properties:
  * -
  *

  we use region to refer to a cycle equivalent region of the spanning tree
  therefore region is synonymous with class

 * The construction is as follows:
     "When a region is first entered, we set its parent to the current region
     and then update the current region to be the region just entered.
     When a region is exited,
     the current region is set to be the exited region’s parent."

  * When a region is first entered:
      We know a region has been entered because:
        - there's an OBE in the current vertex (capping or not)
    1. we set its parent to the current region
       and then update the current region to be the region just entered
       * its parent will be the class on top of the stack
         * if the stack was empty this class will be the root
    2. we will then push it onto the stack making it the current region
       the current equiv class is the class on top of the stack

  * When a region is exited:
      We know a region has been entered because:
       - we see an outgoing capping back-edge
       - we see an incoming back-edge
    1 the current region is set to be the exited region’s parent.
      a) we pop the value that's on top of the stack
      b) st spanning tree
 */
tree::Tree compute_pst(spanning_tree::Tree &st) {
  // TODO: urgent! why size and not no of equiv classes?
  tree::Tree t = tree::Tree(st.size());
  std::stack<std::size_t> vertex_stack{}; // stack of vertices
  std::stack<std::size_t> seen{};
 
  // go over the nodes in reverse topological order (dfs_num) which may not be
  // equal to node ids

  int current_region{0};

  for (std::size_t r{st.size() - 1}; r > 0; --r) {

    std::size_t v = st.get_sorted(r);
    //std::size_t v = r;

    std::size_t cl = st.get_parent_edge(v).get_class();

    std::cout << "r: "  << r << " v: " << v << " cl: "<< cl << std::endl;

    if (current_region != cl) {
      t.add_vertex(current_region, cl);
      current_region = cl;
      //current_region = cl;
      //vertex_stack.push(v);
      //std::cout << "pushing: " << v << std::endl;
    } else {
      //std::cout << "popping: " << v << std::endl;
      //vertex_stack.pop();
      
    }

    
  }

  return t;
   
  for (std::size_t r{st.size() - 1}; r > 0; --r) {
    // the vertex id of the vertex at the topological sort index r
    std::size_t v = st.get_sorted(r);

    std::set<size_t> obe = st.get_obe_idxs(v);
    std::set<size_t> ibe = st.get_ibe(v);

    // the equiv class is maintained
    if (obe.empty() && ibe.empty()) { continue; }

    // the equivalence class of the incoming tree edge
    std::size_t cl = st.get_parent_edge(v).get_class();

    // check if any of the obe are capping backedges
    bool has_capping_obe{false};
    for (auto e_idx: obe) {
      if (st.get_backedge(e_idx).is_capping_backedge()) {
        has_capping_obe=true;
        break;
      }
    }

    // exit the current region
    // --------------------

    if (!ibe.empty() || has_capping_obe) {
      vertex_stack.pop();
    }

    // enter the new region
    // --------------------

    if (!obe.empty()) { // an equivalence class/region has been entered
      if (!vertex_stack.empty()) { t.add_vertex(vertex_stack.top(), cl); }
      vertex_stack.push(cl);
    }
  }

  return t;
}


} // namespace pst
