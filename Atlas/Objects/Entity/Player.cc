// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Player.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

Player::Player()
     : Account()
{
    SetId(std::string("player"));
    Object::ListType parents;
    parents.push_back(std::string("account"));
    SetParents(parents);
    Object::ListType characters;
    SetCharacters(characters);
}

Player Player::Instantiate()
{
    Player value;

    Object::ListType parents;
    parents.push_back(std::string("player"));
    value.SetParents(parents);
    value.SetObjtype(std::string("object"));
    
    return value;
}

bool Player::HasAttr(const std::string& name) const
{
    if (name == "characters") return true;
    return Account::HasAttr(name);
}

Object Player::GetAttr(const std::string& name) const
    throw (NoSuchAttrException)
{
    if (name == "characters") return attr_characters;
    return Account::GetAttr(name);
}

void Player::SetAttr(const std::string& name, const Object& attr)
{
    if (name == "characters") { SetCharacters(attr.AsList()); return; }
    Account::SetAttr(name, attr);
}

void Player::RemoveAttr(const std::string& name)
{
    if (name == "characters") return;
    Account::RemoveAttr(name);
}

void Player::SendContents(Bridge* b) const
{
    SendCharacters(b);
    Account::SendContents(b);
}

Object Player::AsObject() const
{
    Object::MapType m = Account::AsObject().AsMap();
    m["characters"] = Object(attr_characters);
    return Object(m);
}

} } } // namespace Atlas::Objects::Entity