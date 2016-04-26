
#include "TopControllers.hh"

#include "Rec1.hh"
#include "Send1.hh"
#include "Top.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtcapsulepart.hh"
#include "umlrtcommsport.hh"
#include "umlrtcommsportfarend.hh"
#include "umlrtcontroller.hh"
#include "umlrtslot.hh"
#include <cstddef>


UMLRTController DefaultController( "DefaultController" );

static Capsule_Top top( &Top, &Top_slots[InstId_Top], NULL, NULL, true );

static UMLRTSlot * slots_Top[] = 
{
    &Top_slots[InstId_Top_rec1],
    &Top_slots[InstId_Top_send1]
};

static UMLRTCapsulePart parts_Top[] = 
{
    {
        &Top,
        Capsule_Top::part_rec1,
        1,
        &slots_Top[0]
    },
    {
        &Top,
        Capsule_Top::part_send1,
        1,
        &slots_Top[1]
    }
};

static UMLRTCommsPortFarEnd borderfarEndList_Top_rec1[] = 
{
    {
        0,
        &borderports_Top_send1[Capsule_Send1::borderport_send1]
    }
};

UMLRTCommsPort borderports_Top_rec1[] = 
{
    {
        &Rec1,
        Capsule_Rec1::borderport_Rec1,
        &Top_slots[InstId_Top_rec1],
        1,
        borderfarEndList_Top_rec1,
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    }
};

static const UMLRTCommsPort * borderports_Top_rec1_ptrs[] = 
{
    &borderports_Top_rec1[0]
};

static Capsule_Rec1 top_rec1( &Rec1, &Top_slots[InstId_Top_rec1], borderports_Top_rec1_ptrs, NULL, true );

static UMLRTCommsPortFarEnd borderfarEndList_Top_send1[] = 
{
    {
        0,
        &borderports_Top_rec1[Capsule_Rec1::borderport_Rec1]
    }
};

UMLRTCommsPort borderports_Top_send1[] = 
{
    {
        &Send1,
        Capsule_Send1::borderport_send1,
        &Top_slots[InstId_Top_send1],
        1,
        borderfarEndList_Top_send1,
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    }
};

static const UMLRTCommsPort * borderports_Top_send1_ptrs[] = 
{
    &borderports_Top_send1[0]
};

static Capsule_Send1 top_send1( &Send1, &Top_slots[InstId_Top_send1], borderports_Top_send1_ptrs, NULL, true );

UMLRTSlot Top_slots[] = 
{
    {
        "Top",
        0,
        &Top,
        NULL,
        0,
        &top,
        &DefaultController,
        2,
        parts_Top,
        0,
        NULL,
        NULL,
        true,
        false
    },
    {
        "Top.rec1",
        0,
        &Rec1,
        &Top,
        Capsule_Top::part_rec1,
        &top_rec1,
        &DefaultController,
        0,
        NULL,
        1,
        borderports_Top_rec1,
        NULL,
        true,
        false
    },
    {
        "Top.send1",
        0,
        &Send1,
        &Top,
        Capsule_Top::part_send1,
        &top_send1,
        &DefaultController,
        0,
        NULL,
        1,
        borderports_Top_send1,
        NULL,
        true,
        false
    }
};

