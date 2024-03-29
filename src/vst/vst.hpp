#ifndef VST_HPP
#define VST_HPP

#include <cstddef>

#include "../graph/spanning_tree.hpp"
#include "../graph/tree.hpp"

// TODO: rename vst to pvst
namespace vst {

void cycle_equiv(spanning_tree::Tree &t);
  
class Vertex {
  std::size_t idx;
  std::size_t cycle_equiv_class_;

  std::size_t parent;
  std::set<std::size_t> children;

public:

  // constructor(s)
  // --------------
  Vertex(std::size_t idx); // root

  // root for use by PST
  Vertex(std::size_t idx, std::size_t cycle_equiv_class_);
  Vertex(std::size_t idx, std::size_t cycle_equiv_class_, std::size_t parent);

  // getters
  // -------
  // given the idx of the child in the tree vector
  std::set<std::size_t> const &get_children() const;

  // setters
  // -------
  // given the idx of the child in the tree vector
  void add_child(std::size_t child_idx);
};

class VST {
  std::vector<Vertex> t;
  static const std::size_t root_idx_{};

public:
  // constructor(s)
  // --------------
  VST(spanning_tree::Tree &t);

  // getters
  // -------
  std::size_t size() const;
  std::size_t root_idx() const;
  std::set<std::size_t> const& get_children(std::size_t v) const;

  // IO
  // --
  void print_dot();
};

tree::Tree compute_pvst(spanning_tree::Tree &st);
tree::Tree compute_pvst_grey(spanning_tree::Tree &st);


} // namespace vst


/*

 */

#endif
