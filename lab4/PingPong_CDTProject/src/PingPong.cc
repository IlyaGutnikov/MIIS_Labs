
#include "PingPong.hh"

#include "umlrtobjectclass.hh"
#include "umlrtoutsignal.hh"
struct UMLRTCommsPort;

static UMLRTObject_field fields_ping[] = 
{
};

static UMLRTObject payload_ping = 
{
    0,
    0,
    fields_ping
};

static UMLRTObject_field fields_pong[] = 
{
};

static UMLRTObject payload_pong = 
{
    0,
    0,
    fields_pong
};

PingPong::Base::Base( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal PingPong::Base::ping() const
{
    UMLRTOutSignal signal;
    signal.initialize( "ping", signal_ping, srcPort, &payload_ping );
    return signal;
}

PingPong::Conj::Conj( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal PingPong::Conj::pong() const
{
    UMLRTOutSignal signal;
    signal.initialize( "pong", signal_pong, srcPort, &payload_pong );
    return signal;
}


