#pragma once

#include <torch/nn/modules/batchnorm.h>
#include <torch/nn/options/instancenorm.h>

namespace torch {
namespace nn {

/// Base class for all (dimension-specialized) instance norm modules
template <size_t D, typename Derived>
class InstanceNormImpl : public torch::nn::BatchNormImplBase<D, Derived> {
 protected:
  virtual void _check_input_dim(const Tensor& input) override;

 public:
  using torch::nn::BatchNormImplBase<D, Derived>::BatchNormImplBase;

  Tensor forward(const Tensor& input) override;

  /// Pretty prints the `InstanceNorm{1,2,3}d` module into the given `stream`.
  void pretty_print(std::ostream& stream) const override;
};

/// Applies the InstanceNorm1d function.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.InstanceNorm1d to learn
/// about the exact behavior of this module.
class TORCH_API InstanceNorm1dImpl : public InstanceNormImpl<1, InstanceNorm1dImpl> {
 protected:
  virtual void _check_input_dim(const Tensor& input) override;

 public:
  using InstanceNormImpl<1, InstanceNorm1dImpl>::InstanceNormImpl;
};

TORCH_MODULE(InstanceNorm1d);

/// Applies the InstanceNorm2d function.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.InstanceNorm2d to learn
/// about the exact behavior of this module.
class TORCH_API InstanceNorm2dImpl : public InstanceNormImpl<2, InstanceNorm2dImpl> {
 protected:
  virtual void _check_input_dim(const Tensor& input) override;

 public:
  using InstanceNormImpl<2, InstanceNorm2dImpl>::InstanceNormImpl;
};

TORCH_MODULE(InstanceNorm2d);

/// Applies the InstanceNorm3d function.
/// See https://pytorch.org/docs/master/nn.html#torch.nn.InstanceNorm3d to learn
/// about the exact behavior of this module.
class TORCH_API InstanceNorm3dImpl : public InstanceNormImpl<3, InstanceNorm3dImpl> {
 protected:
  virtual void _check_input_dim(const Tensor& input) override;

 public:
  using InstanceNormImpl<3, InstanceNorm3dImpl>::InstanceNormImpl;
};

TORCH_MODULE(InstanceNorm3d);

} // namespace nn
} // namespace torch
