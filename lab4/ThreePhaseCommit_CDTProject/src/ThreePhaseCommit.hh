
#ifndef THREEPHASECOMMIT_HH
#define THREEPHASECOMMIT_HH

#include "umlrtoutsignal.hh"
#include "umlrtprotocol.hh"
#include "umlrtsignal.hh"
struct UMLRTCommsPort;

namespace ThreePhaseCommit
{
    class Base : public UMLRTProtocol
    {
    public:
        Base( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal yes() const;
    };
    class Conj : public UMLRTProtocol
    {
    public:
        Conj( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal canCommit() const;
    };
    enum SignalId
    {
        signal_canCommit = UMLRTSignal::FIRST_PROTOCOL_SIGNAL_ID,
        signal_yes
    };
};

#endif

