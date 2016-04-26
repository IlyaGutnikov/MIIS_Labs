
#ifndef TOPCONTROLLERS_HH
#define TOPCONTROLLERS_HH

#include "umlrtcontroller.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

enum CapsuleInstanceId
{
    InstId_Top,
    InstId_Top_rec1,
    InstId_Top_send1
};
extern UMLRTController DefaultController;
extern UMLRTCommsPort borderports_Top_rec1[];
extern UMLRTCommsPort borderports_Top_send1[];
extern UMLRTSlot Top_slots[];

#endif

