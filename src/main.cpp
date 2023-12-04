#include "./core/core.hpp"
#include "./cli/cli.hpp"
#include "./io/io.hpp"
#include "./graph/bidirected.hpp"
#include "./graph/biedged.hpp"
#include "./graph/spanning_tree.hpp"
#include "./algorithms/cycle_equiv.hpp"
#include "./pvst/pvst.hpp"
#include "./genomics/genomics.hpp"
#include "graph/tree.hpp"


#include "./graph/u_graph.hpp"
#include <string>


int main(int argc, char *argv[]) {
  core::config app_config;
  cli::cli(argc, argv, app_config);

  if (app_config.verbosity()) { app_config.dbg_print(); }

  std::string fn_name{"[povu::main]"};
  
  if (app_config.verbosity() > 2)  { std::cerr << "[povu::main] Reading graph\n"; }

  // read the input gfa into a bidirected variation graph
  bidirected::VariationGraph vg = io::from_gfa::to_vg(app_config.get_input_gfa().c_str());
  if (app_config.verbosity() > 1) { vg.dbg_print(); }

  if (app_config.verbosity() > 2) { std::cerr << "[povu::main] Bi-edging" << "\n"; }
  // convert the bidirected variation graph into a biedged variation graph
  biedged::BVariationGraph bg(vg);
  if (app_config.verbosity() > 2) { bg.print_dot(); }
  bg.componetize();
  if (app_config.verbosity() > 2) { bg.print_dot(); }

  // compute the spanning tree of the biedged variation graph
    if (app_config.verbosity() > 2) { std::cerr << "[povu::main] Computing spanning tree\n"; }
  spanning_tree::Tree st = bg.compute_spanning_tree();
  if (app_config.verbosity() > 4) { std::cout << "\n\n" << "Spanning Tree" << "\n\n"; st.print_dot(); }

  // compute the cycle equivalence classes of the spanning tree
  if (app_config.verbosity() > 2) { std::cerr << fn_name << "Finding cycle equivalent classes\n"; }
  algorithms::cycle_equiv(st);
  if (app_config.verbosity() > 4) {	st.print_dot(); }

  std::vector<std::pair<std::size_t, std::size_t>> v = st.compute_edge_stack2();


  if (app_config.verbosity() > 2) { std::cerr << "[povu::main] Generating the PVST\n"; }
  tree::Tree t = pvst::compute_pvst(v);
  if (app_config.verbosity() > 4)  { std::cout << "\n\n" << "PVST" << "\n\n"; t.print_dot(true); }


  if (app_config.verbosity() > 2)  { std::cerr << "[povu::main] Calling variants\n"; }
  genomics::call_variants(t, vg, app_config);

  
  return 0;

  u_graph::FlowGraph afg = u_graph::FlowGraph(st);
  if (app_config.verbosity() > 2) { 
    std::cout << "\n\n" << "Annotated Flow Graph" << "\n\n";
    afg.print_dot();
  }
  
  

  return 0;
}
