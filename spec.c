/***
 * Author: liheng
 * Created: unknown
 * Last MDF: 2005-01-22
 *
 * 2005-01-22 liheng
 * 
 *     * preprocess the species tree
 *     * add fully-sequenced tag
 */
#include <stdlib.h>
#include "cpp_utils.h"
#include "tree.h"

/* AEDAE */

char *tr_species_tree_string="\
((ORYSA*-4530.rice,ARATH*-3702)Magnoliophyta-3398,(SCHPO*-4896.S_pombe,YEAST*-4932)Ascomycota-4890,\
 ((((((((((((HUMAN*-9606,PANTR*-9598.chimpanzee)Homo/Pan/Gorilla-207598, \
            MACMU*-9544.monkey)Catarrhini-9526, \
            OTOGA-*30611.galago)Primates-9443, \
         ((MOUSE*-10090,RAT*-10116)Murinae-39107,RABIT-9986)Glires-314147)Euarchontoglires-314146, \
        ((BOVIN*-9913.cow,PIG-*9823)Cetartiodactyla-91561, \
         (CANFA*-9615.dog,FELCA-*9685.cat)Carnivora-33554, \
         SORAR-*42254.shrew, \
         MYOLU-*59463.bat)Laurasiatheria-314145, \
        (ECHTE-9371.tenrec,LOXAF-9785.elephant)Afrotheria-311790, \
        DASNO-9361.armadillo)Eutheria-9347,MONDO*-13616.opossum)Theria-32525,\
       ORNAN-*9258.platypus)Mammalia-40674,\
      CHICK*-9031)Amniota-32524,\
     XENTR*-8364.frog)Tetrapoda-32523,\
    (BRARE*-7955.zebrafish, \
     ((TETNG*-99983.pufferfish,FUGRU*-31033.pufferfish)Tetraodontidae-31031,\
      (GASAC-*69293.stickleback,ORYLA-*8090.ricefish)Smegmamorpha-129949)Percomorpha-32485)Clupeocephala-186625)Euteleostomi-117571,\
   (CIOIN*-7719,CIOSA-*51511)Ciona-7718)Chordata-7711,\
  (((DROME*-7227.fly,DROPS*-7237.fly)Sophophora-32341,\
    (AEDAE-*7159.mosquito,ANOGA*-7165.mosquito)Culicidae-7157)Diptera-7147, \
   APIME-*7460.honeybee)Endopterygota-33392,\
  SCHMA*-6183.fluke,\
  (CAEEL*-6239.worm,CAEBR*-6238.worm,CAERE*-31234.worm)Caenorhabditis-6237)Bilateria-33213)Eukaryota-2759;";

char *tr_core_species_list[] = {
		"HUMAN", "MOUSE", "MONDO", "CHICK", "XENTR", "BRARE", "FUGRU", "CIOIN", "DROME",
		"CAEEL", "SCHMA", "YEAST", "SCHPO", "ORYSA", "ARATH", 0};

Tree *tr_default_spec_tree()
{
	Tree **forest, *tree;
	int n;

	forest = tr_parse_str(tr_species_tree_string, &n);
	tree = forest[0];
	free(forest);
	cpp_post_spec_tree(tree, 0);
	return tree;
}
Tree *tr_core_spec_tree()
{
	Tree **forest, *tree;
	int n;

	forest = tr_parse_str(tr_species_tree_string, &n);
	tree = forest[0];
	free(forest);
	cpp_post_spec_tree(tree, 1);
	return tree;
}
