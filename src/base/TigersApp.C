#include "TigersApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<TigersApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

TigersApp::TigersApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  TigersApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  TigersApp::associateSyntax(_syntax, _action_factory);
}

TigersApp::~TigersApp() {}

void
TigersApp::registerApps()
{
  registerApp(TigersApp);
}

void
TigersApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new production objects here! */
}

void
TigersApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new production objects here! */
}

void
TigersApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
TigersApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
TigersApp__registerApps()
{
  TigersApp::registerApps();
}

extern "C" void
TigersApp__registerObjects(Factory & factory)
{
  TigersApp::registerObjects(factory);
}

extern "C" void
TigersApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  TigersApp::associateSyntax(syntax, action_factory);
}
