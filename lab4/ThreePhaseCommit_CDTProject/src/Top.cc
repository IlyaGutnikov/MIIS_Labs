
#include "Top.hh"

#include "Rec1.hh"
#include "Send1.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtcapsulepart.hh"
#include "umlrtslot.hh"
#include <cstddef>
#include "umlrtcapsulerole.hh"
#include "umlrtcommsport.hh"
#include "umlrtframeservice.hh"
class UMLRTRtsInterface;

Capsule_Top::Capsule_Top( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, rec1( &slot->parts[part_rec1] )
, send1( &slot->parts[part_send1] )
{
}




void Capsule_Top::bindPort( bool isBorder, int portId, int index )
{
}

void Capsule_Top::unbindPort( bool isBorder, int portId, int index )
{
}

void Capsule_Top::initialize( const UMLRTMessage & msg )
{
}

void Capsule_Top::inject( const UMLRTMessage & msg )
{
}


static const UMLRTCapsuleRole roles[] = 
{
    {
        "rec1",
        &Rec1,
        1,
        1,
        false,
        false
    },
    {
        "send1",
        &Send1,
        1,
        1,
        false,
        false
    }
};

static void instantiate_Top( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    UMLRTFrameService::connectPorts( &slot->parts[Capsule_Top::part_rec1].slots[0]->ports[Capsule_Rec1::borderport_Rec1], 0, &slot->parts[Capsule_Top::part_send1].slots[0]->ports[Capsule_Send1::borderport_send1], 0 );
    Rec1.instantiate( NULL, slot->parts[Capsule_Top::part_rec1].slots[0], UMLRTFrameService::createBorderPorts( slot->parts[Capsule_Top::part_rec1].slots[0], Rec1.numPortRolesBorder ) );
    Send1.instantiate( NULL, slot->parts[Capsule_Top::part_send1].slots[0], UMLRTFrameService::createBorderPorts( slot->parts[Capsule_Top::part_send1].slots[0], Send1.numPortRolesBorder ) );
    slot->capsule = new Capsule_Top( &Top, slot, borderPorts, NULL, false );
}

const UMLRTCapsuleClass Top = 
{
    "Top",
    NULL,
    instantiate_Top,
    2,
    roles,
    0,
    NULL,
    0,
    NULL
};

