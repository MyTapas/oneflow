#ifndef ONEFLOW_CORE_OPERATOR_SOFTMAX_LOSS_OP_H_
#define ONEFLOW_CORE_OPERATOR_SOFTMAX_LOSS_OP_H_

#include "oneflow/core/operator/operator_manager.h"

namespace oneflow {

class SoftmaxLossOp final : public UserOperator {
 public:
  OF_DISALLOW_COPY_AND_MOVE(SoftmaxLossOp);
  SoftmaxLossOp() = default;
  ~SoftmaxLossOp() = default;

  void InitFromOpConf() override;
  const PbMessage& GetSpecialConf() const override;
  bool IsLossOp() const override { return true; }

  void InferBlobDesc4FwBlobs(
      std::function<BlobDesc*(const std::string)> GetBlobDesc4BnInOp,
      ParallelPolicy policy, int64_t parallel_id,
      int64_t parallel_num) override;

 private:
};

}  // namespace oneflow

#endif  // ONEFLOW_CORE_OPERATOR_SOFTMAX_LOSS_OP_H_
