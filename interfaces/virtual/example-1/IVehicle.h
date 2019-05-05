#ifndef IVEHICLE_H
#define IVEHICLE_H

struct IVehicle {
  virtual ~IVehicle() = default;

  virtual void StartEngine(void) = 0;
};

#endif
