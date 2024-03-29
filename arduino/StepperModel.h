/*
 * Copyright 2011 by Eberhard Rensch <http://pleasantsoftware.com/developer/3d>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

/*Changed by Jacek Korbel 2018 from EggBot to PlasmaCutter for Tubes*/
 
#ifndef STEPPERMODEL
#define STEPPERMODEL

// Uncomment if You have Autohoming:
#define AUTO_HOMING 

class StepperModel
{
private:
  
  int dirPin;
  int stepPin;
  int enablePin;
  int sleepPin;
  int resetPin;
  int ms1Pin;
  int ms2Pin;
  int ms3Pin;
  
  int endStopPin;
  int endStopType;
  
  long minStepCount;
  long maxStepCount;

  double steps_per;
  double steps_per_mm;
  double steps_per_deg;
  double steps_per_rad;

  double gearRatio;
  double defaultDiameter;

  int moveType;

  double kStepsPerRevolution;
  int kMicroStepping;

  volatile long currentStepcount;
  volatile long targetStepcount;
  volatile long targetStepcountInMM;

  volatile bool direction;
 
  long getStepsForMM(double mm);
  long getStepsForMMinMM(double mm);
 
public:
  volatile long delta;
  volatile long counter;
  double targetPosition;
  double targetPositionInMM;
  
 StepperModel(
        int inDirPin, int inStepPin, int inEnablePin, int inEndStopPin, 
        int inMs1Pin, int inMs2Pin, int inMs3Pin, 
        int inSleepPin, int inResetPin,
        bool vms1, bool vms2, bool vms3, 
        long minSC, long maxSC,
        double in_kStepsPerRevolution, int in_kMicroStepping, int in_gearRatio,
        double in_defaultDiameter,
        int in_endStopType,
	int in_moveType);
  
  void resetSteppersForObjectDiameter(double diameter);
  void resetSteppersForMoveType(int type);  

  void autoHoming();
  
  void setTargetPosition(double pos);
  double getCurrentPosition();
  double getCurrentPositionInMM();
  
  void enableStepper(bool enabled);
  
  void resetStepper();
  
  void doStep(long intervals);
};

#endif
