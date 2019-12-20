// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2001 Stefanus Du Toit, Karsten-O. Laux

// $Id$

#include <Atlas/Message/Element.h>

namespace Atlas { namespace Message {

void Element::clear(Type new_type)
{
  switch(t)
     {
   case TYPE_NONE:
   case TYPE_INT:
   case TYPE_FLOAT:
   case TYPE_PTR:
     break;
   case TYPE_STRING:
	   ((StringType*)(&s))->~StringType();
     break;
   case TYPE_MAP:
	   ((MapType*)(&m))->~MapType();
     break;
   case TYPE_LIST:
	   ((ListType*)(&l))->~ListType();
     break;
   }

  t = new_type;
}

Element::Element(const Element& obj) : t(obj.t)
{
  switch(t)
    {
      case TYPE_NONE:
        break;
      case TYPE_INT:
        i = obj.i;
        break;
      case TYPE_FLOAT:
        f = obj.f;
        break;
      case TYPE_PTR:
        p = obj.p;
        break;
      case TYPE_STRING:
		  new(&s) StringType(obj.String());
        break;
      case TYPE_MAP:
		  new(&m) MapType(obj.Map());
        break;
      case TYPE_LIST:
		  new(&l) ListType(obj.List());
        break;
    }

}

Element::Element(Element&& obj) noexcept : t(obj.t)
{
    //Move data from the incoming object, and set the type of it to none, which
    //results in the incoming object "forgetting" all about the data.
  switch(t)
    {
      case TYPE_NONE:
        break;
      case TYPE_INT:
        i = obj.i;
        break;
      case TYPE_FLOAT:
        f = obj.f;
        break;
      case TYPE_PTR:
        p = obj.p;
        break;
      case TYPE_STRING:
		new(&s) StringType(std::move(obj.String()));
		break;
	  case TYPE_MAP:
		new(&m) MapType(std::move(obj.Map()));
		break;
	  case TYPE_LIST:
		new(&l) ListType(std::move(obj.List()));
		break;
    }
    obj.t = TYPE_NONE;

}

Element& Element::operator=(const Element& obj)
{
  //check for self assignment
  if(&obj == this)
    return *this;

  //first clear
  clear(obj.t);

  // then perform actual assignment of members
  switch(t)
    {
    case TYPE_NONE:
      break;
    case TYPE_INT:
      i = obj.i;
      break;
    case TYPE_FLOAT:
      f = obj.f;
      break;
    case TYPE_PTR:
      p = obj.p;
      break;
	case TYPE_STRING:
		new(&s) StringType(obj.String());
		break;
	case TYPE_MAP:
		new(&m) MapType(obj.Map());
		break;
	case TYPE_LIST:
		new(&l) ListType(obj.List());
		break;
    }

  return *this;
}

Element& Element::operator=(Element&& obj) noexcept
{
  //check for self assignment
  if(&obj == this)
    return *this;

  //first clear
  clear(obj.t);

  //Move data from the incoming object, and set the type of it to none, which
  //results in the incoming object "forgetting" all about the data.
  switch(t)
  {
    case TYPE_NONE:
      break;
    case TYPE_INT:
      i = obj.i;
      break;
    case TYPE_FLOAT:
      f = obj.f;
      break;
    case TYPE_PTR:
      p = obj.p;
      break;
    case TYPE_STRING:
      new(&s) StringType(std::move(obj.String()));
      break;
    case TYPE_MAP:
      new(&m) MapType(std::move(obj.Map()));
      break;
    case TYPE_LIST:
      new(&l) ListType(std::move(obj.List()));
      break;
  }
  obj.t = TYPE_NONE;


  return *this;
}

bool Element::operator==(const Element& o) const
{
    if (t != o.t) { return false; }
    switch(t) {
        case TYPE_NONE: return true;
        case TYPE_INT: return i == o.i;
		case TYPE_FLOAT: return Equal(f, o.f);
        case TYPE_PTR: return p == o.p;
        case TYPE_STRING: return String() == o.String();
        case TYPE_MAP: return Map() == o.Map();
        case TYPE_LIST: return List() == o.List();
    }
    return false;
}

const char * Element::typeName(Type ot)
{
    switch (ot) {
        case TYPE_NONE: return "none";
        case TYPE_INT: return "int";
        case TYPE_FLOAT: return "float";
        case TYPE_PTR: return "pointer";
        case TYPE_STRING: return "string";
        case TYPE_MAP: return "map";
        case TYPE_LIST: return "list";
    }
    return "UNKNOWN";
}

} } //namespace Atlas::Message

