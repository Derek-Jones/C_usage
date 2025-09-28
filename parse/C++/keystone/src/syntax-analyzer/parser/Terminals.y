//******************************************************************************
//
//  Terminals.btyacc
// 
//  Copyright (C) 2000-2004 by
// 
//    Department of Computer Science, Clemson University,
//    Department of Computer Science, National University of Ireland, Maynooth.
//  
//  http://keystone.sourceforge.net
// 
//  <keystone@cs.clemson.edu>
// 
//  Keystone is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
// 
//  Keystone is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
// 
//******************************************************************************

//*** Keywords ***
%token  KW_asm        KW_do           KW_inline            KW_short        KW_typeid
%token  KW_auto       KW_double       KW_int               KW_signed       KW_typename
%token  KW_bool       KW_dynamic_cast KW_long              KW_sizeof       KW_union
%token  KW_break      KW_else         KW_mutable           KW_static       KW_unsigned
%token  KW_case       KW_enum         KW_namespace         KW_static_cast  KW_using
%token  KW_catch      KW_explicit     KW_new               KW_struct       KW_virtual
%token  KW_char       KW_extern       KW_operator          KW_switch       KW_void
%token  KW_class      KW_false        KW_private           KW_template     KW_volatile
%token  KW_const      KW_float        KW_protected         KW_this         KW_wchar_t
%token  KW_const_cast KW_for          KW_public            KW_throw        KW_while
%token  KW_continue   KW_friend       KW_register          KW_true
%token  KW_default    KW_goto         KW_reinterpret_cast  KW_try
%token  KW_delete     KW_if           KW_return            KW_typedef
%token  KW_export

//*** Pseduo Keywords ***
%token KW_unsigned_char KW_unsigned_short KW_unsigned_long KW_long_double

//*** Literals ***
%token PS_LITERAL INTEGER_LITERAL CHARACTER_LITERAL FLOATING_LITERAL STRING_LITERAL 

//*** Single-Character Operators ***
%token LEFTPAREN  RIGHTPAREN        // ( )
%token LEFTBRACK  RIGHTBRACK        // { }
%token LEFTARRAY RIGHTARRAY         // [ ]
%token PLUS MINUS STAR DIVIDE MOD   // + - * / %
%token GREATER LESS EQUAL           // > < =
%token AND OR NOT XOR               // & | ! ^
%token COMMA SEMI COLON             // , ; :
%token COMPLEMENT DOT QUESTION      // ~ . ?          

//*** Multi-Character Operators ***
%token COLCOL ELLIPSES
%token PLUSEQ MINUSEQ STAREQ DIVEQ MODEQ
%token XOREQ  ANDEQ   OREQ   LTLT  GTGT     GTGTEQ     LTLTEQ     EQEQ   NOTEQ
%token LEQ    GEQ     ANDAND OROR  PLUSPLUS MINUSMINUS DOTSTAR ARROWSTAR  ARROW

//*** The context-sensitive versions of IDENTIFIER ***
%token IDENTIFIER 
%token ID_typedef_name ID_original_namespace_name ID_namespace_alias
%token ID_enum_name    ID_class_name
%token ID_template_name


%type <tcount> KW_class KW_struct KW_union KW_enum KW_namespace KW_template
%type <tcount> KW_typename KW_operator LEFTPAREN COMMA COLON ELLIPSES

%type <id_sym> PS_LITERAL
%type <id_sym> INTEGER_LITERAL CHARACTER_LITERAL FLOATING_LITERAL
%type <id_sym> STRING_LITERAL

%type <decl> IDENTIFIER ID_typedef_name ID_original_namespace_name
%type <decl> ID_namespace_alias ID_enum_name ID_template_name
%type <decl> ID_class_name

