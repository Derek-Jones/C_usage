
#include <iostream>

#include "Scope.h"

#include "Ast.h"

#include "ActionsHelp.h"

namespace key
{
  //----------------------------------------------------------------------------

  cBlock* ensureIsBlock ( cAsgNode* node )
  {
    if ( ! node )
    {
      return 0;
    }

    if ( !dynamic_cast<cBlock*>( node ) )
    {
      AsgNodeList_t nodes;
      nodes.push_back( node );
      cBlock* block = STATE->cBlockCreate( node->mFilename,
                                           node->mStartLine,
                                           node->mEndLine,
                                           "",
                                           VB_UNKNOWN,
                                           0,
                                           nodes
                                         );

      for ( std::vector<cAsgNode*>::iterator ptr = block->mContents.begin();
            ptr != block->mContents.end();
            ++ptr
          )
      {
        if ( cObject* obj = dynamic_cast<cObject*>( (*ptr) ) )
        {
          obj->mDefinedIn = block;
        }
      }

      node = block;
    }
    return static_cast<cBlock*>( node );
  }

  //----------------------------------------------------------------------------

  AsgNodeList_t* collapseIfObjectList ( cAsgNode* node )
  {
    AsgNodeList_t* nodeList = new AsgNodeList_t;
    if ( cObjectList* ol = dynamic_cast<cObjectList*>( node ) )
    {
      if ( ol->mObjects.size() == 1 )
      {
        unsigned int size = ol->mObjects.size();
        for ( unsigned int i = 0; i < size; ++i )
        {
          nodeList->push_back( ol->mObjects[i] );
        }
      }
      else
      {
        nodeList->push_back( node );
      }
    }
    else
    {
      nodeList->push_back( node );
    }

    return nodeList;
  }

  //----------------------------------------------------------------------------

  AsgNodeList_t* collapseContainedObjectLists ( AsgNodeList_t* nodes )
  {
    /// collapse cObjectList nodes
    /// cObjectList is an implementation artifact - eliminate them from the final tree
    if ( ! nodes )
    {
      return 0;
    }

    AsgNodeList_t* nodeList = new AsgNodeList_t;

    for ( AsgNodeList_t::iterator ptr = nodes->begin();
          ptr != nodes->end();
          ++ptr
        )
    {
      AsgNodeList_t* tmpList = collapseIfObjectList( *ptr );
      if ( tmpList )
      {
        nodeList->insert( nodeList->end(), tmpList->begin(), tmpList->end() );
      }
    }

    return nodeList;
  }

  //----------------------------------------------------------------------------

  BasicType::BType convertStringToBType ( const std::string& str )
  {
    if ( str == "char" )
      return BasicType::BT_CHAR;

    if ( str == "unsigned char" )
      return BasicType::BT_UCHAR;

    if ( str == "wchar_t" )
      return BasicType::BT_WCHAR;

    if ( str == "bool" )
      return BasicType::BT_BOOL;

    if ( str == "short" )
      return BasicType::BT_SHORT;

    if ( str == "unsigned short" )
      return BasicType::BT_USHORT;

    if ( str == "int" )
      return BasicType::BT_INT;

    if ( str == "long" )
      return BasicType::BT_LONG;

    if ( str == "unsigned long" )
      return BasicType::BT_ULONG;

    if ( str == "signed" )
      return BasicType::BT_SIGNED;

    if ( str == "unsigned" )
      return BasicType::BT_UNSIGNED;

    if ( str == "float" )
      return BasicType::BT_FLOAT;

    if ( str == "double" )
      return BasicType::BT_DOUBLE;

    if ( str == "long double" )
      return BasicType::BT_LDOUBLE;

    if ( str == "void" )
      return BasicType::BT_VOID;

    return BasicType::NUM_BT;
  }

  //----------------------------------------------------------------------------
}

