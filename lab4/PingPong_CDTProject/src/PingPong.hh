
#ifndef PINGPONG_HH
#define PINGPONG_HH

#include "umlrtoutsignal.hh"
#include "umlrtprotocol.hh"
#include "umlrtsignal.hh"
struct UMLRTCommsPort;

namespace PingPong
{
    class Base : public UMLRTProtocol
    {
    public:
        Base( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal ping() const;
    };
    class Conj : public UMLRTProtocol
    {
    public:
        Conj( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal pong() const;
    };
    enum SignalId
    {
        signal_pong = UMLRTSignal::FIRST_PROTOCOL_SIGNAL_ID,
        signal_ping
    };
};

#endif

