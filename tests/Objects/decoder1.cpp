#include "Objects/Decoder.h"
#include "Objects/loadDefaults.h"

using namespace Atlas;

bool root_arrived = false;
bool look_arrived = false;
bool acct_arrived = false;
bool anonymous_arrived = false;
bool unknown_arrived = false;

class TestDecoder : public ObjectsDecoder
{
protected:
    virtual void objectArrived(const Root& r)
    {
        assert(r->getAttr("id").asString() == "root_instance");
        root_arrived = true;
    }

    virtual void objectArrived(const Look& l)
    {
        assert(l->getAttr("id").asString() == "look_instance");
        look_arrived = true;
    }

    virtual void objectArrived(const Account &a)
    {
        acct_arrived = true;
    }

    virtual void objectArrived(const Anonymous&) {
        anonymous_arrived = true;
    }

    virtual void unknownObjectArrived(const Object&) {
        unknown_arrived = true;
    }
};

int main(int argc, char** argv)
{
    try {
        loadDefaults("../../../../protocols/atlas/spec/atlas.xml");
    } catch(DefaultLoadingException e) {
        cout << "DefaultLoadingException: "
             << e.msg << endl;
        return 1;
    }
    TestDecoder t;
    t.streamBegin();
    t.streamMessage(Bridge::mapBegin);
        t.mapItem("parents", Bridge::listBegin);
//            t.listItem("root");
        t.listEnd();
//        t.mapItem("id", "root_instance");
        t.mapItem("id", "foo");
    t.mapEnd();
    t.streamMessage(Bridge::mapBegin);
        t.mapItem("objtype", "op");
        t.mapItem("parents", Bridge::listBegin);
            t.listItem("look");
        t.listEnd();
        t.mapItem("id", "look_instance");
    t.mapEnd();
    t.streamEnd();
    assert(!root_arrived);
    assert(anonymous_arrived);
    assert(look_arrived);
    assert(!acct_arrived);
    assert(!unknown_arrived);
}