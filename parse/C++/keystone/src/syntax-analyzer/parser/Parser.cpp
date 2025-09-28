#include "ActionFacade.h"
#include "ArgumentStack.h"
#include "ContextManager.h"
#include "DeclarationStack.h"
#include "KeywordManager.h"
#include "LocationTracker.h"
#include "Actions.h"
#include "TokenDecorator.h"

#include "Parser.h"

//------------------------------------------------------------------------------
// Static Member Initialization
//------------------------------------------------------------------------------

Parser *Parser::instance_ = 0;

//------------------------------------------------------------------------------
// Static Methods
//------------------------------------------------------------------------------

Parser* Parser::Instance ( void )
{
  if ( instance_ == 0 )
  {
    instance_ = new Parser;
  }

  return instance_;
}

//------------------------------------------------------------------------------

Parser::Parser ( )
       : keywordManager_  ( new KeywordManager   )
       , locationTracker_ ( new LocationTracker  )
       , contextManager_  ( new ContextManager   )
       , facade_          ( new ActionFacade     ( contextManager_ ) )
       , decorator_       ( new TokenDecorator   ( locationTracker_, facade_ )  )
       , argStack_        ( new ArgumentStack    )
       , declStack_       ( new DeclarationStack ( locationTracker_ ) )
       , actions_         ( new Actions          ( locationTracker_, decorator_, facade_, argStack_, declStack_ ) )
{ }

//------------------------------------------------------------------------------

void Parser::recycle ( void )
{
  delete actions_;
  delete declStack_;
  delete argStack_;
  delete decorator_;
  delete facade_;
  delete contextManager_;
  delete locationTracker_;

  locationTracker_ = new LocationTracker;
  contextManager_  = new ContextManager;
  facade_          = new ActionFacade     ( contextManager_ );
  decorator_       = new TokenDecorator   ( locationTracker_, facade_ );

  decorator_->recycle();

  argStack_        = new ArgumentStack;
  declStack_       = new DeclarationStack ( locationTracker_ );
  actions_         = new Actions          ( locationTracker_, decorator_, facade_, argStack_, declStack_ );
}

//------------------------------------------------------------------------------
