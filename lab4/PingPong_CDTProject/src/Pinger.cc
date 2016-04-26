
#include "Pinger.hh"

#include "PingPong.hh"
#include "umlrtcommsportrole.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include <cstddef>
#include "umlrtcapsuleclass.hh"
#include "umlrtframeservice.hh"
class UMLRTRtsInterface;
struct UMLRTCommsPort;

#include <iostream>

Capsule_Pinger::Capsule_Pinger( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, pinger( borderPorts[borderport_pinger] )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[top__Playing] = "top__Playing";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}





void Capsule_Pinger::bindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_pinger:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_pinger, index, true );
            break;
        }
}

void Capsule_Pinger::unbindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_pinger:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_pinger, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_pinger], index );
            break;
        }
}

void Capsule_Pinger::inject( const UMLRTMessage & message )
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

void Capsule_Pinger::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____top__initial__ActionChain2( &message );
    currentState = top__Playing;
}

const char * Capsule_Pinger::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_Pinger::entryaction_____PingPong__Pinger__Pinger__Region1__Playing__sendPing( const UMLRTMessage * msg )
{
    // the following code has been generated
    /* UMLRT-CODEGEN:platform:/resource/PingPong/PingPong.uml#_xM00MAuEEeahKpDUmM4QfQ */
    #define rtdata ( (void *)msg->getParam( 0 ) )
    // generated code ends
     if ( pinger.ping().send() ) {
      std::cout << "Ping sent!" << std::endl;
    } else {
      std::cout << "Error sending Ping!" << std::endl;
    }
    // the following code has been generated
    #undef rtdata
    // generated code ends
}

void Capsule_Pinger::transitionaction_____PingPong__Pinger__Pinger__Region1__onPong__logTransition( const UMLRTMessage * msg )
{
    // the following code has been generated
    /* UMLRT-CODEGEN:platform:/resource/PingPong/PingPong.uml#_0SCHEAuDEeahKpDUmM4QfQ */
    #define rtdata ( (void *)msg->getParam( 0 ) )
    // generated code ends
    std::cout << "onPong transition taken!" << std::endl;
    // the following code has been generated
    #undef rtdata
    // generated code ends
}

void Capsule_Pinger::actionchain_____top__initial__ActionChain2( const UMLRTMessage * msg )
{
    entryaction_____PingPong__Pinger__Pinger__Region1__Playing__sendPing( msg );
}

void Capsule_Pinger::actionchain_____top__onPong__ActionChain3( const UMLRTMessage * msg )
{
    transitionaction_____PingPong__Pinger__Pinger__Region1__onPong__logTransition( msg );
    entryaction_____PingPong__Pinger__Pinger__Region1__Playing__sendPing( msg );
}

Capsule_Pinger::State Capsule_Pinger::state_____top__Playing( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_pinger:
        switch( msg->getSignalId() )
        {
        case PingPong::signal_pong:
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
        Capsule_Pinger::port_pinger,
        "PingPong",
        "pinger",
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

static void instantiate_Pinger( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    slot->capsule = new Capsule_Pinger( &Pinger, slot, borderPorts, NULL, false );
}

const UMLRTCapsuleClass Pinger = 
{
    "Pinger",
    NULL,
    instantiate_Pinger,
    0,
    NULL,
    1,
    portroles_border,
    0,
    NULL
};

