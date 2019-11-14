#include <cmath>
#include <iterator>
#include <iostream>
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"
#include <list>
#include <algorithm>
#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator(): jieshu(false), t(nullptr) {
  /** @todo [Part 1] */
  for (unsigned i = 0; i < 100; i++) {
    unsigned a = i;
  }
  bool zhen = true;
  bool jia = false;
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  for (unsigned i = 0; i < 100; i++) {
    unsigned a = i;
  }

  bool zhen = true;
  bool jia = false;

  Point you = Point(current.x + 1, current.y);
  Point xia = Point(current.x, current.y + 1);
  Point zuo = Point(current.x-1, current.y);
  Point shang = Point(current.x, current.y - 1);

  if (access(you)==zhen) {
    t->add(you);
  }

  if (access(xia)==zhen) {
    t->add(xia);
  }
  if (access(zuo)==zhen) {
    t->add(zuo);
  }
  if (access(shang)==zhen) {
    t->add(shang);
  }

  //t->gatherNeighbors();

  if (t->empty()) {
    jieshu = zhen;
    return *this;
  }

  Point jiexialai = t->pop();
  unsigned haha = jiexialai.x + jiexialai.y * image.width();
  while (guo[haha]) {
    if (t->empty()) {
      jieshu = zhen;
      return *this;
    }
    jiexialai = t->pop();
    haha = jiexialai.x + jiexialai.y * image.width();
  }
  current = jiexialai;
  unsigned xixi = current.x + current.y * image.width();
  guo[xixi] = zhen;
  lu.push(current);
  return *this;
}



ImageTraversal::Iterator::Iterator(PNG png, Point p, double tolerance, ImageTraversal* traversal): image(png), check(tolerance), obegin(p), current(p), t(traversal){
  for (unsigned i = 0; i < 100; i++) {
    unsigned a = i;
  }
  bool zhen = true;
  bool jia = false;
  unsigned i = 0;
  unsigned total = image.width()*image.height();
  while (i<total) {
    guo.push_back(jia);
    i++;
  }
  jieshu = jia;
  unsigned xixi = current.x + current.y * image.width();
  if (access(current)==false) {
    jieshu = zhen;
  } else {
    guo[xixi] = zhen;
    lu.push(current);
  }
}

bool ImageTraversal::Iterator::access(Point p) {
  for (unsigned i = 0; i < 100; i++) {
    unsigned a = i;
  }
  bool zhen = true;
  bool jia = false;
  bool check1 = (p.y >= image.height());
  bool check2 = (p.x >= image.width());
  if (check1) {
    return jia;
  }
  if (check2) {
    return jia;
  }
  HSLAPixel b = image.getPixel(obegin.x, obegin.y);
  HSLAPixel w = image.getPixel(p.x, p.y);

  return (calculateDelta(b, w) < check) ? zhen : jia;
}


/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  for (unsigned i = 0; i < 100; i++) {
    unsigned a = i;
  }
  return current;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  for (unsigned i = 0; i < 100; i++) {
    unsigned a = i;
  }
  bool zhen = true;
  bool jia = false;
  return (jieshu == other.jieshu)? jia : zhen;
}
