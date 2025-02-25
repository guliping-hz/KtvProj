/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_SYSTEM_WRAPPERS_SOURCE_RW_LOCK_GENERIC_H_
#define WEBRTC_SYSTEM_WRAPPERS_SOURCE_RW_LOCK_GENERIC_H_

#include "rw_lock_wrapper.h"

namespace webrtc {

class CriticalSectionWrapper;
class ConditionVariableWrapper;

class RWLockGeneric : public RWLockWrapper {
 public:
  RWLockGeneric();
  virtual ~RWLockGeneric();

  virtual void AcquireLockExclusive();
  virtual void ReleaseLockExclusive();

  virtual void AcquireLockShared();
  virtual void ReleaseLockShared();

 private:
  CriticalSectionWrapper* critical_section_;
  ConditionVariableWrapper* read_condition_;
  ConditionVariableWrapper* write_condition_;

  int readers_active_;
  bool writer_active_;
  int readers_waiting_;
  int writers_waiting_;
};

}  // namespace webrtc

#endif  // WEBRTC_SYSTEM_WRAPPERS_SOURCE_RW_LOCK_GENERIC_H_
