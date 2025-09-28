
#ifndef _ACTIONS_HELP_H_
#define _ACTIONS_HELP_H_

#include <string>

//#include "Ast.h"
#include "SchemaAliases.h"
#include "BasicType.h"

class cAsgNode;
class cBlock;

namespace key
{
  cBlock* ensureIsBlock ( cAsgNode* );

  AsgNodeList_t* collapseIfObjectList         ( cAsgNode* );
  AsgNodeList_t* collapseContainedObjectLists ( AsgNodeList_t* );

  BasicType::BType convertStringToBType ( const std::string& );
}

#endif
