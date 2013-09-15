#include <list>
#include <memory>
#include "action-unit.hpp"
#include "macro.hpp"

typedef std::unique_ptr <Action> ActionPtr;

struct ActionUnit :: Impl {
  std::list <ActionPtr> actions;

  void addActionPtr (Action* action) {
    this->actions.push_back (ActionPtr (action));
  }

  void undo () {
    for (auto it = this->actions.rbegin (); it != this->actions.rend (); ++it)
      (*it)->undo ();
  }

  void redo () {
    for (auto it = this->actions.begin (); it != this->actions.end (); ++it)
      (*it)->redo ();
  }
};

DELEGATE_CONSTRUCTOR (ActionUnit)
DELEGATE_DESTRUCTOR  (ActionUnit)

DELEGATE1 (void, ActionUnit, addActionPtr, Action*)
DELEGATE  (void, ActionUnit, undo)
DELEGATE  (void, ActionUnit, redo)
