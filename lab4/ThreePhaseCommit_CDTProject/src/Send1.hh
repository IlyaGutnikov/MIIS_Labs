
#ifndef SEND1_HH
#define SEND1_HH

#include "ThreePhaseCommit.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtmessage.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_Send1 : public UMLRTCapsule
{
public:
    Capsule_Send1( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    ThreePhaseCommit::Base send1;
public:
    enum BorderPortId
    {
        borderport_send1
    };
    enum PartId
    {
    };
    enum PortId
    {
        port_send1
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
    void entryaction_____ThreePhaseCommit__Send1__Send1__Region1__Playing__sendPing( const UMLRTMessage * msg );
    void transitionaction_____ThreePhaseCommit__Send1__Send1__Region1__onPong__logTransition( const UMLRTMessage * msg );
    void actionchain_____top__initial__ActionChain2( const UMLRTMessage * msg );
    void actionchain_____top__onPong__ActionChain3( const UMLRTMessage * msg );
    State state_____top__Playing( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass Send1;

#endif

