
#include "Rec1.hh"

#include "ThreePhaseCommit.hh"
#include "umlrtcommsportrole.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include <cstddef>
#include "umlrtcapsuleclass.hh"
#include "umlrtframeservice.hh"
class UMLRTRtsInterface;
struct UMLRTCommsPort;

#include <iostream>

Capsule_Rec1::Capsule_Rec1( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, Rec1( borderPorts[borderport_Rec1] )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[top__Playing] = "top__Playing";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}





void Capsule_Rec1::bindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_Rec1:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_Rec1, index, true );
            break;
        }
}

void Capsule_Rec1::unbindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_Rec1:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_Rec1, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_Rec1], index );
            break;
        }
}

void Capsule_Rec1::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case top__Playing:
        currentState = state_____top__Playing( &message );
        break;
    default:
        break;
    }
}

void Capsule_Rec1::initialize( const UMLRTMessage & message )
{
    msg = &message;
    currentState = top__Playing;
}

const char * Capsule_Rec1::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_Rec1::transitionaction_____ThreePhaseCommit__Rec1__Rec1__Region1__onPing__logTransition( const UMLRTMessage * msg )
{
    // the following code has been generated
    /* UMLRT-CODEGEN:platform:/resource/ThreePhaseCommit/ThreePhaseCommit.uml#_iGL6UAuGEeahKpDUmM4QfQ */
    #define rtdata ( (void *)msg->getParam( 0 ) )
    // generated code ends
    if ( Rec1.canCommit().send() ) {
      std::cout << "canCommit sent!" << std::endl;
    } else {
      std::cout << "Error sending canCommit!" << std::endl;
    }
    // the following code has been generated
    #undef rtdata
    // generated code ends
}

void Capsule_Rec1::actionchain_____top__onPing__ActionChain4( const UMLRTMessage * msg )
{
    transitionaction_____ThreePhaseCommit__Rec1__Rec1__Region1__onPing__logTransition( msg );
}

Capsule_Rec1::State Capsule_Rec1::state_____top__Playing( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_Rec1:
        switch( msg->getSignalId() )
        {
        case ThreePhaseCommit::signal_yes:
            actionchain_____top__onPing__ActionChain4( msg );
            return top__Playing;
        default:
            this->unexpectedMessage();
            break;
        }
        return currentState;
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}


static const UMLRTCommsPortRole portroles_border[] = 
{
    {
        Capsule_Rec1::port_Rec1,
        "ThreePhaseCommit",
        "Rec1",
        "",
        1,
        true,
        true,
        false,
        false,
        false,
        false,
        true
    }
};

static void instantiate_Rec1( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    slot->capsule = new Capsule_Rec1( &Rec1, slot, borderPorts, NULL, false );
}

const UMLRTCapsuleClass Rec1 = 
{
    "Rec1",
    NULL,
    instantiate_Rec1,
    0,
    NULL,
    1,
    portroles_border,
    0,
    NULL
};

