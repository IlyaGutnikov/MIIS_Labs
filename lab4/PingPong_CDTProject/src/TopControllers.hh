
#ifndef TOPCONTROLLERS_HH
#define TOPCONTROLLERS_HH

#include "umlrtcontroller.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

enum CapsuleInstanceId
{
    InstId_Top,
    InstId_Top_pinger,
    InstId_Top_ponger
};
extern UMLRTController DefaultController;
extern UMLRTCommsPort borderports_Top_pinger[];
extern UMLRTCommsPort borderports_Top_ponger[];
extern UMLRTSlot Top_slots[];

#endif

