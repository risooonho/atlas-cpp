// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Set.h"

using namespace std;
using namespace Atlas;
using namespace Atlas::Message;

namespace Atlas { namespace Objects { namespace Operation { 

Set::Set()
     : Action()
{
    SetAttr("id", string("set"));
    Object::ListType parent;
    parent.push_back(string("action"));
    SetAttr("parent", parent);
}

Set Set::Instantiate()
{
    Set value;

    Object::ListType parent;
    parent.push_back(string("set"));
    value.SetAttr("parent", parent);
    value.SetAttr("objtype", string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
