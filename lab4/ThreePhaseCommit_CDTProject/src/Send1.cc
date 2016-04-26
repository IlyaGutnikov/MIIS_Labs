
#include "Send1.hh"

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

Capsule_Send1::Capsule_Send1( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, send1( borderPorts[borderport_send1] )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[top__Playing] = "top__Playing";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}





void Capsule_Send1::bindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_send1:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_send1, index, true );
            break;
        }
}

void Capsule_Send1::unbindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_send1:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_send1, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_send1], index );
            break;
        }
}

void Capsule_Send1::inject( const UMLRTMessage & message )
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

void Capsule_Send1::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____top__initial__ActionChain2( &message );
    currentState = top__Playing;
}

const char * Capsule_Send1::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_Send1::entryaction_____ThreePhaseCommit__Send1__Send1__Region1__Playing__sendPing( const UMLRTMessage * msg )
{
    // the following code has been generated
    /* UMLRT-CODEGEN:platform:/resource/ThreePhaseCommit/ThreePhaseCommit.uml#_xM00MAuEEeahKpDUmM4QfQ */
    #define rtdata ( (void *)msg->getParam( 0 ) )
    // generated code ends
     if ( send1.yes().send() ) {
      std::cout << "Yes sent!" << std::endl;
    } else {
      std::cout << "Error sending Ping!" << std::endl;
    }
    // the following code has been generated
    #undef rtdata
    // generated code ends
}

void Capsule_Send1::transitionaction_____ThreePhaseCommit__Send1__Send1__Region1__onPong__logTransition( const UMLRTMessage * msg )
{
    // the following code has been generated
    /* UMLRT-CODEGEN:platform:/resource/ThreePhaseCommit/ThreePhaseCommit.uml#_0SCHEAuDEeahKpDUmM4QfQ */
    #define rtdata ( (void *)msg->getParam( 0 ) )
    // generated code ends
    std::cout << "onCanCommit transition taken!" << std::endl;
    // the following code has been generated
    #undef rtdata
    // generated code ends
}

void Capsule_Send1::actionchain_____top__initial__ActionChain2( const UMLRTMessage * msg )
{
    entryaction_____ThreePhaseCommit__Send1__Send1__Region1__Playing__sendPing( msg );
}

void Capsule_Send1::actionchain_____top__onPong__ActionChain3( const UMLRTMessage * msg )
{
    transitionaction_____ThreePhaseCommit__Send1__Send1__Region1__onPong__logTransition( msg );
    entryaction_____ThreePhaseCommit__Send1__Send1__Region1__Playing__sendPing( msg );
}

Capsule_Send1::State Capsule_Send1::state_____top__Playing( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_send1:
        switch( msg->getSignalId() )
        {
        case ThreePhaseCommit::signal_canCommit:
            actionchain_____top__onPong__ActionChain3( msg );
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
        Capsule_Send1::port_send1,
        "ThreePhaseCommit",
        "send1",
        "",
        1,
        true,
        false,
        false,
        false,
        false,
        false,
        true
    }
};

static void instantiate_Send1( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    slot->capsule = new Capsule_Send1( &Send1, slot, borderPorts, NULL, false );
}

const UMLRTCapsuleClass Send1 = 
{
    "Send1",
    NULL,
    instantiate_Send1,
    0,
    NULL,
    1,
    portroles_border,
    0,
    NULL
};

