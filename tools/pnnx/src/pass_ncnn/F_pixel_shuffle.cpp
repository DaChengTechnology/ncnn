// Copyright 2021 Tencent
// SPDX-License-Identifier: BSD-3-Clause

#include "pass_ncnn.h"

namespace pnnx {

namespace ncnn {

class F_pixel_shuffle : public GraphRewriterPass
{
public:
    const char* match_pattern_graph() const
    {
        return R"PNNXIR(7767517
3 2
pnnx.Input              input       0 1 input
F.pixel_shuffle         op_0        1 1 input out upscale_factor=%upscale_factor
pnnx.Output             output      1 0 out
)PNNXIR";
    }

    const char* type_str() const
    {
        return "PixelShuffle";
    }

    const char* name_str() const
    {
        return "pixel_shuffle";
    }

    void write(Operator* op, const std::map<std::string, Parameter>& captured_params) const
    {
        op->params["0"] = captured_params.at("upscale_factor");
        op->params["1"] = 0;
    }
};

REGISTER_GLOBAL_PNNX_NCNN_GRAPH_REWRITER_PASS(F_pixel_shuffle, 20)

} // namespace ncnn

} // namespace pnnx
