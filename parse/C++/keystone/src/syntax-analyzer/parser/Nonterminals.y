/*
 *  Nonterminals.btyacc
 *
 *  Copyright (C) 2000-2004 by
 *
 *    Department of Computer Science, Clemson University,
 *    Department of Computer Science, National University of Ireland, Maynooth.
 * 
 *  http://keystone.sourceforge.net
 *
 *  <keystone@cs.clemson.edu>
 *
 *  Keystone is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  Keystone is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

%type <optype> unary_operator

%type <tcount> class_key
%type <tcount> colcol_opt assignment_operator template_opt ptr_operator
%type <tcount> comma_opt virtual_opt cv_qualifier cv_qualifier_seq
%type <tcount> cv_qualifier_seq_opt export_opt ellipses_opt

%type <tcount> typename_opt

%type <name> an_operator
%type <name> boolean_literal

%type <block> compound_statement
%type <block> function_body
%type <block> ctor_initializer
%type <block> ctor_initializer_opt
%type <block> function_try_block

%type <dspec> decl_specifier
%type <dspec> storage_class_specifier function_specifier
%type <stmt> simple_declaration
%type <stmt> statement labeled_statement expression_statement
%type <stmt> selection_statement iteration_statement jump_statement declaration_statement
%type <stmt> try_block for_init_statement declaration block_declaration
%type <stmt> explicit_instantiation explicit_specialization
%type <stmt> namespace_definition named_namespace_definition original_namespace_definition
%type <stmt> extension_namespace_definition unnamed_namespace_definition asm_definition
%type <stmt> linkage_specification
%type <stmt> namespace_alias_definition template_declaration template_argument
%type <stmt> using_directive using_declaration 
%type <tspec> exception_specification exception_specification_opt
%type <stmt> declarator
%type <stmt> direct_declarator
%type <ident> member_declarator function_definition
//%type <ident> init_declarator
%type <stmt> init_declarator
%type <endef> enumerator_definition 
%type <parm> parameter_declaration
%type <expr> primary_expression postfix_expression unary_expression new_expression
%type <expr> delete_expression cast_expression pm_expressionression multiplicative_expression
%type <expr> additive_expression shift_expression relational_expression equality_expression
%type <expr> and_expression exclusive_or_expression inclusive_or_expression logical_and_expression
%type <expr> logical_or_expression conditional_expression assignment_expression expression
%type <expr> expression_opt constant_expression constant_expression_opt condition condition_opt
%type <exprbase> initializer initializer_opt initializer_clause
%type <expr> pure_specifier
%type <expr> pure_specifier_opt constant_initializer constant_initializer_opt
%type <expr> mem_initializer throw_expression assignment_expression_opt
%type <init> initializer_list
%type <nameref> id_expression unqualified_id qualified_id nested_name_specifier
%type <nameref> nested_name_specifier_opt pseudo_destructor_name any_id_expression
%type <nameref> template_id class_name class_or_namespace_name type_name declarator_id
%type <nameref> mem_initializer_id conversion_function_id any_identifier_or_template
%type <paramlist> expression_list expression_list_opt new_placement new_placement_opt
%type <paramlist> new_initializer new_initializer_opt
%type <tparmlist> template_parameter_list
%type <ctype> new_type_id simple_type_specifier type_specifier elaborated_type_specifier
%type <ctype> enum_specifier type_id type_specifier_seq
%type <ctype> type_specifier_seq_opt abstract_declarator abstract_declarator_opt
%type <ctype> direct_abstract_declarator direct_abstract_declarator_opt
%type <ctype> conversion_declarator_opt conversion_declarator conversion_type_id
%type <cti> class_head class_specifier
%type <newdecl> new_declarator new_declarator_opt
%type <arrdims> direct_new_declarator
%type <bclass> base_specifier
%type <cblock> handler
%type <cfcp> exception_declaration
%type <tparm> template_parameter type_parameter 

%type <memdecls> member_specification member_specification_opt
%type <memdecl> member_declaration
%type <asgcont> declaration_seq declaration_seq_opt namespace_body
%type <asgcont> init_declarator_list init_declarator_list_opt
%type <asgcont> member_declarator_list member_declarator_list_opt mem_initializer_list
%type <asgcont> statement_seq statement_seq_opt template_argument_list template_argument_list_opt
%type <enumcont> enumerator_list enumerator_list_opt
%type <dscont> decl_specifier_seq decl_specifier_seq_opt
%type <argcont> parameter_declaration_clause parameter_declaration_list_opt
%type <argcont> parameter_declaration_list
%type <inhcont> base_clause_opt base_clause base_specifier_list
%type <handcont> handler_seq handler_seq_opt
%type <typcont> type_id_list type_id_list_opt

%type <decl> typedef_name namespace_name
%type <decl> any_identifier 
%type <decl> original_namespace_name namespace_alias 
%type <decl> enum_name template_name 
%type <decl> operator_function_id
%type <decl> enumerator 
%type <decl> identifier_opt qualified_namespace_specifier
%type <decl> any_unqualified_id  any_qualified_id

