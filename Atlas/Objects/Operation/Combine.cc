// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Combine.h"

using namespace std;
using namespace Atlas;
using namespace Atlas::Message;

namespace Atlas { namespace Objects { namespace Operation { 

Combine::Combine()
     : Create()
{
    SetId(string("combine"));
    Object::ListType parents;
    parents.push_back(string("create"));
    SetParents(parents);
    SetSpecification(string("atlas-game"));
}

Combine Combine::Instantiate()
{
    Combine value;

    Object::ListType parents;
    parents.push_back(string("combine"));
    value.SetParents(parents);
    value.SetObjtype(string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
