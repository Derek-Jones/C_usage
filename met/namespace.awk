# namespace.awk, 28 Dec 03
#

BEGIN {
	total_ids=0
	map_namespace["local_objects"]="block scope objects"
	map_namespace["global_objects"]="file scope objects"
	map_namespace["enum_consts"]="enumeration constants"
	map_namespace["tags"]="tag names"
	map_namespace["typedefs"]="typedef names"
	map_namespace["func_defs"]="function definitions"
	map_namespace["func_decls"]="function declarations"
	map_namespace["labels"]="label names"
	map_namespace["func_params"]="function parameters"
	map_namespace["macro_definition"]="macro definitions"
	map_namespace["macro_parameter"]="macro parameters"
	map_namespace["members"]="struct/union members"
	}

$1 == "File:" {
	num_ids[$2]=$3
	namespace=$2
	total_ids+=$3
	next
	}

	{
	next
	}

END {
	for (id in num_ids)
	   printf("%s ,, %2.1f\n", map_namespace[id], 100*(num_ids[id]/total_ids))
	}
