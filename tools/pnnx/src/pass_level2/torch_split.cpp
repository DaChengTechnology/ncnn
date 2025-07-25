// Copyright 2021 Tencent
// SPDX-License-Identifier: BSD-3-Clause

#include "pass_level2.h"

namespace pnnx {

class torch_split : public GraphRewriterPass
{
public:
    const char* match_pattern_graph() const
    {
        return R"PNNXIR(7767517
5 4
pnnx.Input              input_0     0 1 tensor
pnnx.Input              input_1     0 1 split_size_or_sections
pnnx.Input              input_2     0 1 dim
aten::split             op_0        3 1 tensor split_size_or_sections dim out
pnnx.Output             output      1 0 out
)PNNXIR";
    }

    const char* type_str() const
    {
        return "torch.split";
    }
};

REGISTER_GLOBAL_PNNX_GRAPH_REWRITER_PASS(torch_split, 60)

class torch_split_01 : public GraphRewriterPass
{
public:
    const char* match_pattern_graph() const
    {
        return R"PNNXIR(7767517
4 3
pnnx.Input              input_0     0 1 tensor
pnnx.Input              input_1     0 1 split_size_or_sections
aten::split             op_0        2 1 tensor split_size_or_sections out dim=%dim
pnnx.Output             output      1 0 out
)PNNXIR";
    }

    const char* type_str() const
    {
        return "torch.split";
    }
};

REGISTER_GLOBAL_PNNX_GRAPH_REWRITER_PASS(torch_split_01, 60)

class torch_split_1 : public GraphRewriterPass
{
public:
    const char* match_pattern_graph() const
    {
        return R"PNNXIR(7767517
5 4
pnnx.Input              input_0     0 1 tensor
pnnx.Input              input_1     0 1 split_size_or_sections
pnnx.Input              input_2     0 1 dim
aten::split_with_sizes  op_0        3 1 tensor split_size_or_sections dim out
pnnx.Output             output      1 0 out
)PNNXIR";
    }

    const char* type_str() const
    {
        return "torch.split";
    }
};

REGISTER_GLOBAL_PNNX_GRAPH_REWRITER_PASS(torch_split_1, 60)

class torch_split_onnx : public GraphRewriterPass
{
public:
    const char* match_pattern_graph() const
    {
        return R"PNNXIR(7767517
3 2
pnnx.Input              input       0 1 tensor
aten::split             op_0        1 1 tensor out dim=%dim indices=%split_size_or_sections
pnnx.Output             output      1 0 out
)PNNXIR";
    }

    const char* type_str() const
    {
        return "torch.split";
    }
};

REGISTER_GLOBAL_PNNX_GRAPH_REWRITER_PASS(torch_split_onnx, 60)

class torch_split_onnx_1 : public torch_split_onnx
{
public:
    const char* match_pattern_graph() const
    {
        return R"PNNXIR(7767517
4 3
pnnx.Input              input_0     0 1 tensor
pnnx.Input              input_1     0 1 split_size_or_sections
aten::split             op_0        2 1 tensor split_size_or_sections out dim=%dim indices=None
pnnx.Output             output      1 0 out
)PNNXIR";
    }
};

REGISTER_GLOBAL_PNNX_GRAPH_REWRITER_PASS(torch_split_onnx_1, 60)

} // namespace pnnx
