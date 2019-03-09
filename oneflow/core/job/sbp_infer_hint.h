#ifndef ONEFLOW_CORE_JOB_SBP_INFER_HINT_H_
#define ONEFLOW_CORE_JOB_SBP_INFER_HINT_H_

#include "oneflow/core/job/sbp_parallel.pb.h"
#include "oneflow/core/job/parallel_desc.h"

namespace oneflow {

class SbpInferHint final {
 public:
  SbpInferHint(bool is_model_blob, const ParallelDesc& parallel_desc, int64_t num_axes,
               const SbpParallel& sbp_parallel)
      : is_model_blob_(is_model_blob),
        parallel_desc_(&parallel_desc),
        num_axes_(num_axes),
        sbp_parallel_(sbp_parallel) {}
  SbpInferHint(const SbpInferHint&) = default;
  ~SbpInferHint() = default;

  // Getters
  bool is_model_blob() const { return is_model_blob_; }
  int64_t parallel_num() const { return parallel_desc_->parallel_num(); }
  int64_t num_axes() const;
  int64_t split_axis() const;
  bool has_split_axis() const;
  bool is_model_split() const;
  bool is_model_broadcast() const;
  bool is_data_split() const;
  bool is_data_partial_sum() const;
  bool is_data_blob() const { return !is_model_blob(); }
  const SbpParallel& sbp_parallel() const { return sbp_parallel_; }
  const ParallelDesc& parallel_desc() const { return *parallel_desc_; }

 private:
  const bool is_model_blob_;
  const ParallelDesc* parallel_desc_;
  const int64_t num_axes_;
  const SbpParallel sbp_parallel_;
};

}  // namespace oneflow

#endif  // ONEFLOW_CORE_JOB_SBP_INFER_HINT_H_
