# mkctype.awk, 31 Aug 03

function mk_pr_type(obj_type)
{
sp_obj_type=""
gsub(" ", "", obj_type)
last_obj_type=obj_type
while (obj_type != "") {
   for (t in c_types)
      if (index(obj_type, t) == 1) {
         sp_obj_type=sp_obj_type " " t
         sub(t, "", obj_type)
         }
      if (index(obj_type, "_ptr_to_func") == 1) {
         sp_obj_type=sp_obj_type " _ptr_to_func"
         sub("_ptr_to_func", "", obj_type)
         }
      if (index(obj_type, "ptr_to_func") == 1) {
         sp_obj_type=sp_obj_type " ptr_to_func"
         sub("ptr_to_func", "", obj_type)
         }
      if (index(obj_type, "ptr_to") == 1) {
         sp_obj_type=sp_obj_type " ptr_to"
         sub("ptr_to", "", obj_type)
         }
   if (last_obj_type == obj_type) {
      print last_obj_type " | " obj_type
      break
      }
   last_obj_type=obj_type
   }
num_fields=split(sp_obj_type, sub_types, " ")
pr_type=""
prev_array=0
prev_ptr=0
for (i=num_fields; i != 0; i--) {
   if (sub_types[i] == "ptr_to_func")
      {
      prev_ptr=1
      pr_type=pr_type " *()"
      }
   else if (sub_types[i] == "ptr_to")
      {
      if (prev_array == 1)
         pr_type="( " pr_type " ) *"
      else
         pr_type=pr_type " *"
      prev_array=0
      prev_ptr=1
      }
   else if (sub_types[i] == "const")
      {
      if (prev_ptr == 1)
         pr_type=pr_type " const"
      else
         pr_type="const " pr_type
      }
   else if (sub_types[i] == "array")
      {
      if (prev_ptr == 1)
         pr_type="( " pr_type " ) []"
      else
         pr_type=pr_type " []"
      prev_array=1
      prev_ptr=0
      }
   else
      pr_type=sub_types[i] " " pr_type
   }
}

function init_types()
{
c_types["char"]=1
c_types["short"]=1
c_types["int"]=1
c_types["long"]=1
c_types["float"]=1
c_types["double"]=1
c_types["signed"]=1
c_types["unsigned"]=1
c_types["const"]=1
c_types["restrict"]=1
c_types["volatile"]=1
c_types["void"]=1
c_types["enum"]=1
c_types["array"]=1
c_types["struct"]=1
c_types["union"]=1
}

