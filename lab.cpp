#include <bits/stdc++.h>
using namespace std;
class Basecomp;
class Mediator {
 public:
  virtual void Notify(Basecomp *sender, string event) const = 0;
};
class Basecomp {
 protected:
  Mediator *mediator_;

 public:
  Basecomp(Mediator *mediator = nullptr) : mediator_(mediator) {
  }
  void set_mediator(Mediator *mediator) {
    this->mediator_ = mediator;
  }
};
class comp1 : public Basecomp {
 public:
  void DoA() {
    cout << "component 1 implements A.\n";
    this->mediator_->Notify(this, "A");
  }
  void DoB() {
    cout << "component 1 implements B.\n";
    this->mediator_->Notify(this, "B");
  }
};

class comp2 : public Basecomp {
 public:
  void DoC() {
    cout << "component 2 implements C.\n";
    this->mediator_->Notify(this, "C");
  }
  void DoD() {
    cout << "component 2 implements D.\n";
    this->mediator_->Notify(this, "D");
  }
};
class concmed : public Mediator {
 private:
  comp1 *comp1_;
  comp2 *comp2_;

 public:
  concmed(comp1 *c1, comp2 *c2) : comp1_(c1), comp2_(c2) {
    this->comp1_->set_mediator(this);
    this->comp2_->set_mediator(this);
  }
  void Notify(Basecomp *sender, string event) const override {
    if (event == "A") {
      cout << "Mediator reacts and triggers operations:\n";
      this->comp2_->DoC();
    }
    if (event == "D") {
      cout << "Mediator reacts and triggers operations:\n";
      this->comp1_->DoB();
      this->comp2_->DoC();
    }
  }
};
void clcode() {
  comp2 *c1 = new comp2;
  comp1 *c2 = new comp1;
  concmed *mediator = new concmed(c2, c1);
  cout << "Client triggers the operation A.\n";
  c2->DoA();
  cout << "\n";
  cout << "Client triggers the  operation D.\n";
  c1->DoD();

  delete c1;
  delete c2;
  delete mediator;
}

int main() {
  clcode();
  return 0;
}