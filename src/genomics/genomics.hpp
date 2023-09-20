#include <vector>

#include "../pvst/pvst.hpp"
#include "../graph/tree.hpp"
#include "../graph/digraph.hpp"
#include "../core/core.hpp"

namespace genomics {
// TODO: make use of this or delete
enum variant_type {
	SNP,
	DEL,
	INS,
	INV,
	DUP,
	CNV,
	BND
};
  
enum output_format {
	VCF, // which version of VCF?
	PAF, // not yet supported
};
    
void call_variants(tree::Tree pvst_,
				   digraph::DiGraph dg,   core::config app_config);
} // namespace genomics

namespace vcf {

bool print_vcf(std::vector<std::vector<std::size_t>> paths,
			   digraph::DiGraph dg,
			   std::string ref_path_name,
			   std::size_t ref_path_id);

void print_vcf_header(std::string ref_name);

} // namespace vcf