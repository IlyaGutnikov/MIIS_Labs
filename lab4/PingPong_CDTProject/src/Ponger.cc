
#include "Ponger.hh"

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

Capsule_Ponger::Capsule_Ponger( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, ponger( borderPorts[borderport_ponger] )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[top__Playing] = "top__Playing";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}





void Capsule_Ponger::bindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_ponger:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_ponger, index, true );
            break;
        }
}

void Capsule_Ponger::unbindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_ponger:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_ponger, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_ponger], index );
            break;
        }
}

void Capsule_Ponger::inject( const UMLRTMessage & message )
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

void Capsule_Ponger::initialize( const UMLRTMessage & message )
{
    msg = &message;
    currentState = top__Playing;
}

const char * Capsule_Ponger::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_Ponger::transitionaction_____PingPong__Ponger__Ponger__Region1__onPing__logTransition( const UMLRTMessage * msg )
{
    // the following code has been generated
    /* UMLRT-CODEGEN:platform:/resource/PingPong/PingPong.uml#_iGL6UAuGEeahKpDUmM4QfQ */
    #define rtdata ( (void *)msg->getParam( 0 ) )
    // generated code ends
    if ( ponger.pong().send() ) {
      std::cout << "Pong sent!" << std::endl;
    } else {
      std::cout << "Error sending Ping!" << std::endl;
    }
    // the following code has been generated
    #undef rtdata
    // generated code ends
}

void Capsule_Ponger::actionchain_____top__onPing__ActionChain4( const UMLRTMessage * msg )
{
    transitionaction_____PingPong__Ponger__Ponger__Region1__onPing__logTransition( msg );
}

Capsule_Ponger::State Capsule_Ponger::state_____top__Playing( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_ponger:
        switch( msg->getSignalId() )
        {
        case PingPong::signal_ping:
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
        Capsule_Ponger::port_ponger,
        "PingPong",
        "ponger",
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

static void instantiate_Ponger( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    slot->capsule = new Capsule_Ponger( &Ponger, slot, borderPorts, NULL, false );
}

const UMLRTCapsuleClass Ponger = 
{
    "Ponger",
    NULL,
    instantiate_Ponger,
    0,
    NULL,
    1,
    portroles_border,
    0,
    NULL
};

