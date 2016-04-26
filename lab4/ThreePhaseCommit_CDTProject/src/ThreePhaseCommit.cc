
#include "ThreePhaseCommit.hh"

#include "umlrtobjectclass.hh"
#include "umlrtoutsignal.hh"
struct UMLRTCommsPort;

static UMLRTObject_field fields_canCommit[] = 
{
};

static UMLRTObject payload_canCommit = 
{
    0,
    0,
    fields_canCommit
};

static UMLRTObject_field fields_yes[] = 
{
};

static UMLRTObject payload_yes = 
{
    0,
    0,
    fields_yes
};

ThreePhaseCommit::Base::Base( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal ThreePhaseCommit::Base::yes() const
{
    UMLRTOutSignal signal;
    signal.initialize( "yes", signal_yes, srcPort, &payload_yes );
    return signal;
}

ThreePhaseCommit::Conj::Conj( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal ThreePhaseCommit::Conj::canCommit() const
{
    UMLRTOutSignal signal;
    signal.initialize( "canCommit", signal_canCommit, srcPort, &payload_canCommit );
    return signal;
}


