#include <utility>
#include <glm/glm.hpp>
#include "winged/face-intersection.hpp"

struct WingedFaceIntersection::Impl {
  WingedFaceIntersection* self;
  WingedMesh*             _mesh;
  WingedFace*             _face;

  Impl (WingedFaceIntersection* s) : self (s) {}

  void update (float d, const glm::vec3& p, WingedMesh& m, WingedFace& f) {
    if (this->self->Intersection::update (d,p)) {
      this->_mesh = &m;
      this->_face = &f;
    }
  }

  WingedMesh& mesh () const {
    assert (this->self->isIntersection ());
    return *this->_mesh;
  }

  WingedFace& face () const {
    assert (this->self->isIntersection ());
    return *this->_face;
  }
};

DELEGATE_BIG6_BASE (WingedFaceIntersection,(),(this),Intersection,())
DELEGATE4      (void            , WingedFaceIntersection, update, float, const glm::vec3&, WingedMesh&, WingedFace&)
DELEGATE_CONST (WingedMesh&     , WingedFaceIntersection, mesh)
DELEGATE_CONST (WingedFace&     , WingedFaceIntersection, face)
