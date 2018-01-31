//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "TigersTestApp.h"
#include "TigersApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<TigersTestApp>()
{
  InputParameters params = validParams<TigersApp>();
  return params;
}

TigersTestApp::TigersTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  TigersApp::registerObjectDepends(_factory);
  TigersApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  TigersApp::associateSyntaxDepends(_syntax, _action_factory);
  TigersApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    TigersTestApp::registerObjects(_factory);
    TigersTestApp::associateSyntax(_syntax, _action_factory);
  }
}

TigersTestApp::~TigersTestApp() {}

void
TigersTestApp::registerApps()
{
  registerApp(TigersApp);
  registerApp(TigersTestApp);
}

void
TigersTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
TigersTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
TigersTestApp__registerApps()
{
  TigersTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
TigersTestApp__registerObjects(Factory & factory)
{
  TigersTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
TigersTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  TigersTestApp::associateSyntax(syntax, action_factory);
}
