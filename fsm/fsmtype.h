#ifndef CODEKATA_CPP_FSMTYPE_H
#define CODEKATA_CPP_FSMTYPE_H

#include <memory>
#include <vector>

namespace vic {
    class MachineBase;
    class ActionMachine;
    class MachineSet;
    class MachineSetHandler;
    class Event;
    class IPredicate;
    class State;
    class Transition;
    class NonTransitionAction;

    typedef std::shared_ptr<MachineBase> MachineBaseSharedPtr;
    typedef std::weak_ptr<MachineBase> MachineBaseWeakPtr;
    typedef std::vector<MachineBaseWeakPtr> MachineBaseWeakPtrVec;

    typedef std::shared_ptr<MachineSet> MachineSetSharedPtr;
    typedef std::weak_ptr<MachineSet> MachineSetWeakPtr;

    typedef std::shared_ptr<MachineSetHandler> MachineSetHandlerSharedPtr;

    typedef std::shared_ptr<Event> EventSharedPtr;

    typedef std::shared_ptr<IPredicate> IPredicateSharedPtr;

    typedef std::shared_ptr<State> StateSharedPtr;
    typedef std::weak_ptr<State> StateWeakPtr;

    typedef std::shared_ptr<Transition> TransitionSharedPtr;
    typedef std::shared_ptr<NonTransitionAction> NonTransitionActionSharedPtr;

    typedef std::shared_ptr<ActionMachine> ActionMachineSharedPtr;
} // namespace vic

#endif //CODEKATA_CPP_FSMTYPE_H
