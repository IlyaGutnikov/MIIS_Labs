
#ifndef PONGER_HH
#define PONGER_HH

#include "PingPong.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtmessage.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_Ponger : public UMLRTCapsule
{
public:
    Capsule_Ponger( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    PingPong::Conj ponger;
public:
    enum BorderPortId
    {
        borderport_ponger
    };
    enum PartId
    {
    };
    enum PortId
    {
        port_ponger
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
    void transitionaction_____PingPong__Ponger__Ponger__Region1__onPing__logTransition( const UMLRTMessage * msg );
    void actionchain_____top__onPing__ActionChain4( const UMLRTMessage * msg );
    State state_____top__Playing( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass Ponger;

#endif

