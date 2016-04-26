
#ifndef REC1_HH
#define REC1_HH

#include "ThreePhaseCommit.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtmessage.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_Rec1 : public UMLRTCapsule
{
public:
    Capsule_Rec1( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    ThreePhaseCommit::Conj Rec1;
public:
    enum BorderPortId
    {
        borderport_Rec1
    };
    enum PartId
    {
    };
    enum PortId
    {
        port_Rec1
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
    void transitionaction_____ThreePhaseCommit__Rec1__Rec1__Region1__onPing__logTransition( const UMLRTMessage * msg );
    void actionchain_____top__onPing__ActionChain4( const UMLRTMessage * msg );
    State state_____top__Playing( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass Rec1;

#endif

