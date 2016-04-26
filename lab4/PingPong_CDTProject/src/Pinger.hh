
#ifndef PINGER_HH
#define PINGER_HH

#include "PingPong.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtmessage.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_Pinger : public UMLRTCapsule
{
public:
    Capsule_Pinger( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    PingPong::Base pinger;
public:
    enum BorderPortId
    {
        borderport_pinger
    };
    enum PartId
    {
    };
    enum PortId
    {
        port_pinger
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        top__Playing,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[2];
    State currentState;
    void entryaction_____PingPong__Pinger__Pinger__Region1__Playing__sendPing( const UMLRTMessage * msg );
    void transitionaction_____PingPong__Pinger__Pinger__Region1__onPong__logTransition( const UMLRTMessage * msg );
    void actionchain_____top__initial__ActionChain2( const UMLRTMessage * msg );
    void actionchain_____top__onPong__ActionChain3( const UMLRTMessage * msg );
    State state_____top__Playing( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass Pinger;

#endif

