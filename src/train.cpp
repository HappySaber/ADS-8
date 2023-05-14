// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
  Cage* cage = nullptr;
  if (first == nullptr) {
    first = new Cage;
    first->light = light;
    first->next->prev = first;

  } else {
    cage = new Cage;
    cage->next = first;
    cage->prev = first->prev;
    cage->light = light;
    first->prev = cage;
    first->next = first;
    first->prev = first;
  }
}

int Train::getLength() {
    Cage* f = first;
    f->light = true;
    int count = 1;
    while (true) {
        f = f->next;
        if (f->light == false) {
          count++;
          countOp++;
        } else {
          f->light = false;
          for (int i = count; i > 0; i--) {
            f = f->prev;
            countOp++;
          }
          countOp++;
          if (f->light = false)
            return count;
          else
            count == 1;
        }
    }
}

int Train::getOpCount() {
    return countOp;
}
