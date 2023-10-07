#include "project04.h"


int main(int argc, char **argv) {

    struct scan_table_st scan_table; // table of tokens
    struct parse_table_st parse_table; // table of parse nodes
    struct parse_node_st *parse_tree; // tree (pointers only) of parse nodes

    char input[SCAN_INPUT_LEN];
    int len;

    if (strncmp(argv[1], "-e", SCAN_TOKEN_LEN) == 0) {
    	strncpy(input, argv[2], SCAN_INPUT_LEN);
    	len = strnlen(input, SCAN_INPUT_LEN);

		//scanning
    	scan_table_init(&scan_table);
    	scan_table_scan(&scan_table, input, len);

		//parsing
    	parse_table_init(&parse_table);
    	parse_tree = parse_program(&scan_table);

		//evaluating and printing
    	char *val_string;
    	unsigned int val = eval_tree(parse_tree);
    	
    	if (argc > 3 && (strncmp(argv[3], "-b", SCAN_TOKEN_LEN) == 0)) {
    		if (strncmp(argv[4], "10", SCAN_TOKEN_LEN) == 0){
    			val_string = int_to_string(val, 10);
    			print_value(val_string, 10);
    		} else if (strncmp(argv[4], "2", SCAN_TOKEN_LEN) == 0) {
    		    val_string = int_to_string(val, 2);
    		    print_value(val_string, 2);
    		} else if (strncmp(argv[4], "16", SCAN_TOKEN_LEN) == 0) {
    		    val_string = int_to_string(val, 16); 
    		    print_value(val_string, 16);  			
			}
			
    	} else {
    		val_string = int_to_string(val, 10);
    		print_value(val_string, 10);
    	}

   
    		
    //same as above but in this case the base and the expression are in a different order
    } else if (strncmp(argv[1], "-b", SCAN_TOKEN_LEN) == 0) {
		strncpy(input, argv[4], SCAN_INPUT_LEN);
    	len = strnlen(input, SCAN_INPUT_LEN);

    	scan_table_init(&scan_table);
    	scan_table_scan(&scan_table, input, len);
    	// scan_table_print(&scan_table);

    	parse_table_init(&parse_table);
    	parse_tree = parse_program(&scan_table);
    	//parse_tree_print(parse_tree);

    	int val = eval_tree(parse_tree);
    	char *val_string;
    	if (strncmp(argv[2], "10", SCAN_TOKEN_LEN) == 0) {
    		val_string = int_to_string(val, 10);
    		print_value(val_string, 10);
    	} else if (strncmp(argv[2], "2", SCAN_TOKEN_LEN) == 0) {
    	    val_string = int_to_string(val, 2);
    	    print_value(val_string, 2);
    	} else if (strncmp(argv[2], "16", SCAN_TOKEN_LEN) == 0) {
    	    val_string = int_to_string(val, 16);  
    	    print_value(val_string, 16); 			
		}
    }
        
    return 0;
}
