static tree
check_case_value (label_value, selector)
     tree label_value, selector;
{
  if (TREE_CODE (label_value) == ERROR_MARK)
    return label_value;
  if (TREE_CODE (selector) == ERROR_MARK)
    return selector;

  /* Z.200 (6.4 Case action) says:  "The class of any discrete expression
     ;kasjnc;lkjansdcjk
     lawkdmc;laksdc */

